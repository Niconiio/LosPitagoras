# **Trigonometry Viewer**
### Problemática a solucionar: 
Muchos estudiantes de enseñanza media usan las funciones trigonométricas básicas sin siquiera preguntarse qué significan, de donde vienen y sus posibles aplicaciones.

### Objetivo general del proyecto:
Que los estudiantes de enseñanza media comprendan de una mejor forma lo que significan estas funciones mediante una herramienta didáctica que permita experimentar con ellas, tal que a través de su exploración visualicen y entiendan mejor conceptos de funciones trigonométricas y sus aplicaciones.

### Objetivos específicos del proyecto:
- Crear un programa que muestre graficamente las funciones seno, coseno, tangente y el circulo unitario (Hito 1).
- Crear un producto con un apartado visual más fluido, que permita a los estudiantes de enseñanza media interactuar con estas funciones a través de parámetros (hito 2).
- Relacionar estas funciones trigonométricas con conceptos de física u otros, a través de uno o más ejemplos interactivos dentro del programa, utilizando una interfaz gráfica. (Hito3).

### Roles de cada integrante
| Integrante | Rol Scrum | Responsabilidades Principales |
| :--- | :--- | :--- |
| **Yeremi Rodríguez** | **Product Owner** | Clarifica objetivos y resuelve dudas al equipo y realiza consultas al profesor. |
| **Daniel Vera** | **Scrum Master** | Facilita la organización  |
| **Yeremi Rodríguez** | **Equipo** | Escritura de código, ejecución de pruebas técnicas, mantenimiento del repositorio en GitHub y solución de errores.|
| **Nicole Zuñiga** | **Equipo** | Escritura de código, planificación del video|
| **Daniel Vera** | **Equipo** | Escritura de código, planificación del video|

## Hito 1:
- Crear una primera versión funcional del proyecto en lenguaje C
- Crear un Github con una clara organización y completo
- Crear una presentación en video sobre el avance del proyecto  

### Funcionalidades implementadas:

**struct point**

```c
struct point {
    int x;
    int y;
    char letra;
};
```

  **Descripción:** Estructura de datos que representa un punto en el plano, con coordenadas enteras y un caracter que representa el punto en el gráfico.

**Graficadora en el plano cartesiano (graf_xy):**

```void graf_xy(struct point lista[], int tam,int y_max, int y_min, int  x_max, int x_min, char relleno);```

**Descripción:** Recibe una arreglo de datos de tipo struct point y lo grafica en consola.

**Parametros:**

  - **struct point lista[]:** arreglo de datos tipo struct point.
  int tam: Tamaño del arreglo lista.

  - **int y_max:** entero que representa la altura maxima del grafico desde el origen.

  - **int y_min:** entero que representa la altura minima del grafico desde el origen.

  - **int x_max:** coordenada x maxima que tomara el grafico desde el origen.

  - **int x_min:** coordenada x minima que tomara el grafico desde el origen.

  - **char relleno:** Relleno alrededor del grafico.

**Función seno y coseno (fcoseno y fseno)**:

```void fcoseno(struct point lista[], int tam, int x_min, int x_max, float escala_y, char c);```

```void fseno(struct point lista[], int tam, int x_min, int x_max, float escala_y, char c);```

**Descripción:** Modifican un arreglo externo a ellas de tamaño fijo dado por x_min y x_max, estas funciones recorren de x_min a x_max evaluandolo en sus respectivas funciones y asignando valores de x e y a cada punto del arreglo.

**Círculo unitario (circle_u):**

```void circle_u(float x, float y);```


**Descripción:** Reciben dos valores flotantes x e y, y ubica un punto en el circulo unitario.

**Nota:** al evaluar x e y, se deben usar la función math especificando un angulo, talque x = cos(angulo) e y = sin(angulo).

**Ejemplo de uso:** 

  ```float angulo;
  scanf("%f", &angulo);
  circle_u(cos(angulo), sin(angulo))
```

>Nota: Los archivos de hito 1 estan en la rama con el mismo nombre en github.

### Avance logrado hasta ahora y próximos pasos hacia el Hito 2:
- Se logró crear un programa basico sobre una graficadora de seno, coseno y circulo unitario
- Los pasos hacia el hito 2 será traducir el proyecto a C++ y representar resultados de manera visual.

## Hito 2:

### Cambios estructurales realizados al migrar desde C a C++

**C++**: Se cambiaron todos los printf() y scanf(), por cin y cout, se cambio la biblioteca math por cmath.

**Programación Orientada a Objetos:** Se distinguieron en el proyecto 2 entidades principales, Graficadora y funciones, así que en la implementación de C++, se abstrajo esta idea a dos clases principales, graf y funcion, graf es una clase que representa un graficador de funciones, tal que graf_xy paso a ser parte de un metodo, y sus parametros como atributos de la clase, del mismo modo, para cada función trigonométrica se creó una clase derivada de la clase funcion, e igual con la clase graficadora la funciónes trigonometricas se transformaron en metodos y los parametros en atributos. 

