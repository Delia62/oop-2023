#pragma once
#include <string>
using namespace std;
enum Type { prieten, coleg, cunoscut };

class Contact {
  private:
    string nume;

  public:
    virtual Type get_type() = 0 {};
    Contact(string nume) : nume(nume) {
    }
    string getNume() const {
        return nume;
    }
    ~Contact() {
    }
};
