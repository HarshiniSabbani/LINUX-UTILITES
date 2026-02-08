#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_t tid1,tid2;
int var=1;  //shared variable
pthread_mutex_t m1;  //mutex initialization
void *f1(void *p)
{
        printf("in thread1...\n");
        pthread_mutex_lock(&m1);//lock
        printf("in thread1...var=%d\n",var);
        ++var;
        sleep(14);//cpu time taking process
        ++var;
        printf("in thread1...var=%d\n",var);
        pthread_mutex_unlock(&m1);//unlock
        printf("thread1...exiting\n");
        pthread_exit(NULL);
}

void *f2(void *p)
{
        printf("thread2...\n");
        pthread_mutex_lock(&m1);//lock
        printf("in thread2..var=%d\n",var);
        ++var;
        sleep(12);//take cpu time
        var+=100;
        printf("in thread2..var=%d\n",var);
        pthread_mutex_unlock(&m1);//unlock
        printf("thread2...exiting\n");
        pthread_exit(NULL);
}


int main()
{
        printf("pid=%d\n",getpid());
        pthread_mutex_init(&m1,NULL);
        pthread_create(&tid1,NULL,f1,NULL);
        pthread_create(&tid2,NULL,f2,NULL);
        pthread_join(tid1,NULL);
        pthread_join(tid2,NULL);
        pthread_exit(NULL);
        pthread_exit(NULL);
        return 0;
}
