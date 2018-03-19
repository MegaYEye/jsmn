#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	char uart_sendbuf[1000];
	char * str=0;
	int num;
        sprintf(uart_sendbuf,
                        "POST /%s HTTP/1.1\r\n"
                        "Host: 192.168.1.100:2000\r\n"
                        "Content-Type: application/json\r\n"
                        "seq1: %d\r\n"
                        "chksum: %d\r\n"
                        "Content-Length: %d\r\n" 
                        "Cache-Control: no-cache\r\n\r\n"
                        "%s\r\n\r\n"
                        , "msg_type", 22,111, strlen("json_str"), "json_str");	
        //printf("%s\n", uart_sendbuf);
        str=strstr(uart_sendbuf,"chksum:");
        sscanf(str,"chksum:%d",&num);
        printf("%d\n",num);
        printf("%d",strlen(uart_sendbuf));
	return 0;
}