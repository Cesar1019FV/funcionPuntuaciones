#include<stdio.h>
#include<stdlib.h>
#include "puntajes.h"

/*
- recibe el nombre del ganador +++
- crea el archivo de puntuaciones y lo abre +++
- incertar el nombre y los intentos +++
- algoritmo burbuja para acomodar puntuaciones ++
- se cierra el documento
*/
//imprimir en programa: [Jugador]   [Cantidad de intentos]

void puntajes(char ganador[], int intentos) {
  FILE *puntajes = fopen("puntajes.txt", "a+");
  
  if(!puntajes){
    printf("No he podido abrir el archivo");
    return 1;
  }

  fprintf(puntajes, "%s %d\n", ganador, intentos);
  
  fclose(puntajes);
}

    char name[50][1024];
    int intentos[20];


void ordenamiento()
{
    FILE *fp = fopen("puntajes.txt","r");;
    int i=0,size,j,swap;
    char ch; 
  
    if(fp==NULL)
    { 
    printf("\n No he podido abrir el archivo \n");
    exit(0);
    }
    while(ch!=EOF)
    {
    fscanf(fp,"%s %d",&name[i][i],&intentos[i]);  
    ch=fgetc(fp); 
    i++;
    } 
    size=i-1;
    for(i=1;i<size;++i){
      for(j=0;j<size-i;j++){
        if(intentos[j+1]<intentos[j]){

            swap    = intentos[j];
            intentos[j]   = intentos[j+1];
            intentos[j+1] = swap;

            swap      = name[i][i];
            name[i][i]   = name[i+1][i+1];
            name[i+1][i+1] = swap;
        }
      }
    }  
    fp=fopen("sortedRecord.txt","w");
    for(i=0;i<10;i++){
      fprintf(fp,"%s %d \n",&name[i][i],intentos[i]);
      printf ("%s %d \n", &name[i][i],intentos[i]); 
    }
    fclose(fp); 
}
