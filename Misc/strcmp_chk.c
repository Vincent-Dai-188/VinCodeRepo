#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int recv_size = 0, ret;
    char buffer[1024];                            /*数据的缓冲区*/
	
	for(;;) {                                     /*循环处理过程*/
		memset(buffer, 0, 1024);            
		/*从标准输入中读取数据放到缓冲区buffer中*/
        recv_size = read(0, buffer, 1024);
        if(recv_size > 0){                        /*读到数据*/
			printf("String inputed: %s (len = %d)\n", buffer, recv_size);
			ret = strncmp("", buffer, 1);
			if (ret == 0 ) {
				printf("'^X' captured! Abort!\n");
				break;
			}
			else
				printf("Result of strcmp() = %d!\n", ret);
        }
    }

	return 0;
}
