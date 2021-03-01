#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct info{
    int* arr;
    int t_num;
} info;
int arrofsize = 1000;
void* half_sum(void* p){
    info* ptr = (info*)p;
    int n = ptr->t_num;
    int* t_of_sum = (int*) calloc(1, sizeof(int));
    if(n == 0){
        for(int i = 0; i < arrofsize/2; i++)
            t_of_sum[0] = t_of_sum[0] + ptr->arr[i];
    }
    else{
        for(int i = arrofsize/2; i < arrofsize; i++)
            t_of_sum[0] = t_of_sum[0] + ptr->arr[i];
    }
    pthread_exit(t_of_sum);
}
int main(void){
    int* int_arr = (int*) calloc(arrofsize, sizeof(int));
    for(int i = 0; i < arrofsize; i++)
        int_arr[i] = i + 1;
    info thread_info[2];
    thread_info[0].t_num = 0;
    thread_info[0].arr = int_arr;
    thread_info[1].t_num = 1;
    thread_info[1].arr = int_arr;
    pthread_t tid[2];
    pthread_create(&tid[0], NULL, half_sum, &thread_info[0]);
    pthread_create(&tid[1], NULL, half_sum, &thread_info[1]);
    int* add0;
    int* add1;
    pthread_join(tid[0], (void**)&add0);
    pthread_join(tid[1], (void**)&add1);
    printf("Sum_of_whole_array : = %i\n", *add0 + *add1);
    return 0;
}
