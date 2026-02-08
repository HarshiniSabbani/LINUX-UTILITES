#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(int argc,char *argv[])
{
        int fd;
        fd=open(argv[1],O_RDONLY);
        if(fd==-1)
        {
                perror("read");
                exit(0);
        }
        int fd1;
        fd1=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0644);
        char a[100];
        int ret;
        ret=read(fd,a,sizeof(a));
        write(fd1,a,ret);
}