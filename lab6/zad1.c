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
    void wypisz_f (float *poczatek, float *koniec) { 
  while (poczatek < koniec) 
    printf ("%6.2f", *poczatek++); 
  printf ("\n");    
  return;}
  void print_tab_all(int y,int a[][y], int x){
 int i, j;
  for (i = 0; i < x; i++){
    for (j = 0; j < y; j++)
       printf ("%3d", a[i][j]);
    printf ("\n");   }
   return;}

void swap (float *p, float *q) { 
  float temp = *p;
  *p = *q;
  *q = temp;
  return;}
    int main(void){
    
    float TAB_2[7] = {1.5, 2.5, 3.5, 4.5, 5.5, 6.5 ,7.5};
    float* TAB_1[7];
    for (int i = 0; i < 7; i++)
    {
        TAB_1[i] = &TAB_2[i];
    }
    float* wsk[7];
    float* wsk1[7];
    *wsk = *TAB_1;
    *wsk1= *TAB_1;
    printf("tab2--->");wypisz_f(*wsk, *wsk+7);

    while(*wsk<*wsk1+7)
    {
        printf("TAB_1[%ld] = %p\n", *wsk - *wsk1, *wsk);
        (*wsk)++;
    }
     *wsk = *TAB_1;
     for(int i = 0; i<(7/2); i++)
     {
        swap(*wsk+i,*wsk+7-i-1);
     }
printf("\nTablice po odwroceniu:\n");
printf("tab2--->");wypisz_f(*wsk, *wsk+7);
while(*wsk<*wsk1+7)
    {
        printf("TAB_1[%ld] = %p\n", *wsk - *wsk1, *wsk);
        (*wsk)++;
    }
     *wsk = *TAB_1;
  
  //cykliczne przesuniecie:
  for (int i = 0; i<7; i++)
  {
    TAB_1[i] = &TAB_2[(i+1)%7];
  }
    printf("TAB2 przez identyfikator TAB_2--->"); wypisz_f(TAB_2, TAB_2+7);
    printf("TAB2 przez identyfikator TAB_1--->"); 
    for(int i = 0; i<7;i++)
    {
        printf("%6.2f", *TAB_1[i]);
    }
    printf("\n");
    for (int i = 0; i<7; i++)
    {
      printf("TAB_1[%d] = %p\n", i, TAB_1[i]);
    }
  
    
    return 0;
    }