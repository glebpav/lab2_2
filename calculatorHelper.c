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
            // printf("push: %f\n", atof(thisElement));
            push(&operandsStack, atof(thisElement));
        } else {
            if (operandsStack.length < 2) {
                printf("Error: input string is incorrect1\n");
                break;
            }
            int operand2 = pop(&operandsStack);
            int operand1 = pop(&operandsStack);
            push(&operandsStack, execute(operand1, operand2, thisElement));
        }
    }

    if (operandsStack.length != 1) {
        printf("Error: input string is incorrect2\n");
        return;
    }
    printf("Result: %f", pop(&operandsStack));
    destroy(&operandsStack);
    for (int i = 0; i < elementsArrayLen; ++i) free(elementsArray[i]);
    free(elementsArray);

}

double execute(double operand1, double operand2, char *operator) {
    if (strlen(operator) != 1) {
        printf("Error: unknown operator exception\n");
        return 0;
    }

    printf("%f %s %f \n", operand1, operator, operand2);
    switch (operator[0]) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Error: divide to zero exception\n");
                return 0;
            }
            return operand1 / operand2;
        default:
            printf("Error: unknown operator exception\n");
            return 0;
    }
}