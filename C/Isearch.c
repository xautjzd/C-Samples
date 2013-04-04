#include<stdio.h>

int main(){
    int array[]={4,2,3,7,11,6};
    int number=7;
    int size=6;
    int *found=Isearch(&number,array,
                              6,sizeof(int),
                              intCmp);
    if(found==Null)
        printf("Not found!");
    else
        printf("%d\n",number);
}

void * Isearch(void *key,void *base,
               int n,int elemSize,
               int (*cmpfn)(void *,void *))
{
    for(int i=0;i<n;i++){
        void *elemAddr=(char *)base+i*elemSize;
        if(cmpfn(key,elemAddr)==0)
            return elemAddr;
    }    
    return Null;
}
