#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef void (*sighandler_t) (int);

void usr1handler( int sig )
{
    if( sig == SIGUSR1 )
    {
        printf("Ricevuto SIGUSR1\n");
    }
    else if( sig == SIGTERM )
    {
        printf("Ricevuto SIGTERM\n");
        exit(0);
    }
}

void usr2handler( int sig )
{

}

int main( void )
{
    sighandler_t p;
    
    p = signal( SIGUSR1, usr1handler );
    if( p == SIG_ERR )
    {
        printf("SIGUSR1 non registrato\n");
        
        exit(-1);
    }
    
    p = signal( SIGTERM, usr1handler );
    if( p == SIG_ERR )
    {
        printf("SIGUSR1 non registrato\n");
        
        exit(-1);
    }

    while(1);
    
    return 0;
}
