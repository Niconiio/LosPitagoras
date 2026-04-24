#include <stdio.h>
#include "encabezado.h"


int main(){
  int opcion;
  int x_min;
  int x_max;
  int y_min;
  int y_max;
  char c='c';
  struct circulo_u;
  float x;
  float y;

//Grafica el seno, el coseno, y el circulo unitario.
  do{
    printf("Seleccione que desea visualizar\n");//el usuario debe ingresar el numero correspondiente a la accion que desea realizar
    printf("1)Funcion seno\n");
    printf("2)Funcion coseno\n");
    printf("3)Visualizacion en el circulo unitario a partir de dos catetos\n");
    printf("0)Salir\n");
    printf("Opcion:\n");
    scanf("%d",&opcion);
    if (opcion ==1){
      printf("ingrese el rango de visualizacion con un x minimo y un x_ maximo ");
      scanf("%d %d",&x_min, &x_max);
      printf("ahora ingrese y minimo e y maximo ");
      scanf("%d %d",&y_min, &y_max);

      int tamano = x_max - x_min + 1; //se define el tamaño de la lista
      int tam;
      struct point lista[tamano];

      fseno(lista, tam, x_min, x_max, escala_y,c);
    }
    else if(opcion==2){
      printf("ingrese el rango de visualizacion con un x minimo y un x maximo ");
      scanf("%d %d",&x_min, &x_max);
      printf("ahora ingrese y minimo e y maximo ");
      scanf("%d %d",&y_min, &y_max);

      int tamano = x_max - x_min + 1;
      int tam;
      struct point lista[tamano];

      fcoseno(lista, tam, x_min, x_max, escala_y,c);
    }
    else if(opcion==3){

      printf("Indique cual es el largo del primer cateto x");
      scanf("%f",&x);
      printf("Indique cual es el largo del segundo cateto y" );
      scanf("%f", &y);
      circle_u(x, y);
      anguloentrecatetos(x,y);
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
