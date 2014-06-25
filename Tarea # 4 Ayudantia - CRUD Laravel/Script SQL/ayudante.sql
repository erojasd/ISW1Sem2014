BEGIN TRANSACTION;

DROP TABLE IF EXISTS Bodega CASCADE;
CREATE TABLE Bodega (
    pk serial NOT NULL,
    Nombre_Bodega varchar(255) NOT NULL,    
    Codigo_Bodega varchar(255) NOT NULL,
    UNIQUE(Codigo_Bodega)
    PRIMARY KEY (pk)
);

DROP TABLE IF EXISTS Producto CASCADE;
CREATE TABLE Producto (
    pk serial NOT NULL,
    Nombre_Producto varchar(255) NOT NULL,    
    Codigo_Producto varchar(255) NOT NULL,
    Precio_Neto varchar(255) NOT NULL,
    UNIQUE(Codigo_Producto, Bodega_fk)
    PRIMARY KEY (pk)
);


