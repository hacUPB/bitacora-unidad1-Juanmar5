# Sesión 3

# **Apply: Aplicación 🛠**

# **Actividad 6: Hola Objeto: creación de un objeto en el stack**

Este experimento es fundamental porque conecta el concepto fundamental de POO (objetos) con este curso.

Vas a crear una clase sencilla llamada Punto que represente un punto en el espacio con dos coordenadas (`x` e `y`). Luego, crearás un objeto de esta clase en el `stack` y utilizarás el depurador para inspeccionar su contenido y dirección de memoria.

### Pasos:

- Abre Visual Studio y crea un nuevo proyecto de consola en C++.
- Define la siguiente clase en un archivo `.cpp` (puedes incluir todo en `main.cpp`):

```cpp
#include <iostream>
using namespace std;
class Punto {
		public:   int x;
							int y;
    // Constructor
    Punto(int _x, int _y) : x(_x), y(_y) {
		    cout << "Constructor: Punto(" << x << ", " << y << ") creado." << endl;
		    }
    // Destructor
    ~Punto() {
		    cout << "Destructor: Punto(" << x << ", " << y << ") destruido." << endl;
		    }
    // Método para imprimir valores
    void imprimir() {
		    cout << "Punto(" << x << ", " << y << ")" << endl;
		    }
		};
int main() {
		// Coloca un breakpoint en la siguiente línea
		Punto p(10, 20);
    // Muestra el contenido del objeto
    p.imprimir();
    // Utiliza el depurador para inspeccionar 'p', observa la dirección de memoria y el valor de x e y.
    return 0;
    }
```

- Vas a analizar el programa anterior con su equivalente en C# (puedes crear un nuevo proyecto de consola C# en una nueva ventana de Visual Studio):

```cpp
using System;
public class Punto{
		public int x;
		public int y;
    public Punto(int _x, int _y)    {
		    x = _x;
		    y = _y;
		    Console.WriteLine($"Constructor: Punto({x}, {y}) creado.");
		}
    ~Punto()    {
		    Console.WriteLine($"Destructor: Punto({x}, {y}) destruido.");
		}
    public void Imprimir()    {
		    Console.WriteLine($"Punto({x}, {y})");
		    }
		}
class Program{
		static void Main(string[] args)    {
		Punto p = new Punto(10, 20);
		p.Imprimir();
		}
}
```

- Ejecuta el programa en C++ en modo depuración (F5) y coloca un breakpoint en la línea donde se declara `Punto p(10, 20);`.
- Paso a paso (F10), observa en la ventana de variables (Autos/Locals) los valores de `x` y `y`. En el menú Debug, selecciona Windows > Memory > Memory 1 y observa la dirección de memoria de `p`. Escribe en la entrada de texto de Memory 1 la dirección de memoria de `p` así `&p` y presiona Enter. Observa la dirección de memoria de `p`. Observa el contenido de la memoria, deberías ver algunos números en hexadecimal, tales como $0a 00 00 00 14 00 00 00.$
- Abre la calculadora de Windows y selecciona el modo de programador. Cambia a modo hexadecimal. Escribe 0a ¿Qué valor en decimal obtienes? Escribe 14 ¿Qué valor en decimal obtienes? ¿Qué observas?
- Nota el orden en el que están almacenados los bytes en la memoria. Observa que el byte de menor peso (menos significativo) está almacenado primero, es decir, en una dirección de memoria menor. A esto se le conocen como arquitecturas little-endian. Otro tipo de arquitectura es big-endian, donde el byte de mayor peso (más significativo) se almacena primero. La mayoría de las arquitecturas modernas son little-endian. Si la arquitectura de tu computador fuera big-endian, ¿Cómo quedarían almacenados los bytes en la memoria de `p`?

**Reflexiona sobre las siguientes cuestiones**:

1. ¿Cuál es la diferencia entre un constructor y un destructor en C++?
2. ¿Cuál es la diferencia entre un objeto y una clase en C++?
3. ¿Qué diferencia notas entre el objeto Punto en C++ y C#?
4. ¿Qué es `p` en C++ y qué es `p` en C#? (en uno de ellos `p` es un objeto y en el otro es una referencia a un objeto).
5. ¿En qué parte de memoria se almacena `p` en C++ y en C#?
6. ¿Qué observaste con el depurador acerca de `p`? Según lo que observaste ¿Qué es un objeto en C++?

# **Actividad 7: Objetos en el heap: creación y observación**

