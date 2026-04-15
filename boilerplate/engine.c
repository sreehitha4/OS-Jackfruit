#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>

#define MAX_CONTAINERS 10
typedef struct {
    char id[20];
    pid_t pid;
    char state[20];
} container;
container containers[MAX_CONTAINERS];
int container_count=0;
void add_container(char *id,pid_t pid){
    strcpy(containers[container_count].id,id);
    containers[container_count].pid=pid;
    strcpy(containers[container_count].state,"running");
    container_count++;
}
void list_containers(){
    printf("ID\tPID\tSTATE\n");
    for(int i=0;i<container_count;i++){
       printf("%s\t%d\t%s\n",
              containers[i].id,
              containers[i].pid,
              containers[i].state);
    }
}
void show_logs(){
     FILE *f=fopen("logs.txt","r");
     if(!f){
       printf("No logs found\n");
       return;
     }
     char ch;
     while((ch=fgetc(f))!=EOF){
        putchar(ch);
     }
     fclose(f);
}
void stop_container(char *id){
    system("pkill sleep");
    printf("Container stopped (using pkill)\n");

     }
     
int run_container(char *id,char *rootfs,char *cmd){
   pid_t pid=fork();
   if(pid==0){
      printf("Inside container %s\n",id);
      if(chroot(rootfs)!=0){
         perror("chroot failed");
         exit(1);
      }
      chdir("/");
      execl("/bin/sh","/bin/sh",NULL);
      perror("exec failed");
      exit(1);
   }else{
       waitpid(pid,NULL,0);
   }
   return 0;
}
      
int start_container(char *id,char *rootfs,char *cmd){
    pid_t pid=fork();
    if(pid==0){
      if(chroot(rootfs)!=0){
        perror("chroot failed");
        exit(1);
      }
      chdir("/");
      execlp(cmd,cmd,NULL);
      perror("exec failed");
      exit(1);
     }else{
        add_container(id,pid);
        printf("Started container %s with PID%d\n",id,pid);
        printf("ID\tPID\tSTATE\n");
        printf("%s\t%d\trunning\n",id,pid);
     }

return 0;
}
int main(int argc,char *argv[]){
    if(argc<2){
       printf("Uasge:\n");
       printf("./engine run <id> <rootfs> <cmd>\n");
       printf("./engine start <id> <rootfs> <cmd>\n");
       printf("./engine stop <id>\n");
       printf("./engine ps\n");
       printf("./engine logs\n");
       return 1;
}
if(strcmp(argv[1],"run")==0){
   if(argc<5){
      printf("Usage: ./engine run <id> <rootfs> <cmd>\n");
      return 1;
    } 
    run_container(argv[2],argv[3],argv[4]);
}
else if(strcmp(argv[1],"start")==0){
    if(argc<5){
      printf("Usage: ./engine start <id> <rootfs> <cmd>\n");
      return 1;
    }
    start_container(argv[2],argv[3],argv[4]);
}
else if(strcmp(argv[1],"stop")==0){
    if(argc<3){
       printf("Usage: ./engine stop <id>\n");
       return 1;
    }
    stop_container(argv[2]);
}
else if(strcmp(argv[1],"ps")==0){
    list_containers();
}
else if(strcmp(argv[1],"logs")==0){
    show_logs();
}
else{
   printf("Unknown command\n");
}
return 0;
} 
