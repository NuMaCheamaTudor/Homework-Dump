#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int x;
    int y;
}Point;
Point p;
p.x=30;
p.y=40;
Point *a=&p;
Point **b = &a;
int main()
{
    printf("%d",a);

    return 0;
}
