--  PRUEBA INTEGRAL 3 (26.12)
--  BASE DE DATOS: FINANZAS

--  1.	(04 puntos)	Antes de desarrollar la evaluación crea la tabla CREDITO_CUOTAS y, a continuación, 
--      establece la integridad de entidad y referencial.

--  Integridad de entidad
ALTER TABLE CREDITO_CUOTAS ADD CONSTRAINT PK_CREDITO_CUOTAS PRIMARY KEY(numeroCred, numeroCuota);

ALTER TABLE CREDITO_CUOTAS ADD CONSTRAINT FK_CREDITO_CREDITO_CUOTAS FOREIGN KEY (numeroCred) 
REFERENCES CREDITO(numeroCred);


--  2.	(21 puntos)	Implementar un procedimiento almacenado, denominado cancelarCuota, que permita registrar 
--      el pago de una determinada cuota de un crédito en particular.

--      Consideraciones:
--      •	Analizar detenidamente el modelo antes de responder.
--      •	El pago de una cuota debe comprender la totalidad del monto respectivo; en caso contrario, no se acepta el pago.
--      •	Las situaciones que se pueden presentar al momento de cancelar una cuota son:
--          -	Pago de cuota correspondiente al periodo normal de pago, es decir, sin cuotas atrasadas.
--          -	Pago de cuota adelantada; esto implica que la cuota actual debe figurar cancelada.
--          -	Pago de cuota atrasada. Si hay tres o menos cuotas atrasadas, se cancela la más atrasada; 
--              en caso contrario, no se acepta el pago.
--      •	El manejo de las situaciones descritas en el punto anterior efectuarlo en un bloque anónimo. 
--          Sólo cuando un pago sea aceptable, llamar al procedimiento.
--      •	Si el pago aceptado correspondiera a la cancelación de la última cuota del crédito, este se deberá dar por 
--          cancelado en el mismo procedimiento.
--      •	Validar lo que corresponda.
--      •	Aplicar excepciones.

CREATE OR REPLACE PROCEDURE cancelarCuota(nroCred IN CREDITO_CUOTAS.numeroCred%TYPE, nroCuo IN CREDITO_CUOTAS.numeroCuota%TYPE)
AS
cantCuotas  CREDITO.cantidadCuotas%TYPE;
BEGIN
UPDATE CREDITO_CUOTAS SET fechaPago = TO_DATE(SYSDATE), estadoCuota = 'C' WHERE numeroCred = nroCred AND numeroCuota = nroCuo;

SELECT cantidadCuotas INTO cantCuotas FROM CREDITO WHERE numeroCred = nroCred;

IF(nroCuo = cantCuotas)THEN
    UPDATE CREDITO SET estado = 2 WHERE numeroCred = nroCred;
END IF;
END;

--  BLOQUE ANÓNIMO

SET SERVEROUTPUT ON

DECLARE
nroCred     CREDITO.numeroCred%TYPE;
nroCuo      CREDITO_CUOTAS.numeroCuota%TYPE;
existe      NUMBER(1,0);
estCred     CREDITO.estado%TYPE;
nroMinVig   CREDITO_CUOTAS.numeroCuota%TYPE;
nroMinMora  CREDITO_CUOTAS.numeroCuota%TYPE;
filaCuoPag  CREDITO_CUOTAS%ROWTYPE;
filaCuoAct  CREDITO_CUOTAS%ROWTYPE;
cantVig     NUMBER(1,0);
cantMora    NUMBER(1,0);
montoPag    CREDITO_CUOTAS.montoCuota%TYPE;

ERROR_CREDITO   EXCEPTION;
ERROR_ESTADO    EXCEPTION;
ERROR_CUOTA     EXCEPTION;
CUOTA_CANCELADA EXCEPTION;
ERROR_MONTO     EXCEPTION;
ERROR_MORA      EXCEPTION;
ERROR_PAGO_MORA EXCEPTION;

BEGIN
--  Validación del crédito. Verificación de estado
nroCred := &NUMERO_CREDITO;
SELECT COUNT(numeroCred) INTO existe FROM CREDITO WHERE numeroCred = nroCred;
IF(existe = 0)THEN
    RAISE ERROR_CREDITO;
END IF;

SELECT estado INTO estCred FROM CREDITO WHERE numeroCred = nroCred;
IF(estCred NOT IN (1,3))THEN
    RAISE ERROR_ESTADO;
END IF;

--  Validación de la cuota a cancelar. Verificación de estado
nroCuo := &NUMERO_CUOTA_A_CANCELAR;
SELECT COUNT(numeroCuota) INTO existe FROM CREDITO_CUOTAS WHERE numeroCred = nroCred AND numeroCuota = nroCuo;
IF(existe = 0)THEN
    RAISE ERROR_CUOTA;
END IF;

SELECT * INTO filaCuoPag FROM CREDITO_CUOTAS WHERE numeroCred = nroCred AND numeroCuota = nroCuo;
IF(filaCuoPag.estadoCuota = 'C')THEN
    RAISE CUOTA_CANCELADA;
END IF;

