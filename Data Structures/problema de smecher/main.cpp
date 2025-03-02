#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int alege_poz_pivot(int* v, int st, int dr) {
    return (st + dr) / 2;
}

int partition_Lomuto(int* v, int st, int dr) {
    int poz_pivot = alege_poz_pivot(v, st, dr);
    swap(v[poz_pivot], v[dr]);
    int i = st - 1;

    for (int j = st; j < dr; j++) {
        if (v[j] < v[dr]) {
            swap(v[++i], v[j]);
        }
    }
    swap(v[i + 1], v[dr]);
    return i + 1;
}

bool isSorted(int a[], int n) {
    while (--n > 0)
        if (a[n] < a[n - 1])
            return false;
    return true;
}

void shuffle(int a[], int n) {
    for (int i = 0; i < n; i++)
        swap(a[i], a[rand() % n]);
}

void bogosort(int a[], int n) {
    while (!isSorted(a, n))
        shuffle(a, n);
}

void quicksort(int* v, int st, int dr, int nivel) {
    const int k = 45;
    if (st < dr) {
        if (dr - st + 1 <= k) {
            bogosort(v + st, dr - st + 1);
        } else {
            int poz_pivot = partition_Lomuto(v, st, dr);
            quicksort(v, st, poz_pivot - 1, nivel + 1);
            quicksort(v, poz_pivot + 1, dr, nivel + 1);
        }
    }
}

int is_sorted(int* v, int st, int dr) {
    for (int i = st; i < dr; i++)
        if (v[i] > v[i + 1])
            return 0;
    return 1;
}

int main() {
    srand(time(NULL));

    int n = 15;
    int v[n];

    for (int i = 0; i < n; i++)
        v[i] = rand() % 25;

    cout << "Initial array:" << endl;
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;

    quicksort(v, 0, n - 1, 0);

    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;

    cout << (is_sorted(v, 0, n - 1) ? "SORTAT " : "!!!!NESORTAT") << endl;

    return 0;
}
