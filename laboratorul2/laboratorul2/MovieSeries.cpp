#include "MovieSeries.h"
#include <string.h>
#include <cstdio>
#include <algorithm>
#include<iostream>
using namespace std;


void MovieSeries::init() {
    cnt = 0;
}
bool MovieSeries::add(Movie* x) {
    if (cnt > 16)
        return false;
    else {
        film[cnt] = x;
        cnt++;
    }
    return true;
}
void MovieSeries::print() {
    for (int i = 0; i < cnt; i++) {
        cout << film[i]->get_name() << endl; 
        cout << film[i]->get_year() << endl;
        cout << film[i]->get_score() << endl;
        cout << film[i]->get_length() << endl;
        cout << film[i]->get_passed_years() << endl;


    }
}

void MovieSeries::sort() {
    for (int i = 0; i < cnt - 1; i++)
        for (int j = i + 1; j < cnt; j++) {
            if (film[i]->get_passed_years() < film[j]->get_passed_years()) {
                std::swap(film[i], film[j]);
            }
        }
}
