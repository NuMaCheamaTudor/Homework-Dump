#include <stdio.h>
#include <stdlib.h>

int cmp_desc(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    if (num1 % 2 != 0 && num2 % 2 != 0)
        return (num2 - num1);
    else if (num1 % 2 != 0)
        return -1;
    else if (num2 % 2 != 0)
        return 1;
    else
        return (num1 - num2);
}
int main()
{
    int n,i,*v;

scanf("%d",&n);
*v=(int*)malloc(n*sizeof(int));
for(i=0;i<n;i++)
    scanf("%d",&v[i]);
     qsort(v, n, sizeof(int), cmp_desc);
for(i=0;i<n;i++)
    printf("%d ",v[i]);



}
