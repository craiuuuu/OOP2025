#include <iostream>
#include "Number.h"
using namespace std;

int main()
{	
	char* n1 = new char[60]; 
	char* n2 = new char[60];
	int baza1,baza2;
	cout << "Alegeti nr1:" << endl;
	cin >> n1;
	cout << "alegeti baza pt nr1:" << endl;
	cin >> baza1;
	/*cout << "Alegeti nr2:" << endl;
	cin >> n2;
	cout << "alegeti baza pt nr2:" << endl;
	cin >> baza2;*/
	Number nr1(n1, baza1);
	//Number nr2(n2, baza2);
	nr1.~Number();
	//delete[] n2;

	int schimbarebaza1, schimbarebaza2;
	
	cout << "schimba baza lui n1:";
	cin >> schimbarebaza1;
	nr1.SwitchBase(schimbarebaza1);
	nr1.Print();
	

}