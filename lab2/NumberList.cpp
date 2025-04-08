#include "NumberList.h"
#include <cstring>
#include <iostream>


void NumberList::Init()
{
	this-> count = 0;
}

bool NumberList::Add(int x)
{
	if (this->count >= 10)
	{
		return false;
	}
	
	this-> numbers[count] = x;
	this-> count++;
	return true;

}

void NumberList::Sort()
{	
	int aux;
	for (int i = 0; i <= count-1; i++)
	{
		for (int j = i + 1; j <= count; j++)
		{
			if (this->numbers[i] > this->numbers[j])
			{
				aux = this->numbers[i];
				this->numbers[i] = this->numbers[j];
				this->numbers[j] = aux;
			}
		}
	}
}

void NumberList::Print()
{
	for (int i = 0; i < count; i++)
	{
		std::cout << this->numbers[i] << " ";
	}
}

