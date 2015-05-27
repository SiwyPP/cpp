#include <iostream>
#include <complex>
#include "Vector.h"
using namespace std;

Vector f()
{
	Vector x(10);
	Vector y(10);
	

	x.fill();
	y = move(x);

	return y;
}

void main()
{
	Vector v1 = Vector(10);
	v1.fill();
	v1.show();
	Vector v2 = Vector(v1);
	cout << "Zawartosc v2: " << endl;
	v2.show();
	cout << "Wywolanie: " << endl;
	Vector v3 = move(v2);
	cout << "Zawartosc v3 \n";
	v3.show();
	cout << "Zawartosc v2 \n";
	v2.show();

	cout << "v4 i wywolanie funkcji \n";
	Vector v4 = f();


	cout << "v5 \n";
	/*
	Vector v5;
	v5 = v4;
	*/
	Vector v5 = move(v4);
	cout << "Zawartosc v4 \n";
	v4.show();
	getchar();
}