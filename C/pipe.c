#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE 100
#define PIPE_STDIN 1
#define PIPE_STDOUT 0

int main()
{
    const char *string="Hello,world!";
    int ret,pipefd[2];        /*pipefd[1]:writing for pipe    
                                pipefd[0]:reading for pipe*/
    char buffer[MAX_LINE+1];

    /*Create a anonymous pipe*/
    ret=pipe(pipefd);   //0 on success    -1 on error

    if(ret == 0)
    {
        /*write the string into the pipe*/
        write(pipefd[PIPE_STDIN],string,strlen(string));
        
        /*read the string from the pipe*/
        ret=read(pipefd[PIPE_STDOUT],buffer,MAX_LINE);
       
        /*Null terminate the string*/
        buffer[ret]=0;

        printf("%s\n",buffer);
    }
    return 0;
}
