#include<stdlib.h>
#include<string>
#include<vector>
#include <cstdlib>
#define pi 3.14159

//#ifndef encabezado_h
//#define encabezado_h

extern int escala_y;
extern int x_min, x_max, y_min, y_max;
extern int tamano;

//std::vector<std::vector<int>> cuadratic(std::vector<std::vector<int>> lista, int x_min, int x_max, float escala_y);
void graf_xy(std::vector<std::vector<int>> lista, int tam,int y_max, int y_min, int  x_max, int x_min, char relleno, char letra);

class funcion{
  protected:
    int rec[2] = {0,0};
    int escala;
    int tam_graf;
  public:
    std::string nombre;
    std::string tipo;
    char punto;
    int dom[2] = {0,0};
    std::vector<std::vector<int>> grafico;
    int Show_Tam(){tam_graf = grafico.size();return grafico.size();};
    virtual void funcion_(){};
};





void sumar3_funciones_graficar(funcion fA, funcion fB, funcion fC, std::vector<funcion> funciones, char relleno);





class graf{
  protected: 
    std::vector<std::vector<int>> grafico_final; //El arreglo de coordenadas que va a graficarse, resultante de una función 
    int dom[2] = {0,0};
    int rec[2] = {0,0};
    char relleno;
    int target; //posicion de la Funcion a graficar
    std::vector<funcion> funciones; //Aquí varias funciones, cuyo grafico en coordenadas, sera enviado a grafico_final usando una interfaz comun mediante el metodo virtual funcion_()
    int tam_graf_final;
  public:  
    std::string nombre;
    graf(int y_max, int y_min,int  x_max, int x_min, char relleno): relleno(relleno){
      rec[0] = y_min; rec[1] = y_max; dom[0] = x_min; dom[1] = x_max;}
    void sumar_ultimas_3_funciones(){sumar3_funciones_graficar(funciones[funciones.size()-1],funciones[funciones.size()-2], funciones[funciones.size()-3], funciones, relleno);}
    void add_funcion(funcion A){funciones.push_back(A);} //Pasa por valor una función al objeto graf
    void graficar(){graf_xy(grafico_final, tam_graf_final, rec[1], rec[0], dom[1], dom[0], relleno, funciones[target].punto);} //grafica el ultimo, si o si se ejecuta despues de tener todo listo
    void add_funcion_graficar(funcion A){funciones.push_back(A); 
    target = funciones.size()-1; 
    grafico_final = funciones[target].grafico; 
    tam_graf_final = grafico_final.size(); graficar();} 
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















