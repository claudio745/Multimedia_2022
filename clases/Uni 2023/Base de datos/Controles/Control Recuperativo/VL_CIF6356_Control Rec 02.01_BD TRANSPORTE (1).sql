--  CONTROL RECUPERATIVO (02.01)

-- TABLAS

CREATE TABLE BUS
(numeroMaqBS        NUMBER(3,0) NOT NULL,
 patenteBS          CHAR(6)     NOT NULL,
 agnoFabricBS       NUMBER(4,0) NOT NULL,
 cantidadAsienBS    NUMBER(2,0) NOT NULL,
 cantidadPisosBS    NUMBER(1,0) NOT NULL,
 tipoMaqBS          CHAR(1)     NOT NULL,
 estadoBS           NUMBER(1,0) NOT NULL
);


CREATE TABLE SALIDA
(numeroSL       NUMBER(6,0) NOT NULL,
 numeroMaqBS    NUMBER(3,0) NOT NULL,
 fechaSL        DATE        NOT NULL,
 horaSL         CHAR(5)     NOT NULL,
 codigoCondSL   NUMBER(5,0) NULL,
 andenSL        NUMBER(2,0) NULL,
 estadoSL       NUMBER(1,0) NOT NULL
);





