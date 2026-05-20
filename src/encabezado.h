#include<stdlib.h>
#include<string>
#define pi 3.14159

#ifndef encabezado_h
#define encabezado_h

extern int escala_y;
extern int x_min, x_max, y_min, y_max;
extern int tamano;


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















