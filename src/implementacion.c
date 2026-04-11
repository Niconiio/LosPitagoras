#include <stdio.h>
#include "encabezado.h"


//Yeremi Rodríguez

/*
Ejemplo de uso:

GRAFICA LA FUNCIÓN x = y
--------------------------------------------------------------------------------
#include <stdio.h>
#include "encabezado.h"
#include <math.h>

int main(){
//Grafica el seno, el coseno, y el circulo unitario.

int n = 11;
char re = '-';
int y_ma = 10;
int y_mi = -10;
int x_mi = 0;
int x_ma = 10;
struct point prueba[n];

for (int i = 0; i < n; i++){
  //función x = y
  prueba[i].x = i;
  prueba[i].y = i;
  prueba[i].letra = '@';
}

graf_xy(prueba, n, y_ma, y_mi,  x_ma,  x_mi, re);

  return 0;
}





-  -  -  -  -  -  -  -  -  -  @  
-  -  -  -  -  -  -  -  -  @  -
-  -  -  -  -  -  -  -  @  -  -
-  -  -  -  -  -  -  @  -  -  -
-  -  -  -  -  -  @  -  -  -  -
-  -  -  -  -  @  -  -  -  -  -
-  -  -  -  @  -  -  -  -  -  -
-  -  -  @  -  -  -  -  -  -  -
-  -  @  -  -  -  -  -  -  -  -
-  @  -  -  -  -  -  -  -  -  -
@  -  -  -  -  -  -  -  -  -  -
-  -  -  -  -  -  -  -  -  -  -
-  -  -  -  -  -  -  -  -  -  -
-  -  -  -  -  -  -  -  -  -  -
-  -  -  -  -  -  -  -  -  -  -
-  -  -  -  -  -  -  -  -  -  -
-  -  -  -  -  -  -  -  -  -  -
-  -  -  -  -  -  -  -  -  -  -
-  -  -  -  -  -  -  -  -  -  -
-  -  -  -  -  -  -  -  -  -  -
-  -  -  -  -  -  -  -  -  -  -
----------------------------------------------------------------------------------
*/





//para una cantidad de puntos muy pequeños
void graf_xy(struct point lista[], int tam,int y_max, int y_min, int  x_max, int x_min, char relleno){
//Utiliza indices similareas a los de un matriz, pero las filas se cuentan desde mayor a menor
    int i = y_max; //Filas, eje y
    int j = x_min; //Columnas eje x
    int fill;

    char re = '-';
//y
    for (int i = y_max; i >= y_min; i--){
        //x
        for (int j = x_min; j <= x_max; j++){
            fill = 1;
            //Busqueda
            for (int ind = 0; ind < tam; ind ++){
                if (lista[ind].x == j && lista[ind].y == i){
                    printf("%c  ", lista[ind].letra);
                    fill = 0;}}
            if (fill == 1)
                if (j == 0)
                    printf("%d ", i);
                else
                    printf("%c  ",re);
    }  
        printf("\n");
    }

}







//Para una cantudad de puntos grandes, es posible recorrer de forma procedural











