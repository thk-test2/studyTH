#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd;
    fd = open("./test.txt", O_WRONLY | O_CREAT | O_TRUNC,
              S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);

    if (fd == -1) printf("open error\n");
    else printf("open success\n");

    fd = creat("./test2.txt", 0644);
    if (fd == -1) printf("create error\n");
    else printf("create success\n");

    return 0;
}
