#include <stdio.h>
#include <stdlib.h>


void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}

int cmp1(const void*a, const void*b)
{
    return *(const int*)a - *(const int *)b;
}

int funkcja(int y, int tab[][y], int x, int val){

qsort(tab, x*y, sizeof(int), cmp1);
int* found = bsearch(&val, tab, x*y, sizeof(int), cmp1);
if(found)
{
    int indeks = found-tab[0];
    return (indeks%y);
}
else
{
    printf("Nie znaleziono wartosci %d w tablicy.", val);
    return -1;
}
}
int main (void)
{
    int tab_A[3][6] = {{1,-4,1,2,11},{12,2,32,2},{72,2,-32,2}};
int tab_B[4][3] = {{1,-24,1},{9,32,2},{5,64,1},{3,32,1}};
    int indeks_wiersza = funkcja(6,tab_A,3,11);
    if(indeks_wiersza!=-1)
        wypisz_i(*(tab_A+indeks_wiersza),*(tab_A+indeks_wiersza)+6);
    
    indeks_wiersza=funkcja(3,tab_B,4, 9);
    if(indeks_wiersza!=-1)
        wypisz_i(*(tab_B+indeks_wiersza),*(tab_B+indeks_wiersza)+3);
    
     indeks_wiersza=funkcja(3,tab_B,4, 8000);
     if(indeks_wiersza!=-1)
        wypisz_i(*(tab_B+indeks_wiersza),*(tab_B+indeks_wiersza)+3);
    return 0;
}