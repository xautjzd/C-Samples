#include <stdio.h>
#include <time.h>
#include <string.h>

#define BUF_SIZE 256

int main(){
    time_t current_time;
    struct tm *tm_ptr,timestruct;
    char buf[BUF_SIZE];

    time(&current_time); //get current time
    tm_ptr=localtime(&current_time);
    strftime(buf,BUF_SIZE,"%A %d %B %Y,%I:%M:%S %p",tm_ptr);
    printf("Current time is: %s\n",buf);

    strcpy(buf,"Mon 01 April 2013,17:27 will be done!");
    strptime(buf,"%a %d %b %Y,%R",tm_ptr);
    printf("date:%d/%d/%d\n",tm_ptr->tm_year%100,tm_ptr->tm_mon+1,tm_ptr->tm_mday);
    printf("time:%d:%d\n",tm_ptr->tm_hour,tm_ptr->tm_min);
}
