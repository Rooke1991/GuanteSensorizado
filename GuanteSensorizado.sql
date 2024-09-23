CREATE TABLE IF NOT EXISTS LecturasGuante (
    id SERIAL PRIMARY KEY,  -- Identificador único para cada entrada
    dedo VARCHAR(15),  -- Identificador de cada dedo (pulgar, índice, etc.)
    fecha_medicion TIMESTAMP,  -- Fecha y hora de la medición
    curvatura INTEGER NOT NULL  -- Valor de la curvatura del dedo
);

-- Datos tomados para el dedo Pulgar
INSERT INTO LecturasGuante (dedo, fecha_medicion, curvatura)
VALUES ('pulgar', '2024-08-01 10:30:00', 18),
       ('pulgar', '2024-08-05 14:00:00', 33),
       ('pulgar', '2024-08-10 09:15:00', 11);
	   
-- Datos tomados para el dedo Índice
INSERT INTO LecturasGuante (dedo, fecha_medicion, curvatura)
VALUES ('indice', '2024-08-01 10:30:00', 90),
       ('indice', '2024-08-05 14:00:00', 85),
       ('indice', '2024-08-10 09:15:00', 88);

-- Datos tomados para el dedo Corazón
INSERT INTO LecturasGuante (dedo, fecha_medicion, curvatura)
VALUES ('corazon', '2024-08-01 10:30:00', 80),
       ('corazon', '2024-08-05 14:00:00', 82),
       ('corazon', '2024-08-10 09:15:00', 78);

-- Datos tomados para el dedo Anular
INSERT INTO LecturasGuante (dedo, fecha_medicion, curvatura)
VALUES ('anular', '2024-08-01 10:30:00', 88),
       ('anular', '2024-08-05 14:00:00', 89),
       ('anular', '2024-08-10 09:15:00', 90);

-- Datos tomados para el dedo Meñique
INSERT INTO LecturasGuante (dedo, fecha_medicion, curvatura)
VALUES ('menique', '2024-08-01 10:30:00', 78),
       ('menique', '2024-08-05 14:00:00', 80),
       ('menique', '2024-08-10 09:15:00', 75);

SELECT * FROM LecturasGuante;