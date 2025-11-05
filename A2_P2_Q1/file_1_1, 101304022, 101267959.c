#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

int main(){
    pid_t p = fork();
    int count = 0;
        while(1){
                printf("ID: %d, Count: %i\n",p,count);
                count++;
                sleep(3);
        }
    return 0;
}