#include <iostream>
using namespace std;

struct Nod {
    int valoare;
    Nod* stanga;
    Nod* dreapta;

    Nod(int v) : valoare(v), stanga(nullptr), dreapta(nullptr) {}
};

Nod* insereaza(Nod* radacina, int valoare) {
    if (!radacina) return new Nod(valoare);
    if (valoare < radacina->valoare)
        radacina->stanga = insereaza(radacina->stanga, valoare);
    else if (valoare > radacina->valoare)
        radacina->dreapta = insereaza(radacina->dreapta, valoare);
    return radacina;
}

bool cauta(Nod* radacina, int valoare) {
    if (!radacina) return false;
    if (radacina->valoare == valoare) return true;
    if (valoare < radacina->valoare)
        return cauta(radacina->stanga, valoare);
    else
        return cauta(radacina->dreapta, valoare);
}

void adaugaUnic(Nod* sursa, Nod* altul, Nod*& rezultat) {
    if (!sursa) return;

    if (!cauta(altul, sursa->valoare)) {
        rezultat = insereaza(rezultat, sursa->valoare);
    }

    adaugaUnic(sursa->stanga, altul, rezultat);
    adaugaUnic(sursa->dreapta, altul, rezultat);
}

void parcurgeInOrdine(Nod* radacina) {
    if (!radacina) return;
    parcurgeInOrdine(radacina->stanga);
    cout << radacina->valoare << " ";
    parcurgeInOrdine(radacina->dreapta);
}

int main() {
    Nod* multimeA = nullptr;
    Nod* multimeB = nullptr;

    multimeA = insereaza(multimeA, 5);
    multimeA = insereaza(multimeA, 3);
    multimeA = insereaza(multimeA, 7);
    multimeA = insereaza(multimeA, 2);
    multimeA = insereaza(multimeA, 4);

    multimeB = insereaza(multimeB, 6);
    multimeB = insereaza(multimeB, 3);
    multimeB = insereaza(multimeB, 8);
    multimeB = insereaza(multimeB, 7);

    Nod* rezultat = nullptr;

    adaugaUnic(multimeA, multimeB, rezultat);
    adaugaUnic(multimeB, multimeA, rezultat);

    cout << "Diferenta simetrica este: ";
    parcurgeInOrdine(rezultat);
    cout << endl;

    return 0;
}
