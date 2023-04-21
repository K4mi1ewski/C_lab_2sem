#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char** podziel(char* lancuch, int *n)
{
    char**tablica = malloc(sizeof(char*));
    char podzielniki[]=" .;:,";
    int i = 0;//ilosc wyrazow
    char* buff = strtok(lancuch, podzielniki);
    
    while(buff!=NULL)
    {
        int nowy = 1;
        for(int j = 0; j<i;j++)
        {
            if(strcmp(tablica[j], buff)==0)
                nowy = 0;
        }
        if (nowy)
        {
            tablica[i]=buff;
            i++;
            tablica = realloc(tablica, (i+1)*sizeof(char*));
        }
        buff=strtok(NULL,podzielniki);
    }
    tablica = realloc(tablica, i*sizeof(char*));//usuniecie nadmiarowego rozmiaru tablicy po skonczeniu sie wyrazow
    *n = i;//zapamietanie ilosci elementow w tablicy slow
    return tablica;
}

void sort(char** tablica, int n)
{
    for(int i = 0; i<(n-1); i++)
    {
        int min = i;
        for (int j = i+1; j<n; j++)
        {
            if(strcmp(tablica[j], tablica[min])<0)
                min = j;
        }
        char*buff=tablica[min];
        tablica[min]=tablica[i];
        tablica[i]=buff;
    }
}

char* sklej(char** lancuch, int n)
{
    int rozmiar = 0;
    for(int i = 0; i<n;i++)
    {
        rozmiar +=(strlen(lancuch[i])+1);
    }
    printf("Rozmiar:%d\n",rozmiar);
    char* str = malloc(rozmiar*sizeof(char));
    str=strcpy(str, lancuch[0]);
    for (int i = 1; i<n;i++)
    {
        str = strcat(str, " ");
        str=strcat(str, lancuch[i]);
    }
    str[rozmiar-1] = '\0';
    return str;
}

int main (int argc, char*argv[])
{
char* arg = argv[1];
int licznik = 0;
char**wynik = podziel(arg, &licznik);
for(int i = 0; i<licznik; i++)
{
    printf("%s\n", wynik[i]);
}
sort(wynik, licznik);
printf("Po posortowaniu:\n");
for(int i = 0; i<licznik; i++)
{
    printf("%s\n", wynik[i]); 
}
char* sklejony = sklej(wynik, licznik);
printf("Wyraz po sklejeniu: %s\n", sklejony);



free (wynik);
free(sklejony);
    return 0;
}