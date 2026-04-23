#include <stdio.h>
#include <stdlib.h>
#include "encabezado.h"
#define pi 3.14159

float round_(float n){
    if ((n-(int)(n))>= 0.5)
        return (int)(n)+1.0;
    else
        return (float)((int)(n));
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
    *tam = 0;
    for (int x = x_min; x <= x_max; x++) {
        lista[*tam].x = x;
        lista[*tam].y = (int)(round_(sin(x/(float)(escala_y)) * escala_y));
        lista[*tam].letra = c;
        (*tam)++;
    }
void fcoseno(struct point lista[], int *tam, int x_min, int x_max, float escala_y, char c) {

    tam = 0;

    for (int x = x_min; x <= x_max; x++) {

        lista[tam].x = x;

        lista[tam].y = (int)(round_(cos(x / (float)(escala_y)) escala_y));

        lista[tam].letra = c;

        (tam)++;

    }

}
} //liberar memoria en main











