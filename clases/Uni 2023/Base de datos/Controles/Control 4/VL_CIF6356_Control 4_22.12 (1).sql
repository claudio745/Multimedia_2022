--  CONTROL 4 (22.12)
--  BASE DE DATOS: INVERSION
--  CONEXIÓN: COTIZACION

--  OBSERVACION: El modelo de esta base de datos es la que figura en el Control 3, publicado en eAula.

--  PARTE 1
--  Crear la tabla COTIZACION. Leer atentamente los comentarios junto a cada columna

CREATE TABLE COTIZACION
(numeroCZ   NUMBER(10,0) NOT NULL,   --  Número correlativo que inicia con el año respectivo. Por ejemplo: la primera cotización para el año 2024, sería 20241
 numeroCT   NUMBER(7,0)  NOT NULL,   --  Identificador del cotizante
 fechaRegCZ DATE         NOT NULL,   --  Fecha de registro o ingreso de una cotización
 mesCZ      NUMBER(2,0)  NOT NULL,   --  Mes al que corresponde la cotización ingresada (mes por el que se está cotizando)
 agnoCZ     NUMBER(4,0)  NOT NULL,   --  Año al que corresponde la cotización ingresada (año al que pertenece el mes que se está cotizando)
 montoCZ    NUMBER(6,0)  NOT NULL,   --  Monto correspondiente a la cotización (actualmente, 10% de la renta imponible). Este monto es el que pasa directamente al ahorro obligatorio del cotizante
 comisionCZ NUMBER(5,0)  NOT NULL,   --  Monto correspondiente a la comisión cobrada por la AFP al cotizante por administrar sus fondos
 fechaPagCZ DATE         NULL,       --  Fecha de pago efectiva de la cotización del empleado por parte del empleador a la AFP
 estadoCZ   CHAR(1)      NOT NULL    --  Estado de la cotización. Dominio: {D (declarada), C (cancelada)}. Importante: Un empleador puede declarar una cotización sin haberla pagado (cancelado). Esto implica que el monto no afecta al ahorro obligatorio.
);

ALTER TABLE COTIZACION ADD CONSTRAINT PK_COTIZACION PRIMARY KEY(numeroCZ);
ALTER TABLE COTIZACION ADD CONSTRAINT FK_COTIZANTE_COTIZACION FOREIGN KEY(numeroCT) REFERENCES COTIZANTE(numeroCT);

--  PARTE 2 - EJERCICIOS
--  1.  (20 puntos) Implementar un bloque anónimo que permita ingresar una cotización válida para un cotizante en particular.
--      Consideraciones:
--      * Para determinar los montos de una cotización se requiere la remuneración imponible del cotizante, 
--        la cual no debe ser inferior al sueldo mínimo.
--      * El estado de la cotización no posee valor por defecto, ya que el empleador podría declarar o cancelar la cotización.
--        Una cotización cancelada implica el pago de esta; una declarada cancelada no.
--        En el caso de una cotizacion cancelada, su fecha de pago es la misma del registro
--      * Las cotizaciones se declaran o cancelan con un mes de desfase, por lo tanto, no existen pagos futuros
--      * Validar lo que corresponda
--      * Aplicar excepciones






--  2.  (15 puntos)
--      Implementar un procedimiento almacenado, denominado actualizarAhorro, que, para las cotizaciones que fueron
--      registradas como canceladas en la fecha en curso, actualice el ahorro obligatorio del cotizante respectivo.
--      Inlcuir el bloque anónimo que llame al procedimiento     
