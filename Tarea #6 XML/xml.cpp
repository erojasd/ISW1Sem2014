/*Bibliotecas estandar utilizadas*/
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <string.h>

/*Para trabajar con XML se prueba la libreria pugixml */
#include "pugiconfig.hpp"
#include "pugixml.hpp"
#include "pugixml.cpp"

/*Constantes*/
#define _TIME_
#define N 15

using namespace std;

/*Variables Globales*/
 // se utiliza en funcion para pasar a mayuscula
char Pos2[N];
// Mensaje a desencriptar
char Mensaje [N];
// Host de internet donde reside el mensaje
const char *host = "http://sebastian.cl/isw-rest/api/mensajeCifrado";

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
char SalidaFecha[128], Fila[100];

/*Se define cual es el parametro de entrada*/
for(i=0;i< argc;i++)
{
    if(strcmp(argv[i],"-d")==0)  entrada = 1;
    if(strcmp(argv[i],"-v")==0)  entrada = 2;
}

/*_________________________________________________________________________________________________________*/

/*Si el programa se ejecuta opción “-d” debe decifrar el mensaje propuesto en la pagina web
"http://sebastian.cl/isw-rest/api/mensajeCifrado"*/
if (entrada == 1)
{
    pugi::xml_document doc;
    if (!doc.load_file("tarea.xml"))
	{
		cerr << "Error al cargar el documento XML." << endl;
		return -1;
	}
	// Creamos un objeto nodo
	pugi::xml_node root_node;
	// Le asignamos el nodo principal comprobando que sea correcto sino no sigue el programa
	if (!(root_node = doc.child("mensaje")))
	{
		cerr << "El documento no es un mapa valido." << endl;
		return -2;
	}
    /*Se recorre la estructura del archivo, teniendo en cuenta que este no varia en el tiempo*/
	for (pugi::xml_node node = root_node.first_child(); node; node = node.next_sibling())
	{
		string node_name = node.name();
        /*Si encontramos la etiqueta mensaje se guarda su contenido en una variable global llamada Mensaje para su posterior
        Desencriptacion*/
		if (node_name == "mensaje")
		{
		    strcpy(Mensaje, node.child_value());
		    cout<<Mensaje<<endl;
		}

		else cout << "No se encontro el Mensaje" <<endl;
	}

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
    printf("Programa creado bajo el sistema operativo Ubuntu 13.10\n");
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

