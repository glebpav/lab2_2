#include <stdio.h>
#include "stringHelper.h"
#include "string.h"
#include "stdlib.h"

char **getElementsArray(char *inputString, int *elementsArrayLen) {
    char **elementsArray = NULL;
    *elementsArrayLen = 0;
    char *stringDuplicate = strdup(inputString);
    char *buffer = strtok(stringDuplicate, " ");
    while (buffer != NULL) {
        elementsArray = realloc(elementsArray, (*elementsArrayLen + 1) * sizeof(char *));
        elementsArray[*elementsArrayLen] = strdup(buffer);
        *elementsArrayLen += 1;
        buffer = strtok(NULL, " ");
    }
    return elementsArray;
}

char *getLine(void) {
    char *line = malloc(100), *linep = line;
    size_t lenmax = 100, len = lenmax;
    int c;

    if (line == NULL)
        return NULL;

    for (;;) {
        c = fgetc(stdin);
        if (c == EOF)
            break;

        if (--len == 0) {
            len = lenmax;
            char *linen = realloc(linep, lenmax *= 2);

            if (linen == NULL) {
                free(linep);
                return NULL;
            }
            line = linen + (line - linep);
            linep = linen;
        }

        if ((*line++ = c) == '\n')
            break;
    }
    *line = '\0';
    return linep;
}

bool isDigit(char *randomString) {
    for (int i = 0; i < strlen(randomString); ++i) {
        if (randomString[i] > '9') return false;
    }
    return true;
}