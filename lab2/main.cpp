#include <stdlib.h>
#include "NumberList.h"
#include <iostream>

int main()
{	
	int x;
	NumberList list;

	list.Init();

	while (std::cin >> x && list.Add(x) )
	{
		list.Add(x);
	}

	list.Sort();


	std::cout << "Lista este sortata: ";
	list.Print();


	return 0;
}