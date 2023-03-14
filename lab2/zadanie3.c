#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

    //generowanie liczb losowych calkowitych z przedziału (min, max)
    int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
    }
int number_cmp (char* num_1, char*num_2);
int main (void)
{
    srand (time(0));
   int rozmiar1 = i_rand (31, 40);
   int rozmiar2 = i_rand (31, 40);
   char napis1[rozmiar1];
   napis1[rozmiar1-1]='\0';
   char napis2[rozmiar2];
   napis2[rozmiar2-1]='\0';
    for (int i = 0; i < rozmiar1-1; i++)
    {   
        if(i==0)
            napis1[i] = i_rand (49, 57);
        else
        napis1[i] = i_rand(48, 57);
    }
    for (int i = 0; i < rozmiar2-1; i++)
    {   
        if (i==0)
        napis2[i] = i_rand(49, 57);
        else
        napis2[i]=i_rand(48,57);
    }
printf ("pierwsza liczba = %s", napis1);
printf ("\ndruga liczba = %s\n", napis2);
if (number_cmp(napis1, napis2) == 0)
    printf ("Liczby sa rowne!\n");
else if (number_cmp(napis1, napis2) == 1)
    printf ("Pierwsza jest wieksza\n");
else
    printf("Druga jest wieksza\n");
    return 0;
}
int number_cmp (char* num_1, char* num_2)
{
    if (strlen (num_1) > strlen (num_2))
        return 1;
        
    else if (strlen(num_1) < strlen (num_2))
        return -1;
    else
    {
        int wynik = strcmp (num_1, num_2);
        return wynik;
    }
}