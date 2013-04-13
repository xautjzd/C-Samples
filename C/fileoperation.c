#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define NUMBER 20
int main(){
    FILE   *fp;
    char buf[NUMBER+1],ch;
    fp=fopen("sockserv.c","r");
    if(fp==NULL)
        perror(strerror(errno));
    else{
        fseek(fp,3,SEEK_SET);
        fgets(buf,NUMBER,fp);
        printf("%s\n",buf);
        
        long pos=ftell(fp);
        printf("%ld\n",pos);
        
        fseek(fp,23,SEEK_SET);
        printf("%c\n",fgetc(fp));

        rewind(fp);
        printf("%ld\n",ftell(fp));
        fclose(fp);
    }
    exit(0);
}
