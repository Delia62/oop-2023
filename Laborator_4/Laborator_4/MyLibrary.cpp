#define _CRT_SECURE_NO_WARNINGS
#include "MyLibrary.h"
#include<iostream>
#include<stdarg.h>
#include<string.h>
#include <initializer_list>



MyLibrary::MyLibrary(const MyLibrary& others) : books(others.books), books_count(others.books_count), output_stream(others.output_stream) {
    //std::cout << "###############################################################";
}

MyLibrary::~MyLibrary() {
    delete[] books;
}


MyLibrary::MyLibrary(std::ostream& output_stream) : output_stream(output_stream)  {
    this->books_count = -1;
    this->books = nullptr;
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int* books) : output_stream(output_stream) {
    if (books_count > 0) {
    this->books = (int*) (calloc(books_count, sizeof(int)));
    this->books_count = books_count;
    for (int i = 0; i < books_count; i++) {
        this->books[i] = books[i];
    }

    }
    
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max) : output_stream(output_stream) {
    this->books= (int*) (malloc(books_count * sizeof(int)));
    this->books_count = books_count;
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < this->books_count; i++) {
        this->books[i] = min + rand() % (min - (max - 1) + 1);
    }

}
MyLibrary::MyLibrary(std::ostream& output_stream, const char* books_values) : output_stream(output_stream) {
    int i;
    char* c = NULL;
    c = new char[strlen(books_values)];
    this->books = new int[100];
    int nr = 0;
    strcpy(c, books_values);
    char* p = strtok(c, ";");
    while (p) {
        int x = 0;
        for (i = 0; i < strlen(p); i++)
            x = x * 10 + p[i] - '0';
        this->books[nr] = x;
        p = strtok(NULL, ";");
        nr++;
        this->books_count++;
    }


}
MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, ...) : output_stream(output_stream) {
    if (books_count > 0) {
    this->books = (int*) (calloc(books_count, sizeof(int)));
    this->books_count = books_count;
    va_list v1;
    va_start(v1, books_count);
    for (int i = 0; i < books_count; i++) {
        this->books[i] = va_arg(v1, int);
    }
    va_end(v1);
    }
    

}
MyLibrary::MyLibrary(std::initializer_list<int> v) : output_stream(std::cout) /* : MyLibrary(std::cout, v.size(), v.begin(), v.end()) */ {
    books = new int[v.size() + 1];
    books_count = 0;
    int i = 0;
    for (int element : v) {
    books[i] = element;
    books_count++;
    i++;
    }
    /* if (!std::empty(v)) {
    int i = 0;
    books = new int[v.size() + 1];
    for (const auto& x : v) {
        books[i] = x;
        books_count++;
        i++;
    }*/
     
}

void MyLibrary::print_books() const{ 
    
    int books_count = this->books_count;
    if (books_count <= 0)
       output_stream << "Found -1 books" <<'\n';
    else{
        
        if (this->books == nullptr)
        output_stream << "-1" <<'\n';
       else {
           output_stream << "Found : " << books_count << " books"<<'\n';
           for (unsigned i = 0; i < books_count; i++)
           output_stream << *(this->books + i) << " ";
           output_stream << '\n';
           }
       
     }
       
}

void MyLibrary::update_book_id_by_index(unsigned book_index, int book_id) const {

    if (book_index <= books_count)
        books[book_index] = book_id;
   // std::cout << this->books[book_index];
    //std::cout << "###############################################################";
}
unsigned MyLibrary::get_books_count() const {
    return this->books_count;
      }
int MyLibrary::get_book_id_by_index(int index) const {
    if (index < this->books_count)
        return this->books[index];
    else
        return -1;
      }
