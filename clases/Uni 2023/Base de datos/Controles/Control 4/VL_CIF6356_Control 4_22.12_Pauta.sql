--  CONTROL 4 (22.12)
--  BASE DE DATOS: INVERSION
--  CONEXIÓN: COTIZACION

--  OBSERVACION: El modelo de esta base de datos es la que figura en el Control 3, publicado en eAula.

--  PARTE 1
--  Crear la tabla COTIZACION. Leer atentamente los comentarios junto a cada columna

CREATE TABLE COTIZACION
(numeroCZ   NUMBER(10,0) NOT NULL,   --  Número correlativo que inicia con el año respectivo. Por ejemplo: la primera cotización para el año 2024, sería 20241
 numeroCT   NUMBER(7,0)  NOT NULL,   --  Identificador del cotizante
 fechaRegCZ DATE         NOT NULL,   --  Fecha de registro o ingreso de una cotización
 mesCZ      NUMBER(2,0)  NOT NULL,   --  Mes al que corresponde la cotización ingresada (mes por el que se está cotizando)
 agnoCZ     NUMBER(4,0)  NOT NULL,   --  Año al que corresponde la cotización ingresada (año al que pertenece el mes que se está cotizando)
 montoCZ    NUMBER(6,0)  NOT NULL,   --  Monto correspondiente a la cotización (actualmente, 10% de la renta imponible). Este monto es el que pasa directamente al ahorro obligatorio del cotizante
 comisionCZ NUMBER(5,0)  NOT NULL,   --  Monto correspondiente a la comisión cobrada por la AFP al cotizante por administrar sus fondos
 fechaPagCZ DATE         NULL,       --  Fecha de pago efectiva de la cotización del empleado por parte del empleador a la AFP
 estadoCZ   CHAR(1)      NOT NULL    --  Estado de la cotización. Dominio: {D (declarada), C (cancelada)}. Importante: Un empleador puede declarar una cotización sin haberla pagado (cancelado). Esto implica que el monto no afecta al ahorro obligatorio.
);

ALTER TABLE COTIZACION ADD CONSTRAINT PK_COTIZACION PRIMARY KEY(numeroCZ);
ALTER TABLE COTIZACION ADD CONSTRAINT FK_COTIZANTE_COTIZACION FOREIGN KEY(numeroCT) REFERENCES COTIZANTE(numeroCT);

--  PARTE 2 - EJERCICIOS
--  1.  (20 puntos) Implementar un bloque anónimo que permita ingresar una cotización válida para un cotizante en particular.
--      Consideraciones:
--      * Para determinar los montos de una cotización se requiere la remuneración imponible del cotizante, 
--        la cual no debe ser inferior al sueldo mínimo.
--      * El estado de la cotización no posee valor por defecto, ya que el empleador podría declarar o cancelar la cotización.
--        Una cotización cancelada implica el pago de esta; una declarada cancelada no.
--        En el caso de una cotizacion cancelada, su fecha de pago es la misma del registro
--      * Las cotizaciones se declaran o cancelan con un mes de desfase, por lo tanto, no existen pagos futuros
--      * Validar lo que corresponda
--      * Aplicar excepciones

SET SERVEROUTPUT ON

DECLARE
nroCT   COTIZANTE.numeroCT%TYPE;
existe  NUMBER(1,0);
mes     COTIZACION.mesCZ%TYPE;
agno    COTIZACION.agnoCZ%TYPE;
remImp  NUMBER(8,0);
estCZ   COTIZACION.estadoCZ%TYPE;
nroCZ   COTIZACION.numeroCZ%TYPE;
comCZ   AFP.comisionAFP%TYPE;

ERROR_COTIZANTE     EXCEPTION;
ERROR_MES           EXCEPTION;
ERROR_AGNO          EXCEPTION;
ERROR_REMUNERACION  EXCEPTION;
ERROR_ESTADO        EXCEPTION;
BEGIN
nroCT := '&NRO_COTIZANTE';

SELECT COUNT(numeroCT) INTO existe FROM COTIZANTE WHERE numeroCT = nroCT;

IF(existe = 0)THEN
    RAISE ERROR_COTIZANTE;
END IF;

