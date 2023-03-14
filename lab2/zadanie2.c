#include <stdio.h>
#include <string.h>


void write_binar(unsigned int n, char* wsk);
unsigned int bits (unsigned int x);

int main (void)
{
    unsigned number, result;
    printf("Wczytaj liczbe: ");
    scanf ("%u", &number);
    char result_str[8*sizeof(unsigned)+1]="";
    write_binar (number, result_str);
    printf ("\n");
    printf ("Liczba wczytana %u : %s \n", number, result_str);
    result = bits (number);
    char str2 [8*sizeof(unsigned)+1]="";
    write_binar (result, str2);
    printf ("%u Po wyzerowaniu bitow: %s\n", number, str2);




    return 0;
}

void write_binar (unsigned int n, char* wsk)
{
    unsigned int maska = 1; 
   // printf ("Maska: %u\n", maska);
    
    maska = maska << (8*sizeof(unsigned int) - 1); //przesuniecie jedynki na najstarszy bit maski
  //  printf ("Maska 2: %u\n", maska);
    for (int i = 0; i<(8*sizeof(unsigned int)); i++)
    {
    if ((maska&n) == 0)
        strcat (wsk, "0");
    else
        strcat (wsk, "1");
    maska = maska >> 1;
    }
}

unsigned int bits (unsigned int x)
{
    unsigned int maska = 1;
    for (int i = 0; i<((8*sizeof(unsigned int) - 1 )/ 2); i++)//ustawienie bitow parzystych na 1
    {
        maska = maska << 2;
        maska = maska | 1;
    }
    maska = ~maska;//ustawienie bitow parzystych na 0, bitow nieparzystych na 1
    return (x & maska); //zwracamy liczbe z wyzerowanymi bitami parzystymi
}