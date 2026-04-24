#include <stdio.h>
#include "encabezado.h"
#include <math.h>


int main(){
  int opcion;
  int x_min;
  int x_max;
  int y_min;
  int y_max;
  char c='G';
  struct circulo_u;
  float cat1;
  float cat2;

//Grafica el seno, el coseno, y el circulo unitario.
  do{
    printf("\nSeleccione que desea visualizar\n");//el usuario debe ingresar el numero correspondiente a la accion que desea realizar
    printf("1)Funcion seno\n");
    printf("2)Funcion coseno\n");
    printf("3)Visualizacion en el circulo unitario a partir de dos catetos\n");
    printf("0)Salir\n");
    printf("Opcion:\n");
    scanf("%d",&opcion);

    switch (opcion){
      case 1:{
        printf("ingrese el rango de visualizacion con un x minimo y un x_ maximo: ");
        scanf("%d %d",&x_min, &x_max);
        printf("ahora ingrese y minimo e y maximo: ");
        scanf("%d %d",&y_min, &y_max);

        int tamano = abs(x_max - x_min) + 1; //se define el tamaño de la lista
        int tam;
        struct point lista[tamano];

        fseno(lista, &tam, x_min, x_max, escala_y,c);
		graf_xy(lista, tam, y_max, y_min, x_max, x_min, '.');
        break;
      }

      case 2:{
        printf("ingrese el rango de visualizacion con un x minimo y un x maximo: ");
        scanf("%d %d",&x_min, &x_max);
        printf("ahora ingrese y minimo e y maximo: ");
        scanf("%d %d",&y_min, &y_max);

        int tamano = abs(x_max - x_min) + 1;
        int tam;
        struct point lista[tamano];

        fcoseno(lista, &tam, x_min, x_max, escala_y,c);
		graf_xy(lista, tam, y_max, y_min, x_max, x_min, '.');
        break;
      }
      case 3:{
        printf("Indique cual es el largo del primer cateto x: ");
        scanf("%f",&cat1);
        printf("Indique cual es el largo del segundo cateto y: " );
        scanf("%f", &cat2);

        float angulo= atan2(cat2,cat1);
        float x= cos(angulo);
        float y= sin(angulo);
        circle_u(x, y);
        anguloentrecatetos(x, y);
        break;

      }

      case 0:{
        printf("Termino del programa.\n");
        break;
      }

      default:{
        printf("Opción no válida.\n");
        break;
      }
    }
  }while (opcion !=0);
  return 0;
}
