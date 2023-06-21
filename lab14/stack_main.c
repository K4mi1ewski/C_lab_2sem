#include "stack.h"

int main ()
{
node* a = malloc(sizeof(node));
node* b = malloc(sizeof(node));
node* c = malloc(sizeof(node));
node* d = malloc (sizeof(node));
a->value=1;
b->value=2;
c->value=3;
d->value=4;
a->next=NULL;
b->next=NULL;
c->next=NULL;
d->next=NULL;

node*stack1=NULL;
node*stack2=NULL;

node*popped=pop_one(&stack1);
    if(popped)
        {printf("%d",popped->value);
        free(popped);
        }
    else
        printf("Brak elementow w stosie!");
push_one(&stack1,a);
push_one(&stack1,b);
print_stack(stack1);
push_one(&stack2,c);
push_one(&stack2,d);
print_stack(stack2);
stack1=push_many(stack1,&stack2);
print_stack(stack1);
popped=pop_one(&stack1);
print_stack(stack1);
if(popped)
        {printf("%d",popped->value);
        free(popped);
        }
    else
        printf("Brak elementow w stosie!");
print_stack(stack1);
node* usuniete = pop_x(&stack1, 6);
if(usuniete)
    {node*tmp=usuniete;
        while(usuniete)
        {
            tmp=usuniete->next;
            printf("%d->",usuniete->value);
            free(usuniete);
            usuniete=tmp;
        }
    }   
else
    printf("podano niepoprawna ilosc elementow!");

print_stack(stack1);
node* usuniete=pop_x(&stack1, 2);
if(usuniete)
    {node*tmp=usuniete;
        while(usuniete)
        {
            tmp=usuniete->next;
            printf("%d->",usuniete->value);
            free(usuniete);
            usuniete=tmp;
        }
    }   
else
    printf("podano niepoprawna ilosc elementow!");
print_stack(stack1);
clear_st(&stack1);
    return 0;
}

