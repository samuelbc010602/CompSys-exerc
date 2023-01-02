#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int f = open("tekst.txt",O_RDWR);
    printf("f = %d \n",f);

    unsigned char b;
    int e; 

    /*while(1){
        e = fread(&b,1,1,f);
        if(e == 0){
            break;
        }
        e = fwrite(&b,1,1,stdout);
    }
    */

    int rc = fork();
    printf("rc = %d \n",rc);
    if (rc == 0){
        printf("printer barn \n");
        char * barn = "babaufghjsbns \n";
        size_t bytes_written = write(f,barn,strlen(barn));
    }else if(rc > 0){
        printf("printer forælder \n");
        char * parent = "rigtigt tekst \n";
        size_t bytes_written = write(f,parent,strlen(parent));
    }

    printf("\n");
}


/*
ligesom det forige program så splittes programmet i to ved linje 25, ved fork(). Først kører forælderen, så 
går den tilbage til linje 25 og køre programmet som var det barnet
*/