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
int main (void)
{
    Node* head1=NULL;
    Node* el1 = malloc(sizeof(Node));
    el1->value = 'a';
    Node* el2 = malloc(sizeof(Node));
    el2->value = 'c';
    Node* el3 = malloc(sizeof(Node));
    el3->value = 'v';
    Node* el4 = malloc(sizeof(Node));
    el4->value = 'f';
    Node* el5= malloc(sizeof(Node));
    el5->value = 't';
    head1 = add_end(head1, el1);
    head1 = add_end(head1, el2);
    head1 = add_end(head1, el3);
    head1 = add_end(head1, el4);
    head1 = add_end(head1, el5);

    printlist(head1);
    head1=clearlist(head1);
    return 0;
}