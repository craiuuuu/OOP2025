#include "Sort.h"
#include <iostream>
using namespace std;

int main() {
    
    Sort s1(5, 10, 99);
    cout << "s1 fara sort:";
    s1.Print();
    cout << endl;
    s1.InsertSort(true);
    cout << "s1: ";
    s1.Print();
    cout << endl;

    int lista[] = { 5, 3, 1, 4, 2 };
    Sort s2(5, lista);
    cout << "s2 fara sort: ";
    s2.Print();
    cout << endl;
    s2.BubbleSort(true);
    cout << "s2: ";
    s2.Print();
    cout << endl;

  
    int vec[] = { 9, 7, 5, 3, 1 };
    Sort s3(5, vec);
    cout << "s3 fara sort: ";
    s3.Print();
    cout << endl;
    s3.QuickSort(true);
    cout << "s3: ";
    s3.Print();
    cout << endl;

  
   Sort s4(3, 10, 20, 30);
    cout << "s4 fara sort:";
    s4.Print();
    cout << endl;
    s4.InsertSort(true);
    cout << "s4: ";
    s4.Print();
    cout << endl;

    
    Sort s5("10,40,100,5,70");
    cout << "s5 fara sort: ";
    s5.Print();
    cout << endl;
    s5.InsertSort(true);
    cout << "s5: ";
    s5.Print();
    cout << endl;

    return 0;
}