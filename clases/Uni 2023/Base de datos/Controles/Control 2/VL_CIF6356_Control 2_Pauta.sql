--  CONTROL 2 (31.10)
--  NOMBRE ESTUDIANTE:

--  1. (10 puntos) Implementar cada una de las tablas. Lee cuidadosamente los comentarios que figuran en el modelo.
CREATE TABLE SORTEO
(codigoTJ       NUMBER(3,0)     NOT NULL,
 numeroST       NUMBER(4,0)     NOT NULL,
 fechaST        DATE            NOT NULL,
 pozoST         NUMBER(10,0)    NOT NULL,
 fechaVencST    DATE            NOT NULL
);
 
CREATE TABLE APUESTA
(codigoAP       NUMBER(10,0)    NOT NULL,
 fechaAP        DATE            NOT NULL,
 codigoTJ       NUMBER(3,0)     NOT NULL,   
 numeroST       NUMBER(4,0)     NOT NULL,
 ganadorAP      NUMBER(1,0)     NULL,
 montoPremioAP  NUMBER(10,0)    NULL,
 cobradoAP      NUMBER(1,0)     NULL,
 fechaCobroAP   DATE            NULL,
 codigoAG       NUMBER(8,0)     NOT NULL,
 comisionAG     NUMBER(8,0)     NOT NULL
);

CREATE TABLE AGENCIA
(codigoAG       NUMBER(8,0)     NOT NULL,
 nombreAG       VARCHAR2(50)    NOT NULL,
 codigoCM       NUMBER(5,0)     NOT NULL
);

--  2. (04 puntos) Establece la integridad de entidad

ALTER TABLE SORTEO
ADD CONSTRAINT PK_SORTEO PRIMARY KEY(codigoTJ, numeroST);

ALTER TABLE APUESTA
ADD CONSTRAINT PK_APUESTA PRIMARY KEY(codigoAP);

ALTER TABLE AGENCIA
ADD CONSTRAINT PK_AGENCIA PRIMARY KEY(codigoAG);

--  3. (03 puntos) Establece la integridad referencial

ALTER TABLE APUESTA
ADD CONSTRAINT FK_SORTEO_APUESTA FOREIGN KEY(codigoTJ, numeroST)
REFERENCES SORTEO(codigoTJ, numeroST);

ALTER TABLE APUESTA
ADD CONSTRAINT FK_AGENCIA_APUESTA FOREIGN KEY(codigoAG)
REFERENCES AGENCIA(codigoAG);

--  4. (6 puntos) Establece la integridad de dominio sólo para las siguientes columnas:

--  SORTEO.pozoST, considerando que no será inferior a $150.000.000 ni superior a $8.000.000.000

    ALTER TABLE SORTEO
    ADD CONSTRAINT CK_pozoST CHECK(pozoST BETWEEN 150000000 AND 8000000000);

--  APUESTA.ganadorAP

    ALTER TABLE APUESTA
    ADD CONSTRAINT CK_gabadorAP CHECK (ganadorAP IN (0,1));

--  APUESTA.comisionAG (valor por defecto)

    ALTER TABLE APUESTA
    MODIFY comisionAG DEFAULT 0;

--  5. (7 puntos) 

--  Inserta un sorteo que ya se haya efectuado pero aún no ha vencido

    INSERT INTO SORTEO VALUES(100, 2829, '29-10-2023', 4000000000, '28-12-2023');

--  Inserta un sorteo que aún no se ha efectuado

    INSERT INTO SORTEO VALUES(100, 2830, '01-11-2023', 2500000000, '31-12-2023');

--  Inserta una apuesta para el primer sorteo insertado

    INSERT INTO AGENCIA VALUES(00105272, 'AGENCIA 105', 05);

    INSERT INTO APUESTA VALUES(11111, '28-10-2023', 100, 2829, 1, 250000, 0, NULL, 00105272, 250000 * 0.02);  
    
--  Inserta una apuesta para el segundo sorteo insertado

    INSERT INTO APUESTA(codigoAP, fechaAP, codigoTJ, numeroST, codigoAG) 
    VALUES (33333, '30-10-2023', 100, 2830, 00105272);
--  o bien,
    INSERT INTO APUESTA VALUES(33333, '30-10-2023', 100, 2830, NULL, NULL, NULL, NULL, 00105272, 0);  

--  6. (05 puntos)
--  Agrega a la tabla SORTEO la columna ganadorMaxST. Dominio={SI, NO}

    ALTER TABLE SORTEO
    ADD ganadorMaxST CHAR(2) NULL;

--  Asumiendo que se ha efectuado el segundo sorteo insertado, actualiza la apuesta respectiva considerando que:
--  la apuesta resultó ganadora con un premio de $90.000 y fue cobrada 15 días después de efectuada

    UPDATE APUESTA SET ganadorAP = 1, montoPremioAP = 90000, cobradoAP = 1, fechaCobroAP='16-11-2023'
    WHERE codigoAP = 33333;

--  7. (05 puntos)
--  Mostrar las apuestas ganadoras efectuadas en un cierto rango de fechas cuyo premio es inferior a un cierto valor y
--  no han sido cobradas

    SELECT APUESTA.*
    FROM APUESTA
    WHERE ganadorAP = 1 AND fechaAP BETWEEN '&FECHA_INI' AND '&FECHA_FIN' AND montoPremioAP < &MONTO_PREMIO AND cobradoAP = 0;
