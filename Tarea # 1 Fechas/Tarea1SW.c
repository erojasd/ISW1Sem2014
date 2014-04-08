#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>

typedef struct
{
   int dia;
   int mes;
   int anio;
}
Fecha;

void capturarFechaActual(Fecha* ptrHoy);
Fecha leerFecha(const char* msg, const Fecha fechaActual);
void imprimirDiferencia(const Fecha a, const Fecha b);

int verificarFecha(int anyo, int mes, int dia);
int esBisiesto(const int anyo);
int compararFecha(Fecha a, Fecha b);

int getLine(char* s, const int tam);
void flushStdin(void);

int main(int argc, char *argv[])
{
   int i = 0, entrada = 0, ann, r, MesAux, fech = 0, AnioC, D, M, contadormes = 0, error = 1;
   int diasPorMes[14] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
   Fecha inicio, hoy;
   float Aux;
   char MesActual [10], LecturaFecha [12];

   for (i = 0; i < argc ; i++)
   {
        if(strcmp(argv[i],"-f")==0) entrada = 1;
        else if(strcmp(argv[i],"-v")==0) entrada = 2;
   }
   capturarFechaActual(&hoy);

   if(entrada == 0)
   {
       printf("\nOpcion no valida, ejecute nuevamente el programa");
      // getch();
       return 0;
   }
   /*En caso de ingresar el -f 2013-04-03 por ejemplo se ejecuta el punto 1 de la tarea 01, calculo de dias meses años etc*/
   else if(entrada == 1 && argv[2] != '\0')
   {
       strcpy(LecturaFecha,argv[2]);

       if(sscanf(LecturaFecha,"%d-%d-%d", &inicio.anio, &inicio.mes, &inicio.dia) != 3)
       {
            puts("\tFormato de fecha no valido\n");
           // getch();
            return 0;
       }
       else
       {
           error = verificarFecha(inicio.anio, inicio.mes, inicio.dia);
           /* Verificar que la fecha sea consistente */
           if (error)
            {
            puts("\tLa fecha no es consistente, ejecute nuevamente\n");
            return 0;
            }

           /* Verificar que no sea mayor que la fecha actual del sistema */
           else if (compararFecha(inicio, hoy) > 0)
           {
            puts("\tError: La fecha de ingresada no debe ser mayor que la actual\nEjecute nuevamente");
            return 0;
           }

           else
           {
            /*Una vez que la fecha es correcta, se manda a ejecutar el algoritmo principal*/
             imprimirDiferencia(inicio, hoy);

            /*Calculo del numero de la semana basado en el algoritmo de ..... */
            D = inicio.dia;
            M = inicio.mes;
            AnioC = inicio.anio;
            Aux = (29.4 + (float)((inicio.anio%100)/4) + (float)(inicio.anio%100) +  (float)((inicio.anio/100)/4) - (float)((inicio.anio/100)*2));
            int DiaEnero = ((int)Aux%7) - 1;
            fech = ((D + DiaEnero - 1 + diasPorMes[inicio.mes - 1])/7) + 1;
            printf("\nAdemas La fecha Ingresada corresponde a la semana : %d ", fech);
            //getch();
            return 0;
           }
       }
   }
   /*En caso de ingresar el -v se ejecuta el punto 2 de la tarea 01, Datos de los integrante sy fecha de compilacion*/
   else if (entrada == 2 && argv[2] == '\0')
   {
       printf("\nIntegrantes:\n\nRicardo Lopez\nCarlos Guerrero\nDaniel Gutierrez\n\n");
       int MesAux = hoy.mes;
            if (MesAux == 1) strcpy(MesActual,"Enero");
       else if (MesAux == 2) strcpy(MesActual,"Febrero");
       else if (MesAux == 3) strcpy(MesActual,"Marzo");
       else if (MesAux == 4) strcpy(MesActual,"Abril");
       else if (MesAux == 5) strcpy(MesActual,"Mayo");
       else if (MesAux == 6) strcpy(MesActual,"Junio");
       else if (MesAux == 7) strcpy(MesActual,"Julio");
       else if (MesAux == 8) strcpy(MesActual,"Agosto");
       else if (MesAux == 9) strcpy(MesActual,"Septiembre");
       else if (MesAux == 10) strcpy(MesActual,"Octubre");
       else if (MesAux == 11) strcpy(MesActual,"Noviembre");
       else if (MesAux == 12) strcpy(MesActual,"Diciembre");
       printf("Le fecha de compilacion es: %d, Mes de %s, Anio %d\n\n ",hoy.dia, MesActual, hoy.anio);
       //getch();
       return 0;
   }
   /*Una especie de try catch para cuando no se ingresen bien los parametros*/
   else
   {
       printf("\nOpcion no valida, ejecute nuevamente el programa");
       //getch();
       return 0;
   }

}
/*Funciones utilizadas para hacer funcionar el programa*/

