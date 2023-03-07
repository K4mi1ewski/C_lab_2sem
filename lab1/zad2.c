#include <stdio.h>
#define N 10
void zamiana (int* a, int* b);
void odwroc (int *tab, int dlugosc);
void wymien_tablice (int* tab1, int* tab2, int length);
int main (void)
{
    //a)
    int x = 20;
    int y = 240;
    printf ("x: %d, y: %d\n", x, y);
    zamiana (&x,&y);
    printf ("Po zamianie: x: %d, y: %d\n",x ,y);
    //b)
    int array [N] = {2, 5, 19, 1, 12, 8, 44, 32, 920, 10};
    printf ("Tablica przed odwroceniem:\n");
    for (int i =0;i<N;i++)
    { printf ("tab[%d] = %d\n", i, *(array+i));}
    odwroc (array, N);
    printf ("Tablica po odwroceniu:\n");
    for (int i =0;i<N;i++)
    { printf ("tab[%d] = %d\n", i, *(array+i));}
    //c)
    int array2 [N] = {8, 192, 2389, 129, 908, 112, 965, 2, 1, 4321};
    printf ("Tablice przed wymiana:\n");
    printf ("1. Tabica:\n");
    for (int i = 0; i<N; i++) { printf ("tab[%d] = %d\n", i, *(array+i));}
    printf ("2. Tabica:\n");
    for (int i = 0; i<N; i++) { printf ("tab[%d] = %d\n", i, *(array2+i));}

    wymien_tablice(array,array2,N);

    printf ("Tablice po wymianie:\n");
    printf ("1. Tabica:\n");
    for (int i = 0; i<N; i++) { printf ("tab[%d] = %d\n", i, *(array+i));}
    printf ("2. Tabica:\n");
    for (int i = 0; i<N; i++) { printf ("tab[%d] = %d\n", i, *(array2+i));}
    return 0;
}

void zamiana (int* a, int* b)
{
    int buff;
    buff = *a;
    *a=*b;
    *b=buff;
}
void odwroc (int *tab, int dlugosc)
{
    for (int i = 0; i < dlugosc/2; i++)
    {
        zamiana (tab+i, tab+dlugosc-1-i);
    }
}
void wymien_tablice (int* tab1, int* tab2, int length)
{
    for (int i = 0; i<length;i++)
    {
        zamiana (tab1+i,tab2+i);
    }
}