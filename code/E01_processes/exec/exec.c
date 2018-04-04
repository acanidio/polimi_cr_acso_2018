#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main( int argc, char* argv[] )
{
    char* args[] = { "pippo", "pluto", NULL };
    execvp("./prog", args );
    
    printf("Prova\n");
    
    return 0;
}
