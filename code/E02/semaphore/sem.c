#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N 10

static sem_t sem;
static sem_t sem2;

static int a = 0;

void* th1( void* args )
{
    int i;
    for( i = 0; i < N; i++ )
    {
        a = i;
        printf("[TH1] a = %d\n", a);
        sem_post( &sem );
        sem_wait( &sem2 );
    }
    
    pthread_exit( (void*)NULL );
}

void* th2( void* args )
{
    int i;
    for( i = 0; i < N; i ++)
    {
        sem_wait(&sem);
        printf("[TH2] 2a = %d\n", 2 * a);
        // sem_post(&sem2);
    }
    
    pthread_exit( (void*)NULL );
}

int main()
{
    pthread_t t1, t2;
    
    sem_init( &sem, 0, 0 );
    sem_init( &sem2, 0, 0 );
    
    pthread_create( &t1, NULL, th1, NULL );
    pthread_create( &t2, NULL, th2, NULL );
    
    pthread_join( t1, NULL );
    pthread_join( t2, NULL );
    
    sem_destroy( &sem );
    sem_destroy( &sem2 );
    
    return 0;
}
