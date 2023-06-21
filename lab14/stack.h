#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    int value;
    struct tnode* next;
} node;

void print_stack(struct tnode* head);
void push_one(struct tnode** head, struct tnode* el);
struct tnode* push_many(struct tnode* head, struct tnode** list_elements_to_add);
struct tnode* pop_one(struct tnode** head);
struct tnode* pop_x(struct tnode** head, int x);
void clear_st(struct tnode**head);
#endif
