#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
        int n,i;
        scanf("%d",&n);
        char**prop=(char**)malloc(n*sizeof(char*));
        for(i=0;i<n;i++){
            prop[i]=(char*)malloc(1000*sizeof(char));
              fgets(prop[i],1000,stdin);
              getchar();
              }

              int nr=0;
              {for(i=0;i<n;i++)
                nr=nr+strlen(prop[i]);
                getchar();}
                for(i=0;i<n;i++)
                    pritnf("%s",prop[i]);
              printf("Nr de caractere citite %d este ",nr);

    return 0;
}
