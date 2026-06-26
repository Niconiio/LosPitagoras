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

    for (float x = x_min; x <= x_max; x+=0.05) {
        if ((int)tipo == 1){
            seno_x =(A*sin(x*B + C));
            temp.push_back({x, seno_x});
        } else if ((int)tipo == 2){
            coseno_x =  A*cos(x*float(B) + C);
            temp.push_back({x, coseno_x});
         }  
    } grafico = temp;
}

