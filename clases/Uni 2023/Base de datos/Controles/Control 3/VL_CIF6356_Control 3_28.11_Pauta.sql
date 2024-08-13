--  1. (12 puntos) 
--  Registrarse, por código, como cotizante.
--  Implementa un bloque anónimo que, para un/una cotizante en particular, permita ingresar una inversión 
--  válida, correspondiente al 100% del ahorro obligatorio.
--  El código de la inversión debe ser generado por el bloque en base a la última inversión registrada.
--  Aplica excepciones.
--  Ten presente que el usuario debe ingresar lo estrictamente necesario

INSERT INTO COTIZANTE VALUES(9999, '999999999', 'ESPINOZA', 'CEA', 'ROSA', '09-09-1999', 'F', 1034, 19000000, 0, 'I', 'SR', 5401);

SET SERVEROUTPUT ON

DECLARE 
rut     COTIZANTE.rutCT%TYPE;
existe  NUMBER(1,0);
nroCT   COTIZANTE.numeroCT%TYPE;
ahorro  COTIZANTE.ahorroObligCT%TYPE;
codIN   INVERSION.codigoIN%TYPE;
fondo   INVERSION.tipoFondoIN%TYPE;
ejec    INVERSION.ejecutorIN%TYPE;

ERROR_COTIZANTE EXCEPTION;
ERROR_TIPOFONDO EXCEPTION;
ERROR_EJECUTOR  EXCEPTION;

BEGIN
rut := '&RUT_COTIZANTE';
SELECT COUNT(rutCT) INTO existe FROM COTIZANTE WHERE rutCT= rut;

IF(existe = 0)THEN
    RAISE ERROR_COTIZANTE;
ELSE
    fondo := '&TIPO_FONDO';
    IF(fondo NOT IN ('A','B','C','D','E'))THEN
        RAISE ERROR_TIPOFONDO;
    ELSE
        ejec := '&EJECUTOR';
        IF(ejec NOT IN ('AF','EJ','RA'))THEN
            RAISE ERROR_EJECUTOR;
        ELSE
            SELECT numeroCT, ahorroObligCT INTO nroCT, ahorro FROM COTIZANTE WHERE rutCT = rut;
            SELECT NVL(MAX(codigoIN),0) + 1 INTO codIN FROM INVERSION;
            
            INSERT INTO INVERSION VALUES(codIN, 1, nroCT, TO_DATE(SYSDATE), fondo, 100, ahorro, ejec, 1);
        END IF;
    END IF;
END IF;
EXCEPTION
WHEN ERROR_COTIZANTE THEN DBMS_OUTPUT.PUT_LINE('Cotizante no encontrado');
WHEN ERROR_TIPOFONDO THEN DBMS_OUTPUT.PUT_LINE('Tipo de fondo incorrecto');
WHEN ERROR_EJECUTOR THEN DBMS_OUTPUT.PUT_LINE('Ejecutor incorrecto');
END;