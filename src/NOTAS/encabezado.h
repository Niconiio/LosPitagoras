#include<stdlib.h>
#include<string>
#include<iostream>
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
    int tam_graf; //Su valor debe especificarse en el constructor
  public:
    std::string nombre;
    std::string tipo;
    char punto;
    int dom[2] = {0,0};
    std::vector<std::vector<int>> grafico;
    int Show_Tam(){tam_graf = grafico.size();return grafico.size();};
    //virtual std::vector<std::vector<int>> funcion_() = 0;
    //virtual std::vector<std::vector<int>> funcion_(){};
    virtual void funcion_(){};
};


//class circulo_u{
  //public:
    //float angulo;
    //void graficar(float B){angulo = B; circle_u(cos(B), sin(B));}
//};



//Idea: Imitar El Teorema de Fourier, aprov
//Funcion para sumar senos y cosenos, selecionar cuales sumar y operar entre ellos. 
//Darle nombre a las funciones, y a las graficadoras, aprovechar el vector de funciones y gestionarlas  (interfaz) dentro del objeto para seleccionar cual graficar o sumar
//LAs funciones pasan por valor, no por referencia

//Otros modificadores, metodos que agregen texto al grafico, atrave de su posicion.

//system("clear"); usa esto

class graf{
  protected: 
    std::vector<std::vector<int>> grafico_final; //El arreglo de coordenadas que va a graficarse, resultante de una función 
    int dom[2] = {0,0};
    int rec[2] = {0,0};
    char relleno;
    int target; //posicion de la Funcion a graficar
    std::vector<funcion> funciones; //Aquí varias funciones, cuyo grafico en coordenadas, sera enviado a grafico_final usando una interfaz comun mediante el metodo virtual funcion_()
    int tam_graf_final;
  public:  //Que pasa con tam? 
    std::string nombre;

//Suma las ultimas 3 funciones
    void sumar3_funciones_graficar(){

      std::vector<int> A = {funciones[funciones.size()-1].dom[0], funciones[funciones.size()-1].dom[1]};
      std::vector<int> B = {funciones[funciones.size()-2].dom[0], funciones[funciones.size()-2].dom[1]};
      std::vector<int> C = {funciones[funciones.size()-3].dom[0], funciones[funciones.size()-3].dom[1]};
      //funciones[funciones.size()-1].dom == funciones[funciones.size()-2].dom && funciones[funciones.size()-2].dom == funciones[funciones.size()-3].dom
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

    void add_funcion(funcion A){funciones.push_back(A);} //Pasa por valor  una función
    
    graf(int y_max, int y_min,int  x_max, int x_min, char relleno): relleno(relleno){
      rec[0] = y_min; rec[1] = y_max; dom[0] = x_min; dom[1] = x_max;}
    
    void graficar(){
    graf_xy(grafico_final, tam_graf_final, rec[1], rec[0], dom[1], dom[0], relleno, funciones[target].punto);} //grafica el ultimo, si o si se ejecuta despues de tener todo listo
  
    void add_funcion_graficar(funcion A){funciones.push_back(A); 
    target = funciones.size()-1; 
    grafico_final = funciones[target].grafico; 
    tam_graf_final = grafico_final.size(); graficar();} //Suponiendo que las funciones tienen atributos que estan completos; Esta metodo se utiliza en caso que se quiera graficar la ultima funcion directamente, puede haber otro para operaciones
};



//Espero que en la clase graficadora, pueda hacer interactuar varias funciones y sumarlas entre si, para poder crear ondas raras con senos y cosenos
//La graficadora puede tener su propio vector de puntos de funciones, un vector final el cual grafica la función, resultante de realizar  operaciones entre los otros graficos


//Puedo ordenar de menor a mayor los elementos de un vector apartir del primer elemento de un par en un vector de



//Vector de point
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

//Prototipos que se implementan en implementacion.c


void circle_u(float x, float y);

void fcoseno(struct point lista[], int *tam, int x_min, int x_max, float escala_y, char c);
void fseno(struct point lista[], int *tam, int x_min, int x_max, float escala_y, char c);
float round_(float n);
void anguloentrecatetos(float x, float y);
//float abs1(float n);
//float aprox_y(float y, float step);


//#endif















