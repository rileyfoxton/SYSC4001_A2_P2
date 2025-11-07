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
        char *args[] = {"./file_3_2_101304022_101267959.c", NULL};
        execvp("./part232", args);
    }
    wait(NULL);
    return 0;
}
