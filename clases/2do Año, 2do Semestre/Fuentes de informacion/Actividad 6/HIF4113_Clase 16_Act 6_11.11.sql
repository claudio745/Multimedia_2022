--  7.  Mostrar las personas que registran más de tres permisos

SELECT PR.rutPR, fechaNacimPR, generoPR, codigoCMResid, codigoNC
FROM PERSONA PR JOIN PERMISO PM ON PR.rutPR=PM.rutPR
GROUP BY PR.rutPR, fechaNacimPR, generoPR, codigoCMResid, codigoNC
HAVING COUNT(numeroPM) > 3;

--  ACTIVIDAD 6
--  1.  Mostrar las personas que registran menos de cinco permisos en un mes determinado correspondiente al presente año.

SELECT PR.rutPR, fechaNacimPR, generoPR, codigoCMResid, codigoNC
FROM PERSONA PR JOIN PERMISO PM ON PR.rutPR=PM.rutPR
WHERE EXTRACT(MONTH FROM fechaSolicPM)=&MES AND EXTRACT(YEAR FROM fechaSolicPM)=EXTRACT(YEAR FROM SYSDATE)
GROUP BY PR.rutPR, fechaNacimPR, generoPR, codigoCMResid, codigoNC
HAVING COUNT(numeroPM) < 5;

--  2.	Mostrar el rut y género de las personas que superan las tres infracciones durante el año pasado.


--  3.	Mostrar las personas de género masculino cuya edad es superior al promedio general de edad.

SELECT rutPR, fechaNacimPR, generoPR, codigoCMResid, codigoNC
FROM PERSONA
WHERE generoPR='M' AND 
(EXTRACT(YEAR FROM SYSDATE)-EXTRACT(YEAR FROM fechaNacimPR)) < (SELECT AVG(EXTRACT(YEAR FROM SYSDATE)-EXTRACT(YEAR FROM fechaNacimPR)) FROM PERSONA);


--  4.	Mostrar para una persona en particular los datos correspondientes a su infracción más reciente.
