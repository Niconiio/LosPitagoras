#include <stdio.h>
#include "encabezado.h"
#include <math.h>

int main(){
//Grafica el seno, el coseno, y el circulo unitario.
  int opcion;
  do{
    printf("Seleccione que desea visualizar");
    printf("1)Funcion seno");
    printf("2)Funcion coseno");
    printf("0)Salir");
    printf("Opcion:");
    scanf("%d ",&opcion);
    if (opcion ==1){
      fseno(struct point lista[], int *tam, int x_min, int x_max, float escala_y, char @)
    }
    else if(opcion==2){
      fcoseno(struct point lista[], int *tam, int x_min, int x_max, float escala_y, char @)
    }
    else if (opcion == 0) {
      printf("Termino del programa.\n");
    }
    else {
      printf("Opción no válida.\n");
    }

  }while (opcion >0);
  return 0;
}
