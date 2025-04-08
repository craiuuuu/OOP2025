#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <iostream>
#include <cstring>

using namespace std;

int Number::chartodigit(char c)
{
	if (c >= '0' && c <= '9') return c - '0';
	else if (c >= 'A' && c <= 'Z') return 10 + (c - 'A');
	else if (c >= 'a' && c <= 'z') return 10 + (c - 'a');
	else return -1;//alt caracter
}

char Number::digittochar(int d) 
{
	if (d < 10) return '0' + d;
	else return 'A' + (d - 10);
}
	

int Number::convertodecimal(const char* value, int base)
{
	/*int num = 0;
	int i = 0;
	while (value[i]) {
		num = num * 10 + (value[i] - '0');
		i++;
	}
	return num;*/

	if (value == nullptr || base < 2 || base > 16) return 0; // Verificări de siguranță

	int result = 0;
	for (int i = 0; value[i] != '\0'; ++i) {
		int val = chartodigit(value[i]);
		if (val < 0 || val >= base) return 0; // Caracter invalid pentru bază
		result = result * base + val;
	}
	return result;
}

Number::Number(const char* value, int base)
{
	if (base < 2 or base>16)
	{
		cout << "Baza trebuie sa fie intre 2 si 16 .";
		//sau cu throw
	}
	this->base = base;
	this->Value = new char[strlen(value) + 1];
	strcpy(this->Value, value);
}

Number::Number(const Number& other) // copy constr
{
	this->base = other.base;
	this->Value = new char[strlen(other.Value) + 1];
	strcpy(this->Value, other.Value);
}

Number::Number(Number&& other) //move const
{
	this->base = other.base;
	this->Value = other.Value;
	other.Value = nullptr;
}
Number::~Number() 
{
	delete[] this->Value;
}

//copy si move cosntructor

void Number::SwitchBase(int newBase) // switch base
{
	//int numar = convertodecimal(this->Value, this->base);

	//char temp[64];  // buffer temporar
	//int index = 0;

	//while (numar > 0) 
	//{
	//	int rem = numar % newBase;
	//	temp[index++] = digittochar(rem);
	//	numar = numar / newBase;
	//}

	//
	//for (int i = 0; i < index; ++i) 
	//{
	//	this->Value[i] = temp[index - i - 1];
	//}
	//this->Value[index] = '\0';
	//this->base = newBase;

	if (newBase < 2 || newBase > 16) return; // Validare bază

	int decimalValue = convertodecimal(this->Value, this->base);

	if (decimalValue == 0) 
	{
		delete[] this->Value;
		this->Value = new char[2] {'0', '\0'};
		this->base = newBase;
		return;
	}

	int length = 0;
	int temp = decimalValue;
	while (temp > 0) 
	{
		temp /= newBase;
		length++;
	}


	char* newValue = new char[length + 1];
	int index = 0;

	while (decimalValue > 0) 
	{
		int remainder = decimalValue % newBase;
		newValue[index++] = digittochar(remainder);
		decimalValue /= newBase;
	}

	for (int i = 0; i < index / 2; i++) 
	{
		std::swap(newValue[i], newValue[index - i - 1]);
	}
	newValue[index] = '\0';

	delete[] this->Value;
	this->Value = newValue;
	this->base = newBase;
	
}

int Number::GetDigitsCount() 
{	
	int c = 0;
	for (int i = 0; i < strlen(Value); i++)
	{
		c++;
	}
	return c;
}

int Number::GetBase() 
{ 
	return base; 
}

Number operator+(const Number& a, const Number& b)
{
	return Number(a + b);
}

Number operator-(const Number& a, const Number& b)
{
	return Number(a - b);
}

bool Number::operator>(Number numar)
{	
	if (convertodecimal(this->Value,this->base)> convertodecimal(numar.Value,numar.base))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Number::operator<(Number numar)
{
	if (convertodecimal(this->Value, this->base) < convertodecimal(numar.Value, numar.base))
	{
		return 0;
	}
	else
	{
		return 1;
	}

}

bool Number::operator>=(Number numar)
{
	if (convertodecimal(this->Value, this->base) >= convertodecimal(numar.Value, numar.base))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Number::operator<=(Number numar)
{
	if (convertodecimal(this->Value, this->base) <= convertodecimal(numar.Value, numar.base))
	{
		return 0;
	}
	else
	{
		return 1;
	}

}

bool Number::operator==(Number numar)
{
	if (convertodecimal(this->Value, this->base) == convertodecimal(numar.Value, numar.base))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

bool Number::operator!=(Number numar)
{
	if (convertodecimal(this->Value, this->base) != convertodecimal(numar.Value, numar.base))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

void Number::Print()
{
	cout <<"numar:"<< this->Value;
	cout << endl;
	cout << "baza:"<<this->base;

}

void Number::operator--()
{
	int len = strlen(this-> Value);

	for (int i = 0; i < len;i++)
	{
		Value[i] = Value[i + 1];
	}

}

void Number::operator--(int)
{
	Value[strlen(this->Value) - 1] = '\0';
}