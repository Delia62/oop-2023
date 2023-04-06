#include <iostream>
float operator"" _Kelvin(unsigned long long int x) {
    float kel = x - 273.15f;
    return kel;
}

float operator"" _Fahrenheit(unsigned long long int x) {
    float fah = (x - 32) / 1.8;
    return fah;
} 

int main() {
    float a = 300_Kelvin;

    float b = 120_Fahrenheit;
    std::cout << a << " " << b;
    return 0;
}