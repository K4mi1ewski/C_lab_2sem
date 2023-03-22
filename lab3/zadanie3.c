#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 6

int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
    }
int main (void)
{
    srand(time(NULL));
    int TAB[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            TAB[i][j] = i_rand(-20, 20);
        }
    }
    
    int (* wsk)[M] = TAB+2;

//wersja wskaznikowa:
printf ("Wersja wskaznikowa; wylosowana tablica:\n");
for (int i = 0; i<N;i++)
{
    for (int j = 0; j<M; j++)
    {
        printf ("%3d ", TAB[i][j]);
    }
printf ("\n");
}
int indx = 0;
while ((indx < N))
{
    for (int kol = 0; kol < M; kol=kol+2)
    {
        *(*(wsk+indx-2)+kol) = 0;
    }
    indx++;
}//zerowanie kolumn
printf ("Wersja wskaznikowa; tablica z wyzerowanymi kolumnami:\n");
for (int i = 0; i<N;i++)
{
    for (int j = 0; j<M; j++)
    {
        printf ("%3d ", TAB[i][j]);
    }
printf ("\n");
}

//wersja tablicowa:
printf("\n");
for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            TAB[i][j] = i_rand(-20, 20);
        }
    } //ponowne losowanie tablicy
printf ("\nWersja tablicowa; tablica wylosowana:\n");
for (int i = 0; i<N;i++)
{
    for (int j = 0; j<M; j++)
    {
        printf ("%3d ", TAB[i][j]);
    }
printf ("\n");
}
int indeks = 0;
while (indeks < N)
{   
    for (int kol = 0; kol < M; kol=kol+2)
    {
        wsk[indeks-2][kol] = 0;
    }
    indeks++;
}//zerowanie kolumn parzystych

printf ("\nWersja tablicowa; tablica z wyzerowanymi kolumnami:\n");
for (int i = 0; i<N;i++)
{
    for (int j = 0; j<M; j++)
    {
        printf ("%3d ", TAB[i][j]);
    }
printf ("\n");
}
}