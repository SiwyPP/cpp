#pragma once
class Vector
{
private:
	double *elem;
	int sz;


public:
	Vector();
	Vector(int sz);

	double &operator[](const int i) const;
	int size() const;
	~Vector();
};

