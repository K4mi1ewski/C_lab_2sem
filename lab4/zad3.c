#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//generowanie liczb losowych calkowitych z przedziału (min, max)
    int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
    }
    //generowanie liczb losowych rzeczywistych z przedziału (min, max)
    double d_rand(double min, double max){
    double r = (double) rand()/RAND_MAX;
    return r*(max-min) + min;
    }

void wypisz_d (double *poczatek, double *koniec) { 
  while (poczatek < koniec) 
    printf ("%6.2f", *poczatek++); 
  printf ("\n");    
  return;}
  void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}
  double suma (double *tab, int len) { 
  double ss = 0.0;
  for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;}

 #define N 5
 #define M 6

 int find_min_ind (int *T_F, int *T_L){  //poczatek i koniec (T_F - wskaznik na pierwszy element, T_L wskaznik za ostatni element) obszaru tablicy gdzie szukamy minimum
   int min = 0;
   for (int i = 1; i < T_L - T_F; i++)
      if(T_F[min] > T_F[i]) min = i;
  
   return min;}

   int* tab_min (int A[][M], int rows)
   {
    int* tablica = malloc(rows*sizeof(int));
    for (int i = 0; i < rows; i++)
    {
        int mindex;
        mindex = find_min_ind(*(A+i), *(A+i)+M);
        *(tablica+i) = mindex;
    }

    return tablica;
   }
   int row_number (int tablica[][M], int rows)
   {
    int* najmniejsze = tab_min(tablica, rows);
    //int minimalny = tablica[0][*(najmniejsze)];
    int mindex = 0;
    for (int i = 1; i<rows; i++)
    {
        if (tablica[i][*(najmniejsze+i)] < tablica[mindex][*(najmniejsze+mindex)])
        {
            mindex = i;
        }
    }
    free (najmniejsze);
    return mindex;
   }
int main (void)
{
    srand(time(0));
int tab [N][M];
for (int i = 0; i < N; i++)
{
    for (int j = 0; j < M; j++)
    {
        tab[i][j] = i_rand(-5,5);
    }
}
int* indeksy = tab_min (tab, N);
printf ("\nMinimalne indeksy: \n");
wypisz_i(indeksy, indeksy+N);
int minimalny = tab[0][*(indeksy)];
for (int i = 1; i<N; i++)
{
    if (tab[i][*(indeksy+i)] < minimalny)
    {
        minimalny = tab[i][*(indeksy+i)];
    }
}
free (indeksy);
printf ("\nWartosc minimalna w calej tablicy: %d", minimalny);
int wiersz = row_number(tab, N);
printf ("\nZnaleziony numer wiersza: %d", wiersz);
printf ("\n %d wiersz: ", wiersz);
wypisz_i(*(tab+wiersz), *(tab+wiersz)+M);
    return 0;
}