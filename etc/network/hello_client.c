#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *message);

int main(int argc, char *argv[])
{
        int sock;
        struct sockaddr_in serv_addr;
        char message[30];
        int str_len;

        if (argc != 3)
        {
               printf("Usage: %s <IP> <port>\n", argv[0]);
               exit(1);
        }

        sock = socket(PF_INET, SOCK_STREAM, 0); //소켓을 생성하고 있다.
        //소켓을 생성하는 순간에는 서버 소켓과 클라이언트 소켓으로 나뉘지 않는다.
        //bind listen함수의 호출이 이어지면 서버 소켓, connect 함수의 호출로 이어지면 클라이언트 소켓
        if (sock == -1)
               error_handling("socket() error");

        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
        serv_addr.sin_port = htons(atoi(argv[2]));

        if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) //connect 함수호출을 통해서 서버 프로그램에 연결 요청
               error_handling("connect() error");

        str_len = read(sock, message, sizeof(message) - 1);
        if (str_len == -1)
               error_handling("read() error");

        printf("Message from server:%s\n", message);
        close(socket);
        return 0;
}

void error_handling(char *message)
{
        fputs(message, stderr);
        fputc('\n', stderr);
        exit(1);
}

