#include<stdlib.h>
#include<string>
#include<vector>
//#include <cstdlib>
#include <iostream>

#define pi 3.14159

//#ifndef encabezado_h
//#define encabezado_h

extern int escala_y;
extern int x_min, x_max, y_min, y_max;
extern int tamano;


void graf_xy(std::vector<std::vector<int>> lista, int tam,int y_max, int y_min, int  x_max, int x_min, char relleno, char letra);
std::vector<std::vector<int>> cos_sen(std::vector<std::vector<int>> lista, int x_min, int x_max, int A, int B, int C, int tipo);



class funcion{
  protected:
    int rec[2] = {0,0};
    int escala;
    int tam_graf;
  public:
    std::string nombre;
    char punto;
    int dom[2] = {0,0};
    std::vector<std::vector<int>> grafico;
    int Show_Tam(){tam_graf = grafico.size();return grafico.size();};
    virtual void funcion_(){};
};


class sinusoidal: public funcion{
  int A;
  int B;
  int C;
  int tipo;
  public:
    sinusoidal(int x_min, int x_max, int A_, int B_, int C_, char p, std::string nombre_, int tipo_){
      punto = p; dom[0] = x_min; dom[1] = x_max; A = A_; B = B_; C = C_; nombre = nombre_; int tipo = tipo_;}
      void funcion_(){
        grafico = cos_sen(grafico, dom[0], dom[1], A,B,C, tipo); tam_graf = grafico.size();}
};



void sumar3_funciones_graficar(funcion fA, funcion fB, funcion fC, std::vector<funcion> funciones, char relleno);

class graf{
  protected: 
    std::vector<std::vector<int>> grafico_final; 
    int dom[2] = {0,0};
    int rec[2] = {0,0};
    char relleno;
    funcion* funcion_objetivo;
    int SI_funcion = 0;
    int tam_graf_final;
    std::string nombre_grafico;
    std::string nombre_funcion;
  public:  
    graf(int y_max, int y_min,int  x_max, int x_min, char relleno): relleno(relleno){//int y_max, int y_min,int  x_max, int x_min, char relleno
      rec[0] = y_min; rec[1] = y_max; dom[0] = x_min; dom[1] = x_max;}
    void select_funcion(funcion* A){SI_funcion = 1; funcion_objetivo = A; grafico_final = A->grafico; tam_graf_final = A->grafico.size(); nombre_funcion = A->nombre;} 
    void graficar(){     
    if (SI_funcion){  
    std::cout<< "Grafico de " << nombre_funcion <<std::endl<<std::endl;
    graf_xy(grafico_final, tam_graf_final, rec[1], rec[0], dom[1], dom[0], relleno, funcion_objetivo->punto);
    }else{std::cout<<"No hay ninguna funciòn almacenada dentro del grafico"<<std::endl;}}
};

struct point{
  int x;
  int y;
  char letra;
};

class Seno: public funcion{

    public:
      void fseno(struct point lista[], int tam, int x_min, int x_max, float escala_y, char c);
};

class Coseno: public funcion{
  
    public:
      void fcoseno(struct point lista[], int tam, int x_min, int x_max, float escala_y, char c);
};

class Tangente: public funcion{

    public:
      void ftan(struct point lista[], int *tam, int x_min, int x_max, float escala_y, char c);
};
//Prototipos que se implementan en implementacion.c


void circle_u(float x, float y);

void fcoseno(struct point lista[], int *tam, int x_min, int x_max, float escala_y, char c);
void fseno(struct point lista[], int *tam, int x_min, int x_max, float escala_y, char c);
void ftan(struct point lista[], int *tam, int x_min, int x_max, float escala_y, char c);
float round_(float n);
void anguloentrecatetos(float x, float y);
//float abs1(float n);
//float aprox_y(float y, float step);


//#endif















