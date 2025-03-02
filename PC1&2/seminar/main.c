#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
void cautare_cuvant(char *cuv, char *nfout, ...)
{
FILE *fin, *fout;
char *nfin, *p;
int lcrt, g;
char linie[1001];
va_list fisiere;
va_start(fisiere, nfout);
fout = fopen(nfout, "w");
while((nfin = va_arg(fisiere, char*)) != NULL)
{
fin = fopen(nfin, "r");
fprintf(fout, &quot;Fisierul %s\n&quot;, nfin);
fprintf(fout, &quot;Liniile: &quot;);
lcrt = 1;
g = 0;
while(fgets(linie, 1001, fin) != NULL)
{
p = strtok(linie, &quot; :;,.?!\n&quot;);
while(p != NULL)
{
if(strcmp(p, cuv) == 0)
{
fprintf(fout, &quot;%d &quot;, lcrt);
g = 1;
break;
}
p = strtok(NULL, &quot; :;,.?!\n&quot;);
}
lcrt++;

7 / 2

}
if(g == 0)
fprintf(fout, &quot;-&quot;);
fprintf(fout, &quot;\n\n&quot;);
fclose(fin);
}
va_end(fisiere);
fclose(fout);
}
int main()
{
cautare_cuvant(&quot;lac&quot;, &quot;rez.txt&quot;, &quot;eda.txt&quot;, &quot;nu.txt&quot;, NULL);
return 0;
}
