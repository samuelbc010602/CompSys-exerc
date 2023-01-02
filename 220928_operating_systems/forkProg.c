#include <stdio.h>
#include <sys/types.h>
int main(){
    int x = 100;
    pid_t rc = fork();
    printf("pid = %d \n",rc);

    if(rc != 0){
        x +=2;
        printf("child = %d \n",x);
    }else{
        x +=3;
        printf("parent = %d \n",x);
    }
}

/* når fork bliver kaldt kører den først programmet som var det barnet, 
derefter går den tilbage igen til samme sted og kører programmet som forælder. 
*/