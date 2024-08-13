--  CONTROL 4 (02.01)

--  Ejercicio 1 (05 puntos)
--  Crear la tabla ASIENTO de acuerdo con el modelo y establecer las claves correspondientes.

CREATE TABLE ASIENTO
(numeroSL     NUMBER(6,0)   NOT NULL,
 numeroAS     NUMBER(2,0)   NOT NULL,
 situacionAS  NUMBER(1,0)   NOT NULL,
 ubicacionAS  CHAR(1)       NOT NULL,
 estadoAS     CHAR(1)       NOT NULL,
 fechaResAS   DATE          NULL
);
 
ALTER TABLE ASIENTO
ADD CONSTRAINT PK_ASIENTO PRIMARY KEY(numeroSL,numeroAS);

ALTER TABLE ASIENTO
ADD CONSTRAINT FK_SALIDA_ASIENTO FOREIGN KEY(numeroSL) REFERENCES SALIDA(numeroSL);


--  Ejercicio 2 (20 puntos)
--  Implementar un procedimiento almacenado, denominado programarAsientos, que, para una salida en particular, 
--  genere un registro por cada asiento de la máquina respectiva.
--  Consideraciones:
--  • Sólo se permite la generación de los registros para las salidas que se encuentran programadas o confirmadas, 
--  siempre y cuando no se haya realizado previamente.
--  • Considerar para los asientos impares ventana y para los asientos pares pasillo.
--  • Implementar un bloque anónimo que llame al procedimiento sólo cuando la funcionalidad solicitada sea factible.
--  • Validar lo que corresponda
--  • Aplicar excepciones
--  • Analizar detenidamente el modelo antes de responder

CREATE OR REPLACE PROCEDURE programarAsientos(nroSL IN SALIDA.numeroSL%TYPE)
AS
cantAS  BUS.cantidadAsienBS%TYPE;
nroAS   ASIENTO.numeroAS%TYPE;
divis   NUMBER(2,0);
resto   NUMBER(1,0);
ubiAS   ASIENTO.ubicacionAS%TYPE;
BEGIN
SELECT cantidadAsienBS INTO cantAS 
FROM SALIDA JOIN BUS ON SALIDA.numeroMaqBS = BUS.numeroMaqBS WHERE numeroSL = nroSL;

nroAS := 1;
WHILE(nroAS <= cantAS)LOOP
  divis := nroAS / 2;
  resto := nroAS - divis * 2;
  IF(resto <> 0)THEN
    ubiAS := 'V';
  ELSE
    ubiAS := 'P';
  END IF;           

  INSERT INTO ASIENTO VALUES(nroSL, nroAS, 1, ubiAS, 'D', NULL);
  
  nroAS := nroAS + 1;
END LOOP;
END;

--  BLOQUE ANÓNIMO

SET SERVEROUTPUT ON

DECLARE
nroSL   SALIDA.numeroSL%TYPE;
existe  NUMBER(1,0);
estSL   SALIDA.estadoSL%TYPE;
cantAS  ASIENTO.numeroAS%TYPE;

ERROR_SALIDA    EXCEPTION;
ERROR_ESTADO    EXCEPTION;
ERROR_PROGRAM   EXCEPTION;
BEGIN
nroSL := &NUMERO_SALIDA;
SELECT COUNT(numeroSL) INTO existe FROM SALIDA WHERE numeroSL = nroSL;

IF(existe = 0)THEN
    RAISE ERROR_SALIDA;
END IF;

SELECT estadoSL INTO estSL FROM SALIDA WHERE numeroSL = nroSL;  
IF(estSL NOT IN (1,2))THEN
  RAISE ERROR_ESTADO;
END IF;

SELECT COUNT(numeroSL) INTO cantAS  FROM ASIENTO WHERE numeroSL = nroSL;
IF(cantAS > 0)THEN
  RAISE ERROR_PROGRAM;
END IF;

programarAsientos(nroSL);

EXCEPTION
WHEN ERROR_SALIDA THEN DBMS_OUTPUT.PUT_LINE('Salida no encontrada');
WHEN ERROR_ESTADO THEN DBMS_OUTPUT.PUT_LINE('Estado de la salida no permite programar los asientos');
WHEN ERROR_PROGRAM THEN DBMS_OUTPUT.PUT_LINE('Los asientos ya se encuentran programados para la salida ingresada'); 
END;

--  EJERCICIO 3 (10 PUNTOS)

--  Implementar un bloque anónimo que muestre, para el día en curso:
--  • para las salidas confirmadas, la cantidad de asientos por estado
--  • para las salidas cerradas, el porcentaje con máquina completa

SET SERVEROUTPUT ON

DECLARE
nroSL       SALIDA.numeroSL%TYPE;
estSL       SALIDA.estadoSL%TYPE;
cantD       ASIENTO.numeroAS%TYPE;
cantR       ASIENTO.numeroAS%TYPE;
cantA       ASIENTO.numeroAS%TYPE;
cantCerr    ASIENTO.numeroAS%TYPE := 0;
cantComp    NUMBER(3,0) := 0;

CURSOR salidasEstado  IS SELECT numeroSL, estadoSL FROM SALIDA WHERE fechaSL = TO_DATE(SYSDATE) AND estadoSL IN (2,3);

BEGIN
OPEN salidasEstado;
FETCH salidasEstado INTO nroSL, estSL;
IF(salidasEstado%ROWCOUNT > 0)THEN
    WHILE(salidasEstado%FOUND)LOOP
        IF(estSL = 2)THEN
            DBMS_OUTPUT.PUT_LINE('Salida Nro: '||nroSL);
            SELECT COUNT(numeroSL) INTO cantD FROM ASIENTO WHERE numeroSL = nroSL AND estadoAS = 'D';
            SELECT COUNT(numeroSL) INTO cantR FROM ASIENTO WHERE numeroSL = nroSL AND estadoAS = 'R';
            DBMS_OUTPUT.PUT_LINE('Cantidad de asientos Disponibles: '||cantD);
            DBMS_OUTPUT.PUT_LINE('Cantidad de asientos Reservados: '||cantR);
        ELSE
            cantCerr := cantCerr + 1;
            SELECT COUNT(numeroSL) INTO cantR FROM ASIENTO WHERE numeroSL = nroSL AND estadoAS = 'R';
            SELECT MAX(numeroAS) INTO cantA FROM ASIENTO WHERE numeroSL = nroSL;
            
            IF(cantR = cantA)THEN
                cantComp := cantComp + 1;
            END IF;         
        END IF;
        FETCH salidasEstado INTO nroSL, estSL;
    END LOOP;
    IF(cantCerr > 0)THEN
        DBMS_OUTPUT.PUT_LINE('Porcentaje de salidas Cerradas con máquina completa: '||(cantComp / cantCerr * 100));
    ELSE
        DBMS_OUTPUT.PUT_LINE('Porcentaje de salidas Cerradas con máquina completa: 0% (no hubo salidas cerradas)');
    END IF;
ELSE
    DBMS_OUTPUT.PUT_LINE('No se ecnontraron salidas Confirmadas ni Cerradas para el dia en curso');
END IF;
CLOSE salidasEstado;
END;