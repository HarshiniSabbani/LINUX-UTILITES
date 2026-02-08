#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
        if(argc<2)
        {
                printf("invalid arguments\n");
        }
        char *ptr;
        char str[100];
        int fd=open(argv[2],O_RDONLY);

        while(read(fd,str,sizeof(str)))
        {
        if(ptr=strstr(str,argv[1])!=NULL)
        {
                printf("%s\n",str);
        }
        }
}