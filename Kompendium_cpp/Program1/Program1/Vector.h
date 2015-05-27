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

	Vector(const Vector&); // konstruktor kopiujący
	Vector& operator=(const Vector&); //przypisanie kopiujące

	Vector(Vector&&); // konstruktor przenoszący
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

