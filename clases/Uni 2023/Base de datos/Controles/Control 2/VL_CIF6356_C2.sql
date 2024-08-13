--  CONTROL 2 (31.10)
--  NOMBRE ESTUDIANTE:

--  1. (10 puntos) Implementar cada una de las tablas. Lee cuidadosamente los comentarios que figuran en el modelo.




--  2. (04 puntos) Establece la integridad de entidad



--  3. (03 puntos) Establece la integridad referencial



--  4. (6 puntos) Establece la integridad de dominio sólo para las siguientes columnas:

--  SORTEO.pozoST, considerando que no será inferior a $150.000.000 ni superior a $8.000.000.000


--  APUESTA.ganadorAP


--  APUESTA.comisionAG (valor por defecto)


--  5. (7 puntos) 

--  Inserta un sorteo que ya se haya efectuado pero aún no ha vencido


--  Inserta un sorteo que aún no se ha efectuado


--  Inserta una apuesta para el primer sorteo insertado


--  Inserta una apuesta para el segundo sorteo insertado


--  6. (05 puntos)
--  Agrega a la tabla SORTEO la columna ganadorMaxST. Dominio={SI, NO}


--  Asumiendo que se ha efectuado el segundo sorteo insertado, actualiza la apuesta respectiva considerando que:
--  la apuesta resultó ganadora con un premio de $90.000 y fue cobrada 15 días después de efectuada



--  7. (05 puntos)
--  Mostrar las apuestas ganadoras efectuadas en un cierto rango de fechas cuyo premio es inferior a un cierto valor y
--  no han sido cobradas
