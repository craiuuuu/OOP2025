#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <iostream>
#include <cstring>
#include <cstdarg>

int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int Math::Add(double a, double b)
{
	return a + b;
}

int Math::Add(double a, double b, double c)
{
	return a + b + c;
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int Math::Mul(double a, double b)
{
	return a* b;
}


int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}


//va_list vl; cream lista 
//va_start(vl, <numar_argumente>) initializaza lista
//val = va_arg(vl, <tip_argumente>); intr-o bucla for si argumentu cu tipul respectiv
//va_end(vl); 

int Math::Add(int count, ...)
{	
	va_list vl;
	va_start(vl, count);
	int suma = 0;
	for (int i = 0;i < count;i++)
	{
		suma = suma + va_arg(vl, int);
	}
	va_end(vl);

	return suma;
}

char* Math::Add(const char*str1, const char*str2)
{
	if (str1 == nullptr or str2==nullptr)
	{
		return nullptr;
	}

	int sir1_lung = strlen(str1);
	int sir2_lung = strlen(str2);

	
	char* rezultat = new char[sir1_lung + sir2_lung];  // cand folosim delete
	strcpy(rezultat, str1);
	strcat(rezultat, str2);

	return rezultat;
}


