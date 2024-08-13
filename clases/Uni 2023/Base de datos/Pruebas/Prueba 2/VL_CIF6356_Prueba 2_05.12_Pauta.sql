--  1.	(15 puntos)	Implementar un bloque an�nimo que, para las empresas formadas hace m�s de cinco a�os, 
--                  genere una solicitud de cr�dito bajo las siguientes condiciones:

--  �	La empresa no debe figurar con una solicitud a�n sin resolver ni con un cr�dito vigente.
--  �	Si la empresa no ha solicitado cr�ditos en el presente a�o, la solicitud debe efectuarse por un capital de $5.000.000, 
--      sin seguros, a una tasa del 1.2%, con un plazo de 1 a�o y con fecha de primer vencimiento 35 d�as a contar de la fecha
--      de generaci�n de la solicitud.
--  �	Para generar el n�mero del cr�dito debe basarse en el n�mero del �ltimo cr�dito registrado en la tabla respectiva, 
--      el cual debe ser obtenido. 
--  �	Por cada empresa considerada en este proceso, debe mostrar el rut, nombre y fecha de creaci�n, as� como el monto del
--      cr�dito y la fecha del primer vencimiento.
--      Aplique excepciones, si corresponde.

SET SERVEROUTPUT ON
DECLARE
rutCL           CLIENTE.rut%TYPE;
nomCL           CLIENTE.nombreRazonSocial%TYPE;
fecCL           DATE;
cantCredNo      NUMBER(1,0);
cantCredAgno    NUMBER(1,0);  
nroCR           CREDITO.numeroCred%TYPE;
montInt         CREDITO.montoInteres%TYPE;

CURSOR empresasMas5 IS SELECT rut, nombreRazonSocial, fechaNacForm
                       FROM CLIENTE
                       WHERE tipo = 'E' AND EXTRACT(YEAR FROM SYSDATE) - EXTRACT(YEAR FROM fechaNacForm) > 5;
BEGIN
OPEN empresasMas5;
FETCH empresasMas5 INTO rutCL, nomCL, fecCL;
IF(empresasMas5%ROWCOUNT > 0)THEN
    montInt:= 5000000 * 0.012;
    WHILE(empresasMas5%FOUND)LOOP
        SELECT COUNT(numeroCred) INTO cantCredNo FROM CREDITO WHERE rut = rutCL AND estado IN (0,1);
        SELECT COUNT(numeroCred) INTO cantCredAgno FROM CREDITO WHERE rut = rutCL AND EXTRACT(YEAR FROM fechaSolicitud) = EXTRACT(YEAR FROM SYSDATE);
        IF(cantCredNo = 0 AND cantCredAgno = 0)THEN
            SELECT NVL(MAX(numeroCred),0) + 1 INTO nroCR FROM CREDITO;    
            INSERT INTO CREDITO 
            VALUES(nroCR, rutCL, TO_DATE(SYSDATE), NULL, 5000000, 1.2, 12, TO_DATE(SYSDATE) + 35, 0, 0, montInt, 5000000 + montInt, 0);
        
            DBMS_OUTPUT.PUT_LINE('Empresa: '||rutCL||'  '||nomCL||' - '||fecCL);
            DBMS_OUTPUT.PUT_LINE('Cr�dito: $'||(5000000 + montInt)||' - Primer vencimiento: '||(TO_DATE(SYSDATE) + 35));
        
        END IF;
        FETCH empresasMas5 INTO rutCL, nomCL, fecCL;
    END LOOP;
ELSE
    DBMS_OUTPUT.PUT_LINE('No se encontraron empresas con m�s de 5 a�os de creaci�n');
END IF;
CLOSE empresasMas5;
END;


--  2.	(15 puntos)	Implementar un bloque an�nimo que genere, para el mes en curso, la informaci�n de la tabla ESTADISTICAS_MES.
--                  Tener presente que, si ya fue generado el registro para dicho mes, este s�lo deber� ser actualizado.
--                  Una vez finalizado el proceso anterior, deber� informar el porcentaje correspondiente a cada tipo de cliente
--                  y a cada situaci�n de cr�dito (solicitado y autorizado).

SET SERVEROUTPUT ON

