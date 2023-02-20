#include <malloc.h>
#include "myStack.h"
#include "stdio.h"

StackList createStackList() {
    StackList stackList;
    stackList.length = 0;
    return stackList;
}

int peakList(StackList stackList) {
    if (stackList.length == 0 || stackList.next == NULL) {
        printf("Error: empty stack");
        return 0;
    }
    return stackList.next->data;
}

double popList(StackList *stackList) {
    if (stackList == NULL) {
        printf("Error: null pointer exception");
        return 0;
    }
    if (stackList->length == 0 || stackList->next == NULL) {
        printf("Error: empty stack");
        return 0;
    }

    Item *deletingItem = stackList->next;
    double deletingItemData = deletingItem->data;
    stackList->next = deletingItem->next;
    stackList->length -= 1;
    free(deletingItem);
    return deletingItemData;
}

bool pushList(StackList *vector, double value) {
    Item *newItem = calloc(1, sizeof(Item));
    newItem->next = vector->next;
    newItem->data = value;
    vector->next = newItem;
    return true;
}

void destroyList(StackList *stackList) {
    if (stackList == NULL) return;
    Item *nextItem = stackList->next;
    while (nextItem != NULL) {
        Item *deletingItem = nextItem;
        nextItem = deletingItem->next;
        free(deletingItem);
    }
    free(stackList);
}