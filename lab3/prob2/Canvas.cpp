#include "Canvas.h"
#include <iostream>
#include <cmath>

using namespace std;

Canvas::Canvas(int nr_of_col, int nr_of_lines) // 
{
    /*matrix = (char**)(malloc(this->nr_of_lines * sizeof(char*)));
    for (int i = 0; i < this->nr_of_lines; i++)
    {
        matrix[i] = (char*)(malloc(this->nr_of_col * sizeof(char)));
    }*/
    //Clear();

    //sa folosim new in loc de malloc
    matrix = new char* [nr_of_lines];
    for (int i = 0; i < nr_of_lines; i++) 
    {
        matrix[i] = new char[nr_of_col];
    }

}


void Canvas::SetPoint(int x, int y, char ch) 
{
    if (x >= 0 && x < nr_of_col && y >= 0 && y < nr_of_lines)  
    {
        matrix[x][y] = ch;
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    for (int i = 0; i < nr_of_lines; i++) 
    {
        for (int j = 0; j < nr_of_col; j++) 
        {
            int dist = (i - x) * (i - x) + (j - y) * (j - y); 
            if (dist >= ray * (ray - 1) && dist <= ray * (ray + 1)) 
            { 
                SetPoint(j, i, ch);
            }
            else
            {
                SetPoint(j, i,' ');
            }
        }
    }
}


void Canvas::FillCircle(int x, int y, int ray, char ch) 
{
    for (int i = 0; i < nr_of_lines; i++)
    {
        for (int j = 0; j < nr_of_col; j++)
        {
            if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray) {
                SetPoint(j, i, ch);
            }
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    
    for (int j = left; j <= right; j++) 
    {
        SetPoint(j, top, ch);    //sus
        SetPoint(j, bottom, ch); //jos
    }

    
    for (int i = top; i <= bottom; i++) 
    {
        SetPoint(left, i, ch);   //st
        SetPoint(right, i, ch);  //dr
    }
}


void Canvas::FillRect(int left, int top, int right, int bottom, char ch) 
{
    for (int i = top; i <= bottom; i++) 
    {
        for (int j = left; j <= right; j++) 
        {
            SetPoint(j, i, ch);
        }
    }
}

void Canvas::DrawLine(int x0, int y0, int x1, int y1, char ch) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);

    int sx, sy;
    if (x0 < x1) {
        sx = 1;  // dreapta
    }
    else {
        sx = -1; // stanga
    }

    if (y0 < y1) {
        sy = 1;  // jos
    }
    else {
        sy = -1; // sus
    }

    int err = dx - dy; // eroarea

    while (true) {
        SetPoint(x0, y0, ch); // desenam punctu

        if (x0 == x1 && y0 == y1) {
            break; // daca am ajuns la capat ne oprim
        }

        int e2 = 2 * err;

        if (e2 > -dy) {
            err = err - dy;
            x0 = x0 + sx;
        }

        if (e2 < dx) {
            err = err + dx;
            y0 = y0 + sy;
        }
    }
}




void Canvas::Print() 
{
    for (int i = 0; i < nr_of_lines; i++)
    {
        for (int j = 0; j < nr_of_col; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void Canvas::Clear() {
    for (int i = 0; i < nr_of_lines; i++)
    {
        for (int j = 0; j < nr_of_col; j++)
        {
            matrix[i][j] = ' ';
        }
    }
}