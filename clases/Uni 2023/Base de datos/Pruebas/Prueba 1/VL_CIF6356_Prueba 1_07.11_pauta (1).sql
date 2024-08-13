--  1.	(02 puntos)	Agregar a la tabla PARTIDO la columna estadoPT. 
--      Dominio= {P (Programado), J (Jugado), S (Suspendido)}

ALTER TABLE PARTIDO
ADD estadoPT CHAR(1) NULL;

--  2.	(03 puntos)	
--  •	Programar un partido en el que se vaya a jugar de local, en cinco días más. Para estadio y club considera los valores 12 y 02, respectivamente

INSERT INTO PARTIDO VALUES(7777, TO_DATE(SYSDATE) + 5, 12, 02, 'L', NULL, 'P');

--  •	Ingresar una fila en la tabla EQUIPO para el partido que se acaba de programar

INSERT INTO EQUIPO VALUES(7777, 22222, 0, 0, 0, 0);

--  3.	(04 puntos)	Para cada jugador, mostrar la cantidad total de minutos jugados a la fecha.
--      Los datos de interés del jugador son: nombre completo, fecha de nacimiento, altura y posición.

SELECT nombresFB, apellido1FB, apellido2FB, fechaNacFB, alturaFB, posicionFB, NVL(SUM(minutosJug),0) AS Total_Minutos
FROM PLANTEL LEFT JOIN EQUIPO ON PLANTEL.codigoFB=EQUIPO.codigoFB
GROUP BY nombresFB, apellido1FB, apellido2FB, fechaNacFB, alturaFB, posicionFB;

--  4.	(04 puntos)	Para los delanteros, mostrar la cantidad de goles y tarjetas amarillas. 
--      Los datos de interés son: código del jugador, edad y las cantidades solicitadas.

SELECT PLANTEL.codigoFB, EXTRACT(YEAR FROM SYSDATE)-EXTRACT(YEAR FROM fechaNacFB) AS Edad, 
       NVL(SUM(cantidadGol),0) AS Cantidad_Goles, NVL(SUM(cantidadTarjAmar),0) AS Cantidad_Amarillas
FROM PLANTEL LEFT JOIN EQUIPO ON PLANTEL.codigoFB=EQUIPO.codigoFB
WHERE posicionFB = 'DL'
GROUP BY PLANTEL.codigoFB, EXTRACT(YEAR FROM SYSDATE)-EXTRACT(YEAR FROM fechaNacFB);

--  5.	(03 puntos)	Para un partido en particular, que se haya jugado de visita, mostrar los datos del equipo convocado.

SELECT EQUIPO.*
FROM PARTIDO JOIN EQUIPO ON PARTIDO.codigoPT=EQUIPO.codigoPT
WHERE PARTIDO.codigoPT = &CODIGO_PARTIDO AND estadoPT = 'J' AND situacionPT = 'V';

--  6.	(04 puntos)	Para los partidos jugados en un cierto rango de fechas, mostrar la fecha, la duración y 
--      la cantidad de jugadores de los equipos respectivos

SELECT fechaPT, NVL(duracionPT,0) AS Duracion, COUNT(EQUIPO.codigoPT) AS Cantidad_Jugadores
FROM PARTIDO JOIN EQUIPO ON PARTIDO.codigoPT=EQUIPO.codigoPT
WHERE estadoPT = 'J' AND fechaPT BETWEEN '&FECHA_INICIAL' AND '&FECHA_FINAL'
GROUP BY fechaPT, NVL(duracionPT,0);

--  7.	(2.5 puntos)	Mostrar la cantidad de jugadores por posición

SELECT posicionFB, COUNT(codigoFB) AS Cantidad_jugadores
FROM PLANTEL
GROUP BY posicionFB;

--  8.	(2.5 puntos)	Para los partidos que no registran minutos jugados, mostrar la fecha, estadio y situación

SELECT fechaPT, codigoES, situacionPT
FROM PARTIDO
WHERE duracionPT IS NULL;

--  9.	(3 puntos)	Para los partidos jugados de visita en un mes en particular, mostrar el promedio de goles

SELECT AVG(cantidadGol) AS Promedio_Goles
FROM PARTIDO JOIN EQUIPO ON PARTIDO.codigoPT=EQUIPO.codigoPT
WHERE estadoPT = 'J' AND situacionPT = 'V' AND EXTRACT(MONTH FROM fechaPT) = &MES




