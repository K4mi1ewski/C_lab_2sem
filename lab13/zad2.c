#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 30
struct person
{
    int age;
    char code [7];
    char f_name[SIZE];
    char l_name[SIZE];
    
};

struct person* create_tab(char*name,int*rozmiar)
{
    FILE* plik = fopen(name,"r");
    if(plik)
    {
        struct person* tab = NULL;
        int size = 0;
        while(!feof(plik))
        {
            size++;
            tab = realloc(tab, size*sizeof(struct person));
            char fname[SIZE];
            char lname[SIZE];
            int age_;
            char code_[7];
            fscanf(plik,"%s",fname);
            fscanf(plik,"%s",lname);
            fscanf(plik,"%s",code_);
            fscanf(plik,"%d",&age_);
            (tab+size-1)->age=age_;
            strcpy((tab+size-1)->code,code_);
            strcpy((tab+size-1)->f_name,fname);
            strcpy((tab+size-1)->l_name,lname);

        }
        *rozmiar=size;
        fclose(plik);
        return tab;
    }

}
int main ()
{
char*name="baza.txt";
int rozmiar;
struct person*tablica = create_tab(name,&rozmiar);
for(int i = 0; i<rozmiar;i++)
{
    printf("%s %s %s %d\n",(tablica+i)->f_name, (tablica+i)->l_name, (tablica+i)->code, (tablica+i)->age);
}

FILE* plik = fopen("dane.dat","wb");
if (plik)
{
    fwrite(tablica,sizeof(struct person),rozmiar,plik);
    fclose(plik);
}
FILE* plik2 = fopen("dane.dat", "rb");
if(plik2)
{
int size;
fseek(plik2,0,SEEK_END);
size = ftell(plik2);
struct person dane [size/sizeof(struct person)];
fread(dane,sizeof(struct person),size/sizeof(struct person),plik2);

for (int i = 0; i<size/sizeof(struct person);i++)
{
    printf("%s %s %s %d\n",(tablica+i)->f_name, (tablica+i)->l_name, (tablica+i)->code, (tablica+i)->age);
}
fclose(plik2);
}


free(tablica);
    return 0;
}