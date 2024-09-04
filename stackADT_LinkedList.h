#ifndef STACK_linkedlist
#define STACK_linkedlist

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int elem;
    struct node *next;
} *Stack;

typedef enum
{
    FALSE,
    TRUE
} boolean;

boolean empty(Stack L)
{
    return (L == NULL) ? TRUE : FALSE;
}

boolean full(Stack L)
{
    return FALSE;
}

void initialize(Stack *L)
{
    *L = NULL;
    // printf("\nInitialize successful.\n");
}

void push(Stack *L, int elem)
{
    Stack temp = (Stack)malloc(sizeof(struct node));
    if (temp != NULL)
    {
        temp->elem = elem;
        temp->next = *L;
        *L = temp;
        // printf("Push successful.\n");
    }
    else
    {
        printf("Error: Allocation Failed.\n");
    }
}

void pop(Stack *L)
{
    if (empty(*L) == FALSE)
    {
        Stack temp = *L;
        *L = temp->next;
        free(temp);
        // printf("Pop successful.\n");
    }
    else
    {
        printf("Stack is empty, cannot use pop.\n");
    }
}

int top(Stack L)
{
    return (empty(L) == FALSE) ? L->elem : -1;
}

void makeNull(Stack *L)
{
    // manual version
    // while(*L != NULL){
    //     Stack temp = *L;
    //     *L = temp->next;
    //     free(temp);
    // }

    // lazy version
    while (empty(*L) == FALSE)
    {
        pop(L);
    }
    printf("\nMaking list null successful.\n");
}

void display(Stack L)
{
    if (empty(L) == FALSE)
    {
        Stack temp;
        initialize(&temp);
        while(empty(L) == FALSE){
            printf("\n+-----+\n");
            printf("%d \n", top(L));
            push(&temp, top(L));
            pop(&L);
        }
        while(empty(temp) == FALSE){
            push(&L, top(temp));
            pop(&temp);
        }
    }
    else
    {
        printf("Stack is empty, nothing to display.");
    }
}

void pushBottom(Stack* L, int elem){
    Stack temp;
    initialize(&temp);
    while(empty(*L) == FALSE){
        push(&temp, top(*L));
        pop(L);
    }
    push(L, elem);
    while(empty(temp) == FALSE){
        push(L, top(temp));
        pop(&temp);
    }
    printf("Push at the bottom successful.");
}

#endif