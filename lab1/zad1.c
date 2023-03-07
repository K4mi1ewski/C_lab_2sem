#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

    int suma(const int* begin, const int *end);

    int main(void){

        srand (time(NULL));
        int tab[N];//deklaracja tablicy 10 liczb całkowitych, użyj N
        int *p = NULL;//deklaracja wskaźnika p do liczby całkowitej, użyj NULL
//nie używaj zmiennej int  do indeksowania tablicy
//przypisz kolejnym elementom tablicy liczby pseudolosowe z przedziału od 7 do 35 i wypisz je na ekran 

    for(p=tab; p <tab + N ; p++){
       *p=rand()%29 + 7;  // nie korzystaj z tab 
    
        printf("p[%d] = %d\n", p-tab, *p); //oblicz wartość indeksu kolejnych elementów tablicy, wypisz wartości kolejnych elementów używając p
        printf("\n");
       }
p--;


 
//oblicz rekurencyjnie sumę elementów tablicy.

    int su = suma(tab, p);   //nie używaj N
    
    printf("su=%d\n",su);
    return 0;
    }

 //funkcja rekurencyjna liczaca sume elementów tablicy  
   int suma (const int *begin, const int *end){   //nie używaj N 
      if (begin!=end)
   return *begin + suma(begin+1,end);
     else
   return *end;  }