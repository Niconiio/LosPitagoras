#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include "sinusoidales.h"
using std::cout;


sinusoidal::sinusoidal(int x_min, int x_max, int A_, int B_, int C_, char p, std::string nombre_, int tipo_):tipo(tipo_){
      punto = p; dom[0] = x_min; dom[1] = x_max; A = A_; B = B_; C = C_; nombre = nombre_;}

//
void sinusoidal::cos_sen(){
    std::vector<std::vector<float>> temp = {};
    float x_min = dom[0];
    float x_max = dom[1];
    float seno_x;
    float coseno_x;
    for (float x = x_min; x <= x_max; x+=0.1) {
        if ((int)tipo == 1){
            seno_x =(A*sin(x*B + C));
            temp.push_back({x, seno_x});
        } else if ((int)tipo == 2){
            coseno_x =  A*cos(x*float(B) + C);
            temp.push_back({x, coseno_x});
         }  
    } grafico = temp;
}

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



