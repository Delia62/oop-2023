#pragma once
#include "Contact.h"
#include <string>
using namespace std;
class Coleg : public Contact {
  private:
    string numar_telefon;
    string firma;
    string adresa;

  public:
    Type get_type() override {
        return Type::coleg;
    }
    Coleg(string nume, string numar_tel, string firma, string adresa)
        : Contact(nume), numar_telefon(numar_tel), adresa(adresa), firma(firma) {
    }
    string getNumarTelefon() const {
        return numar_telefon;
    }
    string getFirma() const {
        return firma;
    }
    string getAdresa() const {
        return adresa;
    }
};
