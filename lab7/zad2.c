#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char** podziel(char* lancuch, int n)
{
    char *buff = strtok(lancuch, " ,;:.");
    int i = 1;
    char *slowa[n];
    
    while(buff!=NULL){
      
        int nowy = 1; //sprawdza czy dany wyraz pojawil sie wczesniej
        for (int j = 0; j< i;j++)
        {
            if(strcmp(buff, slowa[j])==0)
                nowy=0;
        }
    if(nowy)
    {
        slowa[i-1] = buff;
        i++;
    }
    buff = strtok(NULL, " ,:;.");
    }
    return slowa;
}

void sort(char** tablica, int n)
{
    int min;
    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for (int j = 1+i;j<n;j++)
        {
            if(strcmp(tablica[i], tablica[min])<0)
            min=j;
        }
        char*buff = tablica[min];
        tablica[min] = tablica [i];
        tablica[i] = buff;
    }
}
char* sklej(char** tablica, int n)
{
    char*tab = malloc(strlen((tablica[0])+1)*sizeof(char));
    tab = strcpy(tab, tablica[0]);
    for (int i =1; i<n;i++)
    {
        tab = realloc(tab, (strlen(tab)+strlen(tablica[i])+1)*sizeof(char));
        tab = strcat(tab, " ");
        tab = strcat(tab, tablica[i]);
    }
}
int main (int argc, char*argv[])
{

char* arg = argv[1];
char**wynik = podziel(arg, strlen(arg));
sort(wynik, strlen(arg));
char* string = sklej (wynik, strlen(arg));
free (string);

    return 0;
}