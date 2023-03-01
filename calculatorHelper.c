#include <stdio.h>
#include <stdlib.h>
#include "calculatorHelper.h"
#include "stringHelper.h"
#include "myStack.h"
#include "string.h"
#include "stdbool.h"

void calculate(char *inputString) {

    strrev(inputString);
    bool errorOccurred;
    int elementsArrayLen;
    char **elementsArray = getElementsArray(inputString, &elementsArrayLen);
    Stack operandsStack = createStack();

    for (int elementIdx = 0; elementIdx < elementsArrayLen; ++elementIdx) {
        char *thisElement = elementsArray[elementIdx];
        if (isDigit(thisElement)) {
            // printf("push: %f\n", atof(thisElement));
            errorOccurred = !push(&operandsStack, atof(thisElement));
        } else {
            if (operandsStack.length < 2) {
                printf("Error: input string is incorrect1\n");
                errorOccurred = true;
                break;
            }
            double operand2 = pop(&operandsStack);
            double operand1 = pop(&operandsStack);

            push(&operandsStack, execute(operand2, operand1, thisElement, &errorOccurred));
        }

        if (errorOccurred) break;
    }

    if (!errorOccurred) {
        if (operandsStack.length != 1) {
            printf("Error: input string is incorrect2\n");
        } else {
            printf("Result: %f", pop(&operandsStack));
        }
    }
    destroy(&operandsStack);
    for (int i = 0; i < elementsArrayLen; ++i) free(elementsArray[i]);
    free(elementsArray);

}

double execute(double operand1, double operand2, char *operator, bool *errorOccurred) {

    *errorOccurred = false;

    if (strlen(operator) != 1) {
        *errorOccurred = true;
        printf("Error: unknown operator exception\n");
        return 0;
    }

    printf("%f %s %f \n", operand1, operator, operand2);
    switch (operator[0]) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                *errorOccurred = true;
                printf("Error: divide to zero exception\n");
                return 0;
            }
            return operand1 / operand2;
        default:
            *errorOccurred = true;
            printf("Error: unknown operator exception\n");
            return 0;
    }
}