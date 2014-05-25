#include <iostream>
#include <cstdio>
#include <cstring>
#include <time.h>
#include "blowfish.h"
#include <string.h>
#include <stdint.h>
#include <cstddef>
#include "blowfish.cpp"
#include "MySock.h"
#define _TIME_

using namespace std;

int main(int argc, char *argv[])
{
	int entrada=0;
	MySock sock;
  	HTTP_Request *http;
	for(int i=0;i< argc;i++)
	{
		if(strcmp(argv[i],"-d")==0)  entrada = 1;
		if(strcmp(argv[i],"-v")==0)  entrada = 2;
		
	}
	if(entrada==1)
	{
		const char key[] = "isw";

    	Blowfish clave;
    	std::string decrypted;
    	clave.SetKey(key);
    	sock = MySock("http://sebastian.cl/isw-rest/api/mensajeCifrado");
    	http=sock.GetHTTPData();
    	clave.Decrypt(&decrypted, http->data);
    	std::cout << decrypted << std::endl;

    	return 0;
	}

	else if(entrada==2)
	{
		printf("Integrantes:\nRicardo Lopez\nCarlos Guerrero\nDaniel Gutierrez\n\n");
		printf("Fecha de compilacion: ");
		puts(__DATE__);
		printf("Hora de compilacion: ");
		puts(__TIME__); //Fecha de compilacion.
	}
	return 0;
}