#include <iostream>
#include <complex>
using namespace std;

void main()
{
	const int i = 2;
	static_assert(i != 0, "I za male");

	getchar();
}