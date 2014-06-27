## Tarea 4 Ayudantia - Crud Laravel ##

## Requisitos Previos ##

Tener instalado como minimo:

1. Un sistema Operativo, de preferencia Ubuntu 13.10 distribución de Linux
2. Servidor apache version 2 | Xammp en Windows | Mampp en Mac
2. PHP 5.5
3. PostgreSQL version 9.1 o superior
4. pgadmin III
5. phppgadmin version 9.1 o superior
6. Libreria Curl
7. mycrypt
8. Composer como medio para instalar repositorio laravel

## Indicaciones ##

1. Descargar completo el repositorio ISW1Sem2014 presionando en "Download ZIP"
2. Descargar el script SQL "ayudante.sql" para generar la base de datos localmente
3. Buscar en la carpeta que se descargo el directorio Tarea # 4 Ayudantia - CRUD Laravel-masters y cambiarle el nombre por T4ayudantia
4. Copiar el directorio T4ayudantia a donde tenga el servidor apache corriendo por defecto es /var/www/ 
5. Para crear la base de datos se debe ejecutar el script sql "ayudante.sql" con la aplicación pgadmin III, conectandose con el servidor local.

Expandir el arbol hasta encontrar Databases y crear una nueva base de datos llamada "ayudantia"<br>
Posicionarse en el arbol en la nueva base de datos creada y presionar el boton de la interfez que dice SQL<br>
Cargar el archivo ayudante.sql y ejecutarlo.<br>
<br>
Configurar Laravel: Abrir el archivo database.php de la carpeta app/config del proyecto y modificar las siguientes lineas
'default' => 'pgsql',<br>
<br>
'pgsql' => array(
'driver'   => 'pgsql', <br>
'host'     => 'localhost', <br>
'database' => 'ayudantia', <br>
'username' => 'nuestro_nombre_de_usuario', <br>
'password' => 'nuestro_password_de_servidor', <br>
'charset'  => 'utf8', <br>
'prefix'   => '', <br>
'schema'   => 'public',<br>
<br>
Cargar los modelos al proyecto mediante el comando sudo composer auto-dump<br>
6. Para poder visualizar y editar el proyecto se deben hacer unos tediosos tramites, se abre una terminal y se ejecutan los parametros descritos a continuacion:
<br>
Editar el archivo 000-default.conf para decirle al servidor apache que aqui se encuentra un proyecto nuevo mediante el siguiente código<br>

sudo gedit /etc/apache2/sites-available/000-default.conf
<br>
y se agregan las siguientes lineas
<br>
< Directory /var/www/T4ayudantia/><br>
Options Indexes FollowSymLinks MultiViews<br>
AllowOverride All<br>
Order allow,deny<br>
allow from all<br>
< /Directory ><br>

Luego se teclear una instruccion para confirmar el cambio que se realizo el siguiente codigo:<br>
sudo a2enmod rewrite
<br>
Se reinicia Apache<br>
sudo service apache2 restart
<br>
Debemos dar permiso de lectura y escritura al proyecto y para eso nos posicionamos en la carpeta del proyecto y tecleamos
cd  /var/www/T4ayudantia/<br>
sudo chown -R www-data:www-data app/storage
<br>
7. Finalmente Luego se acceda desde nuestro navegador favorito a la siguiente url
localhost/T4ayudantia/public

Probar la aplicación
