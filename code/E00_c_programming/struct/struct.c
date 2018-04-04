#include <stdio.h>

typedef struct {
    int x;
    int y;
} punto;

int main(void)
{
    punto p;

    p.x = 1;
    p.y = 2;

    printf("(%d,%d)\n", p.x, p.y);

    return 0;
}
