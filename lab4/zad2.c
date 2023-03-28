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

 
int main (void)
{
    srand (time(0));
unsigned rozmiar;
printf("Podaj rozmiar: ");
scanf ("%u", &rozmiar);
int* table = malloc(rozmiar*sizeof(int));
for (int i = 0; i < rozmiar; i++)
{
    *(table+i) = i_rand(-5,5);
}
int* arg_p = malloc(0);
int *arg_n = malloc(0);
printf ("table ---> ");
wypisz_i (table, table+rozmiar);
int p = 0, n = 0;//zmienne przechowujace dlugosc tablic p i n
int nowy_rozmiar = rozmiar;//nowy rozmiar starej tablicy, zmniejszajacy sie po kazdej iteracji
for (int i = rozmiar-1; i>=0; i--)
{
   
   
    if (((*(table+i))%2) == 0)
    {
        p++;
        arg_p = realloc(arg_p, p*sizeof(int));
        *(arg_p+p-1) = *(table+i);
        nowy_rozmiar--;
        //free (table + i);
        table = realloc(table, nowy_rozmiar*sizeof(int));
        
        
    }
    else
    {
        n++;
        arg_n = realloc(arg_n, n*sizeof(int));
        *(arg_n+n-1) = *(table+i);
        nowy_rozmiar--;
        //free (table + i);
        table = realloc(table, nowy_rozmiar*sizeof(int));
        
    }
}
free (table);
printf ("arg n ---> ");
wypisz_i(arg_n, arg_n + n);
printf ("arg p ---> ");
wypisz_i(arg_p, arg_p + p);
printf ("table --->");
if (table == NULL)
{
    printf ("NULL");
}
printf ("\n");
    return 0;
}