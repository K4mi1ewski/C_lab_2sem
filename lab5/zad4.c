#include <stdio.h>
#include <stdlib.h>

double *my_alloc(int i_min, int i_max)
{
    int rozmiar = i_max-i_min+1;
    double* tab = calloc(rozmiar, sizeof(double));
    
    return tab+i_min;
}


void my_free (double **my_tab, int i_min)
{
 if (*my_tab != NULL)
 {
    free(*my_tab - i_min);
    *my_tab = NULL;
 }   
}
int main (void)
{
    double *tablica = my_alloc (-3, 3);
    int rozmiar = 7;
    for (int i = 0; i < rozmiar; i++)
    {
        tablica[i-3] = 2.4;
    }
    my_free(&tablica, -3);
    return 0;
}