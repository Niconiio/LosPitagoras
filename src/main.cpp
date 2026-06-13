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
  int A, B, C;
  char c='G';
  float cat1;
  float cat2;
//Soluciona un error al graficar el seno y coseno al utilizar round
//Grafica el seno, el coseno, y el circulo unitario.
  do{

    cout<<"\n\nSeleccione que desea visualizar \n"; //el usuario debe ingresar el numero correspondiente a la accion que desea realizar
    cout<<"\n1)Funcion seno\n";
    cout<<"2)Funcion coseno\n";
    cout<<"3)Circulo unitario\n";
    cout<<"0)Salir\n";
    cout<<"\n\nOpcion:\n";
     cin>>opcion;

    switch (opcion){
      case 1:{
        cout <<"\nDefina el area del visualización del grafico:"<<std::endl;
        cout<<"Ingrese desde que valores de x desea mostrar la función seno (x min, x max): "; cin>>x_min >>x_max;
        cout<<"Ingrese desde que valores de y desea mostrar la función seno (y min, y max): "; cin>>y_min >>y_max;
        cout<< "\nDefina los parametros de su función seno"<<std::endl;
        cout<<"A: ";cin>> A;
        cout<<"B: ";cin>> B;
        cout<<"C: ";cin>> C;
    
        if (A== 1 && B == 1 && C == 0){std::cout<<"Su función es una función seno comun no parametrizada"<<std::endl<<std::endl;}
        else{std::cout<<"Su función es una función seno parametrizada, " << A <<"sin("<<B<<"x + "<< C<<")"<<std::endl<<std::endl;}
        std::cout<< "Se graficará el seno desde el intervalo ["<<x_min<<", "<<x_max<<"]"<<" del dominio."<<std::endl<<std::endl; //Nce
        sinusoidal seno_coseno(x_min, x_max, A,B,C,'c',"Seno", 1);
        seno_coseno.cos_sen();
        graf X(x_max, x_min, y_min,y_max,'-');
        X.select_funcion(&seno_coseno);
        X.graficar();
        break;
      }

      case 2:{
        cout <<"\nDefina el area del visualización del grafico:"<<std::endl;
        cout<<"Ingrese desde que valores de x desea mostrar la función coseno (x min, x max): "; cin>>x_min >>x_max;
        cout<<"Ingrese desde que valores de y desea mostrar la función coseno (y min, y max): "; cin>>y_min >>y_max;
        cout<< "\nDefina los parametros de su función coseno"<<std::endl;
        cout<<"A: ";cin>> A;
        cout<<"B: ";cin>> B;
        cout<<"C: ";cin>> C;
        if (A== 1 && B == 1 && C == 0){std::cout<<"Su función es una función coseno comun no parametrizada"<<std::endl;}
        else{std::cout<<"Su función es una función coseno parametrizada, " << A <<"cos("<<B<<"x + "<< C<<")"<<std::endl;}
        std::cout<< "Se graficará el coseno desde el intervalo ["<<x_min<<", "<<x_max<<"]"<<"del dominio."<<std::endl; //Nce
        sinusoidal seno_coseno(x_min, x_max, A,B,C,'c',"Coseno", 2);
        seno_coseno.cos_sen();
        graf X(x_max, x_min, y_min,y_max,'-');
        X.select_funcion(&seno_coseno);
        X.graficar();
        break;
      }
      case 3:{
	      cout<<"Seleccione un opción:\n";
	      cout<<"1) Angulo en grados\n";
	      cout<<"2) Angulo en radianes dado por dos catetos\n";
	       cin>>opcion_;
	      if (opcion_ == 1) {
		      float angulo;
          float radio;
		      cout<<"Ingrese angulo en grados: "; cin>>angulo;
          cout<< "Ingrese el radio: "; cin >> radio;
          circulo N(radio, (angulo*pi)/180.0);
          N.circle_u();
		      float x= cos((angulo*pi)/180.0);
		      float y= sin((angulo*pi)/180.0);
          //circle_u(x,y);
		      cout<<"\nRepresentación del punto ("<<x<<","<<y<<") dado por"<<angulo<<"° en el circulo unitario\n";
	
	      }else if(opcion_ == 2){
          int radio;
          cout<< "Ingrese el radio: "; cin >> radio;
		      cout<<"Indique cual es el largo del primer cateto x: ";
		      cin>>cat1;
		      cout<<"Indique cual es el largo del segundo cateto y: ";
		      cin>>cat2;
		      float angulo= atan2(cat2,cat1);
          circulo N(radio,angulo);
          N.circle_u();
		      float x= cos(angulo);
		      float y= sin(angulo);
          //circle_u(x,y);
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
