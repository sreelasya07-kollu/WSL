#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
    pid_t pid= fork();
    if (pid<0){
        printf("fork failed");
    }
   else if (pid ==0){
    printf("child process");
    printf("%d\n",getpid());
   }
   else {
      printf("parent process");
       printf("%d\n",getppid());
   }
    printf("\n");
    return 0;
}
