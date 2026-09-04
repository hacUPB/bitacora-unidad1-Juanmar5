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