#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
pthread_t tid1,tid2;
sem_t s;
int var=1;//shared variable
void *f1(void *p)
{
        sem_wait(&s);//locks by makin it 1
        printf("in thread1..var=%d\n",var);
        ++var;
        sleep(2);
        ++var;
        printf("thread1...var=%d\n",var);
        printf("thread1...exiting\n");
        sem_post(&s);//value in now so it unlocks
}

void *f2(void *p)
{
        sem_wait(&s);//lock it
        printf("in thread2..var=%d\n",var);
        ++var;
        sleep(10);
        ++var;
        printf("thread2...var=%d\n",var);
        printf("thread2...exiting\n");
        sem_post(&s);//unlock
}



int main()
{
        sem_init(&s,0,1);//initialize semaphore
        pthread_create(&tid1,NULL,f1,NULL);
        pthread_create(&tid2,NULL,f2,NULL);
        pthread_join(tid1,NULL);
        pthread_join(tid2,NULL);
        sem_destroy(&s);
        return 0;
}
