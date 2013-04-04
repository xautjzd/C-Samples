#include <arpa/inet.h>
#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <time.h>

#define SERV_PORT 1207
#define LISTENQ 100    //设置套接口排队最大连接个数
int main(){
    int listenfd,connfd;   //监听套接口描述字及连接套接口描述字
    char buffer[INET_ADDRSTRLEN];
    struct sockaddr_in servaddr,cliaddr;//服务器套接口及客户端套接口地址
    time_t timer;  //显示现在时间

    memset(&servaddr,0,sizeof(servaddr));   //初始化服务器套接口地址
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(SERV_PORT);
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

    listenfd=socket(AF_INET,SOCK_STREAM,0); //创建套接口
    if(listenfd<0)
        perror(strerror(errno));
   
    if(-1==bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr)))
        perror(strerror(errno));
   
    if(-1==listen(listenfd,LISTENQ))
        perror(strerror(errno));
   
    while(1){
        connfd=accept(listenfd,(struct sockaddr *)&cliaddr,  &sizeof(cliaddr));
        if(-1==connfd)
            perror(strerror(errno));
        printf("客户端%s:%d已连接\n",inet_ntop(AF_INET,&cliaddr.sin_addr,buffer,sizeof(buffer)),ntohs(cliaddr.sin_port));

        timer=time(NULL);  //获取系统当前时间,也可time(&time);
        printf("现在时间是:%s\n",ctime(&time)); //转换time_t格式为string
        if(-1==close(connfd)){
            perror(strerror(errno));
        }
    }
}

