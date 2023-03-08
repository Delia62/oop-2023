#pragma once

class Math

{
  public:
    static int Add(int, int);

    static int Add(int, int, int);

    static int Add(double, double);

    static int Add(double, double, double);

    static int Mul(int, int);

    static int Mul(int, int, int);

    static int Mul(double, double);

    static int Mul(double, double, double);

    static int Add(int count, ...); // sums up a list of integers

    static char* Add(const char*, const char*);
};





























/* class Example {

	int* vector;
    int MaxNumberOfElements;
    int NumberOfElements;
    char* name;

  public:
    Example();
    Example(int maxNumber);
    ~Example();

    void AddNumber(int number);
    void AddMultipleNumbers(int number1, int number2);
    void AddMultipleNumbers(int number1, int number2, int number3);
    char* SetToName(const char* sir1, const char* sir2, const char* sir3);
    void AddVariadicNumbers(int count, ...);
    void PrintAll();

};*/
