#include <stdio.h>
#include <stdlib.h>
#define UNU(x) x+2*x
#define DOI(x) (x)+(2*x)
#define TREI(x) (x+2*x)
/*int main()
{
    int n=3,m=4;
    int a[n][m],i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        a[i][j]=i*j;
    i=2;
    for(j=0;j<m;j++)
        printf("%d",*(*(a+i)+j));
    return 0;
}*/
int main()
{
   int a=3;
    printf("%d%d%d\n",2*UNU(a+1),2*DOI(a+1),2*TREI(a+1),a);
    return 0;
}
