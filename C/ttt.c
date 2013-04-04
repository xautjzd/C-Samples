#include <stdio.h>

int main(){
    unsigned int a=10,b=11;
    printf("%u-%u= %u\n",a,b,a-b);
    if(a-b>=0)
        printf("hello\n");
    return 0;
}
