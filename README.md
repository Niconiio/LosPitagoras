## **Trigonometry Viewer**
### Problemática a solucionar: 
Muchos estudiantes de enseñanza media usan las funciones trigonométricas básicas sin siquiera preguntarse qué significan, de donde vienen y sus posibles aplicaciones.

### Objetivo general del proyecto:
Que los estudiantes de enseñanza media comprendan de una mejor forma lo que significan estas funciones mediante una herramienta didáctica que permita experimentar con ellas, tal que a través de su exploración visualicen y entiendan mejor conceptos de funciones trigonométricas y sus aplicaciones.

### Objetivos específicos del proyecto:
- Crear un programa que muestre graficamente las funciones seno, coseno, tangente y el circulo unitario (Hito 1).
- Crear un producto con un apartado visual más fluido, que permita a los estudiantes de enseñanza media interactuar con estas funciones a través de parámetros (hito 2).
- Relacionar estas funciones trigonométricas con conceptos de física u otros, a través de uno o más ejemplos interactivos dentro del programa, utilizando una interfaz gráfica. (Hito3)

### Roles de cada integrante
| Integrante | Rol Scrum | Responsabilidades Principales |
| :--- | :--- | :--- |
| **Yeremi Rodríguez** | **Product Owner** | Clarifica objetivos y resuelve dudas al equipo y realiza consultas al profesor. |
| **(H1)Vicente Arellano** | **Scrum Master** | Facilita la organización y planifica las reuniones. |
| **Yeremi Rodríguez** | **Equipo** | Escritura de código, ejecución de pruebas técnicas y solución de errores. |
| **Nicole Zuñiga** | **Equipo** | Escritura de código, ejecución de pruebas técnicas y solución de errores. |
| **Daniel Vera** | **Equipo** | Escritura de código. |
| **Vicente Arellano** | **Equipo** | Escritura de código, mantenimiento del repositorio en GitHub y planificación del video. |

### Hito 1:
- Crear una primera versión funcional del proyecto en lenguaje C
- Crear un Github con una clara organización y completo
- Crear una presentación en video sobre el avance del proyecto  

### Funcionalidades implementadas:

- struct point

```c
struct point {
    int x;
    int y;
    char letra;
};
```

Descripción: Estructura de datos que representa un punto en el plano, con coordenadas enteras y un caracter que representa el punto en el gráfico.

- Graficadora en el plano cartesiano (graf_xy):

```void graf_xy(struct point lista[], int tam,int y_max, int y_min, int  x_max, int x_min, char relleno);```

Descripción: Recibe una arreglo de datos de tipo struct point y lo grafica en consola.

Parametros:

  struct point lista[]: arreglo de datos tipo struct point.
  int tam: Tamaño del arreglo lista.
  int y_max: entero que representa la altura maxima del grafico desde el origen.
  int y_min: entero que representa la altura minima del grafico desde el origen.
  int x_max: coordenada x maxima que tomara el grafico desde el origen.
  int x_min: coordenada x minima que tomara el grafico desde el origen.
  char relleno: Relleno alrededor del grafico.

- Función seno y coseno (fcoseno y fseno):

```void fcoseno(struct point lista[], int tam, int x_min, int x_max, float escala_y, char c);```

```void fseno(struct point lista[], int tam, int x_min, int x_max, float escala_y, char c);```

Descripción: Modifican un arreglo externo a ellas de tamaño fijo dado por x_min y x_max,

las funciones recorren de x_min a x_max evaluandolo en sus respectivas funciones y asignando valores de x e y a cada punto del arreglo.

- Círculo unitario (circle_u):

```void circle_u(float x, float y);```


Descripción: Reciben dos valores flotantes x e y, y ubica un punto en el circulo unitario.

Nota: al evaluar x e y, se deben usar la función math especificando un angulo, talque x = cos(angulo) e y = sin(angulo).

Ejemplo de uso: 

  ```float angulo;
  scanf("%f", &angulo);
  circle_u(cos(angulo), sin(angulo))
```


### Avance logrado hasta ahora y próximos pasos hacia el Hito 2:
- Se logró crear un programa basico sobre una graficadora de seno, coseno y circulo unitario
- Los pasos hacia el hito 2 será traducir el proyecto a C++ y representar resultados de manera visual.

### Documentos adicionales y anexos

Compilación: gcc main.c implementacion.c encabezado.h -o nombre_archivo -lm

### Referencias:
[Markdown](https://markdown.es/)
[Aprende GIT ahora! curso completo GRATIS desde cero](https://www.youtube.com/watch?v=VdGzPZ31ts8)
     [C math (math.h) Library](https://www.w3schools.com/c/c_ref_math.php)
[Herencia c++](https://learn.microsoft.com/es-es/cpp/cpp/inheritance-cpp?view=msvc-170)
