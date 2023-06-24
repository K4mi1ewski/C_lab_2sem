#include<stdio.h>
#include<stdlib.h>

 typedef struct tnode {
       int value;
       struct tnode *next;
     } node;
 
node* create (int var){
    node * ptr = malloc(sizeof (node));
	ptr->value = var;
	ptr->next = NULL;
return ptr;
}

node *add_el(node *head, node *el){
    if(head==NULL){
        head = el;
        return head;
    }
    el->next=head;
    head=el;
    return head;
}
void printlist(node*head)
{
    printf ("address        value           next\n");
    while(head)
    {
        printf("%p      %d          %p\n",head,head->value,head->next);
        head=head->next;
    }
}

void freelist(node**head)
{
     node* temp = *head;
    while(*head!=NULL)
    {
        temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}
void sortlist(node**head)
{
    node*ptr=*head;
    node*prv=NULL;
    node*nxt=NULL;
    while(ptr)
    {
        nxt=ptr->next;
        if(ptr->value%2==0&&(ptr!=*head))
        {
            prv->next=nxt;
            ptr->next=*head;
            *head=ptr;   
        }
        else
            prv=ptr;
          ptr=nxt;
    }
}
int main (void)
{
node*head=NULL;
for(int i = 0; i<13;i++)
{
    node*new=create(i);
    head=add_el(head,new);
}

printlist(head);
sortlist(&head);
printlist(head);
freelist(&head);
    return 0;
}