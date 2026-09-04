#include <iostream>
#include <cstdlib>
using namespace std;
// Función de ejemplo que muestra la dirección de su variable local estática
void funcionConStatic() {
	static int var_estatica = 100;
	cout << "var_estatica: " << var_estatica << endl;
	var_estatica++;
}

void funcionSinStatic() {
	int var_no_estatica = 100;
	cout << "var_no_estatica: " << var_no_estatica << endl;
	var_no_estatica++;
}

int main() {    // Variable local (stack)
	int a = 10;
	int b = 20;
	/**********************************************************
	EXPERIMENTO 5
	***********************************************************/
	for (int i = 0; i < 5; i++) {
		cout << "Iteración " << i << endl;
		funcionSinStatic();
		funcionConStatic();
	}
	/********************************************************/
	return 0;
}