#include <iostream>
using namespace std;

struct Nod {
    int valoare;
    Nod* urmator;
};

Nod* FaceNod(int valoare) {
    Nod* nodNou = new Nod();
    nodNou->valoare = valoare;
    nodNou->urmator = nullptr;
    return nodNou;
}

Nod* FunctieBengoasa(int n) {
    Nod* cap = FaceNod(1);
    Nod* precedent = cap;
    for (int i = 2; i <= n; ++i) {
        Nod* nodNou = FaceNod(i);
        precedent->urmator = nodNou;
        precedent = nodNou;
    }
    precedent->urmator = cap;
    return cap;
}

int josephus(int n, int k) {
    Nod* cap = FunctieBengoasa(n);
    Nod* precedent = nullptr;
    Nod* curent = cap;

    while (curent->urmator != curent) {
        for (int i = 1; i < k; ++i) {
            precedent = curent;
            curent = curent->urmator;
        }
        precedent->urmator = curent->urmator;
        cout << "Bang Bang: " << curent->valoare << endl;
        delete curent;
        curent = precedent->urmator;
    }

    int rezultat = curent->valoare;
    delete curent;
    return rezultat;
}

int main() {
    int n, k;
    cout << "Baga n: ";
    cin >> n;
    cout << "Baga si k: ";
    cin >> k;

    int rezultat = josephus(n, k);
    cout << "MARELE CASTIGATOR:" << rezultat << endl;

    return 0;
}
