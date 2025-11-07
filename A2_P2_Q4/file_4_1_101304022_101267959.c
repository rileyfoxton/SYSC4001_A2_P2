#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/sem.h>
#include <stdio.h>

int main(){
        int countKey = shmget(IPC_PRIVATE,10, IPC_CREAT | 0666 );
        if(countKey < 0){
                perror("GET FAIL");
                exit(1);
        }
        int *count = shmat(countKey, NULL, 0);
        if(*count == -1){
                perror("MAT FAIL");
                exit(0);
        }
        *count = 0;
        int multipleKey = shmget(IPC_PRIVATE, 1024, (IPC_CREAT | 0666) );
        if(multipleKey < 0){
                perror("GET FAIL");
                exit(1);
        }
        int *mult = shmat(multipleKey, NULL, 0);
        if(*mult == -1){
                perror("MAT FAIL");
                exit(0);
        }
        *mult = 3;
        bool forked = true;
        pid_t p = -1;
        int extraCounter = 0;
        while(*count <= 500){
                if(forked &&*count > 100){
                        forked = false;
                        p = fork();
                }
                if(p==0){
                        char arg1[30];
                        char arg2[30];
                        char arg3[30];
                        sprintf(arg1,"%d",countKey);
                        sprintf(arg2,"%d",multipleKey);
                        int execTest = execlp("./shared2", arg1,arg2, NULL);
                        if (execTest == -1) printf("exec failed\n");
                }
                if(*count%*mult == 0){
                        printf("MAIN :ID: %d, Count: %i - is multiple of %i\n",getpid(),*count,*mult);
                }
                else{
                        printf("MAIN :ID: %d, Count: %i\n",getpid(),*count);
                }
                *count += 1;
        }
        return 0;
}
