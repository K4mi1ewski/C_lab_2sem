#include <stdio.h>


void swap (int *p_1, int *p_2) { 
  int temp = *p_1;
    *p_1 = *p_2;
    *p_2 = temp;
 return ;}

 int main (void)
 {

    int abc[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            abc[i][j] = j;
            printf ("TAB[%d][%d] = %d ", i, j, abc[i][j]);
        }
        printf ("\n");
    }
    for (int i = 0; i <5; i++)
    {
        for (int j = i; j<5; j++)
        {
            swap(*(abc+i)+j, *(abc+j)+i);
        }
    }
    printf ("\nPo transponowaniu:\n");
    for (int i = 0; i<5; i++)
    {
        for (int j = 0; j<5; j++)
        {
            printf ("TAB[%d][%d] = %d ",i,j,abc[i][j]);
        }
        printf ("\n");
    }
    int rozmiar = 5;
    for (int i = 0; i<rozmiar-1; i++)
    {
        if (i<(((rozmiar)/2)))
            printf("tab[%d][%d] = %d\n",i,i+1,abc[i][i+1]);
        else    
            printf ("tab[%d][%d] = %d\n", rozmiar-i,rozmiar-(i+1), abc[rozmiar-i][rozmiar-i-1]);
    }//to jest zle
    return 0;
 }