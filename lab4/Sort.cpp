#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cstdarg>
#include <ctime>

using namespace std;

Sort::Sort(int nr_elem, int min, int max)
{   
    this->nr_elem = nr_elem;
    vector = new int[nr_elem];
    srand((unsigned)time(0));
    for (int i = 0; i < nr_elem; i++) {
        vector[i] = rand() % (max - min + 1) + min;
    }
}

Sort::Sort(int nr_elem, int* initlist)
{
    this->nr_elem = nr_elem;
    vector = new int[nr_elem];
    for (int i = 0; i < nr_elem; i++) {
        vector[i] = initlist[i];
    }
}

Sort::Sort(int nr_elem, ...)
{   
    this->nr_elem = nr_elem;
    vector = new int[nr_elem];
    va_list vl;
    va_start(vl, nr_elem);
    for (int i = 0; i < nr_elem; i++) {
        vector[i] = va_arg(vl, int);
    }
    va_end(vl);
}

Sort::Sort(const char* str)  // trb sa-l refac
{   

    char* strcopy= new char[strlen(str) + 1];
    strcpy(strcopy, str);

    nr_elem = 1;
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] == ',')
        {
            nr_elem++;
        }
    }

    vector = new int[nr_elem];//alocare vect
    int index = 0;
    char *p = strtok(strcopy, ",");
    while (p != nullptr) 
    {
        vector[index++] = atoi(p); // il facem integer
        p = strtok(nullptr, ",");
    }

    delete[] strcopy;
}

Sort::~Sort() {
    delete[] vector;
}

void Sort::ReverseArray() {
    for (int i = 0; i < nr_elem/ 2; i++) 
    {
        swap(vector[i], vector[nr_elem - i - 1]);
    }
}

void Sort::InsertSort(bool ascendent) 
{
    for (int i = 1; i < nr_elem; i++) 
    {
        int key = vector[i];
        int j = i - 1;
        while (j >= 0 && vector[j] > key) 
        {
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = key;
    }
    if (!ascendent)
    {
        ReverseArray();
    }
}

void Sort::QuickSortHelper(int low, int high) 
{
    if (low < high) {
        int pi = Partition(low, high);
        QuickSortHelper(low, pi - 1);
        QuickSortHelper(pi + 1, high);
    }
}

int Sort::Partition(int low, int high) 
{
    int pivot = vector[high];
    int i = low - 1;
    for (int j = low; j < high; j++) 
    {
        if (vector[j] < pivot) 
        {
            i++;
            swap(vector[i], vector[j]);
        }
    }
    swap(vector[i + 1], vector[high]);
    return i + 1;
}

void Sort::QuickSort(bool ascendent) 
{
    QuickSortHelper(0, nr_elem - 1);
    if (!ascendent)
    {
        ReverseArray();
    }
}


void Sort::BubbleSort(bool ascendent)
{
    bool swapped;
    for (int i = 0; i < nr_elem - 1; i++) {
        swapped = false;
        for (int j = 0; j < nr_elem - i - 1; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                swap(vector[j], vector[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    if (!ascendent)
    {
        ReverseArray();

    }
}

void Sort::Print() {
    for (int i = 0; i < nr_elem; i++) 
    {
        cout << vector[i] << " ";
    }
}

int Sort::GetElementsCount() {
    return nr_elem;
}

int Sort::GetElementFromIndex(int index) {
    if (index < 0 || index >= nr_elem) {
        cout << "nu e bn frt";
    }
    return vector[index];
}