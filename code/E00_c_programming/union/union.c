#include <stdio.h>

typedef union {
    int  valore;
    char byte[4];
} aint;

int main()
{
    aint a;

    a.valore = 300;

    printf("%d\n", a.byte[0] );

    return 0;
}
