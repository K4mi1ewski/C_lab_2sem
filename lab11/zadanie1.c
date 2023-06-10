#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
    }
    //generowanie liczb losowych rzeczywistych z przedziału (min, max)
double d_rand(double min, double max){
    double r = (double) rand()/RAND_MAX;
    return r*(max-min) + min;
    }

typedef union var {
int i;
double d;
} uvar;

typedef struct liczba{
uvar x;
char typ;
} liczba_;

void struct_prn(liczba_ el)
{
    if(el.typ=='i')
    {
        printf("wartosc: %d, typ: %c\n", el.x.i, el.typ);
    }
    else if (el.typ == 'd')
    {
        printf("wartosc: %lf, typ: %c\n", el.x.d, el.typ);
    }
}

int cmpfun (const void*a,const void*b)
{
    liczba_* A = (liczba_*)a;
    liczba_* B = (liczba_*)b;
    if ((A->typ =='i')&&(B->typ=='d'))
        return 1;
    else if ((A->typ=='d')&&(B->typ=='i'))
        return -1;
    else if ((A->typ =='i')&&(B->typ=='i'))
        return ((A->x.i)-(B->x.i));
    else
        return (((A->x.d)>(B->x.d)) - ((A->x.d)<(B->x.d)));
    
        
}
void sorttab (liczba_ tab[], int n)
{   
qsort(tab, n, sizeof(liczba_), cmpfun);
}
int main (int argc, char** argv)
{

srand(time(0));
int len = i_rand(10,20);
liczba_ numbers[len];
for(int i = 0; i<len; i++)
{
    int p = rand()%2;
    if(p == 0)
    {
        numbers[i].x.d = d_rand(-5,5); 
        numbers[i].typ = 'd';
    }
    else
    {
        numbers[i].x.i = i_rand(-5,5); 
        numbers[i].typ = 'i';
    }
}

for (int i = 0; i<len;i++)
{
    struct_prn(numbers[i]);
}
FILE *plik = fopen("plik.dat", "wb");
size_t rozmiar;
if(plik)
{
    fwrite(numbers, sizeof(liczba_), len, plik);
    fseek(plik, 0, SEEK_END);
    rozmiar = ftell(plik);
    fclose(plik);
}
else{
    printf("blad, nie mozna utworzyc pliku!\n");
    return 1;
}
rozmiar = rozmiar/sizeof(liczba_);
liczba_ tab [rozmiar];
FILE* plik2 = fopen("plik.dat", "rb");
if (plik2)
{
    fread(tab, sizeof(liczba_), len, plik2);
    fclose(plik2);
}
else{
    printf("Blad, nie udalo sie otworzyc pliku!\n");
    return 1;
}
printf("Tablica wartosci wczytanych z pliku dat:\n");
for (int i = 0; i<rozmiar; i++)
{
    struct_prn(tab[i]);
}

sorttab(tab, rozmiar);
printf("Tablica wartosci posortowanych:\n");
for (int i = 0; i<rozmiar; i++)
{
    struct_prn(tab[i]);
}
uvar keyy;
liczba_ szukana;
if(argc!=3)
    {
        printf("Niepoprawne wywolanie programu!\n");
        return 1;
    }
else
{
    char* znak = argv[1];
    if(strcmp(znak,"d")==0)
        keyy.d= (double)atof(argv[2]);
    else if (strcmp(znak,"i")==0)
        keyy.i = atoi(argv[2]);
    else 
        {
            printf("niepoprawne wywolanie programu!\n");
            return 1;
        } 
        szukana.x = keyy;
        szukana.typ = *znak;
}


liczba_* pos = bsearch(&szukana, tab, rozmiar, sizeof(liczba_), cmpfun);
if(pos)
    printf("Indeksy wystepowania szukanej liczby: ");
else
    printf("Nie znaleziono szukanej liczby.");
if((pos!=tab) &&(pos!=NULL)){
    liczba_* pom = pos-1;
    if(szukana.typ=='d'){
        while((pom->x.d==keyy.d)&&(pom-tab)>=0)//to samo tylko dolozyc ifa z typem 'd' i 'i'
        {
        printf("%d ",pom-tab);
        pom=pom-1;
        }
    }
    else if(szukana.typ=='i')
    {
        while((pom->x.i==keyy.i)&&(pom-tab)>=0)//to samo tylko dolozyc ifa z typem 'd' i 'i'
        {
        printf("%d ",pom-tab);
        pom=pom-1;
        }
    }
}


if(szukana.typ=='i' && (pos!=NULL)){
while((pos->x.i==szukana.x.i)&&(pos-tab)<((rozmiar-1))) 
{
    printf("%d ",pos-tab);
    pos=pos+1;
}
}
else if (szukana.typ=='d' && (pos!=NULL)){
    while((pos->x.d==szukana.x.d)&&(pos-tab)<((rozmiar-1))) 
{
    printf("%d ",pos-tab);
    pos=pos+1;
}
}



//dobra to dziala nie wierze XD
return 0;
}