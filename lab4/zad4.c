#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
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

int * podloga (double*a, double*b)
 {
    double iloczyn = (*a) * (*b);
    int* wynik = malloc (sizeof(int));
    *wynik = floor(iloczyn);

    return wynik;
 }
int main (void)
{
double pierwsza = 3.4;
double druga = 2.5;
int* ptr = podloga (&pierwsza, &druga);
printf ("Pierwsza liczba: %f, druga liczba: %f\n", pierwsza, druga);
printf ("podloga: %d\n", *ptr);
free(ptr);

    return 0;
}