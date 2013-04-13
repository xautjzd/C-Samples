#include <stdio.h>
void swap(int *x,int *y);
int main(){
    int x=7,y=10;
    swap(&x,&y);
    printf("%d %d\n",x,y);
}

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
