#include <iostream>
#include <string>
#include "encabezado.h"
#include <cmath>
//#include <stdio.h>
#include <stdlib.h>
using std::cout;

int escala_y= 5;
float x;
float y;

float round_(float n){
    if ((n -(int) n)>= 0.5)
        return (int) n +1.0;
    else
        return (float)((int) n);
}
void anguloentrecatetos(float x, float y){
    float angulohipad;
    float angulohipop;
    float tang= (y/x);
    angulohipop=atan2(y,x);
    angulohipad=((pi/2) - angulohipop);
    cout<<"El angulo formado por la hipotenusa y el cateto adyacente es " <<angulohipad<<"radianes\n";
	cout<<"El angulo formado por la hipotenusa y el cateto opuesto es "<<angulohipop<<"radianes\n";
}
void circle_u(float x, float y){

    /*Gracias a su simplicidad, el código de grax_xy permite graficar conjuntos cambiando las condicionales,
     *    basandose en eso, modificando algunas condicionales y reutilizando parte del código,
     *    es posible dibujar formas en el plano sin tanto esfuerzo y con un poco de creatividad.
     *    Esta es una modificación de graf_xy hecha exclusivamente para representar un punto en el circulo unitario.
     *
     */

    //Utilizamos la función round_ y casting, para redondear al entero mas cercano.
    int x_ =(int)(round_(x*12));
    int y_ = (int)(round_(y*12));

    //Ambos ciclos for recorren las coordenadas tales filas de una matriz, pero j va de mayor a menor
    for (int j = 20; j >= -20;j--){
        for (int i = -20; i <= 20;i++){
            //El punto tiene prioridad sobre cualquier elemento del grafico, por eso se imprime primero
            if(x_ == i && y_ == j)
                cout<<"O ";
            else{
                //Si no es el punto, entonces grafica el resto.
                //Las condicionales, son conjuntos en R^2, hechos con fines esteticos para mostrar el seno y el coseno como componentes del punto
                //Recta coseno al punto desde el origen
                if (x_ < 0 && j == 0 && i >= x_ && i<=0)
                    cout<<"c ";
                else if (x_ > 0 && j == 0 && i <= x_ && i>=0)
                    cout<<"c ";
                //Recta seno al punto desde el origen
                else if (y_ > 0 && i == x_ && j <= y_ && j>0)
                    cout<<"s ";
                else if (y_ < 0 && i == x_ && j >= y_ && j<0)
                    cout<<"s ";
                else{
                    //Conjunto en R^2 que representa de un circunferencia rellena de radio 12 centrada en el origen del plano
                    if((i*i + j*j)<= 144){
                        cout<<". ";
                        //Complemento de este conjunto
                    }else
                        cout<<"  ";
                }
            }
            //Espacios entre filas
        }
        cout<<"\n";
    }
}
//Podria optimizar esta funcion 
void graf_xy(std::vector<std::vector<int>> lista, int tam_lista,int y_max, int y_min, int  x_max, int x_min, char relleno, char letra){
    char signo;
    int a;
    //Soluciona errores de input del usuario.
    if (y_min > y_max){
        a = y_min;
        y_min = y_max;
        y_max = a;
    }
    if (x_min > x_max){
        a = x_min;
        x_min = x_max;
        x_max = a;
    }
    for (int i = y_max; i >= y_min; i--){
        if (i < 0)
            signo = '-';
        else
            signo = '+';      
        //Muestra el Eje de las ordenadas (Y) con los números, determina el espaciado entre los numeros y el eje.
        //Se requiere generalizar para todo orden de magnitud, hasta ahora, el eje Y no distorcionará el grafico, siempre y cuando |y_max| < 1000
        if (abs(y_max) >= 100){
            if (abs(i) >= 100)
                cout<<signo<<abs(i)<<"||  ";
            else if (abs(i) >= 10)
                cout<<signo<<abs(i)<<" ||  ";
            else 
                cout<<signo<<abs(i)<<"  ||  ";
        } else if (abs(y_max) >= 10){
            if (abs(i) >= 10)
                cout<<signo<<abs(i)<<"||  ";
            else 
                cout<<signo<<abs(i)<<" ||  ";
        } else {                
            if (abs(i) >= 100)
                cout<<signo<<abs(i)<<"||  ";
            else if (abs(i) >= 10)
                cout<<signo<<abs(i)<<" ||  ";
            else 
                cout<<signo<<abs(i)<<"  ||  ";
        }
        int j;
        //Ubica puntos en eje x, rellena el grafico y crea eje x
        for (int j = x_min; j <= x_max; j++){    
            int fill = 1; //Flag de impresión
            //Recorre el array, imprime el punto si coincide la posición, si esto pasa ademas fill = 0.
            for (int ind = 0; ind < tam_lista; ind++){

                if (lista[ind][0] == j && lista[ind][1] == i){
                    cout<<letra;
                    fill = 0;
                }
            }
            //Si no encontró ningun punto, imprime relleno o Eje x
            if (fill == 1)
                if (i!= 0)
                    cout<<relleno;
            //Si y= 0, imprime caracter de eje x
                else
                    if (i == 0 && j == 0)
                        cout<<"0  ";
                    else
                        cout<<"=  ";
        }
    cout<<"\n";
    }
}
//Seguramente deba usar un puntero, para esto, porque retorna el primer elemento del puntero


void fseno(struct point lista[], int *tam, int x_min, int x_max, float escala_y, char c) {
    tam = 0; //tamaño de la lista e indice para el for
    for (int x = x_min; x <= x_max; x++) {
        lista[*tam].x = x;
        lista[*tam].y = (int)(round_(sin(x/(float)(escala_y)) * escala_y));
        lista[*tam].letra = c;
        (*tam)++;
    }

}
void fcoseno(struct point lista[], int *tam, int x_min, int x_max, float escala_y, char c) {

    tam = 0; //tamaño de la lista e indice para el for

    for (int x = x_min; x <= x_max; x++) {

        lista[*tam].x = x;

        lista[*tam].y = (int)(round_(cos(x / (float)(escala_y)) * escala_y));

        lista[*tam].letra = c;

        (*tam)++;

    }

}

void ftan(struct point lista[], int *tam, int x_min, int x_max, float escala_y, char c){

    tam = 0; //tamaño de la lista e indice para el for

        for (int x = x_min; x <= x_max; x++){

            if ((pi)/2 % x != 0){    //se debe verificar las asintotas (multiplos de pi/2)
        
            lista[*tam].x = x;

            lista[*tam].y = (int)(round_(tan(x / (float)(escala_y)) * escala_y));

            lista[*tam].letra = c;

            (*tam)++;

            };
        }
}

