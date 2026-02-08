#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
        int i;
        if(argc<2)
        {
                printf("invalid input\n");
                printf("exe c/s\n");
                exit(0);
        }

        if(argv[1][0]=='c')
        {
                for(i=2;i<argc;i++)
                {
                        if(fork()==0)
                        {
                                execlp(argv[i],argv[i],NULL);
                                exit(1);
                        }
                }

        for(i=0;i<argc;i++)
        {
                if(fork()>0)
                {
                        wait(NULL);
                }
        }
        }

        else if(argv[1][0]=='s')
        {
                for(i=2;i<argc;i++)
                {
                        if(fork()==0)
                        {
                                execlp(argv[i],argv[i],NULL);
                                exit(1);
                        }
                        else
                        {
                                wait(NULL);
                        }
                }
        }
}