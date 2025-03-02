#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ID, ts, tf;
} Activitate;

// Functie comparator
int cmpActivitati(const void *p, const void *q) {
    return ((Activitate*)p)->ts - ((Activitate*)q)->ts;
}

int main() {
    int i, n, numar_sali = 0;
    int hs, ms, hf, mf;

    // Vectorul de activitati
    Activitate A[100];
    // Matricea pentru a tine evidenta activitatilor planificate
    int sali[100][100] = {{0}};

    FILE *fin = fopen("activitati.txt", "r");
    fscanf(fin, "%d", &n);

    for(i = 0; i < n; i++) {

        fscanf(fin, "%d: %d:%d-%d:%d", &A[i].ID, &hs, &ms, &hf, &mf);
        A[i].ts = hs * 60 + ms;
        A[i].tf = hf * 60 + mf;
    }
    fclose(fin);

    // Sortam activitatile dupa timpul de inceput
    qsort(A, n, sizeof(Activitate), cmpActivitati);

    // Planificam activitatile in sali
    for(i = 0; i < n; i++) {
        int j, sala_disponibila = -1;
        // Cautam o sala disponibila pentru activitate
        for(j = 0; j < numar_sali; j++) {
            // Daca activitatea curenta nu se suprapune cu nicio activitate din sala j
            if(A[i].ts >= A[sali[j][sali[j][0] - 1] - 1].tf) {
                sala_disponibila = j;
                break;
            }
        }
        // Daca am gasit o sala disponibila, adaugam activitatea in acea sala
        if(sala_disponibila != -1) {
            sali[sala_disponibila][0]++;
            sali[sala_disponibila][sali[sala_disponibila][0]] = A[i].ID;
        }
        // Altfel, alocam o sala noua pentru activitatea curenta
        else {
            sali[numar_sali][0] = 1;
            sali[numar_sali][1] = A[i].ID;
            numar_sali++;
        }
    }

    // Afisam planificarea activitatilor
    printf("Ca sa faci mare bairam iti trebuie %d sali:\n", numar_sali);
    for(i = 0; i < numar_sali; i++) {
        printf("Sala %d: ", i + 1);
        for(int j = 1; j <= sali[i][0]; j++) {
            printf("%d", sali[i][j]);
            if (j < sali[i][0])
                printf(", ");
            else
                printf("\n");
        }
    }

    return 0;
}
