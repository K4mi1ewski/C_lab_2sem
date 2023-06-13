#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
    char value;
    struct tnode * next;
} Node;

void printlist(Node* head)
{
    Node* temp = head;
    printf("Head -> ");
    while(temp)
    {
        printf("['%c'] -> ", temp->value);
        temp = temp->next;
    }
    printf(" NULL\n" );
}

Node* clearlist(Node*h)
{
    while(h) 
    {
        Node* temp = h->next;
        free(h);
        h = temp;
    }
    
    return NULL;
}

Node* add_end (Node* head, Node* elem)
{
elem->next = NULL;
if(head){
Node* temp = head;
while(temp->next)
temp=temp->next;

temp->next = elem;
}
else
    head = elem;
return head;
}


void add_front(Node** h, char val)
{
    Node* new = malloc(sizeof(Node));
    new -> value = val;
    new->next = *h;
    *h = new;
}

Node* fun(Node**head,char val){

    Node* temp = *head;
    Node* new =  NULL;
    Node* prev = NULL;
    Node* next = NULL;
    while(temp)
    {
        next = temp->next;
        if((temp->value == val) ||(temp->value == val-32))
        {
            if(temp==*head)
            {
                new = add_end(new,temp);
                *head=next;
                temp=next;
            }
            else
            {
            new = add_end (new, temp);
            if(prev)
                prev->next = next;
            temp = next;
            }
        }
        else
        {
        prev = temp;
        temp = next;
        }
    }
    return new;
}

int main (void)
{
Node* head = NULL;
add_front(&head, 'a');
add_front(&head, 'b');
add_front(&head, 'c');
add_front(&head, 'a');
add_front(&head, 'a');
add_front(&head, 'A');
add_front(&head, 'd');
add_front(&head, 'A');
add_front(&head, 'a');
printlist(head);
Node* left = fun(&head, 'a');
printlist(head);
printlist(left);


head = clearlist(head);
left = clearlist(left);
}