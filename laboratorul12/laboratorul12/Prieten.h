#pragma once
#include "Contact.h"
#include <string>
using namespace std;

class Prieten : public Contact {
  private:
    string data;
    string adresa;
    string numar_telefon;

  public:
    Type get_type() override {
        return Type::prieten;
    }
    Prieten(string nume, string data, string numar, string adresa)
        : Contact(nume), numar_telefon(numar), data(data), adresa(adresa) {
    }
    string getDataNastere() const {
        return data;
    }
    string getNumarTelefon() const {
        return numar_telefon;
    }
    string getAdresa() const {
        return adresa;
    }
};
