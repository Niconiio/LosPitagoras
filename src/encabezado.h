#include<iostream>
#include<string>
#include<vector>
#include <cstdlib>
#define pi 3.14159



extern int escala_y;
extern int x_min, x_max, y_min, y_max;
extern int tamano;

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

//Suma las ultimas 3 funciones
    void sumar3_funciones_graficar(){

      std::vector<int> A = {funciones[funciones.size()-1].dom[0], funciones[funciones.size()-1].dom[1]};
      std::vector<int> B = {funciones[funciones.size()-2].dom[0], funciones[funciones.size()-2].dom[1]};
      std::vector<int> C = {funciones[funciones.size()-3].dom[0], funciones[funciones.size()-3].dom[1]};
      if (funciones.size()>=3 && (A==B && A == C) && funciones[funciones.size()-1].grafico.size() == funciones[funciones.size()-2].grafico.size() && funciones[funciones.size()-2].grafico.size() == funciones[funciones.size()-3].grafico.size()){
          int y;
          int x;
          int min = 999;
          int max = -999;
          std::vector<std::vector<int>> temp = {};
          for (int i = 0; i < funciones[funciones.size()-1].grafico.size(); i++){
            x=funciones[funciones.size()-1].grafico[i][0];
            y=funciones[funciones.size()-1].grafico[i][1]+funciones[funciones.size()-2].grafico[i][1] + funciones[funciones.size()-3].grafico[i][1];
            temp.push_back({x,y});
            if (y>max){max = y;}
            if (y<min){min = y;}}
          graf_xy(temp, temp.size(), max, min, funciones[funciones.size()-1].dom[1], funciones[funciones.size()-1].dom[0], relleno, funciones[funciones.size()-1].punto);
          }else{std::cout<<"Suma imposible, las funciones tienen dominios distintos o hay menos de 3 funciones"<<std::endl;}
        }

    void add_funcion(funcion A){funciones.push_back(A);} //Pasa por valor una función
    
    graf(int y_max, int y_min,int  x_max, int x_min, char relleno): relleno(relleno){
      rec[0] = y_min; rec[1] = y_max; dom[0] = x_min; dom[1] = x_max;}
    
    void graficar(){
    graf_xy(grafico_final, tam_graf_final, rec[1], rec[0], dom[1], dom[0], relleno, funciones[target].punto);} //grafica el ultimo, si o si se ejecuta despues de tener todo listo
  
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

void circle_u(float x, float y);

void fcoseno(struct point lista[], int *tam, int x_min, int x_max, float escala_y, char c);
void fseno(struct point lista[], int *tam, int x_min, int x_max, float escala_y, char c);
void ftan(struct point lista[], int *tam, int x_min, int x_max, float escala_y, char c);
float round_(float n);
void anguloentrecatetos(float x, float y);

















