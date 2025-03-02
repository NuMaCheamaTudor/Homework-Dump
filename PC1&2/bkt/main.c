#include <stdio.h>
#include <stdlib.h>

int maxim(int a, int b) {
    return a > b ? a : b;
}

int backtrack(int t[100][100], int i, int j, int n) {
    if (i == n - 1) {
        return t[i][j];
    }
    int stanga = backtrack(t, i + 1, j, n);
    int dreapta = backtrack(t, i + 1, j + 1, n);
    return t[i][j] + maxim(stanga, dreapta);
}

int main() {
    int n, i, j, t[100][100];
    FILE* f = fopen("triunghi.txt", "r");
    fscanf(f, "%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            fscanf(f, "%d", &t[i][j]);
        }
    }
    fclose(f);

    int suma = backtrack(t, 0, 0, n);
    printf("Suma maxima:(bkt) %d\n", suma);

    return 0;
}
