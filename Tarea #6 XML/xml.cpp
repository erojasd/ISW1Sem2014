/*Bibliotecas utilizadas*/
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <string.h>
/*Constantes*/
#define _TIME_
#define N 15

using namespace std;

/*Variables Globales*/
char Pos2[N]; // se utiliza en funcion para pasar a mayuscula

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

/*Se define cual es el parametro de entrada*/
for(i=0;i< argc;i++)
{
if(strcmp(argv[i],"-d")==0)  entrada = 1;
if(strcmp(argv[i],"-v")==0)  entrada = 2;

}
/*Si el programa se ejecuta opci ́on “-r” Debe entregar la sumatoria total de
las ventas de cada una de las tiendas.*/
if (entrada == 1)
{

}

/*Si el programa se ejecuta opción “-v” debe mostrar en pantalla (al menos
separados, por saltos de línea), La fecha y hora de compilacion, la fecha y hora
actual, la versión del programa (pueden utilizar un número fijo o la revisión del
repositorio), y el nombre de los integrantes del grupo de trabajo.*/
else if (entrada == 2)
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
    printf("\nVersion del programa: 1.5.2\n");
    cout<<"Programa creado bajo el sistema operativo Ubuntu 13.10"<<endl;
}
else
{
    cout<<"Opcion no valida. Ingresar:"<<endl;
    cout<<""<<endl;
    cout<<"-d para parsear la estructura XML de respuesta"<<endl;
    cout<<"-v para mostrar en pantalla informaciones varias."<<endl;
}
return 0;
}

