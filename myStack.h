#ifndef MY_STACK_H
#define MY_STACK_H

#include "stdbool.h"

#define MAX_VECTOR_LEN 64

typedef struct Item {
    int data;
    struct Item *next;
} Item;

typedef struct StackVector {
    int dataArray[MAX_VECTOR_LEN];
    int length;
} StackVector;

typedef struct StackList {
    Item *next;
    int length;
} StackList;

StackVector createStackVector();
StackList createStackList();

int peakVector(StackVector vector);
int peakList(StackList vector);

int popVector(StackVector *vector);
int popList(StackList *vector);

bool pushVector(StackVector *vector, int value);
bool pushList(StackList *vector, int value);

void destroyVector(StackVector *vector);
void destroyList(StackList *list);

#ifdef list
#   define createStack &createStackVector;
#   define peak &peakVector;
#   define pop &popVector;
#   define push &pushVector;
#   define destroy &destroyVector;
#   define Stack StackVector;
#else
#   define createStack &createStackList;
#   define peak &peakList;
#   define pop &popList;
#   define push &pushList;
#   define destroy &destroyList;
#   define Stack StackList;
#endif

#endif
