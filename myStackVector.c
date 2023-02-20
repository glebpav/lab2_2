#include "myStack.h"
#include "stdio.h"
#include "stdlib.h"

StackVector createStackVector() {
    StackVector stackVector;
    stackVector.length = 0;
    return stackVector;
}

int peakVector(StackVector vector) {
    if (vector.length == 0) {
        printf("Error: empty stack");
        return 0;
    }
    return vector.dataArray[vector.length - 1];
}

double popVector(StackVector *vector) {
    if (vector->length == 0) {
        printf("Error: empty stack");
        return 0;
    }
    vector->length -= 1;
    return vector->dataArray[vector->length];
}

bool pushVector(StackVector *vector, double value) {
    if (vector == NULL || vector->dataArray == NULL) {
        printf("Error: NULL pointer exception");
        return false;
    } else if (vector->length == MAX_VECTOR_LEN) {
        printf("Error: max vector len");
        return false;
    }
    vector->dataArray[vector->length] = value;
    vector->length += 1;
    return true;
}

void destroyVector(StackVector *vectorStack) {}