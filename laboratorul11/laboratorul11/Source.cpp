#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <iostream>
#include <string.h>

struct Empty : std::exception {
    const char* what() const noexcept override {
        return " The queue is empty";
    }
};
template <typename T>

class CircularQueue {
  private:
    std::vector<T> coada;
    int count;
    int inceput;
    int final;
    int size;

  public:
    CircularQueue(int size) : size(size) {
        count = 0;
        inceput = 0;
        final = 0;
        coada.resize(size);
    }
    int Size() {
        return count;
    }
    void push(T val) {
        if (count == size) {
            coada[inceput] = val;
            inceput = (inceput + 1) % size;
            final = (final + 1) % size;
        } else {
            coada[final] = val;
            final = (final + 1) % size;
            count++;
        }
    }

    void pop() {
        if (count != 0) {
            count--;
            inceput = (inceput + 1) % size;
        } else
            throw Empty();
    }
    T& front() {
        if (count == 0)
            throw Empty();
        else {
            int firstElem = (inceput - 1 + size) % size;
            return coada[firstElem];
        }
    }
    T& back() {
        if (count == 0)
            throw Empty();
        else {
            int backElem = (final - 1 + size) % size;
            return coada[backElem];
        }
    }
    bool empty() {
        if (count == 0)
            return true;
        else
            return false;
    }
};
TEST_CASE("check that the size is 2") {
    CircularQueue<int> p(4);
    p.push(1);
    p.push(9);
    REQUIRE(p.Size() == 2);
}
TEST_CASE("check something") {
    CircularQueue<std::string> p(4);
    p.push("Buna dimi");
    p.push("Alta data");
    REQUIRE(p.Size() == 2);
}

TEST_CASE("check that the queue is empty") {
    CircularQueue<int> p(4);
    p.push(1);
    p.pop();
    REQUIRE(p.empty());
}
TEST_CASE("check the first and the last element ") {
    CircularQueue<int> p(4);
    p.front();
    p.back();
    REQUIRE(p.Size() > 0);
}
TEST_CASE("check that the first element is the 5th added element ") {
    CircularQueue<int> p(4);
    p.push(1);
    p.push(2);
    p.push(3);
    p.push(4);
    p.push(5);
    REQUIRE(p.front() == 5);
}
TEST_CASE("add 1000 elements; pop all of them and check that they are correct ") {
    CircularQueue<int> p(4);
    for (int i = 0; i < 1000; i++) {
        p.push(i);
    }
    for (int i = 0; i < 1000; i++) {
        p.pop();
    }
    REQUIRE(p.empty());
}
TEST_CASE("add 4 elements; pop all of them ") {
    CircularQueue<int> p(4);
    for (int i = 0; i < 4; i++) {
        p.push(i);
    }
    for (int i = 0; i < 4; i++) {
        p.pop();
    }
    REQUIRE(p.empty());
}
