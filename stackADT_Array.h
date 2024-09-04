#ifndef STACK_array
#define STACK_array

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct{
    int elem[MAX];
    int top;
}Stack;

typedef enum {FALSE, TRUE} boolean;

boolean empty(Stack L){
    return (L.top == MAX) ? TRUE : FALSE;
}

boolean full(Stack L){
    return (L.top == 0) ? TRUE : FALSE;
}

void initialize(Stack* L){
    L->top = MAX;
    // printf("Initialize successful.");
}

void push(Stack* L, int elem){
    if(full(*L) == FALSE){
        L->elem[--L->top] = elem;
        // printf("Push successful.\n");
    }else{
        printf("Stack is full, cannot use push.\n");
    }
}

void pop(Stack* L){
    if(empty(*L) == FALSE){
        L->top++;
        // printf("Pop successful.\n");
    }else{
        printf("Stack is empty, cannot use pop.\n");
    }
}

int top(Stack L){
    return (empty(L) == FALSE) ? L.elem[L.top] : -1;
}

void makeNull(Stack* L){
    L->top = MAX;
    printf("Making list null successful.\n");
}

void display(Stack L){
    if(empty(L) == FALSE){
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
    }else{
        printf("Stack is empty, nothing to display.");
    }
}

void pushBottom(Stack* L, int elem){
    if(full(*L) == FALSE){
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
    }else{
        printf("Stack is full, cannot insert at bottom.");
    }
}

#endif