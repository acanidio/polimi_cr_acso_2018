#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    
    pid = fork();
    
    if( pid == 0 )
    {
        sleep(10);
        printf("Sono il figlio. PID: %d\n", (int) getpid() );
        printf("Sono il figlio. PPID: %d\n", (int) getppid() );
    }
    else
    {
        // sleep(10);
        printf("Sono il padre. PID: %d\n", (int) getpid() );
        printf("Sono il padre. PPID: %d\n", (int) getppid() );
    }
    
    return 0;
}
