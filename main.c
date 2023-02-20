#include <stdio.h>
#include "myStack.h"
#include "stringHelper.h"
#include "calculatorHelper.h"


// https://habr.com/ru/post/596925/

int main() {

/*
    Stack myStack = createStack();
    push(&myStack, 4);
    push(&myStack, 5);

    printf("is working\n");
    while (myStack.length != 0) {
        printf("value is: %d\n", pop(&myStack));
    }
*/
    char *inputString = getLine();
    calculate(inputString);


    return 0;
}
