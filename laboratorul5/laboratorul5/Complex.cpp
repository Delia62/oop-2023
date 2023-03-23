

#include "Complex.h"
#include<math.h>
#include<stdlib.h>

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}
 Complex Complex::conjugate() const {
    return { real(), -imag() };
}
 Complex& Complex::operator()(double real, double imag) {
    this->real_data = real;
    this->imag_data = imag;
    return *this;


}
Complex operator+(const Complex& l, const Complex& r) {
  
    return { l.real() + r.real(), l.imag() + r.imag() };
}
Complex operator+(const Complex& l, double r) {
  
   const  Complex rez(r, 0);
    return l + rez;
}
 Complex operator+(double l, const Complex& r) {
    
   const Complex rez(l, 0);
    return rez + r;
  

}
 Complex operator-(const Complex& l, const Complex& r) {
    return { l.real() - r.real(), l.imag() - r.imag() };

}
 Complex operator-(const Complex& l, double r) {
   const Complex rez(r, 0);
    return l - rez;
}
 Complex operator-(double l, const Complex& r) {
    const Complex rez(l, 0);
    return rez - r;
}
 Complex operator*(const Complex& l, const Complex& r) {
    return { l.real() * r.real() - l.imag() * r.imag(), l.real() * r.imag() + l.imag() * r.real() };
}
 Complex operator*(const Complex& l, double r) {
    const Complex rez(r, 0);
    return l * rez;
}
Complex operator*(double l, const Complex& r) {
    const Complex rez(l, 0);
    return rez * r;
}

 Complex operator-(const Complex& obj) {

     return { -obj.real(), -obj.imag() };
 }

bool operator==(const Complex& l, const Complex& r) {
     if (l.real() == r.real())
         if (l.imag() == r.imag())
             return true;
     return false;
}
bool operator!=(const Complex& l, const Complex& r) {
     if (l.real() != r.real())
         if (l.imag() != r.imag())
             return true;
     return false;
}

std::ostream& operator<<(std::ostream& out, const Complex& complex) {
     if (complex.imag() == 0 && complex.real() == 0)
         out << "0";
     else if (complex.imag() == 0 && complex.real() != 0)
         out << complex.real();
     else if (complex.imag() != 0 && complex.real() == 0)
         out << "0"<< " + "<< complex.imag() << "i";
     else if (complex.imag() > 0 && complex.real() != 0)
         out << complex.real() << " + " << complex.imag() << "i";
     else
         out << complex.real() << " - " << abs(complex.imag()) << "i";
     return out;


}
Complex& Complex::operator++() {
     ++real_data;
     return *this;
}
Complex Complex::operator++(int) {
     Complex copy(*this);
     ++(*this);
     return copy;
}
Complex& Complex::operator--() {
     --real_data;
     return *this;
}
Complex Complex::operator--(int) {
     Complex copy(*this);
    --(*this);
    return copy;
}






                                          
 