mes := &MES_COTIZACION;
IF(mes NOT BETWEEN 1 AND 12 OR mes >= EXTRACT(MONTH FROM SYSDATE))THEN
    RAISE ERROR_MES;
END IF;

agno := &AÑO_COTIZACION;
IF((mes = 12 AND agno <> EXTRACT(YEAR FROM SYSDATE) -1) OR (mes <> 12 AND agno < EXTRACT(YEAR FROM SYSDATE)) OR (agno > EXTRACT(YEAR FROM SYSDATE)))THEN
    RAISE ERROR_AGNO;
END IF;

remImp := &REMUNERACION_IMPONIBLE;
IF(remImp < 460000)THEN
    RAISE ERROR_REMUNERACION;
END IF;

estCZ := '&SITUACION_COTIZACION_D_C';

IF(estCZ NOT IN ('C','D'))THEN
    RAISE ERROR_ESTADO;
END IF;

SELECT NVL(MAX(numeroCZ),0) INTO nroCZ FROM COTIZACION;

IF(nroCZ = 0)THEN
    nroCZ := EXTRACT(YEAR FROM SYSDATE) * 10 + 1;
ELSE
    IF(SUBSTR(nroCZ, 1,4) = EXTRACT(YEAR FROM SYSDATE))THEN
        nroCZ := nroCZ + 1;
    ELSE
        nroCZ := EXTRACT(YEAR FROM SYSDATE) * 10 + 1;
    END IF;
END IF;

SELECT comisionAFP INTO comCZ FROM COTIZANTE JOIN AFP ON COTIZANTE.codigoAFP = AFP.codigoAFP WHERE numeroCT = nroCT;

IF(estCZ = 'C')THEN
    INSERT INTO COTIZACION
    VALUES(nroCZ, nroCT, TO_DATE(SYSDATE), mes, agno, (remImp * 0.1), (remImp * (comCZ / 100)), TO_DATE(SYSDATE),'C');
ELSE
    INSERT INTO COTIZACION
    VALUES(nroCZ, nroCT, TO_DATE(SYSDATE), mes, agno, (remImp * 0.1), (remImp * (comCZ / 100)), NULL,'D');
END IF;

EXCEPTION
WHEN ERROR_COTIZANTE THEN DBMS_OUTPUT.PUT_LINE('Cotizante ingresado no existe');
WHEN ERROR_MES  THEN DBMS_OUTPUT.PUT_LINE('Mes ingresado incorrecto');
WHEN ERROR_AGNO THEN DBMS_OUTPUT.PUT_LINE('Año ingresado incorrecto');
WHEN ERROR_REMUNERACION THEN DBMS_OUTPUT.PUT_LINE('Remuneración imponible incorrecta');
WHEN ERROR_ESTADO THEN DBMS_OUTPUT.PUT_LINE('Estado de la cotización incorrecto');
END;


--  2.  (15 puntos)
--      Implementar un procedimiento almacenado, denominado actualizarAhorro, que, para las cotizaciones que fueron
--      registradas como canceladas en la fecha en curso, actualice el ahorro obligatorio del cotizante respectivo.
--      Inlcuir el bloque anónimo que llame al procedimiento     

CREATE OR REPLACE PROCEDURE actualizarAhorro
AS
nroCT   COTIZACION.numeroCT%TYPE;
monCZ   COTIZACION.montoCZ%TYPE;

CURSOR cotizacionesHoy IS SELECT numeroCT, montoCZ FROM COTIZACION WHERE estadoCZ = 'C' AND fechaRegCZ = TO_DATE(SYSDATE);

BEGIN
OPEN cotizacionesHoy;
FETCH cotizacionesHoy INTO nroCT, monCZ;
IF(cotizacionesHoy%ROWCOUNT > 0)THEN
    WHILE(cotizacionesHoy%FOUND)LOOP
        UPDATE COTIZANTE SET ahorroObligCT = ahorroObligCT + monCZ WHERE numeroCT = nroCT;
        FETCH cotizacionesHoy INTO nroCT, monCZ;
    END LOOP;
END IF;
CLOSE cotizacionesHoy;
END;

--  BLOQUE ANONIMO

BEGIN
actualizarAhorro;
END;

