#include <stdio.h>
#include <stdlib.h>

int main()
{
   int s,ziua=0,suma=0,b,m;
   printf("Cat costa jucaria??\n");
   scanf("%d",&s);
   while(s>=suma)
   {
       printf("Cat a depus in ziua %d  ?\n",ziua);
       scanf("%d",&b);
       suma=suma+b;
       ziua++;
   }
   printf("Gigel a strans banii dupa %d  zile\n  ",ziua);
   m=suma/ziua;
   printf("A strans in medie %d   roni pe zi\n",m);

   printf("I-au ramas %d   roni\n ",suma-s);

    return 0;
}
