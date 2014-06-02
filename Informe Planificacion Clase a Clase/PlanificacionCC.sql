/* crear Base de datos */

  CREATE DATABASE "PlanificacionCC"
  WITH ENCODING='UTF8'
  CONNECTION LIMIT=-1;


/* Crear Tablas */

CREATE TABLE region
(
	pk serial NOT NULL,
	nombre varchar(255) NOT NULL UNIQUE,
	corfo varchar(255) NOT NULL,
	codigo varchar(5) NOT NULL UNIQUE,
	numero int NOT NULL UNIQUE,
	pais_fk int NOT NULL,
	PRIMARY KEY (pk)
) WITHOUT OIDS;


CREATE TABLE provincia
(
	pk serial NOT NULL,
	nombre varchar(255) NOT NULL UNIQUE,
	region_fk int NOT NULL,
	PRIMARY KEY (pk)
) WITHOUT OIDS;


CREATE TABLE facultad
(
	pk serial NOT NULL,
	facultad varchar(255) NOT NULL UNIQUE,
	descripcion text,
	PRIMARY KEY (pk)
) WITHOUT OIDS;


CREATE TABLE asignatura
(
	codigo varchar(8) NOT NULL UNIQUE,
	nombre varchar(255) NOT NULL UNIQUE,
	descripcion text,
	PRIMARY KEY (codigo)
) WITHOUT OIDS;


CREATE TABLE semana
(
	pk serial NOT NULL UNIQUE,
	semana_anual int NOT NULL,
	semana_planificada char(15),
	PRIMARY KEY (pk)
) WITHOUT OIDS;


CREATE TABLE contenido
(
	clasificacion_fk int NOT NULL,
	Semana serial NOT NULL,
	Objetivo text,
	Contenido text,
	Evaluacion text,
	PRIMARY KEY (clasificacion_fk)
) WITHOUT OIDS;


CREATE TABLE contenido_Semana
(
	pk int NOT NULL,
	clasificacion_fk int NOT NULL
) WITHOUT OIDS;


CREATE TABLE carrera_asignatura
(
	codigo_carrera int NOT NULL,
	codigo_asignatura varchar(8) NOT NULL
) WITHOUT OIDS;


CREATE TABLE escuela
(
	pk serial NOT NULL,
	departamento_fk int NOT NULL,
	escuela varchar(255) NOT NULL,
	descripcion text,
	PRIMARY KEY (pk)
) WITHOUT OIDS;


CREATE TABLE jefeCarrera
(
	docente_fk int NOT NULL UNIQUE,
	escuela_fk int NOT NULL,
	PRIMARY KEY (docente_fk)
) WITHOUT OIDS;


CREATE TABLE planificacion
(
	Cod_Clasificacion serial NOT NULL UNIQUE,
	Rut varchar(12) NOT NULL,
	Facultad int NOT NULL,
	Departamento int NOT NULL,
	Escuela int NOT NULL,
	Objetivo text,
	Asignatura varchar(8) NOT NULL,
	Semestre int,
	Fecha date,
	Estrategia text,
	PRIMARY KEY (Cod_Clasificacion)
) WITHOUT OIDS;


CREATE TABLE decano
(
	Rut varchar(12) NOT NULL UNIQUE,
	facultad_fk int NOT NULL UNIQUE,
	PRIMARY KEY (Rut)
) WITHOUT OIDS;


CREATE TABLE carrera
(
	Codigo int NOT NULL UNIQUE,
	nombre varchar(255),
	escuela_fk int NOT NULL,
	jefeCarrera_fk int NOT NULL UNIQUE,
	PRIMARY KEY (Codigo)
) WITHOUT OIDS;


CREATE TABLE comuna
(
	pk serial NOT NULL,
	nombre varchar(255) NOT NULL UNIQUE,
	provincia_fk int NOT NULL,
	PRIMARY KEY (pk)
) WITHOUT OIDS;


CREATE TABLE docente
(
	pk serial NOT NULL,
	nombre varchar(255) NOT NULL,
	Apellido varchar(255) NOT NULL,
	rut varchar(12) NOT NULL UNIQUE,
	fecha_nacimiento date,
	genero char(1),
	direccion varchar(255) NOT NULL,
	comuna_fk int NOT NULL,
	telefono varchar(15),
	celular varchar(15),
	email varchar(50) NOT NULL,
	departamento_fk int NOT NULL,
	jerarquia varchar(255) NOT NULL,
	contrato varchar(255) NOT NULL,
	jornada varchar(255) NOT NULL,
	grado int NOT NULL,
	funcion varchar(255) NOT NULL,
	eliminado int NOT NULL,
	PRIMARY KEY (pk)
) WITHOUT OIDS;


