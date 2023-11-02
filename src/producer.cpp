#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/mman.h>
#include <fcntl.h>
#include "../include/membuff.hpp"




//pseudocode for producer

// Main function of Producer {
//     Initialize shared memory segment with key "shmfile" and attach to SharedData
//     Initialize semaphore mutex to 1
//     Initialize semaphore empty to TABLE_SIZE
//     Initialize semaphore full to 0
//     Initialize in and out to 0

//     For i from 0 to 19 {
//         Wait on semaphore empty
//         Wait on semaphore mutex

//         Produce an item with value i
//         Place item in table at index "in"
//         Print "Produced: " + i
//         Increment in modulo TABLE_SIZE

//         Signal semaphore mutex
//         Signal semaphore full

//         Sleep for a random time // simulate variable time for producing
//     }

//     Detach shared memory
// }

int main(int argc, char *argv[]) {

    //Vars
    int fd;
    char * shmpath;
    struct sharedMem *prodMem;


    //Grab the shared mem path from command
    shmpath = argv[1];


    //open mem
    fd = shm_open(shmpath, O_CREAT | O_EXCL | O_RDWR, 0600);


    //Truncate it to the size of the struct, ensures extra is not used
    ftruncate(fd, sizeof(*prodMem));

    prodMem = static_cast<sharedMem*>(mmap(NULL, sizeof(*prodMem), PROT_READ | PROT_WRITE,MAP_SHARED, fd, 0));


    //Init the structs
    sem_init(&(prodMem->mutex), 1,1);
    
    sem_init(&(prodMem->full), 1,0);
    
    sem_init(&(prodMem->empty), 1, TABLE_SIZE);

    prodMem->in, prodMem->out = 0;

    for(int i = 4; i >= 0; --i) {
        //Check if buffer is empty and if the mutex is NOT in use
        //If either one is NOT ready, then wait
        sem_wait(&prodMem->empty);
        sem_wait(&prodMem->mutex);

        int prod_val = rand();

        std::cout << "Produced: " << prod_val << std::endl;

        prodMem->table[prodMem->in] = prod_val;


        std::cout << "In value BEFORE: " << prodMem->in << std::endl;

        //Need to mod to ensure only 0 to TABLE_SIZE are used again and again
        prodMem->in += prodMem->in % TABLE_SIZE;

        std::cout << "In value AFTER: " << prodMem->in << std::endl;


        //Release the mutex and mark the buffer as full
        sem_post(&prodMem->mutex);
        sem_post(&prodMem->full);

        sleep(rand()%10);
    }

    shm_unlink(shmpath);


    return 0;
}



