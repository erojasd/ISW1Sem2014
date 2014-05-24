#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*______________________________________________________________________________________________________________________________________________________________________*/

int main(void)
{
FILE *ParteUno, *ParteDos;

ParteUno = fopen("p1.txt","r");
ParteDos = fopen("p2.txt","r");
if(ParteUno == NULL || ParteDos == NULL) exit(1);
/*Recorrer el archivo*/

while (feof(ParteUno) == 0 || feof(ParteDos) == 0)
{

}

}
