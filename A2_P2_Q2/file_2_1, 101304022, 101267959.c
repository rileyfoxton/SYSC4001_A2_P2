#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

int main(){

    pid_t p = fork();
    if(p==0){
        char *args[] = {"./part222", NULL};
        execvp("./part222", args);
    }

    int count = 0;
    while(1){
        p=getpid();
        if(count%3==0){
                printf("MIAN:ID: %d, Count: %i - is multiple of 3\n",p,count);
        }
        else{
                printf("MAIN:ID: %d, Count: %i\n",p,count);
        }
        count++;
        sleep(4);
    }
    return 0;
}