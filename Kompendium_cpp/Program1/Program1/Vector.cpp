#include <iostream>
#include "Vector.h"
#include <stdexcept> 
using namespace std;

//TEST TYCH NOWOŒCI W MAIN NA KOÑCU TEGO PLIKU

Vector::Vector() :elem{ new double[0] }, sz{0}
{
}
/*
Vector::Vector(int sz) : elem{ new double[sz] }, sz{ sz }
{

}
*/
// Lepsza definicja dla tego konstruktora

Vector::Vector(int sz) 
{
	if (sz < 0)
	{	
		length_error e{ "Zla dlugosc!" };
		throw e;
	}
	this->sz = sz;
	elem = new double[sz];
}

Vector::Vector(const Vector& v) : elem{ new double[v.sz] }, sz{v.sz}
{
	for (int i = 0; i < sz; i++)
	{
		elem[i] = v.elem[i];
	}
	cout << "konstruktor kopiujacy" << endl;
}

Vector& Vector:: operator=(const Vector& v)
{
	elem = new double[v.sz];
	sz = v.sz;
	for (int i = 0; i < sz; i++)
	{
		elem[i] = v.elem[i];
	}
	cout << "przypisanie kopiujace" << endl;

	return *this;
}

Vector::Vector(Vector&& v) : elem{ v.elem }, sz{ v.sz }
{
	cout << "Konstruktor przenoszacy" << endl;
	v.elem = nullptr;
	v.sz = 0;
}

Vector& Vector:: operator=(Vector&& v)
{
	cout << "Przeniesienie kopiujace \n";
	elem = v.elem;
	sz = v.sz;

	v.elem = nullptr;
	v.sz = 0;
	return *this;
}


double& Vector:: operator[](const int i) const
{
	if (i < 0 || size() <= i)
	{
		out_of_range e{ "Vector:: operator[]" };
		throw e;
		
	}
		
	
	return elem[i];
}



int Vector::size() const
{
	return sz;
}

Vector::~Vector()
{
	delete[] elem;
	cout << "Destruktor" << endl;
}

/*

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
/*
Vector v5 = move(v4);
cout << "Zawartosc v4 \n";
v4.show();
getchar();
}


*/