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

    

    void swap (int *p_1, int *p_2) { 
  int temp = *p_1;
    *p_1 = *p_2;
    *p_2 = temp;
 return ;}
 int suma (int *tab, int len) { 
  int ss = 0.0;
  for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;}
 void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}
  void wypisz_d (double *poczatek, double *koniec) { 
  while (poczatek < koniec) 
    printf ("%6.2f", *poczatek++); 
  printf ("\n");    
  return;}
int find_min_ind (int *T_F, int *T_L){  //poczatek i koniec (T_F - wskaznik na pierwszy element, T_L wskaznik za ostatni element) obszaru tablicy gdzie szukamy minimum
   int min = 0;
   for (int i = 1; i < T_L - T_F; i++)
      if(T_F[min] > T_F[i]) min = i;
  
   return min;}

  int main (void)
  {
    srand(time(NULL));
    int abc [5][4];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <4; j++)
        {
            abc[i][j] = i_rand(-10, 10);
        }
    }
    wypisz_i (*abc, *abc + 5*4);

    

    int suma_all = suma (*abc, (sizeof(abc)/sizeof(int)));
    int suma_1 = suma (*abc, (sizeof(abc)/sizeof(int))/2);
    int suma_2 = suma (*abc + (sizeof(abc)/sizeof(int))/2, (sizeof(abc)/sizeof(int))/2);
    printf ("Suma all = %d\nSuma_1=%d\nSuma_2=%d\n", suma_all, suma_1, suma_2);

    int mindex1 = find_min_ind (*abc, (*abc + (sizeof(abc)/sizeof(int))/2));
    int mindex2 = find_min_ind ((*abc + (sizeof(abc)/sizeof(int))/2) , (*abc + (sizeof(abc)/sizeof(int)))) + ((sizeof(abc)/sizeof(int))/2); 

    printf ("Wartosc minimalna 1 polowa: %d, jej adres: %p\n", *(*abc+mindex1), (*abc)+mindex1);
    printf ("Wartosc minimalna 2 polowa: %d, jej adres: %p\n", *(*abc+mindex2), (*abc)+mindex2);

    int wiersz1 = (mindex1/4); //4 to dlugosc wiersza
    int kolumna1 = (mindex1/5);
    int wiersz2 = (mindex2/4) ;
    int kolumna2 = (mindex2/5);

    printf ("Najmniejszy element w pierwszej polowie = abc[%d][%d] = %d\n", wiersz1, kolumna1, abc[wiersz1][kolumna1]);
    printf ("Najmniejszy element w drugiej polowie = abc[%d][%d] = %d\n", wiersz2, kolumna2, abc[wiersz2][kolumna2]);

    return 0;
  }