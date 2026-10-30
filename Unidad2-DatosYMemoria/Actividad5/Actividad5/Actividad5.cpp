#include <iostream>
#include <string>
using namespace std;

class Punto {
public:
    string name;
    int x;
    int y;

    // Constructor
    Punto(string _name, int _x, int _y) : name(_name), x(_x), y(_y) {
        cout << "Constructor: Punto " << name << " (" << x << ", " << y << ") creado." << endl;
    }

    // Destructor
    ~Punto() {
        cout << "Destructor: Punto " << name << "(" << x << ", " << y << ") destruido." << endl;
    }

    // Método para imprimir valores
    void imprimir() {
        cout << "Punto " << name << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    // Objeto original
    Punto original("original", 70, 80);
    original.imprimir();
    Punto* p = &original;

    // Copia del objeto
    Punto copia = original;
    copia.name = "copia";
    copia.x = 100;
    copia.y = 200;
    copia.imprimir();
    original.imprimir();

    p->name = "p";
    p->x = 300;
    p->y = 400;
    p->imprimir();
    original.imprimir();

    return 0;
}*