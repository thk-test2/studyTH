#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd;
    const char *buf = "I am testing the write().";
    ssize_t nr;

    fd = open("./test.txt", O_WRONLY | O_CREAT | O_TRUNC,
              S_IWUSR | S_IRUSR | S_IWGRP | S_IRGRP | S_IROTH);

    if (fd == -1) printf("open error\n");
    else printf("open success\n");

    fd = creat("./test2.txt", 0644);
    if (fd == -1) printf("create error\n");
    else printf("create success\n");

    nr = write(fd, buf, strlen(buf));
    if (nr == -1) printf("test2.txt writing error\n");
    else printf("test2.txt writing succeed!(%d)\n", nr);

    return 0;
}
