/*
 *功能:实现栈的基本操作
 *作者:xautjzd
 *时间:2013.2.27
 * */
#include <stdio.hn>
#include <stdlib.h>
#include <string.h>

typedef struct{
    void *elems;
    int elemSize;
    int logLength;
    int allocLength;
}stack;

void stackNew(stack *s,int elemSize);
void stackDispose(stack *s);
void stackPush(stack *s,void *elemAddr);
void stackPop(stack *s,void *elemAddr);

int main(){
    stack s;
    stackNew(&s,sizeof(int));
    int array[4]={1,2,3,4};
    int m,i;
    for(i=0;i<sizeof(array)/sizeof(array[0]);i++)
        stackPush(&s,&array[i]);
    while(s.logLength!=0){
        stackPop(&s,&m);
        printf("%d ",m);
    }
    printf("\n");
}

void stackNew(stack *s,int elemSize){
    s->logLength=0;
    s->allocLength=4;
    s->elemSize=elemSize;
    s->elems=malloc(4*elemSize);
}

void stackDispose(stack *s){
    free(s);
}

void stackPush(stack *s,void *elemAddr){
    if(s->logLength==s->allocLength){
        s->allocLength*=2;
        s->elems=realloc(s->elems,s->allocLength*s->elemSize);
    }

    void *pt=(char *)s->elems + s->logLength*s->elemSize;
    memcpy(pt,elemAddr,s->elemSize);
    s->logLength++;
}

void stackPop(stack *s,void *elemAddr){
    void *pt=(char *)s->elems+(s->logLength-1)*s->elemSize;
    memcpy(elemAddr,pt,s->elemSize);
    s->logLength--;
}
