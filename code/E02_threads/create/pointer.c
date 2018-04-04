#include <stdio.h>

int main( void )
{
    char a[] = { 0, 1, 2, 3 };
    int* p = (int*) &a;
    char* p2 = (char*)&a;
    
    printf("%d\n", *p );
    printf("%d\n", *p2);
}
