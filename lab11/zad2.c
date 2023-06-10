#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
char *va_cat(int dl, ...)
{
char *wynik = calloc(1,sizeof(char));
char *pom;
int wynik_len = 1;
va_list argptr;
va_start(argptr, dl);
for(int i = 0; i < dl; i++){
pom = va_arg(argptr,char *);
wynik_len += strlen(pom);
wynik = realloc(wynik,wynik_len * sizeof(char));
strcat(wynik,pom);
}
va_end(argptr);
return wynik;
}

int main (int argc, char**argv)
{
char* napis1 = "If you never did You should."; 
char* napis2 = " These things are fun";
char* napis3 = " and Fun is good.";

char *wynik = va_cat(3,napis1,napis2,napis3);
puts(wynik);
FILE* plik1 = fopen("plik.txt", "w");

if(plik1){
fputs(wynik, plik1);
fclose(plik1);}
free(wynik);
char* nn1 = "Sometimes ";
char* nn2 = "you will never know ";
char* nn3 = "the value of a moment ";
char* nn4 = "until it becomes a memory.";

wynik = va_cat(4,nn1,nn2,nn3,nn4);
puts(wynik);
FILE* plik2 = fopen("plik.txt", "w");

if(plik2){
fputs(wynik, plik2);
fclose(plik2);}
free(wynik);



    return 0;
}