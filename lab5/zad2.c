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

int suma (int *tab, int len) { 
  int ss = 0.0;
  for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;}

void sort_2d(int cols, int(*tab)[cols], int rows)
{
    int tab_sum[rows];
    for (int i = 0; i < rows; i++)
    {
        tab_sum[i] = suma(*(tab+i), cols);
    }
    int mindex; 
    for (int i = 0; i < rows-1; i++)
    {
        mindex = i;
        for (int j = i+1; j < rows; j++)
        {
            if (tab_sum[j] < tab_sum[mindex])
                mindex = j;
        }
        swap_rows (cols, tab, mindex, i);

    
    }
}

int main (void)
{
 int tab_A[3][6] = {{1,-4,1,2,11},{12,2,32,2},{72,2,-32,2}};
 int tab_B[4][3] = {{1,-24,1},{9,32,2},{5,64,1},{3,32,1}};
printf("Tab A:\n");
for (int i = 0; i < 3; i++)
{
    wypisz_i(*(tab_A+i), *(tab_A+i)+6);
}
sort_2d(6, tab_A, 3);
printf("Tab a po posortowaniu wierszy:\n");
for (int i = 0; i < 3; i++)
{
    wypisz_i(*(tab_A+i), *(tab_A+i)+6);
}
    return 0;
}