--  Validación del monto a cancelar
montoPag := &MONTO_PAGO;
IF(montoPag <> filaCuoPag.montoCuota)THEN
    RAISE ERROR_MONTO;
END IF;

SELECT MIN(numeroCuota) INTO nroMinVig FROM CREDITO_CUOTAS WHERE estadoCuota = 'V' AND numeroCred =nroCred;
SELECT COUNT(numeroCuota) INTO existe FROM CREDITO_CUOTAS WHERE estadoCuota = 'M' AND numeroCred =nroCred;
    
IF(existe > 3)THEN
    RAISE ERROR_MORA;
ELSE
    SELECT MIN(numeroCuota) INTO nroMinMora FROM CREDITO_CUOTAS WHERE estadoCuota = 'M' AND numeroCred =nroCred;
    IF(nroMinMora <> filaCuoPag.numeroCuota)THEN
        RAISE ERROR_PAGO_MORA;
    END IF;
END IF;

cancelarCuota(nroCred, nroCuo);

EXCEPTION
WHEN ERROR_CREDITO THEN DBMS_OUTPUT.PUT_LINE('Crédito no existe');
WHEN ERROR_ESTADO THEN DBMS_OUTPUT.PUT_LINE('Estado del crédito no permite pagos');
WHEN ERROR_CUOTA THEN DBMS_OUTPUT.PUT_LINE('Cuota no existe');
WHEN CUOTA_CANCELADA THEN DBMS_OUTPUT.PUT_LINE('Cuota se encuentra cancelada, no procede el pago');
WHEN ERROR_MONTO THEN DBMS_OUTPUT.PUT_LINE('Monto del pago incorrecto');
WHEN ERROR_MORA THEN DBMS_OUTPUT.PUT_LINE('No se permite pago, posee más de tres cuotas en Mora');
WHEN ERROR_PAGO_MORA THEN DBMS_OUTPUT.PUT_LINE('Debe cancelar la cuota en mora más atrasada');
END;


--  3. (15 puntos) Implementar un bloque anónimo que, para cada crédito vigente, informe:
--      • Número, monto y fecha del primer vencimiento del crédito
--      • Número de cuota, monto, fecha de vencimiento y fecha de pago de la última cuota cancelada
--      • Porcentaje de cuotas canceladas y por cancelar

SET SERVEROUTPUT ON
DECLARE
nroCR     CREDITO.numeroCred%TYPE;
monCR     CREDITO.montoCredito%TYPE;
fecCR     DATE;
cantCuo   CREDITO.cantidadCuotas%TYPE;
cantCan   CREDITO.cantidadCuotas%TYPE;
cantNoCan CREDITO.cantidadCuotas%TYPE;
nroCT     CREDITO_CUOTAS.numeroCuota%TYPE;
monCT     CREDITO_CUOTAS.montoCuota%TYPE;
vencCT    DATE;
pagCT     DATE;
porcCan   NUMBER(3,0) := 0;
porcNoCan NUMBER(3,0) := 0;

CURSOR creditosVig  IS SELECT numeroCred, cantidadCuotas, montoCredito, fechaPrimerVencim FROM CREDITO WHERE estado = 1;

BEGIN
OPEN creditosVig;
FETCH creditosVig INTO nroCR, cantCuo, monCR, fecCR;
IF(creditosVig%ROWCOUNT > 0)THEN
    WHILE(creditosVig%FOUND)LOOP
        DBMS_OUTPUT.PUT_LINE('Credito: '||nroCR||' - $'||monCR||' - Vencimiento 1ra cuota: '||fecCR);
        
        SELECT COUNT(numeroCuota) INTO cantCan FROM CREDITO_CUOTAS WHERE numeroCred = nroCR AND estadoCuota = 'C';
  
        IF(cantCan > 0)THEN
            SELECT numeroCuota, montoCuota, fechaVenc, fechaPago INTO nroCT, monCT, vencCT, pagCT
            FROM CREDITO_CUOTAS 
            WHERE numeroCuota = (SELECT NVL(MAX(numeroCuota),0) FROM CREDITO_CUOTAS WHERE numeroCred = nroCR AND estadoCuota = 'C');
            
            DBMS_OUTPUT.PUT_LINE('Cuota: '||nroCT||' - $'||monCT||' | Vencimiento: '||vencCT||' - Pago: '||pagCT);
        ELSE
            DBMS_OUTPUT.PUT_LINE('No se encontró información de una última cuota cancelada');
        END IF; 
        
        porcCan := cantCan / cantCuo * 100;
        porcNoCan := (cantCuo - cantCan) / cantCuo * 100;
        
        DBMS_OUTPUT.PUT_LINE('Cuotas canceladas: '||porcCan||'%');
        DBMS_OUTPUT.PUT_LINE('Cuotas por cancelar: '||porcNoCan||'%');
        
        FETCH creditosVig INTO nroCR, cantCuo, monCR, fecCR;
    END LOOP;
ELSE
    DBMS_OUTPUT.PUT_LINE('No se encontraron créditos Vigentes');
END IF;
END;













