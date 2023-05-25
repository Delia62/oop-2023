#include <iostream>
#include <vector>
#include "Contact.h"
#include "Agenda.h"
#include "Coleg.h"
#include "Cunoscut.h"
#include "Prieten.h"
using namespace std;

int main() {
    Agenda agenda;

    agenda.Adaugare_contact(new Prieten("Sidonia Ionescu ", "13/09/1879", "07601222", "Str.Mare, nr. 45"));
    agenda.Adaugare_contact(new Prieten("Necule Ionescu ", "13/09/1879", "0760125267", "Str.Mare, nr. 45"));
    agenda.Adaugare_contact(new Cunoscut("Alexandru Popescu", "0760555566"));
    agenda.Adaugare_contact(new Coleg("Vasile Mare", "0760678987", "Vaile SRL", "Str.Bulevardului , nr. 23"));

    Contact* contact = agenda.Cautare_contact("Sidonia Ionescu");
    if (contact != nullptr) {
        cout << "Contactul " << contact->getNume() << " a fost gasit." << std::endl;
    } else {
        cout << "Contactul nu a fost gasit." << std::endl;
    }

    agenda.Stergere_contact("Alexandru Popescu");

    vector<Prieten*> prieteni = agenda.Lista_prieteni();
    cout << "Lista de prieteni:" << std::endl;
    for (auto it = prieteni.begin(); it != prieteni.end(); ++it) {
        cout << (*it)->getNume() << ", " << (*it)->getDataNastere() << ", " << (*it)->getNumarTelefon() << ", "
             << (*it)->getAdresa() << endl;
    }

    return 0;
}