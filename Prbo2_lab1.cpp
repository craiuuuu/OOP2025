#include <iostream>
#include <stdio.h>
#include <cstring>
//#include <stdlib.h>
using namespace std;

void bubbleSort(char cuvintematrice[100][100], int cuvinte) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < cuvinte - 1; i++) {
            if (strlen(cuvintematrice[i]) < strlen(cuvintematrice[i + 1])) {  //sortam desc
                char temp[100];
                strcpy_s(temp, cuvintematrice[i]);
                strcpy_s(cuvintematrice[i], cuvintematrice[i + 1]);
                strcpy_s(cuvintematrice[i + 1], temp);
                swapped = true;
            }
        }
    } while (swapped);
}

int main()
{
    char propozitie[101];

    char cuvintematrice[100][100];

    int nrcuv = 0;

    scanf_s("%[^\n]", propozitie, (unsigned)_countof(propozitie));// %[^\n] citim pana la enter

    char *cuv;

    cuv = strtok(propozitie, " ");

    while (cuv != NULL)
    {
        strcpy(cuvintematrice[nrcuv], cuv);
        nrcuv++;
        cuv = strtok(NULL, " ");
    }

    bubbleSort(cuvintematrice, nrcuv);

    for (int i = 0; i < nrcuv; i++)
    {
        printf_s("%s", cuvintematrice[i]);
        printf_s("\n");
    }



    return 0;
}