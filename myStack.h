#define MAX_VECTOR_LEN 64

#include "stdbool.h"

#ifndef MY_STACK_H
#define MY_STACK_H

typedef struct Item {
    double data;
    struct Item *next;
} Item;

typedef struct StackVector {
    double dataArray[MAX_VECTOR_LEN];
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

double popVector(StackVector *vector);

double popList(StackList *vector);

bool pushVector(StackVector *vector, double value);

bool pushList(StackList *vector, double value);

void destroyVector(StackVector *vector);

void destroyList(StackList *stackList);

#ifdef Dlist
#   define createStack createStackList
#   define peak peakList
#   define pop popList
#   define push pushList
#   define destroy destroyList
#   define Stack StackList
#else
#   define createStack createStackVector
#   define peak peakVector
#   define pop popVector
#   define push pushVector
#   define destroy destroyVector
#   define Stack StackVector
#endif

#endif
