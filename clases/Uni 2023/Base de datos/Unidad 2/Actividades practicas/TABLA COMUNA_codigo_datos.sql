--  TABLA COMUNA

CREATE TABLE COMUNA
(codigoCM NUMBER(5,0)   NOT NULL,
 nombreCM VARCHAR2(50)  NOT NULL,
 codigoRG NUMBER(2,0)   NOT NULL
);

--  INTEGRIDAD DE ENTIDAD

ALTER TABLE COMUNA
ADD CONSTRAINT PK_COMUNA PRIMARY KEY(codigoCM);

--  INTEGRIDAD REFERENCIAL

ALTER TABLE CLIENTE
ADD CONSTRAINT FK_COMUNA_CLIENTE FOREIGN KEY(codigoCM)
REFERENCES COMUNA(codigoCM);

--  DATOS

INSERT INTO COMUNA VALUES (5101,'VALPARAISO',5);
INSERT INTO COMUNA VALUES (5102,'CASABLANCA',5);
INSERT INTO COMUNA VALUES (5103,'CONCON',5);
INSERT INTO COMUNA VALUES (5104,'JUAN FERNANDEZ',5);
INSERT INTO COMUNA VALUES (5105,'PUCHUNCAVI',5);
INSERT INTO COMUNA VALUES (5107,'QUINTERO',5);
INSERT INTO COMUNA VALUES (5109,'VI�A DEL MAR',5);
INSERT INTO COMUNA VALUES (5201,'ISLA DE PASCUA',5);
INSERT INTO COMUNA VALUES (5301,'LOS ANDES',5);
INSERT INTO COMUNA VALUES (5302,'CALLE LARGA',5);
INSERT INTO COMUNA VALUES (5303,'RINCONADA',5);
INSERT INTO COMUNA VALUES (5304,'SAN ESTEBAN',5);
INSERT INTO COMUNA VALUES (5401,'LA LIGUA',5);
INSERT INTO COMUNA VALUES (5402,'CABILDO',5);
INSERT INTO COMUNA VALUES (5403,'PAPUDO',5);
INSERT INTO COMUNA VALUES (5404,'PETORCA',5);
INSERT INTO COMUNA VALUES (5405,'ZAPALLAR',5);
INSERT INTO COMUNA VALUES (5501,'QUILLOTA',5);
INSERT INTO COMUNA VALUES (5502,'CALERA',5);
INSERT INTO COMUNA VALUES (5503,'HIJUELAS',5);
INSERT INTO COMUNA VALUES (5504,'LA CRUZ',5);
INSERT INTO COMUNA VALUES (5506,'NOGALES',5);
INSERT INTO COMUNA VALUES (5601,'SAN ANTONIO',5);
INSERT INTO COMUNA VALUES (5602,'ALGARROBO',5);
INSERT INTO COMUNA VALUES (5603,'CARTAGENA',5);
INSERT INTO COMUNA VALUES (5604,'EL QUISCO',5);
INSERT INTO COMUNA VALUES (5605,'EL TABO',5);
INSERT INTO COMUNA VALUES (5606,'SANTO DOMINGO',5);
INSERT INTO COMUNA VALUES (5701,'SAN FELIPE',5);
INSERT INTO COMUNA VALUES (5702,'CATEMU',5);
INSERT INTO COMUNA VALUES (5703,'LLAILLAY',5);
INSERT INTO COMUNA VALUES (5704,'PANQUEHUE',5);
INSERT INTO COMUNA VALUES (5705,'PUTAENDO',5);
INSERT INTO COMUNA VALUES (5706,'SANTA MARIA',5);
INSERT INTO COMUNA VALUES (5801,'QUILPUE',5);
INSERT INTO COMUNA VALUES (5802,'LIMACHE',5);
INSERT INTO COMUNA VALUES (5803,'OLMUE',5);
INSERT INTO COMUNA VALUES (5804,'VILLA ALEMANA',5);
INSERT INTO COMUNA VALUES (6101,'RANCAGUA',6)
INSERT INTO COMUNA VALUES (6201,'SAN FERNANDO',6)
