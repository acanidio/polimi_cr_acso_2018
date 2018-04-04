#include <stdio.h>

#define N 3

static int count = 0;

void f(void)
{
    printf("%d\n", ++count);
}

int main(void)
{
    int i;

    for(i = 0; i < N; i++)
    {
        f();
    }

    count = 5;
    printf("%d\n", count);

    return 0;
}
