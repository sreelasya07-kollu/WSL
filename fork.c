

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
    fork();
    printf("%d\n",getppid());
    printf("%d\n",getpid());
    return 0;
}
