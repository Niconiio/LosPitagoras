#include <iostream>
#include <string>
#include "encabezado.h"
#include <math.h>

#include <stdio.h>
#include <stdlib.h>


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
    printf("El angulo formado por la hipotenusa y el cateto adyacente es %f radianes\n", angulohipad);
	printf("El angulo formado por la hipotenusa y el cateto opuesto es %f radianes", angulohipop);

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
                printf("O ");
            else{
                //Si no es el punto, entonces grafica el resto.

                //Las condicionales, son conjuntos en R^2, hechos con fines esteticos para mostrar el seno y el coseno como componentes del punto
                //Recta coseno al punto desde el origen
                if (x_ < 0 && j == 0 && i >= x_ && i<=0)
                    printf("c ");
                else if (x_ > 0 && j == 0 && i <= x_ && i>=0)
                    printf("c ");

                //Recta seno al punto desde el origen
                else if (y_ > 0 && i == x_ && j <= y_ && j>0)
                    printf("s ");
                else if (y_ < 0 && i == x_ && j >= y_ && j<0)
                    printf("s ");

                else{

                    //Conjunto en R^2 que representa de un circunferencia rellena de radio 12 centrada en el origen del plano
                    if((i*i + j*j)<= 144){
                        printf(". ");
                        //Complemento de este conjunto
                    }else
                        printf("  ");
                }


            }
            //Espacios entre filas

        }
        printf("\n");
    }
}


void graf_xy(struct point lista[], int tam,int y_max, int y_min, int  x_max, int x_min, char relleno){
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
                printf("%c%d||  ", signo, abs(i));
            else if (abs(i) >= 10)
                printf("%c%d ||  ", signo, abs(i));
            else 
                printf("%c%d  ||  ", signo, abs(i));
        } else if (abs(y_max) >= 10){
            if (abs(i) >= 10)
                printf("%c%d||  ",signo, abs(i));
            else 
                printf("%c%d ||  ",signo, abs(i));
        } else {                
            if (abs(i) >= 100)
                printf("%c%d||  ", signo, abs(i));
            else if (abs(i) >= 10)
                printf("%c%d ||  ", signo, abs(i));
            else 
                printf("%c%d  ||  ", signo, abs(i));
        }
        int j;
        //Ubica puntos en eje x, rellena el grafico y crea eje x
        for (int j = x_min; j <= x_max; j++){

            
            int fill = 1; //Flag de impresión
            //Recorre el array, imprime el punto si coincide la posición, si esto pasa ademas fill = 0.
            for (int ind = 0; ind < tam; ind++){
                if (lista[ind].x == j && lista[ind].y == i){
                    printf("%c  ", lista[ind].letra);
                    fill = 0;
                    
                }
            }
            //Si no encontró ningun punto, imprime relleno o Eje x
            if (fill == 1)
                if (i!= 0)
                    printf("%c  ",relleno);
            //Si y= 0, imprime caracter de eje x
                else
                    if (i == 0 && j == 0)
                        printf("0  ");
                    else
                        printf("=  ");
    /*
            Idea descartada: No es posible mostrar numeros en el eje x sin deformar el grafico, se desea una solución alternativa.
                if (i != 0)
                    printf("%c  ",relleno);
                else
                    printf("%d  ", j);
    */        
        }
    printf("\n");
    }
}

void fseno(struct point lista[], int *tam, int x_min, int x_max, float escala_y, char c) {
    *tam = 0; //tamaño de la lista e indice para el for
    for (int x = x_min; x <= x_max; x++) {
        lista[*tam].x = x;
        lista[*tam].y = (int)(round_(sin(x/(float)(escala_y)) * escala_y));
        lista[*tam].letra = c;
        (*tam)++;
    }

}
void fcoseno(struct point lista[], int *tam, int x_min, int x_max, float escala_y, char c) {

    *tam = 0; //tamaño de la lista e indice para el for

    for (int x = x_min; x <= x_max; x++) {
        lista[*tam].x = x;

        lista[*tam].y = (int)(round_(cos(x / (float)(escala_y)) * escala_y));

        lista[*tam].letra = c;

        (*tam)++;

    }

}












