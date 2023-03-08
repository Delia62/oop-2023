#define _CRT_SECURE_NO_WARNINGS
#include"Math.h"
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
#include<stdio.h>
#include<string.h>


int Math::Add(int x, int y) {
    return x + y;

}
int Math::Add(int x, int y, int z) {
    return x + y + z;
}

int Math::Add(double x, double y) {
    return (int) (x + y);
}

int Math::Add(double x, double y, double z) {
    return (int) (x + y + z);
}

int Math::Mul(int x, int y) {
    return x * y;
}

int Math::Mul(int x, int y, int z) {
    return x * y * z;
}

int Math::Mul(double x, double y) {
    return (int) (x * y);
}

int Math::Mul(double x, double y, double z) {
    return (int) (x * y * z);
}

int Math::Add(int count,...) {
    int sum = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int);
        sum += num;
    }
    va_end(args);
    return sum;
}

char* Math::Add(const char* x, const char* y) {
    if (x == nullptr || y == nullptr)
        return nullptr;
    char* z = new char [strlen(x)+strlen(y)+1];
    strcpy(z, x);
    strcat(z, y);
    return z;
 
}





























/*#include"Example.h"

#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
#include<stdio.h>
#include<stdarg.h>


Example::Example() {
    this->vector = nullptr;
    this->name = nullptr;
    this->MaxNumberOfElements = 0;
    this->NumberOfElements = 0;
}

Example::Example(int maxNumber) {
    this->NumberOfElements = 0;
    this->MaxNumberOfElements = maxNumber;
    this->vector = (int*) malloc(this->MaxNumberOfElements * sizeof(int));
    this->name = (char*) malloc(256 * sizeof(char));
}

Example::~Example() {
    if (this->vector != nullptr)
        free(this->vector);
    if (this->name != nullptr)
        free(this->name);

}

void Example::AddNumber(int number) {
    if (this->NumberOfElements < this->MaxNumberOfElements && this->vector != nullptr)
        this->vector[this->NumberOfElements++] = number;
}

void Example::AddMultipleNumbers(int number1, int number2) {
    if (this->NumberOfElements + 2 < this->MaxNumberOfElements && this->vector != nullptr) {
        this->vector[this->NumberOfElements++] = number1;
        this->vector[this->NumberOfElements++] = number2;
    }
}
void Example::AddMultipleNumbers(int number1, int number2, int number3) {
    if (this->NumberOfElements + 3  < this->MaxNumberOfElements && this->vector != nullptr) {
        this->vector[this->NumberOfElements++] = number1;
        this->vector[this->NumberOfElements++] = number2;
        this->vector[this->NumberOfElements++] = number3;
    }
}
void Example::AddMultipleNumbers(int count, ...) {
    if (this->NumberOfElements + count < this->MaxNumberOfElements && this->vector != nullptr) {
        va_list vl;
        va_start(vl, count);
        for (int i = 0; i < count; i++) {
            this->vector[this->NumberOfElements++] = va_arg(vl, int);
        }
    }
}

char * Example::SetToName(const char* sir1, const char* sir2, const char* sir3) {
    int sizeToRealloc;
    sizeToRealloc = strlen(sir1) + strlen(sir2) + strlen(sir3) + 1;
    if (this->name == nullptr) {
    this->name = (char*) malloc(sizeToRealloc); 
    memset(this->name, 0, sizeToRealloc);
     }
    else {
     this->name = (char*) realloc(this->name, sizeToRealloc);
        memset(this->name, 0, sizeToRealloc);
        if (this->name != nullptr) {
            memcpy(this->name, sir1, strlen(sir1));
            memcpy(this->name + strlen(sir1), sir2, strlen(sir2));
            memcpy(this->name + strlen(sir1) + strlen(sir2), sir3, strlen(sir3));
        }
    }
       
}

void Example::PrintAll() {
    if (this->vector != nullptr ) {
        printf("Numarul maxim de elem: %d\n", this->MaxNumberOfElements);
        printf("Numarul curent de elem: %d\n", this->NumberOfElements);
        for (int i = 0; i < this->NumberOfElements; i++)
            printf("%d ", this->vector[i]);
        printf("\n");

    } 
    else {
        printf("Vectorul este null\n");
    }
    if (this->name != nullptr)
        printf("Numele este: %s\n", this->name);
    else
        printf("Numele este nullptr");

}
*/