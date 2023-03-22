
  #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");   
return;}
    //generowanie liczb losowych calkowitych z przedziału (min, max)
    int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
    }
    void swap (int *p_1, int *p_2) { 
  int temp = *p_1;
    *p_1 = *p_2;
    *p_2 = temp;
 return ;}
    void parzyste (int*p, int* k);
    int main (void)
    {
        srand (time(0));
        int rozmiar = i_rand(2, 20);
        int tab[rozmiar];
        for (int i = 0; i<rozmiar; i++)
        {
            tab[i] = i_rand (0, 100);
        }
        printf ("Wylosowana tablica: ");
        wypisz_i (tab, tab+rozmiar);
        parzyste (tab, tab+rozmiar);
        printf ("\nTablica po zamianie: ");
        wypisz_i (tab, tab+rozmiar);
        printf ("\n");

        return 0;
    }
    void parzyste (int*p, int*k)
    {
        int* last_swap = p;
        while (p<k)
        {
            if (((*p)%2) == 0)
            {
                swap (last_swap, p);
                last_swap++;
            }
            p++;
        }
    }