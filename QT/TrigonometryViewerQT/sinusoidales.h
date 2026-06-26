#include<stdlib.h>
#include<string>
#include<vector>
#include <cmath>
#include <iostream>

#define pi 3.14159

void graf_xy(std::vector<std::vector<int>> lista, int tam,int y_max, int y_min, int  x_max, int x_min, char relleno, char letra);

class funcion{
  protected:
    int tam_graf;
  public:
    std::string nombre;
    char punto;

    std::vector<std::vector<float>> grafico;
};

class sinusoidal: public funcion{
    float A, B, C;

  public:
    int tipo;
    float rec[2];
    float dom[2];
    int get_tipo(){return tipo;}
    void set_A(float A_){A = A_;}
    void set_B(float B_){B = B_;}
    void set_C(float C_){C = C_;}
    void set_tipo(int eleccion){tipo = eleccion;}
    sinusoidal(){A = 1; B = 1; C = 0; tipo = 1;}
    sinusoidal(int x_min, int x_max, int A_, int B_, int C_, char p, std::string nombre_, int tipo_);
    void cos_sen();
};

void anguloentrecatetos(float x, float y);

















