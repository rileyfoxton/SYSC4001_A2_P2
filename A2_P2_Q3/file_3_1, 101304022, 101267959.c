#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>

int main(){

    pid_t p = fork();
    if(p==0){
        char *args[] = {"./part232", NULL};
        execvp("./part232", args);
    }
    wait(NULL);
    return 0;
}