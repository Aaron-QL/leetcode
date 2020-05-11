#include "../include/my.h"

char *queue;
int capacity;
int len;

char enqueue(char);
char dequeue();


bool isValid(char * s){
    len = strlen(s);
    printf("len: %d\n", len);
    if (len == 0) {
        return true;
    } else if (len % 2 != 0) {
        return false;
    }
    capacity = len / 2;
    printf("capacity: %d\n", capacity);
    queue = malloc(capacity * sizeof(char));
    char c;
    while ((c = *s++) != '\0') {
        switch (c) {
            case '(':
            case '[':
            case '{':
                if (enqueue(c) == false) {
                    return false;
                }
                break;
            case ')':
                if (dequeue() != '(') {
                    return false;
                }
                break;
            case ']':
                if (dequeue() != '[') {
                    return false;
                }
                break;
            case '}':
                if (dequeue() != '{') {
                    return false;
                }
                break;
        }
    }

    return capacity == (len / 2) ? 1 : 0;
}

char enqueue(char c)
{
    if (capacity > 0) {
        capacity--;
        *queue++ = c;
        return true;
    } else {
        return false;
    }
}

char dequeue()
{
    if (capacity < (len / 2)) {
        capacity++;
        return *--queue;
    } else {
        return false;
    }
}
