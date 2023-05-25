#pragma once
#include "Contact.h"
class Cunoscut : public Contact {
  private:
    string numar_telefon;

  public:
    Type get_type() override {
        return Type::cunoscut;
    }
    Cunoscut(string nume, string numar) : Contact(nume), numar_telefon(numar) {
    }
    string getNumarTelefon() const {
        return numar_telefon;
    }
};
