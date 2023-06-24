#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
       int value;
       struct tnode *next;
       struct tnode *prev;
     }node;

node* create (int var){
    node * ptr = malloc(sizeof (node));
	ptr->value = var;
	ptr->next=NULL;
    ptr->next = NULL;
return ptr;
}
void print_list_next(node *head){
    node *tmp = head;
    printf("Head-> ");
    while(tmp)
    {
        printf("['%d'] -> ",tmp -> value);
        tmp = tmp -> next;
    }
    printf("NULL\n");
}

void print_list_prev(node *head){
    node *tmp= head;
    printf("NULL -> ");
    if(head == NULL) {printf("head\n"); return;}
    while(tmp->next)
        tmp=tmp->next;
    while(tmp){
        printf("['%d'] -> ",tmp -> value);
        tmp = tmp -> prev;
    }
    printf("head\n");
}

node* add_first(node*head,node*el)
{
    if(head==NULL)
        {
            el->next=NULL;
            el->prev=NULL;
            head=el;
        }
    else
    {
        head->prev=el;
        el->next=head;
        el->prev=NULL;
        head=el;
    }   
    return head;
}

node* add_last(node*head,node*el)
{
    if(head==NULL)
    {
        el->prev=NULL;
        el->next=NULL;
        head=el;
    }
    else
    {
        node*tmp=head;
        while(tmp->next)
            tmp=tmp->next;
        el->prev=tmp;
        tmp->next=el;
        el->next=NULL;
    }
    return head;
}
void free_list(node**head)
{
     node* temp = *head;
    while(*head!=NULL)
    {
        temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}

node* del_el_all(struct tnode** head, int var)
{
    node*newlist=NULL;
    node*tmp=*head;
    while(tmp)
    {
        node*nxt=tmp->next;
        node*prv=tmp->prev;
        if(var==tmp->value)
        {
            if(tmp==*head)
            {
                *head=tmp->next;
                newlist=add_last(newlist,tmp);
                (*head)->prev=NULL;
                tmp=nxt;
            }
            else
            {
                tmp->next->prev=prv;
                tmp->prev->next=nxt;
                newlist=add_last(newlist,tmp);
                tmp=nxt;
            }
        }
        else
            tmp=tmp->next;
    }
    return newlist;
}

node* del_el_one(struct tnode** head, int var)
{
    node*tmp=*head;
    while(tmp)
    {node*nxt=tmp->next;
    node*prv=tmp->prev;
        if(tmp->value==var)
        {
            if(tmp==*head)
            {
                *head=nxt;
                (*head)->prev=NULL;
                tmp->next=NULL;
                return tmp;
            }
            else
            {
                if(tmp->next)
                    tmp->next->prev=prv;
                tmp->prev->next=nxt;
                return tmp;
            }
        }
        tmp=tmp->next;
    }
    return NULL;
}

void add_sort(struct tnode** head1, struct tnode* el)
{
    if(*head1 == NULL)
    {
        el -> next = NULL;
        el -> prev = NULL;
        *head1 = el;
        return;
    }
    if(el -> value < (*head1) -> value){
        el -> next = *head1;
        (*head1)->prev=el;
        *head1 = el;
        (*head1) -> prev = NULL;
        return;
    }
    node *tmp = *head1;
   
    while(((el -> value) > (tmp -> value))&&(tmp->next)) 
        tmp = tmp -> next;
    if(el->value<=tmp->value){
    node*prv=tmp->prev;
    node*nxt=tmp->next;
    tmp->prev->next=el;
    tmp->prev=el;
    el->prev=prv;
    el->next=tmp;
    }
    else
    {
        tmp->next=el;
        el->next=NULL;
        el->prev=tmp;
    }

}

node* div_list(node** head)
{
    node*list=NULL;
    node*tmp=*head;
    while(tmp)
    {
        node*nxt=tmp->next;
        node*prv=tmp->prev;
        if((tmp->value)%2==0)
            {
                if(tmp==*head)
                {
                    *head=nxt;
                    (*head)->prev=NULL;
                    list=add_last(list,tmp);
                    tmp=nxt;
                }
                else
                {
                    tmp->prev->next=nxt;
                    if(tmp->next)
                        tmp->next->prev=prv;
                    list=add_last(list,tmp);
                    tmp=nxt;
                }
            }
        else
        {
            tmp=tmp->next;
        }
    }
    return list;
}
int main (void)
{
    node*l1=NULL;
    node*l2=NULL;
for(int i = 0; i<10;i++)
{
    node*wsk=create(i);
    l1=add_last(l1,wsk);
}
node*wsk=create(4);
l1=add_first(l1,wsk);
wsk=create(8);
l1=add_first(l1,wsk);
wsk=create(15);
l1=add_first(l1,wsk);


print_list_next(l1);
print_list_prev(l1);

int buf;
printf("podaj jaki element usunac: ");
scanf("%d",&buf);

node*deleted=del_el_one(&l1,buf);
if(deleted)
   {
     printf("usunieto %d\n",deleted->value);
    free(deleted);
   }
else
    printf("Nie udalo sie usunac takiego elementu!\n");

print_list_next(l1);

printf("podaj jakie elementy usunac: ");
scanf("%d",&buf);

l2=del_el_all(&l1,buf);
if(l2)
{
    printf("usunieto:\n");
    print_list_next(l2);
    free_list(&l2);
}
else
printf("Nie udalo sie znalezc takich elementow!\n");
printf("Listy po podzieleniu na parzyste i nieparzyste:\n");
l2=div_list(&l1);
print_list_next(l1);
print_list_next(l2);
free_list(&l2);
free_list(&l1);

node*posortowana=NULL;
wsk=create(14);
add_sort(&posortowana,wsk);
wsk=create(13);
add_sort(&posortowana,wsk);
wsk=create(12);
add_sort(&posortowana,wsk);
wsk=create(30);
add_sort(&posortowana,wsk);
wsk=create(5);
add_sort(&posortowana,wsk);
printf("posortowana lista:\n");
print_list_next(posortowana);
print_list_prev(posortowana);
free_list(&posortowana);
return 0;
}
