#include<semaphore.h>
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


#define BUF_SIZE 2

struct buffer {
        int data_info;
};

struct buffer buf[BUF_SIZE];

sem_t full, finish;

int value, i;


void *producer(void *data_info);

void *consumer(void *data_info);

int main(void)
{
    int consumer_data,selection, producer_data;
    int k;

    if (sem_init(&finish, 0, BUF_SIZE)) {
        printf("Error Occured: semaphore not initialize\n");
        return -1;
    }
    while (1) {
        printf("Selection\n");
        printf("Producer : 1 , Consumer : 2 , Display : 3 , Exit : 0 ... ");
        scanf("%d",&selection);
        switch (selection) {
        case 1:
            sem_getvalue(&finish, &value);
            sem_getvalue(&full, &value);
            printf("\nProducer\n");
            pthread_t prod_t;
            printf("Enter data:");
            scanf("%d", &producer_data);
            if (pthread_create(&prod_t, NULL, producer, (void *) &producer_data)) {
                printf("Error Occured: thread not created\n");
                return -1;
            }
            break;
        case 2:
            printf("\nConsumer\n");
            sem_getvalue(&finish, &value);
            sem_getvalue(&full, &value);

            pthread_t con_t;
            
            if (pthread_create(&con_t, NULL, consumer, (void *) &consumer_data)) {
                printf("Error: thread not created\n");
                return -1;
            }
            if (i == 0) {
                printf("Buffer finish\n");
                break;
            }

           pthread_join(con_t, NULL);

            printf("Consume data: %d\n", consumer_data);
            break;
        case 3:

                if (i == 0) {

                    printf("Buffer finish\n");
                    break;
                }
                for (k = 0; k < i; k++)
                    printf("buf[%d]: %d\n", k, buf[k].data);
                break;
        case 0:
            sem_destroy(&full);

            sem_destroy(&finish);
            exit (0);
            break;
        }
    }
    sem_destroy(&full);
    sem_destroy(&finish);
    return 0;
}

void *producer(void *arg)
{
    int data_info = *(int *) arg;

    if (sem_wait(&finish)) { 
        printf("Error Occured: sem wait failed\n");

        pthread_exit(NULL);
    }

    buf[i].data_info = data_info;
    i++;

    if (sem_post(&full)) { 
        printf("Error Occured: sem wait failed\n");
        pthread_exit(NULL);
    }

    pthread_exit(NULL);
}

void *consumer(void *arg)
{

    if (sem_wait(&full)) { 
        printf("Error Occured: sem wait failed\n");
        pthread_exit(NULL);
    }

    i--;
    *(int *) arg = buf[i].data_info;

    if (sem_post(&finish)) { 
        printf("  Error Occured: sem wait failed \n");
        pthread_exit(NULL);
    }
    pthread_exit(NULL);
}