void capturarFechaActual(Fecha* ptrHoy)
{
   time_t horaLocal;
   struct tm* p;
   horaLocal = time(NULL);
   p = localtime(&horaLocal);
   ptrHoy->dia = p->tm_mday;
   ptrHoy->mes = p->tm_mon + 1;
   ptrHoy->anio = p->tm_year + 1900;
}

/*No se utiliza por el momento*/
Fecha leerFecha(const char* msg, const Fecha fechaActual)
{
   Fecha f;
   int error = 1;

   do {
      char cadFecha[80];

      printf("%s", msg);
      fflush(stdout);
      getLine(cadFecha, sizeof cadFecha);

      /* Validar el formato de fecha */
      if (sscanf(cadFecha, "%d-%d-%d", &f.anio, &f.mes, &f.dia) != 3)
         puts("\tFormato de fecha no valido\n");
      else {
         error = verificarFecha(f.anio, f.mes, f.dia);

         /* Verificar que la fecha sea consistente */
         if (error)
            puts("\tLa fecha no es consistente, verifique\n");

         /* Verificar que no sea mayor que la fecha actual del sistema */
         else if (compararFecha(f, fechaActual) > 0) {
            puts("\tError: La fecha de ingresada no debe ser mayor que la actual");
            error = 1;
         }
      }

   } while (error);

   return f;
}

void imprimirDiferencia(const Fecha a, const Fecha b)
{
   const int dm[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   Fecha ini = a, fin = b;
   int anios, meses, dias = 0,Aux = ini.anio;

   dias = fin.dia - ini.dia;
   if ( dias < 0 ) {
      dias += dm[ini.mes-1] + (ini.mes == 2 && esBisiesto(ini.anio)) ;
      ++ini.mes;
   }
   meses = fin.mes - ini.mes;
   if( meses < 0 ){
      meses += 12;
      ++ini.anio;
   }
   anios = fin.anio - ini.anio;


   printf("\nHan transcurrido %d anios %d meses %d dias hasta hoy %d-%d-%d\n", anios, meses, dias,fin.anio,fin.mes, fin.dia);
   if (esBisiesto(Aux) == 1) printf("\nEl anio Ingresado es anio bisiesto\n");
   if (esBisiesto(Aux) == 2) printf("\nEl anio Ingresado NO es anio bisiesto\n");
}

/*----------------------------------------------------*/

int verificarFecha(int anyo, int mes, int dia)
{
   static const int diasPorMes[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   if (mes > 0 && mes <= 12) {
      if (dia > 0 && dia <= diasPorMes[mes])
         return 0;
   }

   return 1;
}
int esBisiesto(int anyo)
{
    if(anyo % 4 == 0 && (anyo % 100 != 0 || anyo % 400 == 0))
    return 1;
    else
    return 2;
}

int compararFecha(Fecha a, Fecha b)
{
    if (a.anio != b.anio)
        return a.anio - b.anio;

    else if (a.mes != b.mes)
        return a.mes - b.mes;

    else return a.dia - b.dia;
}

int getLine(char* s, const int tam)
{
   int i, c;
   for (i = 0; i < tam - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
      s[i] = c;
   s[i] = '\0';

   if (c != '\n')
      flushStdin();
   return 0;
}

void flushStdin(void)
{
   int c;
   while ((c = getchar()) != EOF && c != '\n')
      ;
}


