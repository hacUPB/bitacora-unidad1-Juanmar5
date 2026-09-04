#include <iostream>
using namespace std;

// 1. Swap por valor (NO funciona, es solo para comprobarlo)
void swapPorValor(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Dentro de swapPorValor -> a: " << a << ", b: " << b << endl;
}

// 2. Swap por referencia (SI funciona)
void swapPorReferencia(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 3. Swap por puntero (SI funciona)
void swapPorPuntero(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // Prueba 1: por valor
    int x = 1, y = 2;
    cout << "Antes (valor): x = " << x << ", y = " << y << endl;
    swapPorValor(x, y);
    cout << "Despues (valor): x = " << x << ", y = " << y << endl;

    // Prueba 2: por referencia
    int m = 3, n = 4;
    cout << "\nAntes (referencia): m = " << m << ", n = " << n << endl;
    swapPorReferencia(m, n);
    cout << "Despues (referencia): m = " << m << ", n = " << n << endl;

    // Prueba 3: por puntero
    int p = 5, q = 6;
    cout << "\nAntes (puntero): p = " << p << ", q = " << q << endl;
    swapPorPuntero(&p, &q);
    cout << "Despues (puntero): p = " << p << ", q = " << q << endl;

    return 0;
}