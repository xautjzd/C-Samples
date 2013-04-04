#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc,char **argv){
    int row; //将要输入的行
    int rowmax;//每行输入整数个数
    scanf("%d",&row);
    int *pt[row];
    int result[row];
    memset(result,0,sizeof(int) * row);
    int i=row;
    for(;row>0;row--){
        scanf("%d",&rowmax);
        pt[row-1]=(int *)malloc(rowmax * sizeof(int));
        if(pt[row-1]==NULL){
            perror(strerror(errno));
        }
        else{
            for(;rowmax>0;rowmax--){
                scanf("%d",pt[row-1]);
                result[row-1]+=*pt[row-1];
                pt[row-1]++;
            }
        }
    }       
    for(;i>0;i--)
        printf("%d\n\n",result[i-1]);
}
