/*
DATOS DES PROGRAMA
NOMBRE          : xml.cpp correspondiente a la tarea6 de Ingenieria de Software
FECHA ENTREGA   : Lunes 26 Mayo
UTEM

Programa probado y testeado en un notebook HP con Maquina Virtual LinuxMInt 15 | 64 bit | 2GB de RAM

Advertencia:
Para compilar usar el comando   : g++ xml.cpp -lcurl -o xml
Para Usar el programa           : ./xml -d  || ./xml -v
*/

/*Bibliotecas estandar utilizadas*/
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <string.h>
#include <curl/curl.h>

/*Para trabajar con XML se prueba la libreria pugixml se uso como prueba para parsear
#include "src/pugiconfig.hpp"
#include "src/pugixml.hpp"
#include "src/pugixml.cpp"
*/

/*Constantes*/
#define _TIME_
#define N 15

using namespace std;

/*Funcion para*/
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

/*Funcion principal y cuerpo del programa*/
int main(int argc, char *argv[])
{
/*Variables de la funcion principal*/
int entrada = 0, i, PosMensaje, PivoteMensaje;
time_t tiempo = time(0);
struct tm *tlocal = localtime(&tiempo);
char SalidaFecha[128], Fila[100];
string RespuestaWEB;

// Mensaje a desencriptar
char Mensaje[15];

/*Se crean las instancias de tipo CURL para la conexion con la WEB*/
CURL *curl;
CURLcode res;

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

/*________________________Bloque para conectar con la WEB_______________________________________________*/
/*
Comentario: Por mas que se intento mostrar un arbol del archivo XML de la web http://sebastian.cl/isw-rest/api/mensajeCifrado
no se pudo, pero si se logro recopilar el contenido explicito de los nodo hijo. Pero para archivos de hiperTexto mostraba toda la
estructura de arbol. Claramente no es la opcion mas valida para cuando se hable uso de memoria, pero como es una estructura pequeña
nos parecio acertado usar este metodo para resolver la tarea
*/

   curl = curl_easy_init();
   if(curl)
   {
       curl_easy_setopt(curl, CURLOPT_URL, "http://sebastian.cl/isw-rest/api/mensajeCifrado");
       curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
       curl_easy_setopt(curl, CURLOPT_WRITEDATA, &RespuestaWEB);
       res = curl_easy_perform(curl);
       curl_easy_cleanup(curl);
       PosMensaje = RespuestaWEB.find("mensaje");
       /*Condicion de salida en caso de no encontrar la etiqueta mensaje*/
       if(PosMensaje > RespuestaWEB.length())
       {
            cout << "No se encontró el mensaje" << endl;
            return 0;
       }
       /* Se mueve 10 posiciones en el String de entrada para llegar justo donde comienza el codigo*/
       PosMensaje = PosMensaje + 10;
       PivoteMensaje = 0;
       cout << "Los Datos obtenidos de la WEB fueron: ";
       cout << RespuestaWEB << endl;
       /* While utilizado para parsear el mensaje, siempre considerando que este mensaje estara
       a 10 posiciones del inicio de la etiqueta "mensaje" y tendrá un standar de largo 12*/
       while(PivoteMensaje <= 12)
       {
           Mensaje[PivoteMensaje] = RespuestaWEB[PosMensaje];
           //cout << Mensaje[PivoteMensaje] << endl;
           PosMensaje++;
           PivoteMensaje++;
       }
       cout << "" << endl;
       Mensaje[PivoteMensaje-1] = '\0'; /*Correccion en el parseo, un error inesperado que no se le encontro explicacion*/
       cout << "EL mensaje parseado fue: ";
       cout << Mensaje << endl;


    }
/*________________________________Fin de Bloque para conectar con la WEB_______________________________________*/


}

/*Si el programa se ejecuta opción “-v” debe mostrar en pantalla (al menos
separados, por saltos de línea), La fecha y hora de compilacion, la fecha y hora
actual, la versión del programa (pueden utilizar un número fijo o la revisión del
repositorio), y el nombre de los integrantes del grupo de trabajo.*/
else if (entrada == 2)
{
    strftime(SalidaFecha,128,"%m-%d-%y",tlocal);
    cout << "La fecha actual:";
    cout << SalidaFecha << endl;
    strftime(SalidaFecha,128,"%H:%M:%S",tlocal);
    cout << "La hora actual:";
    cout <<SalidaFecha << endl;
    cout << "Integrantes:\nRicardo Lopez\nCarlos Guerrero\nDaniel Gutierrez" << endl;
    cout << "Fecha de compilacion: ";
    puts(__DATE__);
    cout << "Hora de compilacion: ";
    puts(__TIME__); //Fecha de compilacion.
    cout << "\nVersion del programa: 1.5.2\n" << endl;
    cout << "Programa creado bajo el sistema operativo Ubuntu 13.10\n";
}
else
{
    cout << "Opcion no valida. Ingresar:" << endl;
    cout << "" << endl;
    cout << "-d para parsear la estructura XML de respuesta" << endl;
    cout << "-v para mostrar en pantalla informaciones varias." << endl;
}
return 0;
}


/*________________________________________Codigo Inutilizado___________________________________________________*/

/*________________________________Parseo Local del archivo tarea.xml_______________________________________

    pugi::xml_document doc;
    if (!doc.load_file("tarea.xml"))
	{
		cerr << "Error al cargar el documento XML." << endl;
		return 0;
	}
	// Creamos un objeto nodo
	pugi::xml_node root_node;
	// Le asignamos el nodo principal comprobando que sea correcto sino no sigue el programa
	if (!(root_node = doc.child("mensaje")))
	{
		cerr << "El documento no es un mapa valido." << endl;
		return 0;
	}
    Se recorre la estructura del archivo, teniendo en cuenta que este no varia en el tiempo
	for (pugi::xml_node node = root_node.first_child(); node; node = node.next_sibling())
	{
		string node_name = node.name();
        Si encontramos la etiqueta mensaje se guarda su contenido en una variable llamada Mensaje para su posterior
        Desencriptacion
		if (node_name == "mensaje")
		{
		    strcpy(Mensaje, node.child_value());
		    cout << "El mensaje obtenido fue: ";
		    cout << Mensaje << endl;
		    BanderaDePaso = true;
		}
	}
	if (!BanderaDePaso)
    {
        cout << "No se encontro la etiqueta Mensaje" << endl;
        return 0;
    }
________________________________Fin de Parseo Local del archivo tarea.xml_______________________________________*/
