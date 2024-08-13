--  1. (03 puntos) A la tabla CREDITO agregar la columna saldoCred, la cual contendrá el monto del crédito 
--  que aún no ha sido cancelado, en base al comportamiento de pago de las cuotas respectivas.

ALTER TABLE CREDITO ADD saldoCred NUMBER(9,0) NULL;

--  2. (15 puntos) Implementar un bloque anónimo que, para cada crédito vigente:
--  • Informe la cantidad de cuotas vigentes (las que aún no han vencido)
--  • Informe la cantidad de cuotas canceladas
--  • Informe el monto total adeudado por concepto de cuotas en mora (las que vencieron y no han sido canceladas)
--  • Actualice la columna saldoCred

SET SERVEROUTPUT ON

DECLARE
nroCR       CREDITO.numeroCred%TYPE;
monCR       CREDITO.montoCredito%TYPE;
cantVig     CREDITO_CUOTAS.numeroCuota%TYPE;
cantCanc    CREDITO_CUOTAS.numeroCuota%TYPE;
totCanc     CREDITO.montoCredito%TYPE;
totMora     CREDITO.montoCredito%TYPE;

CURSOR creditosVig  IS SELECT numeroCred, montoCredito FROM CREDITO WHERE estado = 1;
BEGIN
OPEN creditosVig;
FETCH creditosVig INTO nroCR, monCR;
IF(creditosVig%ROWCOUNT > 0)THEN
    WHILE(creditosVig%FOUND)LOOP
        SELECT COUNT(numeroCuota) INTO cantVig FROM CREDITO_CUOTAS WHERE estadoCuota = 'V' AND numeroCred = nroCR;
        
        SELECT COUNT(numeroCuota), NVL(SUM(montoCuota),0) INTO cantCanc, totCanc FROM CREDITO_CUOTAS 
        WHERE estadoCuota = 'C' AND numeroCred = nroCR;
        
        SELECT NVL(SUM(montoCuota),0) INTO totMora FROM CREDITO_CUOTAS WHERE estadoCuota = 'M' AND numeroCred = nroCR;
        
        DBMS_OUTPUT.PUT_LINE('Información crédito Nro. '||nroCR);
        DBMS_OUTPUT.PUT_LINE('Cuotas vigentes (V): '||cantVig);
        DBMS_OUTPUT.PUT_LINE('Cuotas canceladas (C): '||cantCanc);
        DBMS_OUTPUT.PUT_LINE('Deuda cuotas morosas (M): '||totMora);

        UPDATE CREDITO SET saldoCred = monCR - totCanc WHERE numeroCred = nroCR;
        
        FETCH creditosVig INTO nroCR, monCR;
    END LOOP;
ELSE
    DBMS_OUTPUT.PUT_LINE('No se encontraron crédito vigentes');
END IF;
CLOSE creditosVig;
END;



--  3. (15 puntos) Implementar un procedimiento almacenado, denominado revisionCreditos, que:
--  Para los créditos a los que sólo les falta el pago de la última cuota y esta se encuentra vigente, las
--  condone; es decir, efectúe el pago automático de estas (esto es un premio para los buenos clientes).
--  Analice, además, qué consecuencias tiene esta acción sobre cada crédito. Luego, impleméntelas.
--  Finalmente, basándose en el procesamiento anterior, el procedimiento deberá devolver a quien 
--  lo llamó, la cantidad de cuotas condonadas y el monto total respectivo.

CREATE OR REPLACE PROCEDURE revisionCreditos(cantCond OUT NUMBER, montCond OUT NUMBER)
AS
nroCR       CREDITO.numeroCred%TYPE;
cantCuoCR   CREDITO.cantidadCuotas%TYPE;
minVig      CREDITO_CUOTAS.numeroCuota%TYPE;
montVig     CREDITO_CUOTAS.montoCuota%TYPE;
cantMora    CREDITO_CUOTAS.numeroCuota%TYPE;

CURSOR creditosVig  IS SELECT numeroCred, cantidadCuotas FROM CREDITO WHERE estado = 1;

BEGIN
cantCond := 0;
montCond := 0;
OPEN creditosVig;
FETCH creditosVig INTO nroCR, cantCuoCR;
IF(creditosVig%ROWCOUNT > 0)THEN
    WHILE(creditosVig%FOUND)LOOP
        SELECT NVL(MIN(numeroCuota),0), NVL(montoCuota,0) INTO minVig, montVig
        FROM CREDITO_CUOTAS WHERE estadoCuota = 'V' AND numeroCred = nroCR
        GROUP BY NVL(montoCuota,0);
        
        SELECT COUNT(numeroCuota) INTO cantMora FROM CREDITO_CUOTAS WHERE estadoCuota = 'M' AND numeroCred = nroCR;
        
        IF(minVig = cantCuoCR AND cantMora = 0)THEN
            UPDATE CREDITO_CUOTAS SET fechaPago = TO_DATE(SYSDATE), estadoCuota = 'C' 
            WHERE numeroCred = nroCR AND numeroCuota = minVig;
            
            UPDATE CREDITO SET estado = 2 WHERE numeroCred = nroCR;   -- Cancelando la última cuota, queda cancelado el crédito
            
            cantCond := cantCond + 1;
            montCond := montCond + montVig;
        END IF;
        
        FETCH creditosVig INTO nroCR, cantCuoCR;
    END LOOP;
END IF;
CLOSE creditosVig;
END;


SET SERVEROUTPUT ON

DECLARE
cantCond    NUMBER(7,0);
montCond    NUMBER(7,0);
BEGIN
revisionCreditos(cantCond, montCond);

DBMS_OUTPUT.PUT_LINE('Cantidad de cuotas condonadas: '||cantCond);
DBMS_OUTPUT.PUT_LINE('Monto total condonado: $'||montCond);
END;





