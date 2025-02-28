#include <iostream>
#include <stdio.h>
//#include <stdlib.h>
using namespace std;
//test
int main()
{
    FILE* f;
    int suma = 0, numar = 0;
    char line[100];
    if (fopen_s(&f, "in.txt", "r") != 0)
    {
        printf("Nu merge sa deschizi fisierul.");
    }
    else
    {
       // printf("Fisier deschis.");

        while (fgets(line, sizeof(line), f))
        {
            numar = 0;
                for (int i = 0; line[i] != '\0';i++)
                {
                    if (line[i] >= '0' && line[i] <= '9')
                    {
                        numar = numar * 10 + (line[i] - '0');
                    }
                }
                
            
            suma = suma + numar;
        }
    }

    cout << suma;

    return 0;
}
