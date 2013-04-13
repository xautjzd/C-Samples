#include <stdio.h>

void printArray(int []);

int main()
{
    int array[10]={1,2,,0,5,7};
    printArray(array);
}

void printArray(int array[]){
    int i=0;
    while(array[i]!='\0'){
        printf("%d",array[i]);
        i++;
    }
    printf("\n");
}
