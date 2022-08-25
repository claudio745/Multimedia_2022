-- 1. Mostrar la cantidad de comunas que inician con V y se encuentran en el paso 1.

SELECT * FROM COMUNA WHERE ETAPACM='PASO 1' AND NOMBRECM LIKE 'V%';

SELECT COUNT(ETAPACM) FROM COMUNA WHERE ETAPACM='PASO 1' AND NOMBRECM LIKE 'V%';


-- 2. Mostrar los datos de las infracciones cometidas en el mes de octubre 
--del presente año por  personas que se encontraban diagnosticadas y confirmadas con COVID.


SELECT * FROM INFRACCION WHERE (FECHAIN BETWEEN '01-10-2021' AND '31-10-2021') 
AND (COVIDDIAG LIKE '1%') AND (COVIDNOTIF LIKE '1%');


-- 3. Mostrar el número, fecha y hora de los permisos cuya 
--comuna de origen es distinta a la comuna de destino.

SELECT NUMEROPM, FECHASOLICPM, HORASOLICPM FROM permiso WHERE CODIGOCMORIG != CODIGOCMDEST;


-- 4. Mostrar la cantidad de adultos mayores de género femenino que residen en la quinta región.


SELECT * FROM PERSONA WHERE (GENEROPR='F') AND 
EXTRACT (YEAR FROM SYSDATE)- EXTRACT(YEAR FROM FECHANACIMPR) >= 65;


-- 5. Mostrar la cantidad de infracciones cometidas por personas 
--notificadas con COVID y que no registraban permiso.


SELECT COUNT(COVIDNOTIF) FROM INFRACCION WHERE COVIDNOTIF=1 AND PERMISOTEMP=0;


