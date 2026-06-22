#include<stdlib.h>
#include<string>
#include<vector>
#include <cmath>
//#include <cstdlib>
#include <iostream>

#define pi 3.14159
/*
extern int escala_y;
extern int x_min, x_max, y_min, y_max;
extern int tamano;
*/
/*class circulo{
  int radio;
  //float angulo;
  float x;
  float y;
  //int punto[2];
  public:
    circulo(int R, float B):radio(R){x = cos(B); y = sin(B);}
    void circle_u();
    //void mostrar_Circulo();
};
*/
void graf_xy(std::vector<std::vector<int>> lista, int tam,int y_max, int y_min, int  x_max, int x_min, char relleno, char letra);
//std::vector<std::vector<int>> cos_sen(std::vector<std::vector<int>> lista, int x_min, int x_max, int A, int B, int C, int tipo);

class funcion{
  protected:
    //int escala;
    int tam_graf;
  public:
    std::string nombre;
    char punto;

    std::vector<std::vector<float>> grafico;
    //int Show_Tam(){tam_graf = grafico.size();return grafico.size();};
};

class sinusoidal: public funcion{
    float A, B, C;

     //Tipo 1 seno, tipo 2 coseno
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

//void sumar3_funciones_graficar(funcion fA, funcion fB, funcion fC, std::vector<funcion> funciones, char relleno);

//void circle_u(float x, float y);
//float round_(float n); //Se elimina round_ y se reemplaza por roundf

void anguloentrecatetos(float x, float y);

















