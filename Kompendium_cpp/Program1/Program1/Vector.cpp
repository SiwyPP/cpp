#include "Vector.h"
#include <stdexcept> 
using namespace std;

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
}
