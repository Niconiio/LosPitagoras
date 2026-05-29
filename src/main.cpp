#include<iostream>
#include "encabezado.h"
using std::cout;
using std::cin;
#include <cmath>


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

    cout<<"\n\nSeleccione que desea visualizar \n"; //el usuario debe ingresar el numero correspondiente a la accion que desea realizar
    cout<<"\n1)Funcion seno\n";
    cout<<"2)Funcion coseno\n";
    cout<<"3)Visualizacion en el circulo unitario a partir de dos catetos\n";
    cout<<"0)Salir\n";
    cout<<"\nOpcion:\n";
     cin>>opcion;

    switch (opcion){
      case 1:{
        cout<<"ingrese el rango de visualizacion con un x minimo y un x_ maximo: ";
         cin>>x_min >>x_max;
        cout<<"ahora ingrese y minimo e y maximo: ";
         cin>>y_min >>y_max;

        int tamano = abs(x_max - x_min) + 1; //se define el tamaño de la lista
        int tam;
        struct point lista[tamano];

        fseno(lista, &tam, x_min, x_max, escala_y,c);
		graf_xy(lista, tam, y_max, y_min, x_max, x_min, '.');
        break;
      }

      case 2:{
        cout<<"ingrese el rango de visualizacion con un x minimo y un x maximo: ";
         cin>>x_min >>x_max;
        cout<<"ahora ingrese y minimo e y maximo: ";
         cin>>y_min >>y_max;

        int tamano = abs(x_max - x_min) + 1;
        int tam;
        struct point lista[tamano];

        fcoseno(lista, &tam, x_min, x_max, escala_y,c);
		graf_xy(lista, tam, y_max, y_min, x_max, x_min, '.');
        break;
      }
      case 3:{
	      cout<<"Seleccione un opción:\n";
	      cout<<"1) Angulo en grados\n";
	      cout<<"2) Angulo en radianes dado por dos catetos\n";
	       cin>>opcion_;
	      if (opcion_ == 1) {
	
		      float angulo;
		      cout<<"Ingrese angulo en grados: ";
		       cin>>angulo;
		      float x= cos((angulo*pi)/180.0);
		      float y= sin((angulo*pi)/180.0);
		      circle_u(x, y);
		      cout<<"\nRepresentación del punto ("<<x<<","<<y<<") dado por"<<angulo<<"° en el circulo unitario\n";
	
	      }else if(opcion_ == 2){
		       cout<<"Indique cual es el largo del primer cateto x: ";
		        cin>>cat1;
		       cout<<"Indique cual es el largo del segundo cateto y: ";
		        cin>>cat2;
		        float angulo= atan2(cat2,cat1);
		        float x= cos(angulo);
		        float y= sin(angulo);
		        circle_u(x, y);
		        anguloentrecatetos(x, y);
	      }
	      else{
	        cout<<"Opcion no admitida\n";
		  }
        break;

      }

      case 0:{
        cout<<"Termino del programa.\n";
        break;
      }

      default:{
        cout<<"Opción no válida.\n";
        break;
      }
    }
  }while (opcion !=0);
  return 0;
}
