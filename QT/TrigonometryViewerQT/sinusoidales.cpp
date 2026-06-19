#include <iostream>
#include "encabezado.h"
#include <cmath>
#include <cstdlib>
#include <vector>
using std::cout;

graf::graf(int y_max, int y_min,int  x_max, int x_min, char relleno): relleno(relleno){//int y_max, int y_min,int  x_max, int x_min, char relleno
      rec[0] = y_min; rec[1] = y_max; dom[0] = x_min; dom[1] = x_max;}


sinusoidal::sinusoidal(int x_min, int x_max, int A_, int B_, int C_, char p, std::string nombre_, int tipo_):tipo(tipo_){
      punto = p; dom[0] = x_min; dom[1] = x_max; A = A_; B = B_; C = C_; nombre = nombre_;}

void graf::select_funcion(funcion* A){SI_funcion = 1; funcion_objetivo = A; grafico_final = A->grafico; tam_graf_final = A->grafico.size(); nombre_funcion = A->nombre;} 

void graf::graficar(){     
    if (SI_funcion){  
    std::cout<< "Grafico de " << nombre_funcion <<std::endl<<std::endl;
    
    graf_xy(grafico_final, tam_graf_final, rec[1], rec[0], dom[1], dom[0], relleno, funcion_objetivo->punto);
    }else{
        std::cout<<"No hay ninguna funciòn almacenada dentro del grafico"<<std::endl;}}

//
void sinusoidal::cos_sen(){
    std::vector<std::vector<int>> temp = {}; 
    int x_min = dom[0]; 
    int x_max = dom[1];
    int seno_x;
    int coseno_x;
    for (int x = x_min; x <= x_max; x++) {
        if ((int)tipo == 1 ){
            seno_x = (int)roundf(A*sin(x/float(B) + C));
            temp.push_back({x, seno_x});
        } else if ((int)tipo == 2){
            coseno_x =  (int)roundf(A*cos(x/float(B) + C));
            temp.push_back({x, coseno_x});
         }  
    } grafico = temp;
}

/*
float round_(float n){
    if ((n -(int) n)>= 0.5)
        return (int) n +1.0;
    else
        return (float)((int) n);
}
*/


void anguloentrecatetos(float x, float y){
    float angulohipad;
    float angulohipop;
    float tang= (y/x);
    angulohipop=atan2(y,x);
    angulohipad=((pi/2) - angulohipop);
    cout<<"El angulo formado por la hipotenusa y el cateto adyacente es " <<angulohipad<<"radianes\n";
	cout<<"El angulo formado por la hipotenusa y el cateto opuesto es "<<angulohipop<<"radianes\n";
}


/*
void sumar3_funciones_graficar(funcion fA, funcion fB, funcion fC, std::vector<funcion> funciones, char relleno){//Las funciones deben tener el mismo dominio para poder graficarse
    
      std::vector<int> A = {fA.dom[0], fA.dom[1]};
      std::vector<int> B = {fB.dom[0], fB.dom[1]};
      std::vector<int> C = {fC.dom[0], fB.dom[1]};
      if (funciones.size()>=3 && (A==B && A == C) && fA.grafico.size() == fB.grafico.size() && fB.grafico.size() == fC.grafico.size()){
          int y;
          int x;
          int min = 999;
          int max = -999;
          std::vector<std::vector<int>> temp = {};
          for (int i = 0; i < fA.grafico.size(); i++){
            x=fA.grafico[i][0];
            y=fA.grafico[i][1]+fB.grafico[i][1] + fC.grafico[i][1];
            temp.push_back({x,y});
            if (y>max){max = y;}
            if (y<min){min = y;}}
          graf_xy(temp, temp.size(), max, min, fA.dom[1], fA.dom[0], relleno, fA.punto);
          }else{std::cout<<"Suma imposible, las funciones tienen dominios distintos o hay menos de 3 funciones"<<std::endl;}
        }
*/
//Se reemplazó circle_u por un metodo, se soluciona error en la función circle_u