DECLARE
filaMes ESTADISTICAS_MES%ROWTYPE;
existe  NUMBER(1,0);
porcN   NUMBER(4,1); 
porcE   NUMBER(4,1);
porcAut NUMBER(4,1);
BEGIN
--  C�lculo de valores
SELECT COUNT(rut) INTO filaMes.cantCliPerNat FROM CLIENTE WHERE tipo = 'N';

SELECT COUNT(rut) INTO filaMes.cantCliEmp FROM CLIENTE WHERE tipo = 'E';

SELECT COUNT(rut) INTO filaMes.cantCredSol FROM CREDITO 
WHERE EXTRACT(MONTH FROM fechaSolicitud) = EXTRACT(MONTH FROM SYSDATE) AND 
      EXTRACT(YEAR FROM fechaSolicitud) = EXTRACT(YEAR FROM SYSDATE);

SELECT COUNT(rut) INTO filaMes.cantCredAut FROM CREDITO 
WHERE fechaOtorgamiento IS NOT NULL AND -- O BIEN estado NOT IN (0,5)
      EXTRACT(MONTH FROM fechaOtorgamiento) = EXTRACT(MONTH FROM SYSDATE) AND 
      EXTRACT(YEAR FROM fechaOtorgamiento) = EXTRACT(YEAR FROM SYSDATE);
      
SELECT NVL(SUM(montoCredito),0) INTO filaMes.montoTotalCredAut FROM CREDITO 
WHERE fechaOtorgamiento IS NOT NULL AND -- O BIEN estado NOT IN (0,5)
      EXTRACT(MONTH FROM fechaOtorgamiento) = EXTRACT(MONTH FROM SYSDATE) AND 
      EXTRACT(YEAR FROM fechaOtorgamiento) = EXTRACT(YEAR FROM SYSDATE);

SELECT NVL(SUM(montoInteres),0) INTO filaMes.montoTotalIntAut FROM CREDITO 
WHERE fechaOtorgamiento IS NOT NULL AND -- O BIEN estado NOT IN (0,5)
      EXTRACT(MONTH FROM fechaOtorgamiento) = EXTRACT(MONTH FROM SYSDATE) AND 
      EXTRACT(YEAR FROM fechaOtorgamiento) = EXTRACT(YEAR FROM SYSDATE);     

--  Establecimiento de operaci�n a realizar

filaMes.mes := EXTRACT(MONTH FROM SYSDATE);

SELECT COUNT(mes) INTO existe FROM ESTADISTICAS_MES WHERE mes = filaMes.mes ;

IF(existe = 0)THEN  -- INSERT
    INSERT INTO ESTADISTICAS_MES 
    VALUES(filaMes.mes, filaMes.cantCliPerNat, filaMes.cantCliEmp, filaMes.cantCredSol, filaMes.cantCredAut, 
           filaMes.montoTotalCredAut, filaMes.montoTotalIntAut);
ELSE    -- UPDATE
    UPDATE ESTADISTICAS_MES SET cantCliPerNat = filaMes.cantCliPerNat, cantCliEmp = filaMes.cantCliEmp,
                                cantCredSol = filaMes.cantCredSol, cantCredAut = filaMes.cantCredAut,
                                montoTotalCredAut = filaMes.montoTotalCredAut, montoTotalIntAut = filaMes.montoTotalIntAut
    WHERE mes = filaMes.mes;
END IF;

porcN := filaMes.cantCliPerNat / (filaMes.cantCliPerNat + filaMes.cantCliEmp) * 100;
porcE := filaMes.cantCliEmp / (filaMes.cantCliPerNat + filaMes.cantCliEmp) * 100;

porcAut := 0;
IF(filaMes.cantCredSol <> 0)THEN
    porcAut := filaMes.cantCredAut / filaMes.cantCredSol * 100;
END IF;

DBMS_OUTPUT.PUT_LINE('Clientes Persona Natural: '||porcN||'%');
DBMS_OUTPUT.PUT_LINE('Clientes Empresa: '||porcE||'%');
DBMS_OUTPUT.PUT_LINE('De la totalidad de los cr�ditos solicitados un '||porcAut||'% fue autorizado');
END;