CREATE TABLE alumno
(
	pk_RutAlumno varchar (12) NOT NULL,
	nombre varchar(255) NOT NULL,
	Apellido varchar(255) NOT NULL,
	fecha_nacimiento date,
	genero char(1),
	direccion varchar(255) NOT NULL,
	comuna_fk int NOT NULL,
	telefono varchar(15),
	celular varchar(15),
	email varchar(50) NOT NULL,
	matricula varchar(255) NOT NULL,
	PRIMARY KEY (pk)
) WITHOUT OIDS;

CREATE TABLE departamento
(
	pk serial NOT NULL,
	facultad_fk int NOT NULL,
	departamento varchar(255) NOT NULL UNIQUE,
	descripcion text,
	PRIMARY KEY (pk)
) WITHOUT OIDS;


CREATE TABLE curso
(
	pk serial NOT NULL,
	semestre int NOT NULL UNIQUE,
	anio int NOT NULL UNIQUE,
	docente_fk int NOT NULL UNIQUE,
	seccion int NOT NULL,
	codigo varchar(8) NOT NULL UNIQUE,
	PRIMARY KEY (pk)
) WITHOUT OIDS;


CREATE TABLE directorDepartamento
(
	Rut varchar(12) NOT NULL UNIQUE,
	departamento_fk int NOT NULL UNIQUE,
	PRIMARY KEY (Rut)
) WITHOUT OIDS;


CREATE TABLE pais
(
	pk serial NOT NULL,
	cod_num int NOT NULL UNIQUE,
	alfa_tres varchar(3) NOT NULL UNIQUE,
	alfa_dos varchar(2) NOT NULL UNIQUE,
	nombre varchar(255) NOT NULL UNIQUE,
	PRIMARY KEY (pk)
) WITHOUT OIDS;



/* Crear llaves foraneas */

ALTER TABLE provincia
	ADD FOREIGN KEY (region_fk)
	REFERENCES regiones (pk)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE comuna
	ADD FOREIGN KEY (provincia_fk)
	REFERENCES provincias (pk)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE departamento
	ADD FOREIGN KEY (facultad_fk)
	REFERENCES facultades (pk)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE Decano
	ADD FOREIGN KEY (facultad_fk)
	REFERENCES facultades (pk)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE Planificacion
	ADD FOREIGN KEY (facultad)
	REFERENCES facultades (pk)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE carrera_asignatura
	ADD FOREIGN KEY (codigo_asignatura)
	REFERENCES asignatura (codigo)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE curso
	ADD FOREIGN KEY (codigo)
	REFERENCES asignatura (codigo)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE contenido_Semana
	ADD FOREIGN KEY (pk)
	REFERENCES Semana (pk)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE contenido_Semana
	ADD FOREIGN KEY (clasificacion_fk)
	REFERENCES Contenido (clasificacion_fk)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE planificacion
	ADD FOREIGN KEY (Escuela)
	REFERENCES escuela (pk)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE jefeCarrera
	ADD FOREIGN KEY (escuela_fk)
	REFERENCES escuela (pk)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE carrera
	ADD FOREIGN KEY (escuela_fk)
	REFERENCES escuela (pk)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE carrera
	ADD FOREIGN KEY (jefeCarrera_fk)
	REFERENCES JefeCarrera (docente_fk)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE Contenido
	ADD FOREIGN KEY (clasificacion_fk)
	REFERENCES planificacion (Cod_Clasificacion)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE carrera_asignatura
	ADD FOREIGN KEY (codigo_carrera)
	REFERENCES carrera (Codigo)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE docente
	ADD FOREIGN KEY (comuna_fk)
	REFERENCES comuna (pk)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;

ALTER TABLE alumno
	ADD FOREIGN KEY (comuna_fk)
	REFERENCES comuna (pk)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE JefeCarrera
	ADD FOREIGN KEY (docente_fk)
	REFERENCES docentes (pk)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE decano
	ADD FOREIGN KEY (Rut)
	REFERENCES docentes (rut)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE curso
	ADD FOREIGN KEY (docente_fk)
	REFERENCES docentes (pk)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE planificacion
	ADD FOREIGN KEY (Rut)
	REFERENCES docentes (rut)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE directorDepartamento
	ADD FOREIGN KEY (Rut)
	REFERENCES docentes (rut)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE escuela
	ADD FOREIGN KEY (departamento_fk)
	REFERENCES departamentos (pk)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE directorDepartamento
	ADD FOREIGN KEY (departamento_fk)
	REFERENCES departamentos (pk)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE docente
	ADD FOREIGN KEY (departamento_fk)
	REFERENCES departamentos (pk)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE planificacion
	ADD FOREIGN KEY (Departamento)
	REFERENCES departamentos (pk)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE Planificacion
	ADD FOREIGN KEY (Asignatura)
	REFERENCES cursos (codigo)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;


ALTER TABLE region
	ADD FOREIGN KEY (paises_fk)
	REFERENCES Paises (pk)
	ON UPDATE RESTRICT
	ON DELETE RESTRICT
;