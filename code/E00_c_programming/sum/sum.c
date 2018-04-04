#include <stdio.h>
#include <stdlib.h>

int pluto(void)
{
    n = 2;
}

int global;

int main( int argc, char* argv[] )
{
    int n, m;

    // for(i = 0; i < argc; i++)
    // {
    //     printf("%s\n",argv[i]);
    // }

    if( argc != 3 )
    {
        printf("ERROR: %s <num1> <num2>\n",argv[0]);
        return -1;
    }

    n = atoi( argv[1] );
    m = atoi( argv[2] );

    printf("%d\n", n + m);

    return 0;
}
