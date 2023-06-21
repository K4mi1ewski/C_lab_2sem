#include "stack.h"

void print_stack(struct tnode* head)
{
    if(head==NULL)
        {
            printf("NULL->");
            return;
        }
    print_stack(head->next);
    printf("%d->",head->value);
}

void push_one(struct tnode** head, struct tnode* el)
{
    
    if(*head!=NULL)
    {
        el->next=*head;
        *head=el;
    }
    else
        {el->next=NULL;
        *head=el;}
}

struct tnode* push_many(struct tnode* head, struct tnode** list_elements_to_add)
{
    node*new=*list_elements_to_add;
    
    while(new->next)
    {
        new=new->next;
    }
    new->next=head;
    return *list_elements_to_add;
}

struct tnode* pop_one(struct tnode** head)
{
    if(*head==NULL)
        return NULL;
    node*h=*head;
    *head=(*head)->next;
    return h;
}

void clear_st(struct tnode**head)
{
    node* temp = *head;
    while(*head!=NULL)
    {
        temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}

struct tnode* pop_x(struct tnode** head, int x)
{
    if(x<=0)
        return NULL;
    node*prev=NULL;
    node*tmp=*head;
    node*h=*head;
    while(tmp!=NULL && (x>0))
    {
        x--;
        prev=tmp;
        tmp=tmp->next;
    }
    if(x==0)
    {
        *head=tmp;
        if(prev)
            prev->next=NULL;
        return h;
    }
    else
        return NULL;

}