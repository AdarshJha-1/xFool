#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int loops;
volatile int counter = 0;

void *worker(void *arg)
{
    for (int i = 0; i < loops; i++)
    {
        counter++;
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: thread <value>\n");
        exit(1);
    }
    loops = atoi(argv[1]);

    pthread_t p1, p2;
    printf("Initial value : %d\n", counter);

    if (pthread_create(&p1, NULL, worker, NULL) != 0)
    {
        fprintf(stderr, "error in creating thread\n");
        exit(1);
    }
    if (pthread_create(&p2, NULL, worker, NULL) != 0)
    {
        fprintf(stderr, "error in creating thread\n");
        exit(1);
    }

    if (pthread_join(p1, NULL) != 0)
    {
        fprintf(stderr, "error using pthread_join, p1\n");
        exit(1);
    }
    if (pthread_join(p2, NULL) != 0)
    {
        fprintf(stderr, "error using pthread_join, p2\n");
        exit(1);
    }

    printf("Final value : %d\n", counter);

    return 0;
}
