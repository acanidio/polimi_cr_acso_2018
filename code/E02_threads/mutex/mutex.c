#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

static int a = 0;
static int c = 2;

static pthread_mutex_t mutexA = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t mutexC = PTHREAD_MUTEX_INITIALIZER;

void* thread1( void* args )
{
    int b;
    
    printf("[THREAD1] TID: %d\n", gettid() );
    
    pthread_mutex_lock( &mutexA );
    
    printf("[THREAD1] Richiesto mutex A\n");
    
    sleep(2);
    
    pthread_mutex_lock( &mutexC );
    
    printf("[THREAD1] Richiesto mutex C\n");
    
    b = a;
    
    sleep(2);
    
    b = b + c * 2;
    
    a = b;
    
    pthread_mutex_unlock( &mutexC );
    
    pthread_mutex_unlock( &mutexA );
    
    printf("[THREAD1] a = %d\n", a );
    
    pthread_exit( (void*)NULL );
}

void* thread2( void* args )
{
    int b;
    
    printf("[THREAD2] TID: %d\n", gettid() );
    
    pthread_mutex_lock( &mutexC );
    
    printf("[THREAD2] Richiesto mutex C\n");
    
    sleep(2);
    
    pthread_mutex_lock( &mutexA );
    
    printf("[THREAD2] Richiesto mutex A\n");
    
    b = a;
    
    sleep(2);
    
    b = b + c;
    
    a = b;
    
    pthread_mutex_unlock( &mutexA );
    
    pthread_mutex_unlock( &mutexC );
    
    printf("[THREAD2] a = %d\n", a );
    
    pthread_exit( (void*)NULL );
}

int main()
{
    pthread_t th1, th2;
    
    printf("[MAIN] TID: %d\n", gettid() );
    
    pthread_create( &th1, NULL, thread1, NULL );
    pthread_create( &th2, NULL, thread2, NULL );
    
    pthread_join( th1, NULL );
    pthread_join( th2, NULL );
    
    printf("[MAIN] a = %d\n", a);
    return 0;
}
