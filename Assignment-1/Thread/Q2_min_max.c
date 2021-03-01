# include <pthread.h>
# include <stdio.h>

# define arrayofsize 10

struct Struct_Max_Min
{
    int input_max;
    int input_min;
};

int arr[arrayofsize];

void *thread_find_min_max(void *);

int main()
{
    pthread_t p_t;
    struct Struct_Max_Min *stuct_main_thread,*struct_thread1;
    int FinalMax,FinalMin;
    
    stuct_main_thread=(struct Struct_Max_Min*)malloc(sizeof(struct Struct_Max_Min));
    
    int input_count;
    for(input_count=0;input_count<arrayofsize;input_count++)
    {
        printf("Enter Value of arr[%d] :",input_count);
        scanf("%d",&arr[input_count]);
    }        
    pthread_create(&p_t,NULL,thread_find_min_max,NULL);
    
    stuct_main_thread->input_max=arr[0];
    stuct_main_thread->input_min=arr[0];
    
    for(input_count=1;input_count<arrayofsize/2;input_count++)
    {
        if(arr[input_count] > stuct_main_thread->input_max)
        {
            stuct_main_thread->input_max=arr[input_count];
        }
        
        if(arr[input_count] < stuct_main_thread->input_min)
        {
            stuct_main_thread->input_min=arr[input_count];
        }
    }    
    
    pthread_join(p_t,(void**)&struct_thread1);    
    
    if(stuct_main_thread->input_max >= struct_thread1->input_max)
    {
        FinalMax=stuct_main_thread->input_max;
    }    
    else
    {
        FinalMax=struct_thread1->input_max;
    }
        
    if(stuct_main_thread->input_min <=struct_thread1->input_min)
    {
        FinalMin=stuct_main_thread->input_min;
    }
    else
    {
        FinalMin=struct_thread1->input_min;
    }
    
    printf("Final Output_Max : %d \n",FinalMax);
    printf("Final Outpu_Min : %d \n",FinalMin);
    return 0;
}


void *thread_find_min_max(void *para)
{
    struct Struct_Max_Min *st_main;
    st_main=(struct Struct_Max_Min*)malloc(sizeof(struct Struct_Max_Min));
        
    int input_count;
    st_main->input_max=arr[arrayofsize/2];
    st_main->input_min=arr[arrayofsize/2];
        
    
    for(input_count=arrayofsize/2 + 1;input_count<arrayofsize;input_count++)
    {
        if(arr[input_count] > st_main->input_max)
        {
            st_main->input_max=arr[input_count];
        }
        if(arr[input_count] < st_main->input_min)
        {
            st_main->input_min=arr[input_count];
        }
    }    
    
    pthread_exit((void*)st_main);        
}