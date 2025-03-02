#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    int i;

    typedef struct{
    char denumire[15],  categorie[15];
    float pret;
    }produs;
    scanf("%d",&n);
    produs *a=malloc(n*sizeof(int));
    for ( i = 0; i < n; i++) {
        printf("Introduceti denumirea pentru produsul %d: ", i + 1);
        scanf("%s", a[i].denumire);
        printf("Introduceti categoria pentru produsul %d: ", i + 1);
        scanf("%s", a[i].categorie);
        printf("Introduceti pretul pentru produsul %d: ", i + 1);
        scanf("%f", &a[i].pret);
    }
    for(i=n-1;i>0;i--)
    {
        if(strcmp(a[i].denumire,"papetarie")==0)
            printf(a[i].denumire);
            }
}
