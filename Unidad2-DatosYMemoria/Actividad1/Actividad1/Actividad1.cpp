#include <iostream>

int sum(int a, int b) 
{
	return a + b;
}

int main() 
{
	int a = 5;
	int b = 7;
	std::cout << "La suma de " << a << " y " << b << " es " << sum(a, b) << "\n";
}