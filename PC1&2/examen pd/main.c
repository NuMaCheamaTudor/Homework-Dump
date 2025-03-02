#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void primele2(int num, char* rez)
{
    char numstr[20];
    snprintf(numstr,sizeof(numstr),"%d",num);
    strncpy(rez,numstr,2);
    rez[2]= '\0';
}
void ultim2(int num, char* rez)
{
    char numstr[20];
    snprintf(numstr,sizeof(numstr),"%d",num);
    int len = strlen(numstr);
    if(len>1)
    {
        strncpy(rez,numstr+len-2,2);
    }
    else
        {
            rez[0]=numstr[0];
    rez[1]= '\0';
        }
        rez[2]= '\0';
}
void cmls(int* numere, int n, int* rez, int* rezsize)
{

}
int main()
{

    return 0;
}
