#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct person
{
    char* nazwisko;
    char* imie;
    int rok;
    struct person* next;
    struct person* next_n;
};

struct person* add_sort(struct person* head, struct person** head2, struct person* el)
{
    if(head)
    {
        if(strcmp(head->nazwisko,el->nazwisko)>0) //strcmp(head->nazwisko,el->nazwisko)>0
        {
            el->next_n=head;
            head = el;
        }
        else{
            struct person* tmp=head;
            while(tmp->next_n&&(strcmp(head->nazwisko,el->nazwisko)<0))
                tmp=tmp->next_n;
            el->next_n = tmp->next_n;
            tmp->next_n=el;
        }
    }
    else 
        head = el;


    if(*head2)
    {
        if((*head2)->rok>el->rok)
        {
            el->next=*head2;
            *head2 = el;
        }
        else{
            struct person* tmp2=*head2;
            while(tmp2->next&&(tmp2->next->rok<el->rok))
                tmp2=tmp2->next;
            el->next = tmp2->next;
            tmp2->next=el;
        }
    }
    else 
        *head2 = el;

return head;
}
int main ()
{
struct person* head1 = NULL;
struct person* head2 = NULL;

struct person a;
a.imie="ABCD";
a.nazwisko="Nowak";
a.rok=2010;
a.next=NULL;
a.next_n=NULL;
struct person b;
b.imie="KLJ";
b.nazwisko="Kowalski";
b.rok=2015;
b.next=NULL;
b.next_n=NULL;

head1=add_sort(head1,&head2,&a);
head1=add_sort(head1,&head2,&b);

struct person* temp1= head1;
struct person* temp2 = head2;
printf("Wypisanie w kolejnosci alfabetycznej:\n");
while(temp1)
{
    printf("%s %s %d ->",temp1->imie,temp1->nazwisko,temp1->rok);
    temp1=temp1->next_n;
}
printf("\nWypisanie wg wieku:\n");
while(temp2)
{
    printf("%s %s %d ->",temp2->imie,temp2->nazwisko,temp2->rok);
    temp2=temp2->next;
}



    return 0;
}