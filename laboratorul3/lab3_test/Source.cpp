#include<iostream>
#include"Math.h"
using namespace std;

int main() {
 
    cout << Math::Add(5, 6)<<endl;
    cout << Math::Add(5.2, 6.7)<<endl;
    cout << Math::Mul(3, 4)<<endl;
    cout << Math::Mul(3.5, 6.8)<<endl;
    cout << Math::Add(3,6,5,4)<<endl;
    cout << Math::Add("Buna dimineata", " s-a trezit dulceata")<<endl;
    char* word = Math::Add("Buna dimineata", " s-a trezit dulceata");
    delete[] word;
}