Modifica el programa anterior para crear un objeto de la clase Punto de manera dinámica (en el heap) utilizando new. Luego, inspecciona con el depurador la dirección del objeto y compárala con la del objeto en el stack.

```cpp
#include <iostream>
using namespace std;
class Punto {
		public:    int x;    int y;
    // Constructor
    Punto(int _x, int _y) : x(_x), y(_y) {
		    cout << "Constructor: Punto(" << x << ", " << y << ") creado." << endl;
		    }
    // Destructor
    ~Punto() {
		    cout << "Destructor: Punto(" << x << ", " << y << ") destruido." << endl;
		    }
    // Método para imprimir valores
    void imprimir() {
		    cout << "Punto(" << x << ", " << y << ")" << endl;
		    }
		};
int main() {
		// Objeto en el stack
		Punto pStack(30, 40);
		pStack.imprimir();
    // Objeto en el heap
    Punto* pHeap = new Punto(50, 60);
    pHeap->imprimir();
    // Coloca breakpoints en la creación de pStack y pHeap
    // Inspecciona las direcciones de memoria de ambos objetos:
    // - pStack: dirección obtenida directamente.
    // - pHeap: la variable pHeap es un puntero que contiene la dirección del objeto en el heap.
    // Recuerda liberar la memoria del heap
    delete pHeap;
    return 0;
}
```

Ejecuta el programa en modo depuración y detente en los breakpoints para comparar:

- La dirección de pStack (ubicado en el stack).
- El valor de pHeap (la dirección del objeto en el heap).

**Reflexiona sobre lo siguiente**:

1. Explicación de la diferencia entre objetos creados en el stack y en el heap.
2. `pStack` ¿Es un objeto o una referencia a un objeto?
3. `pHeap` ¿Es un objeto o una referencia a un objeto? Si es una referencia, ¿A qué objeto hace referencia?
4. Observa en Memory1 (Debug->Windows->Memory->Memory1) el contenido de la dirección de memoria de `pHeap`, recuerda escribir en la entrada de texto de Memory1 la dirección de memoria de `&pHeap` y presionar Enter. Compara el contenido de memoria con el contenido de `pHeap` en la pestaña de Locals (Debug->Windows->Locals). ¿Qué observas? ¿Qué significa esto?

# **Actividad 8: Funciones y objetos en C++**

Analiza, ejecuta, depura y experimenta con el siguiente código en C++.

```cpp
#include <iostream>
#include <string>
using namespace std;
class Punto {
		public:   string name;
							int x;
							int y;
    // Constructor
    Punto(string _name, int _x, int _y) : name(_name),x(_x), y(_y) {
		    cout << "Constructor: Punto "<< name <<" (" << x << ", " << y << ") creado." << endl;
		    }
    // Destructor
    ~Punto() {
		    cout << "Destructor: Punto " << name << "(" << x << ", " << y << ") destruido." << endl;
		    }
    // Método para imprimir valores
    void imprimir() {
		    cout << "Punto "<< name << "(" << x << ", " << y << ")" << endl;
		    }
		};
		void cambiarNombre(Punto p, string nuevoNombre) {
				p.name = nuevoNombre;
				}
int main() {    // Objeto original
		Punto original("original",70, 80);
		original.imprimir();
		cambiarNombre(original, "cambiado");
		original.imprimir();
		return 0;
		}
```

**Reflexiona sobre lo siguiente**:

1. ¿Qué ocurre después de llamar a la función `cambiarNombre`? ¿Por qué aparece el mensaje `Destructor: Punto cambiado(70, 80) destruido.`?
2. ¿Por qué `original` sigue existiendo luego de llamar `cambiarNombre`?
3. ¿En qué parte del mapa de memoria se encuentra `original` y en qué parte se encuentra `p`? ¿Son el mismo objeto? (recuerda usar siempre el depurador para responder estas preguntas).

Modifica la función `cambiarNombre`:

`void cambiarNombre(Punto& p, string nuevoNombre) {  p.name = nuevoNombre;}`

1. ¿Qué ocurre ahora? ¿Por qué?

Modifica ahora a `cambiarNombre` y a `main` de la siguiente manera:

```cpp
void cambiarNombre(Punto* p, string nuevoNombre) {
		p->name = nuevoNombre;
		}
int main() {    // Objeto original
		Punto original("original",70, 80);
		original.imprimir();
    cambiarNombre(&original, "cambiado");
    original.imprimir();
    return 0;
    }
```

1. ¿Qué ocurre ahora? ¿Por qué?
2. En este caso ¿Cuál es la diferencia entre pasar un objeto por valor, por referencia y por puntero?