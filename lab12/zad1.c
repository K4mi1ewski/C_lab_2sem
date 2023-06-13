#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>//toupper()

 typedef struct elem
 {  char litera;
    int licznik;
    struct elem* next;
 } element;

element* create (char var)
{
    element* new = malloc (sizeof(element));
    new->litera=var;
    new->licznik=1;
    new->next=NULL;
    return new;
}

element* add_list (element* head, char val)
{
    if(head)
    {
    if(toupper(head->litera)>toupper(val)||head->litera==val-32) 
    {
        element* el = create(val);
        if(!el)
            return head;
        el->next=head;
        head = el;
        
    }
    else if(head->litera==val)
            head->licznik++;
    else
    {
        element* temp = head;
        while((temp->next)&&(toupper(temp->next->litera)<toupper(val)))
            temp=temp->next;

        if((temp->next)==NULL)
        {
            element* el = create(val);
            if(!el)
                return head;
            temp->next=el;        
        }
        else if(temp->next->litera == val)
            temp->next->licznik++;
        else if((toupper(temp->next->litera)==toupper(val))&&(temp->next->litera == val+32))//dodawana litera trafiła na taką samą, ale o innej wielkosci
        {
            //mamy 4 przypadki
            //1:dodajemy mala trafiamy mala - ten przypadek eliminuje powyzszy if
            //2:dodajemy duza trafiamy duza - ten przypadek eliminuje powyzszy if
            //3:dodajemy mala trafiamy duza - w tym przypadku robimy tak jakbysmy dodawali nowy element, bo mala ma byc przed duza, czyli jak trafilismy na duza to malej jeszcze tam nie ma
            //4:dodajemy duza trafiamy mala - jedyny przypadek do obsluzenia tutaj:
            temp=temp->next;
            if(temp->next->litera==val)
                temp->next->licznik++;
            else
                {
                    element* el = create(val);
                    if(!el)
                         return head;
                    el->next=temp->next;
                    temp->next=el;    
                }
        }
        else
        {
        element* el = create(val);
        if(!el)
            return head;
        el->next=temp->next;
        temp->next=el;
        }
    }
   }
   else
    {
        element* el = create(val);
        if(!el)
            return head;
        head=el;
    }
return head;
}
void printlist(element* head)
{
    printf("Head -> ");
        element* temp = head;
        while(temp)
        {
            printf("[%c : %d]-> ",temp->litera, temp->licznik);
            temp = temp->next;
        }
        printf("NULL\n");
    
}
element* clearlist(element*head)
{
    if(head==NULL)
        return head;
    
    while(head)
    {
        element*tmp=head->next;
        free(head);
        head = tmp;
    }
    return head;
}
int main (int argc, char*argv[])
{
element* lista= NULL;
printlist(lista);
int roz=0;

char*napis = "Sometimes you will never know the value of a moment until it becomes a memory";

printf("%c",napis[4]);
printlist(lista);

char* txt = "plik.txt";
char* binar = "plik_data";
FILE* plik = fopen(txt, "w");
element* tmp = lista;
while(tmp)
{
    fprintf(plik, "%c : %d\n",tmp->litera,tmp->licznik);
    tmp=tmp->next;
}
fclose(plik);

FILE* bin = fopen(binar, "wb");
tmp = lista;
while(tmp)
{
    fwrite(tmp, sizeof(element),1,bin);
    tmp=tmp->next;
}
fclose(bin);

FILE* bin2 = fopen(binar, "rb");
fseek(bin2,0,SEEK_END);
size_t rozmiar = ftell(bin2)/sizeof(element);

element TAB[rozmiar];
fseek(bin2, 0, SEEK_SET);
fread(TAB,sizeof(element),rozmiar,bin2);
fclose(bin2);
for (int i = 0; i<rozmiar;i++)
    printf("%c : %d\n",TAB[i].litera,TAB[i].licznik);


clearlist(lista);
return 0;
}