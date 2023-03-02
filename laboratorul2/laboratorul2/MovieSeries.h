#pragma once
#include"Movie.h";
class MovieSeries {
  private:
    Movie* film[16];
    int cnt;

  public:
    void init();
    bool add(Movie* x);
    void print();
    void sort();
     
};
