#include <stdio.h>
int add(int a, int b)
{
    return a + b;
}
int main(int argc, char *argv[])
{
    for (int i = 0; i < 5; ++i)
    {
        printf("%i\n", add(i, 2 * i));
    }
    
    for (int i = 1; i < argc; ++i)
    {
        printf("%s\n", argv[i]);
    }
    return 0;
}
