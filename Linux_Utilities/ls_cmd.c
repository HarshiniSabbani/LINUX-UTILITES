
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/resource.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main()
{
        DIR *dir=opendir("filesystems");
        if(dir==NULL)
        {
                perror("opendir");
                exit(0);
        }

        struct dirent *entry;
        struct stat st;
        while(entry=readdir(dir))
        {

                  if(fstatat(dirfd(dir), entry->d_name, &st, 0) == -1)
                    {
                         perror("fstatat");
                         continue;
                    }

                if(S_ISDIR(st.st_mode))
                {
                     printf("\x1b[32m%s\x1b[0m\n",entry->d_name);
                }
                printf("%s\n",entry->d_name);
        }

        closedir(dir);
}