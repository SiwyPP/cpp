#pragma once
#include <iostream>
using namespace std;
class Vector
{
private:
	double *elem;
	int sz;


public:
	Vector();
	Vector(int sz);

	Vector(const Vector&); // konstruktor kopiuj�cy
	Vector& operator=(const Vector&); //przypisanie kopiuj�ce

	Vector(Vector&&); // konstruktor przenosz�cy
	Vector& operator=(Vector&&);

	double &operator[](const int i) const;
	int size() const;
	~Vector();



	void fill()
	{
		for (int i = 0; i < sz; i++)
			elem[i] = i;
	}

	void show()
	{
		for (int i = 0; i < sz; i++)
			cout << elem[i] << endl;
		
	}
};

