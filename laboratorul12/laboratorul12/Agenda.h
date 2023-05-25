#pragma once
#include "Contact.h"
#include "Prieten.h"
#include <vector>

class Agenda {
  private:
    vector<Contact*> contacte;

  public:
    Contact* Cautare_contact(string nume) const {
        for (auto it = contacte.begin(); it != contacte.end(); ++it) {
            if ((*it)->getNume() == nume) {
                return *it;
            }
        }
        return nullptr;
    }
    void Stergere_contact(string nume) {
        for (auto it = contacte.begin(); it != contacte.end(); ++it) {
            if ((*it)->getNume() == nume) {
                delete *it;
                contacte.erase(it);
                break;
            }
        }
    }
    vector<Prieten*> Lista_prieteni() const {
        vector<Prieten*> prieteni;
        for (auto it = contacte.begin(); it != contacte.end(); ++it) {
            if ((*it)->get_type() == Type::prieten) {
                prieteni.push_back(dynamic_cast<Prieten*>(*it));
            }
        }
        return prieteni;
    }

    void Adaugare_contact(Contact* x) {
        contacte.push_back(x);
    }
};
