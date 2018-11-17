#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
int main(){
    printf("I'm about to fork everything up\n");
    int cpids[2];
    srand(time(NULL));
    int rands[2]={rand(),rand()};
    for(int n = 0;n<2;n++){
        if(!(cpids[n]=fork())){
            printf("Hi I'm a little baby process! My pid is %d, good night.\n",getpid());
            int sleepytime = (rands[n]%16)+5;
            sleep(sleepytime);
            printf("%d is about to wake up!\n",getpid());
            return sleepytime;
        }
    }
    int statu;
    int pidwait = wait(&statu);
    int retval = WEXITSTATUS(statu);
    printf("My child %d slept for only %d seconds!\n",pidwait,retval);
    printf("Now they're crying again, I'm going to kill() the other one just because.\n");
    kill((cpids[0]==pidwait?cpids[1]:cpids[0]),15);
    return 0;
}