**Standard Template Library:** Hubo un cambio en el tipo de dato con el que se relacionan ambas clases, anteriormente las funciones trigonométricas modificaban un arreglo de struct point (estructura que almacenaba, enteros (x e y) y un caracter) y eso se pasaba como argumento a graf_xy resultando en un grafico en consola, ahora se utilizan vectores de vectores, y el caracter de la curva se almacena dentro del mismo objeto.

### Descripción de las clases creadas, sus responsabilidades y relaciones principales (por ejemplo composición o herencia).

#### - Clase funcion:

```c
class funcion{
  protected:
    int rec[2] = {0,0};
    int escala; 
    int tam_graf;
  public:
    std::string nombre;
    char punto;
    int dom[2] = {0,0};
    std::vector<std::vector<int>> grafico;
    int Show_Tam(){tam_graf = grafico.size();return grafico.size();};
    virtual void funcion_(){};
};
```

**Descripción:** clase base de las funciones seno y coseno, contiene los atributos necesarios para que las funciones realizadas en la entrega anterior puedan utilizarse como metodos de las clases derivadas.

#### - Clase sinusoidal:
```c
class sinusoidal: public funcion{
  int A;
  int B;
  int C;
  int tipo;
  public:
    sinusoidal(int x_min, int x_max, int A_, int B_, int C_, char p, std::string nombre_, int tipo_){
      punto = p; dom[0] = x_min; dom[1] = x_max; A = A_; B = B_; C = C_; nombre = nombre_; int tipo = tipo_;}
      void funcion_(){
        grafico = cos_sen(grafico, dom[0], dom[1], A,B,C, tipo); tam_graf = grafico.size();}
};
```
Descripción: Representan al seno y al coseno, tiene los atributos necesarios para parametrizar esta función como una sinusoidal del tipo Asin(Bx + c) o Acos(Bx + c), su principal responsabilidad es generar el vector de vectores necesario para que la clase graf la grafique.

Atributos:

A,B,C: parametros de las funciones
tipo: Permite seleccionar seno o coseno.

Metodos:

funcion_: Utiliza la funcion cos_sen para generar el grafico de la clase.
sinusoidal(atributos..)



#### - Clase graf

```c
class graf{
  protected: 
    std::vector<std::vector<int>> grafico_final; 
    int dom[2];
    int rec[2];
    char relleno;
    funcion funcion_objetivo;
    int SI_funcion = 0;
    int tam_graf_final;
    std::string nombre_grafico;
    std::string nombre_funcion;
  public:  
    graf(int y_max, int y_min,int  x_max, int x_min, char relleno): relleno(relleno){
      rec[0] = y_min; rec[1] = y_max; dom[0] = x_min; dom[1] = x_max;}
    void select_funcion(funcion A){SI_funcion = 1;funcion_objetivo = A; grafico_final = A.grafico; tam_graf_final = A.size();} 
    void graficar(){     
    if (SI_funcion){  
    std::cout<< "Grafico de " << <<std::endl;
    graf_xy(grafico_final, tam_graf_final, rec[1], rec[0], dom[1], dom[0], relleno, funcion_objetivo.punto);
    }else{std::cout<<"No hay ninguna funciòn almacenada dentro del grafico"<<std::endl;}}
};
```

Descripcion: Clase graficadora, contiene los atributos necesarios para que graf_xy funcione dentro de los metodos del la clase, su principalidad responsabilidad es graficar una función trigonometrica almacenada dentro.

Atributos:

- int dom[2]: Arreglo que almacena los extremos del dominio que se desea graficar.
- int rec[2]: Arreglo que almacena los extremos del recorrido que se desa graficar.
- char relleno: Relleno del grafico para regiones fuera de la curva de la funciòn a graficar.
- funcion funcion_objetivo: Almacena la función que se va a graficar.
- int SI_funcion = 0: flag, cuyo valor es 1 cuando funcion_objetivo es igual a un objeto de la clase funcion.
- int tam_graf_final: Tamaño del vector que contiene los puntos del grafico de la funcion objetivo.
- std::string nombre_grafico: Nombre del grafico, para objetios de esta clase, útil para identificar el objeto de otros.
- std::string nombre_funcion: Nombre de la funcion objetivo.








### Ejemplos de ejecución y resultados esperados 




### Cambios respecto a la entrega anterior

**Sobre el cuarto integrante:**

- Por motivos personales, nuestro compañero **Vicente Arrellano** ha tomado la decisión de cursar la asignatura el próximo semestre, como equipo agradecemos su aporte en el Hito 1.

### Documentos adicionales y anexos

**Compilación:** g++ main.cpp implementacion.cpp encabezado.h -o nombre_archivo
**Ejecución:** ./nombre_archivo

### Referencias:

[Markdown](https://markdown.es/)
[Markdown] (https://learn.microsoft.com/en-us/contribute/media/documents/markdown-cheatsheet.pdf?raw=true)
[Aprende GIT ahora! curso completo GRATIS desde cero](https://www.youtube.com/watch?v=VdGzPZ31ts8)
     [C math (math.h) Library](https://www.w3schools.com/c/c_ref_math.php)
[Herencia c++](https://learn.microsoft.com/es-es/cpp/cpp/inheritance-cpp?view=msvc-170)
