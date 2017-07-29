#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT 8888                                /*侦听端口地址*/

extern void process_conn_client(int s);

int main(int argc, char *argv[])
{
    int s;                                       /*s为socket描述符*/
    struct sockaddr_in server_addr;              /*服务器地址结构*/
    char server_ip_str[INET_ADDRSTRLEN];
    
    s = socket(AF_INET, SOCK_STREAM, 0);         /*建立一个流式套接字 */
    if(s < 0) {                                  /*出错*/
        printf("socket error\n");
        return -1;
    }    

    /*设置服务器地址*/
    bzero(&server_addr, sizeof(server_addr));           /*清零*/
    server_addr.sin_family = AF_INET;                   /*协议族*/
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);    /*本地地址*/
    server_addr.sin_port = htons(PORT);                 /*服务器端口*/
    
    /*将用户输入的字符串类型的IP地址转为整型*/
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    /*连接服务器*/
    connect(s, (struct sockaddr*)&server_addr, sizeof(struct sockaddr));
    //Convert IPv4 and IPv6 addresses from binary to text form
    if (!inet_ntop(AF_INET, &(server_addr.sin_addr), server_ip_str, sizeof(server_ip_str))) {
        perror("inet_ntop failed");
        exit(EXIT_FAILURE);
    }
    printf("*** Connected to server '%s:%d' ***\n", server_ip_str, PORT);
    process_conn_client(s);                      /*客户端处理过程*/
    close(s);                                    /*关闭连接*/
    return 0;
}
