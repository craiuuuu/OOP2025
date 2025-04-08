#pragma once
#include <cstring>
class Number
{
private:
	int base;
    char* Value;

	int chartodigit(char c);
	char digittochar(int d);
    int convertodecimal(const char* value, int base);
public:
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();

	Number(const Number& other);//copy constructor
	Number(Number&& other);//move consturctor

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base

	//int operator[](int index);//index operator

	friend Number operator+(const Number& a, const Number& b); // friend pt ca avem nevoie sa accesam din private
	friend Number operator-(const Number& a, const Number& b);
	bool operator>(Number numar);
    bool operator<(Number numar);
	bool operator>=(Number numar);
	bool operator<=(Number numar);
	bool operator==(Number numar);
    bool operator!=(Number numar);

	void operator--();    // prefix
	void operator--(int);  // postfix
};