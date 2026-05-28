#include<iostream>
#include<string>
#include "encabezado.h"
#include <stdio.h>
#include <math.h>




std::vector<std::vector<int>> cuadratic(std::vector<std::vector<int>> lista, int x_min, int x_max, float escala_y){
    std::vector<std::vector<int>> b; 
    //b = lista;
    lista = {};
    std::vector<int> temp = {};
    for (int x = x_min; x <= x_max; x++) {
        temp.push_back(x);
        temp.push_back((int)round_(x*x));
        lista.push_back(temp);
        temp = {};}

    return lista;}

class cuadratica: public funcion{
  public:
    cuadratica(int x_min, int x_max, int escala_y, char p){
      punto = p; dom[0] = x_min; dom[1] = x_max; escala = escala_y;}
      void funcion_(){
        grafico = cuadratic(grafico, dom[0], dom[1], escala_y); tam_graf = grafico.size();}
};


int main(){
    cuadratica B(-5, 5, 6, 'o');
    B.funcion_();
    graf X(20, -20, 20,0,'-');
    X.add_funcion(B);
    X.add_funcion(B);
    X.add_funcion(B);
    X.sumar3_funciones_graficar();
    return 0;
}