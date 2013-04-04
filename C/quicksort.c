/*
*作者:xautjzd
*时间:2013-3-5
*功能:快速排序
**/
#include <stdio.h>
void quickSort(int a[],int left,int right);
void swap(int *x,int *y);
int main(){
    int array[]={10,9,8,7,6,5,4,3,2,1};
    quickSort(array,0,9);
    int i=0;
    for(i=0;i<10;i++)
        printf("%d ",array[i]);
    printf("\n");
    return 0;
}

void quickSort(int a[],int left,int right){
    int i=left,j=right;
    int pivot=a[left];      //设最左的待排数组为基数
    for(;;){
        while(i<j&&a[j]>=pivot)    //j从右到左找比基数小的数
            j--;
        while(i<j&&a[i]<=pivot)    //i从左到右找比基数大的数
            i++;
        if(i<j)                    //i<j,交换找出符合条件的两数
            swap(&a[i],&a[j]);
        else                       //否则第一次循环结束，i左侧的数比基数都小，i右侧的数比基数都大
            break;
    }
    swap(&a[i],&a[left]);
    if(left<right)            //判断数组长度是否大于1，至少有两数才需继续递归
        quickSort(a,left,i-1);
    if(left<right)
        quickSort(a,i+1,right);
}

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
