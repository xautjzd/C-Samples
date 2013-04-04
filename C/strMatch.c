/*
 *字符串准确匹配
 *时间:2013.2.26
 *作者:xautjzd
 * */

#include <stdio.h>
#include <string.h>

/*
 *src:源字符串指针 str：所要匹配的字符串指针
 * */
int strMatch(const char *src,const char *str);

int main(){
    int pos=strMatch("abbcabcabbbc","abc");
    printf("%d\n",pos);
}

int strMatch(const char *src,const char *str){
    int src_len=strlen(src);
    int str_len=strlen(str);
    if(src_len<str_len)
        return -1;
    int i,j;
    for(i=0;src[i]!='\0';i++){
        for(j=0;str[j]!='\0";j++){
            if(src[i+j]!=str[j])
                break;
        }
        if(str[j]==0)
            return i;
    }
