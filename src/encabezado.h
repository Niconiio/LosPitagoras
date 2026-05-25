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
    int dom[2] = {0,0};
    int rec[2] = {0,0};
    int escala;
    int tam_graf; //Su valor debe especificarse en el constructor
  public:
    std::string nombre;
    char punto;
    std::vector<std::vector<int>> grafico;
    int Show_Tam(){tam_graf = grafico.size();return grafico.size();};
    //virtual std::vector<std::vector<int>> funcion_() = 0;
    //virtual std::vector<std::vector<int>> funcion_(){};
    virtual void funcion_(){};
};



//Idea: Imitar El Teorema de Fourier, aprov
//Funcion para sumar senos y cosenos, selecionar cuales sumar y operar entre ellos. 
//Darle nombre a las funciones, y a las graficadoras, aprovechar el vector de funciones y gestionarlas  (interfaz) dentro del objeto para seleccionar cual graficar o sumar
//LAs funciones pasan por valor, no por referencia

//Otros modificadores, metodos que agregen texto al grafico, atrave de su posicion.



class graf{
  protected: 
    std::vector<std::vector<int>> grafico_final; //El arreglo de coordenadas que va a graficarse, resultante de una función 
    int dom[2] = {0,0};
    int rec[2] = {0,0};
    char relleno;
    int target; //posicion de la Funcion a graficar
    std::vector<funcion*> funciones; //Aquí varias funciones, cuyo grafico en coordenadas, sera enviado a grafico_final usando una interfaz comun mediante el metodo virtual funcion_()
    int tam_graf_final;
  public:  //Que pasa con tam? 
    std::string nombre;

    void add_funcion(funcion A){funciones.push_back(&A);}; //Ahora almacena las funciones por referencia
    
    graf(int y_max, int y_min,int  x_max, int x_min, char relleno): relleno(relleno){
      rec[0] = y_min; rec[1] = y_max; dom[0] = x_min; dom[1] = x_max;}
    
    void graficar(){
    graf_xy(grafico_final, tam_graf_final, rec[1], rec[0], dom[1], dom[0], relleno, funciones[target]->punto);} //grafica el ultimo, si o si se ejecuta despues de tener todo listo
  
    void add_funcion_graficar(funcion A){funciones.push_back(&A); 
    target = funciones.size()-1; 
    grafico_final = funciones[target]->grafico; 
    tam_graf_final = grafico_final.size(); graficar();} //Suponiendo que las funciones tienen atributos que estan completos; Esta metodo se utiliza en caso que se quiera graficar la ultima funcion directamente, puede haber otro para operaciones
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















