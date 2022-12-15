#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <assert.h>
#include <pthread.h>
#include <errno.h>

long finalSum = 0;

struct dataHolder{
    unsigned char * dataToRead;
    pthread_mutex_t* sum_mutex;
    int start;
    int end;
};

void * readBytes(void * data){
    struct dataHolder dataToPass = *((struct dataHolder*)data);
    long local_sum = 0;
    for(int i = dataToPass.start-1;i<dataToPass.end;i++){
	local_sum =local_sum+dataToPass.dataToRead[i];
    }
    pthread_mutex_lock(dataToPass.sum_mutex);
    dataToPass.sumToPrint += local_sum;
    pthread_mutex_unlock(dataToPass.sum_mutex);
    
    //finalSum += local_sum;
}
    


int main(int argc, char** argv) {
  //assert(argc == 2);
  char *filename = argv[1];

  // Open the given file and determine its size.x
  FILE* file = fopen(filename, "r");
  assert(file != NULL);
  fseek(file, 0, SEEK_END);
  size_t size = ftell(file);
  fseek(file, 0, SEEK_SET);

  // mmap file as an array of 'size' bytes.
  unsigned char * data = mmap(NULL,
              size,
              PROT_READ,
              MAP_PRIVATE,
              fileno(file), 0);
  
  assert(data != MAP_FAILED);
  fclose(file);

  pthread_mutex_t sum_mutex = PTHREAD_MUTEX_INITIALIZER;
    
  pthread_t id1,id2;
  pthread_t idHolder[] = {id1,id2};

  struct dataHolder ex1;
  ex1.start = 0;
  ex1.end = size/2;
  ex1.dataToRead = data;
  ex1.sum_mutex = &sum_mutex;
  pthread_create(&idHolder[0], NULL, readBytes,&ex1);

  struct dataHolder ex2;
  ex2.start = 0;
  ex2.end = size/2;
  ex2.dataToRead = data;
  ex2.sum_mutex = &sum_mutex;
  pthread_create(&idHolder[1], NULL, readBytes,&ex2);

  
  for(int i = 0;i<2;i++){
      pthread_join(idHolder[i],NULL);
  }

  printf("final sum = %ld",finalSum);
}












