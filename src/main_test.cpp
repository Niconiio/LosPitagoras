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

//graf(int y_max, int y_min,int  x_max, int x_min, char relleno)
int main(){
    //Prueba del seno
    sinusoidal B(-20, 20, 9,9,9,'o', "Seno", 1);
    B.funcion_(); 
    graf X(20, -20, -20,20,'-');
    X.select_funcion(&B);
    X.graficar();
    return 0;
}