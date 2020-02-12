#include "../../include/my.h"

#define InitCapacity 6

typedef struct {
    void** array;
    int elementSize;
    int stckTop;
    int capacity;
} Stack;

Stack* createStack(int elementSize)
{
    if (elementSize == 0) {
        return NULL;
    }
    Stack* s = (Stack*) malloc(sizeof(Stack));
    if (s == NULL) {
        return NULL;
    }
    s->elementSize = elementSize;
    s->array = malloc(s->elementSize * InitCapacity);
    if (s->array == NULL) {
        return NULL;
    }
    s->stckTop = 0;
    s->capacity = InitCapacity;

    return s;
}

void reallocStack(Stack* s)
{
    if (s->stckTop == s->capacity) {
        s->capacity *= 2;
        s->array = realloc(s->array, s->capacity * s->elementSize);
    }

    if (s->stckTop < s->capacity / 4) {
        s->capacity /= 2;
        s->array = realloc(s->array, s->capacity * s->elementSize);
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

void push(Stack *s, void* e)
{
    if (isFull(s)) {
        reallocStack(s);
    }
    s->array[s->stckTop++] = e;
}

void* pop(Stack *s)
{
    if (isEmpty(s)) {
        printf("empty stack\n");
        return 0;
    }

    void* e = s->array[--s->stckTop];
    if (s->stckTop < s->capacity / 3) {
        reallocStack(s);
    }

    return e;
}