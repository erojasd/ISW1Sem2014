/*Bibliotecas utilizadas*/
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <cstdlib>
#include <libpq-fe.h>
#include <fstream>
#include <string.h>
/*Constantes*/
#define _TIME_
#define N 15

//compilar este archivo con el siguiente código: g++ entrada.cpp -o Ej -I/usr/include/postgresql -I/usr/include -lpq


using namespace std;
/*Variables Globales*/
char Pos2[N];
PGconn *cnn = NULL;
PGresult *result = NULL, *re2=NULL;

const char *host = "sebastian.cl";
const char *port = "5432";
const char *dataBase = "iswdb";
const char *user = "isw";
const char *passwd = "isw";

/*Funcion para pasar a mayuscula el segundo parametro de entrada*/
void PasarMayuscula(void)
{
    int i;
    for(i = 0; i< N; i++) Pos2[i]=toupper(Pos2[i]);
}

/*Funcion principal y cuerpo del programa*/
int main(int argc, char *argv[])
{

/*Variables de la funcion principal*/
int entrada = 0, i=0;
time_t tiempo = time(0);
struct tm *tlocal = localtime(&tiempo);
char SalidaFecha[128];
string resp;
cnn = PQsetdbLogin(host,port,NULL,NULL,dataBase,user,passwd);
long int ejey[12];

/*Se define cual es el parametro de entrada*/
for(i=0;i< argc;i++)
{
if(strcmp(argv[i],"-r")==0)  entrada = 1;
if(strcmp(argv[i],"-g")==0)  entrada = 2;
if(strcmp(argv[i],"-bh")==0) entrada = 3;
if(strcmp(argv[i],"-v")==0)  entrada = 4;
if(strcmp(argv[i],"-h")==0 ) entrada = 5;
}
/*Si el programa se ejecuta opci ́on “-r” Debe entregar la sumatoria total de
las ventas de cada una de las tiendas.*/
if (entrada == 1)
{
	if (PQstatus(cnn) != CONNECTION_BAD) {
        result = PQexec(cnn, "Select tienda, SUM(monto) From Ventas Group By tienda");

        if (result != NULL) {
            int tuplas = PQntuples(result);
            int campos = PQnfields(result);
            cout << endl << "La suma Total por cada una de las tiendas es:" << endl;

            for (i=0; i<tuplas; i++) {
                
                for (int j=0; j<campos; j++) {
                    cout << PQgetvalue(result,i,j);
                    cout<<": ";
                }
                cout << endl;
            }
        }}
        else cout<<"error de conexion"<<endl;
        PQfinish(cnn);
}

/*Si el programa se ejecuta con la opci ́on “-g tienda” el programa debe generar
un grafico de barras en formato JPG, del total de ventas del año, en donde el
eje X, deben ser los meses del año y el eje Y, las ventas.*/
else if (entrada == 2)
{
    strcpy(Pos2,argv[2]);
    PasarMayuscula();
    {
    printf("EL valor de la tienda en peticion no existe\n");
    return 0;
    }

}
/* Si el programa se ejecuta con la opcíon “-bh” el programa debe entregar la
hora del d ́ıa en donde en promedio, se vende m ́as por cada una de las tiendas.*/
else if (entrada == 3)
{
	int max1=0, max2=0, max3=0, max4=0, obtenido, hora=0; //max1=CencoSux, max2=Falaferia, max3=Replay, max4=Porahi, obtenido=valor obtenido desde la consulta
	char prim[200] = "Select avg(monto) from ventas where fecha::timestamp::time between '";
	char sec[50] = ":00:00' and '";
	char num[3];
	char ter[200] = ":59:59' and tienda ='";
	char tienda1[20] ="CencoSux", tienda2[20] ="Falaferia", tienda3[20] ="Replay", tienda4[20] ="Porahi", cuar[2]= "'";
	for(i=8;i<24;i++)
	{
			
			sprintf(num, "%d", i);
			strcat(prim, strcat(num, strcat(sec, num)));
			strcat(prim, strcat(ter, strcat(tienda1, cuar)));
			result = PQexec(cnn, prim);
			if (result != NULL) 
			{
				obtenido = atoi(PQgetvalue(result,0,0));
				if(obtenido>max1)
				{
						max1=obtenido;
						hora=i;
				}
				
			}
			else
			cout<<"Conexion no permitida";
			strcpy(prim, "Select avg(monto) from ventas where fecha::timestamp::time between '");
			strcpy(sec, ":00:00' and '");
	        strcpy(ter, ":59:59' and tienda ='");
	        strcpy(tienda1, "CencoSux");
			
	}
	cout<<"Para la tienda CencoSux, la hora que se promedio mayores ventas fue entre las "<<hora<<":00 y las "<<hora<<":59 y el promedio fue de: $"<<max1<<endl;
	for(i=8;i<24;i++)
	{
			sprintf(num, "%d", i);
			strcat(prim, strcat(num, strcat(sec, num)));
			strcat(prim, strcat(ter, strcat(tienda2, cuar)));
			result = PQexec(cnn, prim);
			if (result != NULL) 
			{
				obtenido = atoi(PQgetvalue(result,0,0));
				if(obtenido>max2)
				{
						max2=obtenido;
						hora=i;
				}
				
			}
			else
			cout<<"Conexion no permitida";
			strcpy(prim, "Select avg(monto) from ventas where fecha::timestamp::time between '");
			strcpy(sec, ":00:00' and '");
	        strcpy(ter, ":59:59' and tienda ='");
	        strcpy(tienda2, "Falaferia");
			
	}
	cout<<"Para la tienda Falaferia, la hora que se promedio mayores ventas fue entre las "<<hora<<":00 y las "<<hora<<":59 y el promedio fue de: $"<<max2<<endl;
	for(i=8;i<24;i++)
	{
			sprintf(num, "%d", i);
			strcat(prim, strcat(num, strcat(sec, num)));
			strcat(prim, strcat(ter, strcat(tienda3, cuar)));
			result = PQexec(cnn, prim);
			if (result != NULL) 
			{
				obtenido = atoi(PQgetvalue(result,0,0));
				if(obtenido>max3)
				{
						max3=obtenido;
						hora=i;
				}
				
			}
			else
			cout<<"Conexion no permitida";
			strcpy(prim, "Select avg(monto) from ventas where fecha::timestamp::time between '");
			strcpy(sec, ":00:00' and '");
	        strcpy(ter, ":59:59' and tienda ='");
	        strcpy(tienda3, "Replay");
			
	}
	cout<<"Para la tienda Replay, la hora que se promedio mayores ventas fue entre las "<<hora<<":00 y las "<<hora<<":59 y el promedio fue de: $"<<max3<<endl;
	
	for(i=8;i<24;i++)
	{
			sprintf(num, "%d", i);
			strcat(prim, strcat(num, strcat(sec, num)));
			strcat(prim, strcat(ter, strcat(tienda4, cuar)));
			result = PQexec(cnn, prim);
			if (result != NULL) 
			{
				obtenido = atoi(PQgetvalue(result,0,0));
				if(obtenido>max4)
				{
						max4=obtenido;
						hora=i;
				}
				
			}
			else
			cout<<"Conexion no permitida";
			strcpy(prim, "Select avg(monto) from ventas where fecha::timestamp::time between '");
			strcpy(sec, ":00:00' and '");
	        strcpy(ter, ":59:59' and tienda ='");
	        strcpy(tienda4, "Porahi");
			
	}
	cout<<"Para la tienda Porahi, la hora que se promedio mayores ventas fue entre las "<<hora<<":00 y las "<<hora<<":59 y el promedio fue de: $"<<max4<<endl;
}

/*Si el programa se ejecuta opción “-v” debe mostrar en pantalla (al menos
separados, por saltos de l ́ınea), La fecha y hora d ecompilacion, la fecha y hora
actual, la versión del programa (pueden utilizar un número fijo o la revisión del
repositorio), y el nombre de los integrantes del grupo de trabajo.*/
else if (entrada == 4)
{
strftime(SalidaFecha,128,"%m-%d-%y",tlocal);
printf("La fecha actual: %s\n",SalidaFecha);
strftime(SalidaFecha,128,"%H:%M:%S",tlocal);
printf("La hora actual: %s\n\n",SalidaFecha);
printf("Integrantes:\nRicardo Lopez\nCarlos Guerrero\nDaniel Gutierrez\n\n");
printf("Fecha de compilacion: ");
puts(__DATE__);
printf("Hora de compilacion: ");
puts(__TIME__); //Fecha de compilacion.
printf("\nVersion del programa: 1.8.3\n");
cout<<"Programa creado bajo el sistema operativo Ubuntu 13.10"<<endl;
}

/*Si el programa no recibe ningún parámetro o si se ejecuta con “-h”, debe
desplegar información con la forma de uso.*/
else if (entrada == 5 || entrada == 0)
{
cout <<"El codigo se tiene que ejecutar de la siguiente forma (Asumiendo que el usuario usa Linux):"<<endl;
cout<<"Primer paso: Haber instalado las librerias correspondientes a PostgreSQL (En el caso de Ubuntu: sudo apt-get install libpq-dev)"<<endl;
cout<<"Segundo Paso: Abrir la terminal"<<endl;
cout<<"Tercer paso: Posicionarse en la carpeta donde está el archivo (Por ejemplo, cd Descargas si esta en la carpeta Descargas)"<<endl;
cout<<"Cuarto paso: Escribir en la terminal 'g++ entrada1.8.3.cpp -o Ej -I/usr/include/postgresql -I/usr/include -lpq', donde '-I/usr/include/postgresql corresponde a las ubicación en donde deberían estar las librerías necesarias para ejecutar el programa, si no están las librerías en esa carpeta (o simplemente la carpeta no existe), mover las librerías a esa carpeta o cambiar la ruta hasta la carpeta donde sí están las librerías'"<<endl;
cout<<"Quinto paso: Arrancar el ejecutable, con cualquiera de las siguientes opciones: ./Ej (el nombre del ejecutable, en este caso 'Ej', es opcional, al igual que en el código para compilar el archivo) seguido de un '-r', '-g tienda' (tienda = CencoSux || tienda  = Replay || tienda = Falaferia || tienda = Porahi), -bh, -v o -h"<<endl;
cout<<"Sexto paso: Evaluar el trabajo"<<endl;
cout<<"Septimo paso: Continuar con la vida"<<endl;

}
return 0;
}

