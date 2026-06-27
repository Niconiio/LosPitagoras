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

# Trigonometry Viewer QT

## Evolución del proyecto

### Hito 1:

### Creación del las funciones principales, seno, coseno, graf_xy y circle_u

Seno y coseno modificaban un arreglo de struct point (structura de datos creada para el proyecto que representa un punto) con las coordenadas (x,f(x)) de estas funciones trigonometricas, graf_xy recibia este arreglo y lo graficaba en consola en base a parametros de visualización (dominio, recorrido), circle_u por su parte recibia un angulo y graficaba las componentes del seno y coseno en el circulo unitario.

### Hito 2:

### Implementación de POO en el proyecto, C++.

**Las funciones creadas y sus parametros del hito 1 se abstrajeron a clases de C++**, las funciones seno y coseno se fusionarón en un solo metodo (cos_sen) de la clase sinusoidal (clase derivada de una clase mas general llamada funcion), esta clase contiene todos los atributos necesarios para el funcionamiento de las funciones sen y cos del hito pasado, se cambió el arreglo a un vector de vectores dentro de la clase (atributo grafico), y se añadió parametrización (nuevos atributos, A, B, C) tal que cada objeto de la clase sinusoidal represente una función seno o coseno en su forma sinusoidal (Asen(Bx + c) o Acos(Bx + C)), el principal rol de sinusoidal es crear el vector con las coordenadas necesarias para graficar. Por su parte, para graf_xy y circle_u el se realizaron cambios similares, graf_xy es parte de un metodo de la clase graf, clase que tiene los atributos necesarios para que graf_xy funcione, se añadió un nuevo atributo para "contener" un objeto de la clase sinusoidal para graficar la función, de forma similar para circle_u que ahora es un metodo de la clase circulo.

### Hito 3:

### Interfaz grafica en QT.

Todo el avance y las funcionalidades hechas en el hito 2 se mantuvieron y migraron a un proyecto en QT (QtWigets Aplication), se elimina la clase graf, y sus metodos, al no necesitarse graficar en consola, se reemplaza esto con elementos de QT como QTCharts (QLineSeries, QCharts, QChartView), se aumentó la "definición" de las funciones sinusoidales (curvas mas suaves), ya que el metodo cos_sen ahora crea un vectores de vectores con valores flotantes (antes los valores de x eran enteros), lo que permite que las curvas en QTCharts sean mas suaves, se mantuvó la clase sinusoidal y se creó una función para graficar las funciones trigonometricas en la interfaz, se reemplazo la clase circulo con un clase circle_u adaptada a QT, cuya responsabilidad es mostrar el circulo unitario en consola. Ahora se visualizan el circulo unitario, y las funciones seno y coseno en una interfaz, todo el programa se utiliza atraves de una ventana, donde el usuario puede variar los parametros (A, B y C), el angulo, desplazar las funciones, etc.


### Descripción de las clases principales, sus responsabilidades y relaciones.

Class sinusoidal: Representa a la funcion seno o coseno parametrizada en su forma general (A*sen(Bx+c)) o (A*cos(Bx+C)).

"cos_sen()" recorre el dominio (dom[0] a dom[1]) en pasos de 0.05 (valor flotante, lo que logra las curvas suaves) y calcula A*sin(B*x+C) si "tipo==1" o A*cos(B*x+C) si "tipo==2", guardando las coordenadas en grafico.
 

Class circle_u: Dibuja el circulo unitario y muestra, para el ángulo dado, el punto sobre la circunferencia y los segmentos que representan su seno y su coseno.


### Explicación de la interfaz desarrollada , indicando objetivo, widgets principales, flujo de uso y forma de parametrización. (ultimo)

Objetivo de la interfaz: ofrecer una ventana utilizable para el usuario, en particular el estudiante, donde pueda ver y manipular en tiempo real las graficas de las funciones sinusoidales y el circulo unitario.

Widgets principales: "spinBox_(A/B/C)_(seno/coseno)", Para controlar A, B y C de las funciones seno y coseno, "Desplazamiento_horizontal_(seno/coseno)", desplazan el dominio visible, "anguloSpinBox", controla el ángulo del circulo unitario, "circuloWidget", dibuja el circulo unitario.

Flujo de uso: al abrir el programa, se muestran de inmediato las curvas de seno y coseno (con A=1, B=1, C=0 por defecto) y el círculo unitario en ángulo 0°. Al modificar cualquiera de los spinboxes A/B/C de seno o coseno, MainWindow::graficar() reconstruye por completo el gráfico correspondiente: recalcula los puntos con cos_sen(), crea un nuevo QChart/QLineSeries, y actualiza el título mostrando la fórmula resultante (por ejemplo 2seno(3x + 1), o el caso especial sen(x)/cos(x) cuando A=1, B=1, C=0). Al mover los sliders de desplazamiento horizontal, se actualiza el dominio (dom[0]/dom[1]) de la función correspondiente, desplazando la "ventana" visible de la curva sin cambiar su forma. Al mover anguloSpinBox, el cambio se envía directamente al widget circuloWidget, que recalcula y redibuja el punto sobre la circunferencia y sus proyecciones de seno/coseno.


### Descripción de la separación entre lógica e interfaz

Utilizando el propio contenido de nuestro proyecto, la logica es la que se encarga de, por ejemplo, hacer los calculos matematicos. Nos entrega "f(x)" por cada "x", Mientras que la interfaz es el código que se encarga de graficar eso en QtCharts.

### funcionalidades implementadas y las pruebas realizadas.

### Ejemplos de ejecución y resultados esperados (ultimo)



### Conclusiones del proyecto y posibles mejoras futuras si el desarrollo continuara.

Si bien se tenia planeado implementar ejemplos de aplicaciones de funciones trigonometricas en fisica u otros en una interfaz, así como otras posibles mejoras, como mas opciones de parametrización de las funciones, o de interfaz, por motivos de tiempo se ha pospuesto esto para mejoras futuras, consideramos como equipo que se ha cumplido lo pedido para esta entrega, tanto el objetivo general como los dos primeros objetivos especificos, se ha desarrollado una interfaz sencilla, funcional y facil de usar donde se parametrizan estas funciones y se interactua con el circulo unitario, manteniendo la funcionalidad pedida para el hito 1, 2 y 3. 

### Documentos adicionales y anexos

**Intrucciones de ejecución y compilación del programa:**

#### Requisitos:

1) Tener instalado QT Creator en su ultima versión (6.11 o superior).
2) Sistema operativo compatible con QT.

#### Pasos:
1) Descarga los archivos de la carpeta trigonometry Viewer QT
2) Crea un proyecto con QT Widgets Aplication, guardalo en una carpeta de preferencia.
3) Copia los archivos descargados a la carpeta del proyecto recien creada, reemplaza los archivos antiguos con los recien copiados.
4) Abre el proyecto, presiona en el boton Run abajo a la izquierda en QT Creator.
5) Usa el programa.

#### Anexos:

Avances realizados y su documentación durante el hito 1 y 2, en ramas h1 e hito 2 en Github.

### Referencias:

[Markdown](https://markdown.es/)
[Markdown] (https://learn.microsoft.com/en-us/contribute/media/documents/markdown-cheatsheet.pdf?raw=true)
[Aprende GIT ahora! curso completo GRATIS desde cero](https://www.youtube.com/watch?v=VdGzPZ31ts8)
[C math (math.h) Library](https://www.w3schools.com/c/c_ref_math.php)
[Herencia c++](https://learn.microsoft.com/es-es/cpp/cpp/inheritance-cpp?view=msvc-170)
