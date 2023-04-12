#include <stdio.h>
#include <stdlib.h>

void swap (int *p, int *q) { 
  int temp = *p;
  *p = *q;
  *q = temp;
  return;}
void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}
void swap_tab (int* A, int* B, int n)
{
    for (int i = 0; i < n; i++)
    {
        swap(A+i, B+i);
    }
}
void swap_rows (int n, int (*TAB)[n], int x, int y)
{
    swap_tab (*(TAB+x), *(TAB+y), n);
}
int main (void)
{
    int tab_1[4][5] = {{1,1,1,1,1},{2,2,2,2,2},{3,3,3,3,3},{4,4,4,4,4}};
    printf ("Tab1 przed zamiana:\n");
    for (int i = 0; i < 4; i++)
    {
        wypisz_i(*(tab_1+i), *(tab_1+i)+5);
        printf("\n");
    }
    swap_rows(5, tab_1, 1, 3);
    printf ("Tab1 po zamianie:\n");
    for (int i = 0; i < 4; i++)
    {
        wypisz_i(*(tab_1+i), *(tab_1+i)+5);
        printf("\n");
    }
    
    
    int tab_2[5][2] = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    printf ("Tab2 przed zamiana:\n");
    for (int i = 0; i < 5; i++)
    {
        wypisz_i(*(tab_2+i), *(tab_2+i)+2);
        printf("\n");
    }
    swap_tab(*(tab_2+1),*(tab_2+2), 2);
     printf ("Tab2 po zamianie:\n");
    for (int i = 0; i < 5; i++)
    {
        wypisz_i(*(tab_2+i), *(tab_2+i)+2);
        printf("\n");
    }
    return 0;
}