#pragma once

class Sort
{
    int nr_elem;
    int* vector;
public:
    //facem constructorii
    Sort(int nr_elem, int min, int max);          // randomu intre min si max
    Sort(int nr_elem, int* initlist);             // lista de initializare gen vector sau linked list
    Sort(int nr_elem, ...);                       // va_args
    Sort(const char* str);      //sort cu ,
    
    ~Sort();//sir de caract

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);

private:
    void QuickSortHelper(int low, int high);
    int Partition(int low, int high);
    void ReverseArray(); //pt inversare pt ascendent
};

 