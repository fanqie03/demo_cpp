#include <stdio.h>

#include <sys/time.h>

int main(){
    struct timeval time;

    /* 获取时间，理论到us */
    gettimeofday(&time, NULL);
    long tic = (time.tv_sec*1000 + time.tv_usec/1000);
 
    // sleep(3);  //延时
    long a = 0;
    long n = 1024*720*3*100;
    int data_length = 1024;
    long data[data_length];
    printf("loop count is %ld\n", n);
    for(long i = 0; i < n; i++){
        a += 1;
        data[(int)i%data_length] += a;
    }
 
    /* 重新获取 */
    gettimeofday(&time, NULL);
    long toc = (time.tv_sec*1000 + time.tv_usec/1000);
    printf("cpp cost: %ld ms\n", (toc - tic));
}