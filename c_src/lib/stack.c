#include "../../include/my.h"

typedef struct TreeNode* elementType;

typedef struct {
    elementType *array;
    int stckTop;
    int capacity;
} Stack;

Stack* createStack(int initSize)
{
    if (initSize < 1) {
        return NULL;
    }
    Stack* s = (Stack*) malloc(sizeof(Stack));
    if (s == NULL) {
        return NULL;
    }
    s->array = (elementType*) malloc(sizeof(elementType) * initSize);
    if (s->array == NULL) {
        return NULL;
    }
    s->stckTop = 0;
    s->capacity = initSize;

    return s;
}

void reallocStack(Stack* s)
{
    if (s->stckTop == s->capacity) {
        s->capacity *= 2;
        s->array = (elementType*) realloc(s->array, s->capacity * sizeof(elementType));
    }

    if (s->stckTop < s->capacity / 4) {
        s->capacity /= 2;
        s->array = (elementType*) realloc(s->array, s->capacity * sizeof(elementType));
    }
}

void freeStack(Stack* s)
{
    if (s != NULL) {
        free(s->array);
        free(s);
    }
}

bool isFull(Stack *s)
{
    return s->stckTop == s->capacity;
}

bool isEmpty(Stack *s)
{
    return s->stckTop == 0;
}

void push(Stack *s, elementType e)
{
    if (isFull(s)) {
        reallocStack(s);
    }
    s->array[s->stckTop++] = e;
}

elementType pop(Stack *s)
{
    if (isEmpty(s)) {
        printf("empty stack\n");
        return 0;
    }

    elementType e = s->array[--s->stckTop];
    if (s->stckTop < s->capacity / 3) {
        reallocStack(s);
    }

    return e;
}

int main(void)
{
    Stack* s = createStack(6);


    return 0;
}