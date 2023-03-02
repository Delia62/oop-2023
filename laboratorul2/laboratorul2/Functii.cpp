#include"Functii.h"
#include"Movie.h"
#include<string.h>
int movie_compare_name(Movie x, Movie y) {
    if (strcmp(x.get_name(),y.get_name()) < 0)
         return -1;
     else
         if(strcmp(x.get_name(),y.get_name()) == 0)
             return 0;
      return 1;
}
int movie_compare_year(Movie x, Movie y) {
    if (x.get_year() < y.get_year())
        return -1;
    else if (x.get_year() == y.get_year())
        return 0;
    return 1;
}
int movie_compare_score(Movie x, Movie y) {
    if (x.get_score() < y.get_score())
        return -1;
    else if (x.get_score() == y.get_score())
        return 0;
    return 1;
}

int movie_compare_length(Movie x, Movie y) {
    if (x.get_length() > y.get_length())
        return 1;
    else if (x.get_length() == y.get_length())
        return 0;
    return -1;
}

int movie_compare_passed_years(Movie x, Movie y) {
    if (x.get_passed_years() < y.get_passed_years())
        return -1;
    else if (x.get_passed_years() == y.get_passed_years())
        return 0;
    return 1;
}
