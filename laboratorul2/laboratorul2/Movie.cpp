#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"
#include<string.h>


void Movie::set_name( const char* name) {
    strcpy(this->name, name);
}
const char* Movie::get_name() {
    return this->name;
}
void Movie::set_year(int year) {
    this->year = year;
}
int Movie::get_year() {
    return this->year;
}
void Movie::set_score(double score) {
    this->score = score;
}
double Movie::get_score() {
    return this->score;
}
void Movie::set_length(int length) {
    this->length = length;
}
int Movie::get_length() {
    return this->length;
}
int Movie::get_passed_years() {
    return 2023-(this->year);
}
