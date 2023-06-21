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
        printf("Brak elementow w stosie!\n");
push_one(&stack1,a);
push_one(&stack1,b);
print_stack(stack1);
printf("\n");
push_one(&stack2,c);
push_one(&stack2,d);
print_stack(stack2);
printf("\n");
stack1=push_many(stack1,&stack2);
print_stack(stack1);
printf("\n");
popped=pop_one(&stack1);
printf("\n");
print_stack(stack1);
if(popped)
        {printf("\nusuwam:%d\n",popped->value);
        free(popped);
        }
    else
        printf("\nBrak elementow w stosie!\n");
print_stack(stack1);
printf("\n");
node* usuniete = pop_x(&stack1, 6);
if(usuniete)
    {node*tmp=usuniete;
    printf("\nUsuniete elementy:\n");
        while(usuniete)
        {
            tmp=usuniete->next;
            printf("%d->",usuniete->value);
            free(usuniete);
            usuniete=tmp;
        }
    }   
else
    printf("\npodano niepoprawna ilosc elementow!\n");

print_stack(stack1);
usuniete=pop_x(&stack1, 2);
printf("\n");
if(usuniete)
    {node*tmp=usuniete;
    printf("\nUsuniete elementy:\n");
        while(usuniete)
        {
            tmp=usuniete->next;
            printf("%d->",usuniete->value);
            free(usuniete);
            usuniete=tmp;
        }
        printf("\n");
    }   
else
    printf("\npodano niepoprawna ilosc elementow!\n");
print_stack(stack1);
clear_st(&stack1);
printf("\n");
print_stack(stack1);
    return 0;
}

