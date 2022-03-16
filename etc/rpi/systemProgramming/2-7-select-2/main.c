#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/select.h>
#include <string.h>

#define TIMEOUT     5
#define BUF_LEN     1024

int main()
{
    struct timeval tv;
    fd_set readfds;
    fd_set writefds;
    int ret;

    char buf[BUF_LEN+1];
    int len;

_RETRY:
    memset(buf, 0, sizeof(buf));

    FD_ZERO (&readfds); // clear
    FD_ZERO (&writefds); // clear

    FD_SET (STDIN_FILENO, &readfds);
    FD_SET (STDOUT_FILENO, &writefds);

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    ret = select(3, &readfds, &writefds, NULL, &tv);
    if (ret == -1) {
        printf("select(): error\n");
        return 1;
    } else if(!ret) {
        printf("%d seconds elapsed\n", TIMEOUT);
        return 0;
    }

    if (FD_ISSET(STDIN_FILENO, &readfds))
    {
        len = read(STDIN_FILENO, buf, BUF_LEN);
        if (len == -1) {
            printf("read(): error\n");
            return 1;
        }
        if (len) {
            buf[len] = '\0';
            printf("read(STDIN): %d: %s\n", len, buf);
        }
    }

    if (FD_ISSET(STDOUT_FILENO, &writefds))
    {
        len = write(STDOUT_FILENO, buf, BUF_LEN);
        if (len == -1) {
            printf("write(): error\n");
            return 1;
        }
        if (len) {
            buf[len] = '\0';
            printf("write(STDOUT): %d: %s\n", len, buf);
        }
    }

    sleep(5);
    goto _RETRY;

    fprintf(stderr, "This should not happen!\n");

    return 0;
}
