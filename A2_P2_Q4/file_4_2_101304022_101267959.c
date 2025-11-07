#include <stdio.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/sem.h>

int main(int argc, char** argv){
        int *count = shmat(atoi(argv[0]), NULL, 0);
        int *mult = shmat(atoi(argv[1]), NULL, 0);
        pid_t p = getpid();
        while(*count <= 500){
                if(*count%*mult == 0){
                        printf("ALT  :ID: %d, Count: %i - is multiple of %i\n",p,*count,*mult);
                }
                else{
                        printf("ALT  :ID: %d, Count: %i\n",p,*count);
                }
                *count += 1;
        }
        return 0;
}
