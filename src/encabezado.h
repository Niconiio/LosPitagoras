#include<stdlib.h>
#include<string>
#include<vector>
#define pi 3.14159

#ifndef encabezado_h
#define encabezado_h

extern int escala_y;
extern int x_min, x_max, y_min, y_max;
extern int tamano;


class graf{
  protected: 
    std::vector<std::vector<int>> grafico_final;
    int dom[2] = {0,0};
    int rec[2] = {0,0};
    char relleno;
    std::vector<funcion> funciones;
    int tam;
  public:
    graf(int y_max, int y_min,int  x_max, int x_min, char relleno): relleno(relleno){rec[0] = y_min; rec[1] = y_max; dom[0] = x_min; dom[1] = x_max;}
    void add_funcion(funcion A){funciones.push_back(A);}
   // void a(){graf_xy(struct point lista[], int tam,int y_max, int y_min, int  x_max, int x_min, char relleno)} //Usar la función, y luego aplicarla
};


class funcion{
  protected:
    int dom[2] = {0,0};
    int rec[2] = {0,0};
    char punto;
    int escala;
    std::vector<std::vector<int>> grafico;
    int tam_graf;
  public:
    int Show_Tam(){tam_graf = grafico.size();return grafico.size();};
    //virtual std::vector<std::vector<int>> funcion_() = 0;
    virtual std::vector<std::vector<int>> funcion_();
};

//Espero que en la clase graficadora, pueda hacer interactuar varias funciones y sumarlas entre si, para poder crear ondas raras con senos y cosenos
//La graficadora puede tener su propio vector de puntos de funciones, un vector final el cual grafica la función, resultante de realizar  operaciones entre los otros graficos

//Gemini que es pair en C++
//Puedo ordenar de menor a mayor los elementos de un vector apartir del primer elemento de un par en un vector de



//Vector de point
struct point{
  int x;
  int y;
  char letra;
};


//Prototipos que se implementan en implementacion.c

void circle_u(float x, float y);
void graf_xy(struct point lista[], int tam,int y_max, int y_min, int  x_max, int x_min, char relleno);
void fcoseno(struct point lista[], int *tam, int x_min, int x_max, float escala_y, char c);
void fseno(struct point lista[], int *tam, int x_min, int x_max, float escala_y, char c);
float round_(float n);
void anguloentrecatetos(float x, float y);
//float abs1(float n);
//float aprox_y(float y, float step);


#endif















