#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void insertInTable1(std::vector<int>& table1, std::vector<int>& table2, int key, int size);
void insertInTable2(std::vector<int>& table1, std::vector<int>& table2, int key, int size);
int hash1(int key, int size);
int hash2(int key, int size);
void insert(std::vector<int>& table1, std::vector<int>& table2, int key, int size);
bool search(const std::vector<int>& table1, const std::vector<int>& table2, int key, int size);
void remove(std::vector<int>& table1, std::vector<int>& table2, int key, int size);
void display(const std::vector<int>& table1, const std::vector<int>& table2, int size);

int main() {

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int n = 10;

    std::vector<int> table1(n, -1);
    std::vector<int> table2(n, -1);

    for (int i = 0; i < n; ++i) {
        int key = std::rand() % 100;
        std::cout << "Inserare: " << key << std::endl;
        insert(table1, table2, key, n);
    }

    display(table1, table2, n);

    int keyToSearch;
    std::cout << "Introduceti cheia care doriti sa fie cautata: ";
    std::cin >> keyToSearch;
    std::cout << "Cautare " << keyToSearch << ": ";
    if (search(table1, table2, keyToSearch, n)) {
        std::cout << "Gasit\n";
    } else {
        std::cout << "Nu a fost gasit\n";
    }

    int keyToRemove;
    std::cout << "Introduceti cheia care doriti sa fie stearsa: ";
    std::cin >> keyToRemove;
    std::cout << "stergere " << keyToRemove << "\n";
    remove(table1, table2, keyToRemove, n);
    display(table1, table2, n);

    return 0;
}

int hash1(int key, int size) {
    return key % size;
}

int hash2(int key, int size) {
    return (key / size) % size;
}

void insertInTable1(std::vector<int>& table1, std::vector<int>& table2, int key, int size) {
    int idx = hash1(key, size);
    if (table1[idx] == -1) {
        table1[idx] = key;
    } else {
        int evictedKey = table1[idx];
        table1[idx] = key;
        insertInTable2(table1, table2, evictedKey, size);
    }
}

void insertInTable2(std::vector<int>& table1, std::vector<int>& table2, int key, int size) {
    int idx = hash2(key, size);
    if (table2[idx] == -1) {
        table2[idx] = key;
    } else {
        int evictedKey = table2[idx];
        table2[idx] = key;
        insertInTable1(table1, table2, evictedKey, size);
    }
}

void insert(std::vector<int>& table1, std::vector<int>& table2, int key, int size) {
    insertInTable1(table1, table2, key, size);
}

bool search(const std::vector<int>& table1, const std::vector<int>& table2, int key, int size) {
    return table1[hash1(key, size)] == key || table2[hash2(key, size)] == key;
}

void remove(std::vector<int>& table1, std::vector<int>& table2, int key, int size) {
    if (table1[hash1(key, size)] == key) {
        table1[hash1(key, size)] = -1;
    } else if (table2[hash2(key, size)] == key) {
        table2[hash2(key, size)] = -1;
    }
}

void display(const std::vector<int>& table1, const std::vector<int>& table2, int size) {
    std::cout << "Tabelul 1: ";
    for (int i = 0; i < size; ++i) {
        std::cout << table1[i] << " ";
    }
    std::cout << "\nTabelul 2: ";
    for (int i = 0; i < size; ++i) {
        std::cout << table2[i] << " ";
    }
    std::cout << std::endl;
}
