#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N   10

int main( void )
{
    int i, status;
    pid_t pid[N];
    pid_t wpid;
    
    printf("Padre: %d\n", (int) getpid() );
    for( i = 0; i < N; i++ )
    {
        wpid = fork();
        
        if( wpid == 0 )
        {
            // FIGLIO
            printf("[FIGLIO] PID %d\n", (int) getpid() );
            sleep(5);
            
            exit(i);
        }
        else
        {
            pid[i] = wpid;
        }    
    }
    
    printf("[PADRE] Aspetto il filgio %d\n", (int) pid[4] );
    wpid = waitpid( pid[4], &status, 0 );
    
    printf("[PADRE] Terminato %d con status %d\n", (int) wpid, status );
    
    printf("[PADRE] Attendo lgi altri figli\n");
    for( i = 0; i < N - 1; i++ )
    {
        wpid = wait( &status );
        printf("[PADRE] Terminato %d con status %d\n", (int) wpid, status );
    }
    
    exit(EXIT_SUCCESS);
}
