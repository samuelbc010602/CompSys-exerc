#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>


int main(){
    pid_t rc = fork();
    int f;
    if(rc == 0){
        printf("hello \n");
        f = open("tekst.txt",O_RDWR);
        char * barn = "1";
        size_t bytes_written = write(f,barn,strlen(barn));
        close(f);
        
    }
    int stop = 1;
    while(1 == stop){
    if(rc > 0){
        FILE * fp = fopen("tekst.txt","r");
        char c = fgetc(fp);
        if(c == '1'){
            printf("goodbye \n");
            stop = 0;
        }
    }
    }


}