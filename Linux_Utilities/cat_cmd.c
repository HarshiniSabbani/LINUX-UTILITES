#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("invalid arguments\n");
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    char buf[1024];
    int n;

    while ((n = read(fd, buf, sizeof(buf))) > 0)
    {
        write(1, buf, n);   // 1 → stdout
    }

    close(fd);
    return 0;
}
