#include <stdio.h>
#include "encabezado.h"
#include <math.h>


int main(){
  int opcion;
  int opcion_;
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
    printf("\n\nSeleccione que desea visualizar\n");//el usuario debe ingresar el numero correspondiente a la accion que desea realizar
    printf("\n1)Funcion seno\n");
    printf("2)Funcion coseno\n");
    printf("3)Visualizacion en el circulo unitario a partir de dos catetos\n");
    printf("0)Salir\n");
    printf("\nOpcion:\n");
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
	      printf("Seleccione un opción:\n");
	      printf("1) Angulo en grados\n");
	      printf("2) Angulo en radianes dado por dos catetos\n");
	
	      scanf("%d",&opcion_);
	      if (opcion_ == 1) {
	
		      float angulo;
		      printf("Ingrese angulo en grados: ");
		      scanf("%f", &angulo);
		      float x= cos((angulo*pi)/180.0);
		      float y= sin((angulo*pi)/180.0);
		      circle_u(x, y);
		      printf("\nRepresentación del punto (%.2f,%.2f) dado por %.2f° en el circulo unitario\n", x,y, angulo);
	
	      }else if(opcion_ == 2){
		        printf("Indique cual es el largo del primer cateto x: ");
		        scanf("%f",&cat1);
		        printf("Indique cual es el largo del segundo cateto y: " );
		        scanf("%f", &cat2);
		        float angulo= atan2(cat2,cat1);
		        float x= cos(angulo);
		        float y= sin(angulo);
		        circle_u(x, y);
		        anguloentrecatetos(x, y);
	      }else{
	        printf("Opcion no admitida\n");
	      }

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
