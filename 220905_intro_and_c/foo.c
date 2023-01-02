#include <stdio.h>
int main(int argc, char * args[]) {
   if(argc != 2){
       printf("Wrong number of arguments \n");
   }else{
       if(args[1][0] == 'A' || args[1][0] == 'a'){
           printf("No A's allowed \n");
       }else{
           printf("%s \n",args[1]);
       }
   }

   return 0;
}

