#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define _TIME_
typedef struct
{
   char nombre [15];
   char fecha [15];
   char Monto [15];
}
Columna;

/*Funciones que se usaran durante el programa*/

int ExtraerValor (char * Linea);
int ExtraerMes (char * Linea2);

/*______________________________________________________________________________________________________________________________________________________________________*/

int main(int argc, char *argv[])
{
 	FILE *archivo;
    int i = 0, entrada = 0, MesSuma = 1;
 	char MesActual [13], caracteres[100];
 	unsigned long TotalAnio = 0, SumaMonto = 0;
    Columna Lector;
 	archivo = fopen("ventas.csv","r");

 	if (archivo == NULL) exit(1);
    /*Se filtra la opcion de entrada:

    • Al ejecutar el programa con la opcion -s archivo.csv El programa debe
    entregar la suma total de las ventas de todas las tiendas, que existan en
    el archivo.csv.

    • Al ejecutar el programa con la opcion -a tienda archivo.csv El programa
    debe entregar la suma mensual de la tienda (de Enero a Diciembre) de la
    tienda especificada por “tienda”.

    • Al ejecutar el programa con la opcion -v el programa debe mostrar en pantalla
    la informaci´on de los integrantes del grupo y la fecha de compilacion,
    posterior a esto debe terminar.
    */
 	for (i = 0; i < argc ; i++)
    {
        if(strcmp(argv[i],"-s")==0) entrada = 1;
        if(strcmp(argv[i],"-a")==0) entrada = 2;
        if(strcmp(argv[i],"-v")==0) entrada = 3;
    }

 	/*Realiza la suma de los totales anuales de todas las tiendas*/
 	if (entrada == 1 && strcmp(argv[2], "archivo.csv" ) == 0)
    {
 	/*Se recorre el archivo linea por linea */
        while (feof(archivo) == 0)
        {
            fgets(caracteres,100,archivo);
            fflush(stdin);
            TotalAnio = TotalAnio + (ExtraerValor(caracteres)/100);
        }
        /*De todas las formas posibles lee dos veces la ultima fila por esta razon se le resta de manera artesanal el ultimo valor ingresado*/
        TotalAnio = TotalAnio - (ExtraerValor(caracteres)/100);
        printf("la suma total de las ventas de todas las tiendas es: %lu00\n",TotalAnio);
        fclose(archivo);
        }
 	/*Fin de la suma de los totales anuales de todas las tiendas*/

    /*Suma parcial por mes por tienda ingresada en los parametros
 	Se considera que el archivo ventas.csv está ordenado por mes ... Se recorre el archivo fila por fila*/

 	else if (entrada == 2 && strcmp(argv[3], "archivo.csv") == 0)
    {
    printf("Para la tienda: %s \n\n", argv[2]);

 	while (feof(archivo) == 0)
 	{
 	    /*Se lee la linea actual*/
 		fgets(caracteres,100,archivo);
 		/*Se realiza una especie de split para separar cada columna del archivo ventas.csv*/
        int ValorMes = ExtraerMes(caracteres);


 		if (!strstr(caracteres, argv[2]) == 0 && ValorMes == MesSuma)
 		{
 		    fflush(stdin); SumaMonto = SumaMonto + ExtraerValor(caracteres);

 		}

 		else if (ValorMes != MesSuma)
        {

            fflush(stdin);
            if (MesSuma == 1) strcpy(MesActual,"Enero");
            else if (MesSuma == 2) strcpy(MesActual,"Febrero");
            else if (MesSuma == 3) strcpy(MesActual,"Marzo");
            else if (MesSuma == 4) strcpy(MesActual,"Abril");
            else if (MesSuma == 5) strcpy(MesActual,"Mayo");
            else if (MesSuma == 6) strcpy(MesActual,"Junio");
            else if (MesSuma == 7) strcpy(MesActual,"Julio");
            else if (MesSuma == 8) strcpy(MesActual,"Agosto");
            else if (MesSuma == 9) strcpy(MesActual,"Septiembre");
            else if (MesSuma == 10) strcpy(MesActual,"Octubre");
            else if (MesSuma == 11) strcpy(MesActual,"Noviembre");
            else if (MesSuma == 12) strcpy(MesActual,"Diciembre");

            printf("El monto por el mes de [%s] es: $%lu\n", MesActual, SumaMonto);
            /*Para el caso que el valor de la columna actual sea parte del monto del mes evaluado
            se debe incluir en el Monto del proximo mes*/
            SumaMonto = 0;
            MesSuma = ValorMes;
        }

        /*__________________________________________________________________________________________________*/

 	  }
 	  if (MesSuma == 12) printf("El monto por el mes de [Diciembre] es: $%lu\n", SumaMonto);
    }


    /*Fin Suma parcial por mes y por tienda*/

 	/*Opcion de Salir del programa*/

 	else if (entrada == 3)
    {
 	printf("\nIntegrantes:\n\nRicardo Lopez\nCarlos Guerrero\nDaniel Gutierrez\n\n");
 	printf("Fecha de compilacion: ");
    puts(__DATE__); //Fecha de compilacion.
    }
 	/*Fin Opcion de Salir del programa*/

 	else
    {
        printf("\nOpcion no Valida, ejecute nuevamente\n");
        exit(1);
    }
    return 0;
}


/*Funciones para ejecutar el programa*/

int ExtraerValor (char * Linea)
{
int MontoF = 0, j, ContRef = 0, CadMonto = 0;
char CadAuxMonto [10];
for (j = 0; j < 100; j++)
{
 	if (Linea[j] == '"') ContRef++;

    else if(ContRef == 5)
    {
        CadAuxMonto [CadMonto] = Linea[j];
        CadMonto++;
    }

    if (ContRef == 6)
    {
     CadAuxMonto [CadMonto] = '\0';
    }
    fflush(stdin); MontoF = atoi (CadAuxMonto);
}
return MontoF;
}


int ExtraerMes (char * Linea2)
{
    int Mes = 0, PivoteF = 0;
    int MontoF = 0, j, ContRef = 0, CadMonto = 0;
    char CadAux [20], CadMes [3];

    for (j = 0; j < 20; j++) CadAux [j] = ' ';
    for (j = 0; j < 3; j++) CadMes [j] = ' ';
    for (j = 0; j < 100; j++)
    {
        if (Linea2[j] == '"') ContRef++;

        else if(ContRef == 3)
        {
        CadAux [CadMonto] = Linea2[j];
        CadMonto++;
        }

        if (ContRef == 4)
        {
        CadAux [CadMonto] = '\0';
        //printf("%s\n", CadAux);
        PivoteF = 0;
        for (PivoteF = 0; PivoteF < 10; PivoteF++)
        {
            if (CadAux[PivoteF] == '-')
            {
                CadMes[0] = CadAux[PivoteF + 1];
                CadMes[1] = CadAux[PivoteF + 2];
                CadMes[2] = '\0';
                fflush(stdin); Mes = atoi (CadMes);
                //Mes = 1;
                return Mes;


            }
        }


        }



}

}
