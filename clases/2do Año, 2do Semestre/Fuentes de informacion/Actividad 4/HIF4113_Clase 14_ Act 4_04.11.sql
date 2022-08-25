--  3.  Mostrar los datos de las infracciones cometidas, en un cierto rango fechas, por personas que 
--      se encontraban diagnosticadas y confirmadas de covid.

SELECT * 
FROM INFRACCION
WHERE fechaIN BETWEEN '&FECHA_INI' AND '&FECHA_FIN' AND covidDiag=0 AND covidNotif=0;


--  4.  Mostrar para las personas de la quinta regi�n la cantidad de infracciones cometidas. 
--      Los datos de inter�s son: rut, c�digo de la comuna de residencia y la cantidad solicitada.

SELECT PR.rutPR, codigoCMResid, COUNT(numeroIN) AS CantidadInfracciones
FROM (PERSONA PR LEFT JOIN INFRACCION I ON PR.rutPR=I.rutPR) JOIN COMUNA CM ON PR.codigoCMresid=CM.codigoCM
WHERE codigoRG=5
GROUP BY PR.rutPR, codigoCMResid;

--  TERMINA LAS CONSULTAS 5 Y 6.

--  5.  Mostrar para cada persona la cantidad de permisos emitidos.

SELECT PR.RutPR, fechaNacimPR, generoPR, codigoCMResid, codigoNC, COUNT(numeroPM)
FROM PERSONA PR LEFT JOIN PERMISO PM ON PR.rutPR=PM.rutPR
GROUP BY PR.RutPR, fechaNacimPR, generoPR, codigoCMResid, codigoNC;

--  Observaci�n: 
--  En este caso no se puede aplicar * para los datos de persona, ya que el GROUP BY no lo acepta
--  Ejecutar con LEFT JOIN y solo JOIN, analizar la diferencia en el resultado.

--  6.  Mostrar para cada persona el total de horas que contabilizan sus permisos.

SELECT PR.RutPR, fechaNacimPR, generoPR, codigoCMResid, codigoNC, SUM(duracionPM)
FROM PERSONA PR LEFT JOIN PERMISO PM ON PR.rutPR=PM.rutPR
GROUP BY PR.RutPR, fechaNacimPR, generoPR, codigoCMResid, codigoNC;

--  Observaci�n: 
--  Recordar que s�lo la funci�n de agregaci�n COUNT devuelce cero si su conteo no es exitoso (por ejemplo, la persona no registra permisos).
--  En cambio, las funciones SUM, MIN, MAX y AVG devuelven null bajo la situaci�n descrita.

--  7.  Mostrar las personas que registran m�s de tres permisos

SELECT PR.RutPR, fechaNacimPR, generoPR, codigoCMResid, codigoNC, COUNT(numeroPM)
FROM PERSONA PR LEFT JOIN PERMISO PM ON PR.rutPR=PM.rutPR
GROUP BY PR.RutPR, fechaNacimPR, generoPR, codigoCMResid, codigoNC
HAVING COUNT(numeroPM) > 3;

--  Observaci�n:
--  HAVING es rl equivalente al WHERE, la diferencia es que act�a sobre resultados de funciones de agregaci�n.
--  NO act�a sobre filas de datos de las tablas.
