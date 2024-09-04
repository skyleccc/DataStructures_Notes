#ifndef STACK_linkedlist
#define STACK_linkedlist

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int elem;
    struct node* next;
}*Stack;

typedef enum {FALSE,TRUE} boolean;

boolean empty(Stack L){
    return (L == NULL) ? TRUE : FALSE;
}

boolean full(Stack L){
    return FALSE;
}

void initialize(Stack* L){
    *L = NULL;
    printf("Initialize successful.\n");
}

void push(Stack* L, int elem){
    Stack temp = (Stack)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->elem = elem;
        temp->next = *L;
        *L = temp;
        printf("Push successful.\n");
    }else{
        printf("Error: Allocation Failed.\n");
    }
}

void pop(Stack* L){
    if(empty(*L) == FALSE){
        Stack temp = *L;
        *L = temp->next;
        free(temp);
        printf("Pop successful.\n");
    }else{
        printf("Stack is empty, cannot use pop.\n");
    }
}

int top(Stack L){
    return (L != NULL) ? L->elem : -1;
}

void makeNull(Stack* L){
    // manual version
    // while(*L != NULL){
    //     Stack temp = *L;
    //     *L = temp->next;
    //     free(temp);
    // }

    // lazy version
    while(*L != NULL){
        pop(L);
    }
    printf("Making list null successful.\n");
}

void display(Stack L){
    if(empty(L) == FALSE){
        Stack trav;
        Stack temp;

        initialize(&temp);
        for(trav = L; trav != NULL; trav = trav->next){
            push(&temp, trav->elem);
        }

        if(trav == NULL){
            while(temp != NULL){
                printf("\n+-----+\n");
                printf("%d -- Display ", temp->elem);
                pop(&temp);
            }
        }
    }else{
        printf("Stack is empty, nothing to display.");
    }
}

#endif