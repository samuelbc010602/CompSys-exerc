#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <assert.h>
#include <pthread.h>
#include <errno.h>

// TODO: add fields here.
struct worker_payload {
    unsigned char * dataToRead;
    int start;
    int end;
    long * sumToPass;
    pthread_mutex_t *pauser;
    
};

void* thread(void* p) {
  struct worker_payload payload = *(struct worker_payload*)p;

  long local_sum = 0;
  for(int i = payload.start;i<payload.end;i++){
      local_sum +=payload.dataToRead[i];
      //payload.sumToPass+=payload.dataToRead[i];
  }

  pthread_mutex_lock(payload.pauser);
  printf("open");
  *payload.sumToPass += local_sum;
  pthread_mutex_unlock(payload.pauser);

  
  
  return NULL;
}

int main(int argc, char** argv) {
  assert(argc == 2);
  char *filename = argv[1];

  // Open the given file and determine its size.
  FILE *file = fopen(filename, "r");
  assert(file != NULL);
  fseek(file, 0, SEEK_END);
  size_t size = ftell(file);
  fseek(file, 0, SEEK_SET);

  // mmap file as an array of 'size' bytes.
  unsigned char *data = mmap(NULL,
                             size,
                             PROT_READ,
                             MAP_PRIVATE,
                             fileno(file), 0);
  assert(data != MAP_FAILED);
  fclose(file);
  pthread_mutex_t initMut = PTHREAD_MUTEX_INITIALIZER;

  
  long sum = 0;
  pthread_t id1,id2;

  // TODO: Create a mutex protecting 'sum'.

  // TODO: Launch two threads which receive as payload:
  //  * 'data'.
  //  * Start and end offsets in 'data' indicating which part of the
  //    array each thread should traverse.
  //  * a pointer to 'sum' it can update.
  //  * a pointer to a mutex protecting 'sum'.

  // TODO: join the two threads.

  struct worker_payload ex1;
  ex1.dataToRead = data;
  ex1.start = 0;
  ex1.end = size/2;
  ex1.sumToPass = &sum;
  ex1.pauser = &initMut;
  pthread_create(&id1,NULL,thread,&ex1);
 
  struct worker_payload ex2;
  ex2.dataToRead = data;
  ex2.start = size/2;
  ex2.end = size;
  ex2.sumToPass = &sum;
  ex1.pauser = &initMut;
  pthread_create(&id2,NULL,thread,&ex1);
  


  pthread_join(id1,NULL);
  pthread_join(id2,NULL);
  printf("Sum: %ld\n", sum);
}
