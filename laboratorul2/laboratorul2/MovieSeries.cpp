#include "MovieSeries.h"
#include <string.h>
#include <cstdio>
#include <algorithm>


void MovieSeries::init() {
    cnt = 0;
}
bool MovieSeries::add(Movie *x) {
    if (cnt < 16)
        return false;
    else {
        film[cnt] = x;
        cnt++;
    }
    return true;
}
void MovieSeries::print() {
    for (int i = 0; i < cnt; i++) {
        printf(
              "%s,%d,%1.f,%d,%d\n",
              film[i]->get_name(),
              film[i]->get_year(),
              film[i]->get_score(),
              film[i]->get_length(),
              film[i]->get_passed_years());
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
