#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	cout << Math::Add(3, 5) << endl;
	cout << Math::Add(3, 5, 7) << endl;
	cout << Math::Add(2.5, 4.3) << endl;
	cout << Math::Add(1.1, 2.2, 3.3) << endl;

	cout << Math::Mul(3, 5) << endl;
	cout << Math::Mul(3, 5, 2) << endl;
	cout << Math::Mul(2.5, 4.0) << endl;
	cout << Math::Mul(1.5, 2.0, 3.0) << endl;

	cout << Math::Add(5, 1, 2, 3, 4, 5) << endl;//asta e cu mai multe variabile

	const char* str1 = "Salutare";
	const char* str2 = "!";
	cout<< Math::Add(str1, str2);
}