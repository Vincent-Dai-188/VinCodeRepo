#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*客户端的处理过程*/
void process_conn_client(int s)
{
    ssize_t size = 0;
    char buffer[1024];                            /*数据的缓冲区*/
    
    for(;;) {                                     /*循环处理过程*/
        /*从标准输入中读取数据放到缓冲区buffer中*/
        size = read(0, buffer, 1024);
        if(size > 0){                             /*读到数据*/
            write(s, buffer, size);               /*发送给服务器*/
            size = read(s, buffer, 1024);         /*从服务器读取数据*/
            write(1, buffer, size);               /*写到标准输出*/
        }
    }
}

/*服务器对客户端的处理*/
void process_conn_server(int s)
{
    ssize_t size = 0;
    char buffer[1024];                            /*数据的缓冲区*/
    char out_buffer[1024];						  /*show buffer*/

    for(;;) {                                     /*循环处理过程*/        
        size = read(s, buffer, 1024);             /*从套接字中读取数据放到缓冲区buffer中*/
        if(size == 0) {                           /*没有数据*/
		    /*从标准输入中读取数据放到缓冲区out_buffer中*/
		    size = read(0, out_buffer, 1024);
		    if(size > 0){                             /*读到数据*/
		        write(s, out_buffer, size);           /*发送给客户端*/
		    }
            return;    
        }
        
		sprintf(out_buffer, "[From client_%d]: %s\n", s, buffer);
        //write(1, buffer, size);                 /*写到标准输出*/
        write(1, out_buffer, strlen(out_buffer) + 1);          /*写到标准输出*/

        sprintf(buffer, "[From Server]: Received %ld bytes.\n", size);
        write(s, buffer, strlen(buffer)+1);       /*发给客户端*/
    }    
}