void circulo::circle_u(){

    int x_ =(int)(roundf((float)x*radio));
    int y_ = (int)(roundf((float)y*radio));

    //Ambos ciclos for recorren las coordenadas tales filas de una matriz, pero j va de mayor a menor
    for (int j = radio + 8; j >= -(radio+8);j--){
        for (int i = -(radio + 8); i <= (radio + 8);i++){
            if(x_ == i && y_ == j)
                cout<<"O ";
            else{
                //Si no es el punto, entonces grafica el resto.

                //Las condicionales, son conjuntos en R^2, hechos con fines esteticos para mostrar el seno y el coseno como componentes del punto
                //Recta coseno al punto desde el origen
                if (x_ < 0 && j == 0 && i >= x_ && i<=0)
                    cout<<"c ";
                else if (x_ > 0 && j == 0 && i <= x_ && i>=0)
                    cout<<"c ";
                //Recta seno al punto desde el origen
                else if (y_ > 0 && i == x_ && j <= y_ && j>0)
                    cout<<"s ";

                else if (y_ < 0 && i == x_ && j >= y_ && j<0)
                    cout<<"s ";
                else{
                    //Conjunto en R^2 que representa de un circunferencia rellena de radio 12 centrada en el origen del plano
                    if((i*i + j*j)<= radio*radio){
                        cout<<". ";
                        //printf(". ");
                        //Complemento de este conjunto
                    }else
                        cout<<"  ";
                        //printf("  ");
                }
            }
        }
        cout<<std::endl;
    }
}


void graf_xy(std::vector<std::vector<int>> lista, int tam_lista,int y_max, int y_min, int  x_max, int x_min, char relleno, char letra){
    char signo;
    int a;
    //Soluciona errores de input del usuario.
    if (y_min > y_max){
        a = y_min;
        y_min = y_max;
        y_max = a;
    }
    if (x_min > x_max){
        a = x_min;
        x_min = x_max;
        x_max = a;
    }
    for (int i = y_max; i >= y_min; i--){
        if (i < 0)
            signo = '-';
        else
            signo = '+';      
        //Muestra el Eje de las ordenadas (Y) con los números, determina el espaciado entre los numeros y el eje.
        //Se requiere generalizar para todo orden de magnitud, hasta ahora, el eje Y no distorcionará el grafico, siempre y cuando |y_max| < 1000
        if (abs(y_max) >= 100){
            if (abs(i) >= 100)
                std::cout<<signo<<abs(i)<<"||  ";
            else if (abs(i) >= 10)
                std::cout<<signo<<abs(i)<<" ||  ";
            else 
                std::cout<<signo<<abs(i)<<"  ||  ";
        } else if (abs(y_max) >= 10){
            if (abs(i) >= 10)
                std::cout<<signo<<abs(i)<<"||  ";
            else 
                std::cout<<signo<<abs(i)<<" ||  ";
        } else {                
            if (abs(i) >= 100)
                std::cout<<signo<<abs(i)<<"||  ";
            else if (abs(i) >= 10)
                std::cout<<signo<<abs(i)<<" ||  ";
            else
                std::cout<<signo<<abs(i)<<"  ||  "; 
        }
        int j;
        //Ubica puntos en eje x, rellena el grafico y crea eje x
        for (int j = x_min; j <= x_max; j++){    
            int fill = 1; //Flag de impresión
            //Recorre el array, imprime el punto si coincide la posición, si esto pasa ademas fill = 0.
            for (int ind = 0; ind < tam_lista; ind++){

                if (lista[ind][0] == j && lista[ind][1] == i){
                    std::cout<<letra<<"  ";
                    fill = 0;
                }
            }
            //Si no encontró ningun punto, imprime relleno o Eje x
            if (fill == 1)
                if (i!= 0)
                    std::cout<<relleno<<"  ";
            //Si y= 0, imprime caracter de eje x
                else //Caracteristicas del grafico
                    if (i == 0 && j == 0)
                        std::cout<<"0  ";
                    else
                        std::cout<<"=  "; 
        }
    std::cout<<std::endl;
    }
}


