// Header Files

#include "stackADT_Array.h"
//#include "stackADT_LinkedList.h"

//

#include <stdio.h>
#include <stdlib.h>

int main(){
    system("cls");

    Stack S;
    int topElem;
    boolean isFull;
    boolean isEmpty;

    initialize(&S);
    display(S);
    isEmpty = empty(S);
    printf("\nIs stack empty?: %s\n\n", (isEmpty == TRUE) ? "TRUE" : "FALSE");

    push(&S, 1);
    display(S);
    isEmpty = empty(S);
    printf("\nIs stack empty?: %s\n\n", (isEmpty == TRUE) ? "TRUE" : "FALSE");

    push(&S, 2);
    push(&S, 7);
    push(&S, 27);
    push(&S, 40);
    display(S);
    topElem = top(S);
    printf("\nTop Element: %d\n", topElem);
    isFull = full(S);
    printf("Is stack full?: %s\n\n", (isFull == TRUE) ? "TRUE" : "FALSE");

    pop(&S); // delete 40
    display(S);
    topElem = top(S);
    printf("\nTop Element: %d\n", topElem);
    isFull = full(S);
    printf("Is stack full?: %s\n\n", (isFull == TRUE) ? "TRUE" : "FALSE");

    pushBottom(&S, 75);
    display(S);
    isFull = full(S);
    printf("\nIs stack full?: %s\n\n", (isFull == TRUE) ? "TRUE" : "FALSE");

    makeNull(&S);
    display(S);
    isEmpty = empty(S);
    printf("\nIs stack empty?: %s\n\n", (isEmpty == TRUE) ? "TRUE" : "FALSE");

    return 0;
}