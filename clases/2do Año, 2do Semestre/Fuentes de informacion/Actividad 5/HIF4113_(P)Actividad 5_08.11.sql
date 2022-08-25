--  ACTIVIDAD 5

--  1.  Mostrar por cada comuna, la cantidad de personas entre los 18 y 35 años del género indicado por el usuario. 
--      Los datos de interés son: nombre y etapa de la comuna, y la cantidad solicitada.

SELECT nombreCM, etapaCM, COUNT(rutPR) AS CantidadPersonas
FROM COMUNA CM LEFT JOIN PERSONA PR ON CM.codigoCM=PR.codigoCMResid
WHERE (EXTRACT(YEAR FROM SYSDATE) - EXTRACT(YEAR FROM fechaNacimPR) BETWEEN 18 AND 35) AND generoPR='&GENERO'
GROUP BY nombreCM, etapaCM;

--  2.  Mostrar para todas las personas que residen en una determinada comuna, la fecha de su infracción más reciente.

SELECT PR.rutPR, fechaNacimPR, generoPR, codigoNC, MAX(fechaIN)
FROM PERSONA PR LEFT JOIN INFRACCION IFR ON PR.rutPR=IFR.rutPR
WHERE codigoCMResid=&COMUNA
GROUP BY PR.rutPR, fechaNacimPR, generoPR, codigoNC;

--  3.  Mostrar para cada comuna la cantidad de permisos generados para salir de ella en un rango de hora determinado.

SELECT codigoCM, nombreCM, etapaCM, codigoRG, COUNT(numeroPM)
FROM COMUNA CM LEFT JOIN PERMISO PM ON CM.codigoCM=PM.codigoCMOrig
WHERE codigoCMDest <> codigoCMOrig
GROUP BY codigoCM, nombreCM, etapaCM, codigoRG;

--  4.  Mostrar el rut, fecha de nacimiento y género de las personas que registran infracciones y no contaban con un permiso

SELECT DISTINCT PR.rutPR, fechaNacimPR, generoPR
FROM PERSONA PR JOIN INFRACCION INF ON PR.rutPR=INF.rutPR
WHERE numeroPM IS NULL;



