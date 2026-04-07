#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
int main(int argc,char *argv[]){
    if(argc<2){
       printf("Usage: ./engine run <id> <rootfs> <cmd>\n");
       return 1;
     }
     if(strcmp(argv[1],"run")==0){
        printf("Running container %s...\n",argv[2]);
        pid_t pid=fork();
        if(pid==0){
           printf("Inside container\n");
           chroot(argv[3]);
           chdir("/");
           execlp("/bin/sh","/bin/sh",NULL);
        }else{
           wait(NULL);
        }
      }
      return 0;
}
