#include <stdio.h>
#include <stdlib.h>
#include "calculatorHelper.h"
#include "stringHelper.h"
#include "myStack.h"
#include "string.h"

void calculate(char *inputString) {

    int elementsArrayLen;
    char **elementsArray = getElementsArray(inputString, &elementsArrayLen);
    Stack operandsStack = createStack();

    for (int elementIdx = 0; elementIdx < elementsArrayLen; ++elementIdx) {
        char *thisElement = elementsArray[elementIdx];
        if (isDigit(thisElement)) {
            push(&operandsStack, atoi(thisElement));
        } else {
            if (operandsStack.length < 2) {
                printf("Error: input string is incorrect");
                break;
            }
            int operand1 = pop(&operandsStack);
            int operand2 = pop(&operandsStack);
            execute(operand1, operand2, thisElement);
        }
    }

    if (operandsStack.length != 0) {
        printf("Error: input string is incorrect");
        return;
    }
    printf("Result: %f", pop(&operandsStack));
}

double execute(double operand1, double operand2, char *operator) {
    if (strlen(operator) != 1) {
        printf("Error: unknown operator exception");
        return 0;
    }
    switch (operator[0]) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Error: divide to zero exception");
                return 0;
            }
            return operand1 / operand1;
        default:
            printf("Error: unknown operator exception");
            return 0;
    }
}