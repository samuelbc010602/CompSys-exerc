#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * args[]){
    if(argc != 1){
        int number;
        if(sscanf(args[1], "%d",&number) == 1){
            int randomNumber = rand()%10;
            if (number == randomNumber){
                printf("Correct guess\n");
            }else if(number < randomNumber){
                printf("Too low\n");
            }else{
                printf("Too high\n");
            }
        }else{
            printf("Input must be a number\n");
        }
    }else{
        printf("Must give number as input\n");
    }
}

