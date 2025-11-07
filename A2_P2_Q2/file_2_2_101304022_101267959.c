#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

int main(){

    int count = 0;
    pid_t p;
    while(1){
        p = getpid();
        if(count%3==0){
            printf("ALT:ID: %d, Count: %i - is multiple of 3\n",p,count);
        }
        else{
            printf("ALT:ID: %d, Count: %i\n",p,count);
        }
        count--;
        sleep(4);
    }
    return 0;
}
