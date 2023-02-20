#include <stdio.h>
#include <malloc.h>
#include "myStack.h"
#include "stringHelper.h"
#include "calculatorHelper.h"


// https://habr.com/ru/post/596925/

int main() {

    char *inputString = getLine();
    calculate(inputString);
    free(inputString);

    return 0;
}
