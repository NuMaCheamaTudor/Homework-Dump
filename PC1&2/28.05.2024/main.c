#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, i, j, t[100][100];
    FILE* f = fopen("triunghi.txt", "r");
    fscanf(f, "%d", &n);
    for(i = 0; i < n; i++)
        for(j = 0; j <= i; j++)
            fscanf(f, "%d", &t[i][j]);
    fclose(f);

    int suma_maxima = t[0][0];
    int coloana = 0;

    printf("Traseul cu suma maxima (greedy):\n");
    printf("t[0][0] = %d\n", t[0][0]);

    for(i = 1; i < n; i++) {
        if (t[i][coloana] > t[i][coloana + 1]) {
            suma_maxima += t[i][coloana];
        } else {
            coloana++;
            suma_maxima += t[i][coloana];
        }
        printf("t[%d][%d] = %d\n", i, coloana, t[i][coloana]);
    }

    printf("Suma maxima: %d\n", suma_maxima);
    return 0;
}
