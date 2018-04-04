#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int status;
    pid_t wpid;
    pid_t pid = fork();
    
    if( pid == 0 )
    {
        printf("Figlio %d\n", (int) getpid() );
        sleep(5);
        
        exit(EXIT_FAILURE);
    }
    else
    {
        wpid = wait( &status );
        printf("PID: %d\n", (int) wpid );
        printf("STATUS: %d\n", status );        
    }
    
    return 0;
}
