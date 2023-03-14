#include <stdio.h>
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

  int suma (int *tab, int len) { 
  int ss = 0;
  for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;}
 
void swap (int*a, int*b);
 int* find_min_wsk (int* tab, int length);
 
 void sort (int*p, int*k);
 int main (void)
 {
    int tab_A[] = {3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,22,12,6,8,4,44,6,42,2,16,5,33,1,7,9,55,1,11,22,34,78,11,21,9,12,5,3,9};
    int L = sizeof(tab_A)/sizeof(int);
    for (int i = 0; (i<=(L-1)/10); i++)
    {
        int zakres;
        if (L - 10*i >=10)
            zakres=10;
        else
            zakres = L-10*i;
        printf ("Zakres %d - %d -->", i*10, i*10+zakres-1);
        for (int j = 0; (j < 10 && j+10*i < L);j++)
        {
            printf ("tab[%d] = %d, ", j+10*i, tab_A[j+10*i]);
        }
        printf("\n");
        
        
        int* minimalny = find_min_wsk (tab_A+10*i, zakres);
        printf ("Element minimalny wartosc = %d, adres = %p, indeks = %ld", *minimalny, minimalny, minimalny-tab_A);
        printf ("\n");
    }

    for (int i=0; i<=L/10; i++)
    {
        int zakres;
        if (L - 10*i >=10)
            zakres=10;
        else
            zakres = L-10*i;
        
        sort (tab_A+10*i, tab_A+(10*i+zakres));
    }
    printf ("\nPosortowana tablica dziesiatkami:\n");
    wypisz_i(tab_A, tab_A+L-1);
    return 0;
 }


int* find_min_wsk (int* tab, int length)
{
    int *min = &tab[0];
    for (int i = 1; i<length; i++)
    {
        if (tab[i] < *min)
        {
            min = &tab[i];
        }
    }
    return min;
}

 void swap(int*a, int*b){
         int temp = *a;
         *a = *b;
         *b = temp;
         return;}

void sort (int*p, int*k)
{
    while (p<k)
    {
        int* pointer = find_min_wsk(p, k-p);
        swap (p, pointer);
        p++;
    }
}