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
        int semID = atoi(argv[2]);
        struct sembuf buf[1];
        buf[0].sem_num = 0;
        pid_t p = getpid();
        while(*count <= 500){
                if(*count%*mult == 0){
                        printf("ALT  :ID: %d, Count: %i - is multiple of %i\n",p,*>
                }
                else{
                        printf("ALT  :ID: %d, Count: %i\n",p,*count);
                }
                semop(semID, buf, 1);
                buf[0].sem_num = 1;
                semop(semID, buf, 1);
                printf("entering exclusive to alt\n");
                *count += 1;
                printf("exiting exclusive to alt\n");
                buf[0].sem_num = -1;
                semop(semID, buf, 1);
                buf[0].sem_num = 0;
                if(*count >500) break;
        }
        semctl(semID, 0, IPC_RMID);
        return 0;
}
