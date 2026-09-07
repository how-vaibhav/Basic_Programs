#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

#define MAX_SIZE 100
#define BUFF_SIZE 100

int main(void){
    pid_t pid;
    int i;
    char buff[BUFF_SIZE];

    fork();
    pid=getpid();

    for( i=0 ; i<MAX_SIZE ; i++ ){
            sprintf(buff , "This process : %d with value : %d \n",pid ,i);
            write(1,buff , strlen(buff));
    }
    return 0;
}