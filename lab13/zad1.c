#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    int value;
    struct tnode * next;
} node;

void printlist(node*head)
{
    node*tmp=head;
    if(tmp==NULL)
        {
            printf("NULL\n");
            return;
        }
    printf("head->");
    do
    {
        printf("[%d]->",tmp->value);
        tmp=tmp->next;
    } while (tmp!=head);
    printf("\n");
}

node* add_el(node*head,node*el)
{
    if(head==NULL) 
    {
        el->next=el;
        head=el;
    }
    else
    {
        node*tmp=head;
        while(tmp->next!=head)
            tmp=tmp->next;//po wykonaniu, tmp wskazuje na ostatni element z listy
        
        tmp->next=el;
        el->next=head;
    }
    return head;
}

node* add_list(node*head,node*list)
{
    node*tmp=head;
    while(tmp->next!=head)
        tmp=tmp->next;
    tmp->next=list;
    tmp=list;
    while(tmp->next!=list)
        tmp=tmp->next;
    tmp->next=head;
    return head;
}

void del_el (node**head, int var)
{
    node*ptr=*head;
    node*last=*head;
    while(last->next!=*head)
        last=last->next;
    node*prev=last;
   int flag=0;
    while(1){
        node*nxt=ptr->next;
        
        if(ptr->value==var)
        {
         if(ptr==*head)
         {
            if(ptr==last)
            {
                free(*head);
                *head=NULL;
                return;
            }
            prev->next=nxt;
            free(*head);
            *head=nxt;
            ptr=nxt;
         }  
         else
         {
            prev->next=nxt;
            free(ptr);
            ptr=nxt;
            flag++;
         } 
        }
        else
        {
            prev=ptr;
            ptr=nxt;
        }
        
        if((ptr==*head)&&(flag!=0))
            return;
    }
}

void free_list(node**head)
{
    if(*head==NULL)
        return;
    
        node*last=*head;
        while(last->next!=*head)
            last=last->next;
        
        last->next=NULL;
        while(*head)
        {
            node*ptr=*head;
            *head=(*head)->next;
            free(ptr);
        }
    
}

node* create (int var){
    node* wsk = malloc(sizeof(node));
	wsk->value = var;
	wsk->next = NULL;
return wsk;}	
int main (int argc, char*argv[])
{
node* head = NULL;
node*head2=NULL;

node*a=create(2);
node*b=create(3);
node*c=create(4);
node*d=create(5);
node*e=create(6);
node*f=create(7);
node*g=create(8);
node*h=create(9);

head=add_el(head,a);
head=add_el(head,b);
head=add_el(head,c);
head=add_el(head,d);

head2=add_el(head2,e);
head2=add_el(head2,f);
head2=add_el(head2,g);
head2=add_el(head2,h);

printlist(head);
printlist(head2);

head = add_list(head,head2);
printlist(head);

del_el(&head,4);
printlist(head);

free_list(&head);
head2=NULL;
printlist(head);
return 0;
}