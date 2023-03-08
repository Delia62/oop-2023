#include "Canvas.h"
#include<iostream>
#include<cstdarg>
using namespace std;

Canvas::Canvas(int lines, int columns) {
    this->lines = lines;
    this->columns = columns;
    clear();
}

void Canvas::set_pixel(int x, int y, char value) {
    data[x][y] = value;
}
void Canvas::set_pixels(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        int x = va_arg(args, int);
        int y = va_arg(args, int);
        int z = va_arg(args, int);
        data[x][y] = z;
    }
    va_end(args);
    
}
void Canvas::clear() {
   
    for (int i = 0; i < this->lines; i++) 
        for (int j = 0; j < this->columns; j++)
            data[i][j] = ' ';
 }

void Canvas::print() const{
    
    
    for (int i = 0; i < this->lines; i++) {
        for (int j = 0; j < this->columns; j++)
            cout << data[i][j];
        cout << endl;
    }
 }
