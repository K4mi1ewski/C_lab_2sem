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

void wypelnij (double A[][6], int rows);
int main (void)
{
srand(time(0));
double A1 [8][6];
double A2 [10][6];
wypelnij(A1, 8);
wypelnij (A2, 10);
//cala tablica:
wypisz_d(*A1, *(A1+8));
wypisz_d(*A2, *(A2+10));
//dla kazdego wiersza:
//A1:
for (int i = 0; i < 8; i++)
{
    wypisz_d(*(A1+i), *(A1+i)+6);
}
//A2:
for (int i = 0; i < 10; i++)
{
    wypisz_d(*(A2+i), *(A2+i)+6);
}

    return 0;
}
void wypelnij (double A[][6], int rows)
{
    int krok = 0;
    double losowa = d_rand(2, 5);
for (int i = 0; i < rows; i++)
{
    for (int j = 0; j < 6; j++)
    {
        A[i][j] = losowa + krok*0.4;
        krok++;
    }
}


}