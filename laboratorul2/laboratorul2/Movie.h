#pragma once
class Movie {
  private:
    char name[256];
    int year;
    double score;
    int length;
    int passed_years;


  public:
    void set_name(const char* name);
    const char* get_name();
    void set_year(int year);
    int get_year();
    void set_score(double score);
    double get_score();
    void set_length(int length);
    int get_length();
    int get_passed_years();
};
