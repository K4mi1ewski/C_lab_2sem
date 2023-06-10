#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
    char value;
    struct tnode * next;
} Node;

void add_front(Node** h, char val)
{
    Node* new = malloc(sizeof(Node));
    new -> value = val;
    new->next = *h;
    *h = new;
}
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

int main (void)
{
Node* head = NULL;

add_front(&head, 'a');
add_front(&head, 'c');
add_front(&head, 'v');
add_front(&head, 'f');
add_front(&head, 't');
printlist(head);
head = clearlist(head);
    return 0;
}