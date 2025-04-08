#include "Canvas.h"
#include <iostream>

int main() {
    Canvas canvas(30, 20);

    canvas.DrawCircle(15, 10, 5, '*');
    canvas.FillCircle(22, 10, 4, '#');
    canvas.DrawRect(2, 2, 10, 6, '@');
    canvas.FillRect(12, 12, 20, 16, '&');
    canvas.DrawLine(0, 0, 29, 19, '+');

    canvas.Print();
    return 0;
}