#include<stdio.h>
#include<string.h>
int main(){
    char buffer1[]="DWDa0tP12df0aa";
    char buffer2[]="DWGA0TP12DF0";
    
    int n=memcmp(buffer1,buffer2,3);

    if(n>0)
        printf("%s is greater than %s.\n",buffer1,buffer2);
    else if(n<0)
        printf("%s is less than %s.\n",buffer1,buffer2);
    else 
        printf("%s is the same as %s.\n",buffer1,buffer2);
    return 0;
}
