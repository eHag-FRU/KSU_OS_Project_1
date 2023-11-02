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


void* producer(void* arg) {
    //Make the struct
    struct sharedMem* prodMem;

    std::cout << "Made struct" << std::endl;

    //Open the "file" that will be for shared memory
    int fd = shm_open("shmfile", O_CREAT | O_EXCL | O_RDWR, 0600);

    ftruncate(fd, sizeof(struct sharedMem));


    std::cout << "SHM_OPEN" << std::endl;

    //Now we need to map to THIS program's LOCAL address space
    prodMem = static_cast<sharedMem*>(mmap(NULL, sizeof(*prodMem), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0));



    std::cout << "MAPPED WITH MMAP" << std::endl;

    //Mutex is set to 1 as it is ready to use
    sem_init(&prodMem->mutex, 1, 1);

    std::cout << "Init mutex" << std::endl;


    //Set full
    sem_init(&prodMem->full, 1, 0);

    std::cout << "Init full" << std::endl;

    //Set empty
    sem_init(&prodMem->empty, 1, TABLE_SIZE);
    std::cout << "Init empty" << std::endl;

    //prodMem->in = 0;
    //prodMem->out = 0;
    //std::cout << "Init in and out" << std::endl;

   //std::cout << "In: " << (prodMem->in) << std::endl;


    for (int i = 0; i <= 19; ++i) {

        //Check if buffer is empty and if the mutex is NOT in use
        //If either one is NOT ready, then wait
        sem_wait(&prodMem->empty);
        sem_wait(&prodMem->mutex);

        int prod_val = rand();

        std::cout << prod_val << std::endl;

        // prodMem->table[prodMem->in] = prod_val;


        // //Need to mod to ensure only 0 to TABLE_SIZE are used again and again
        // prodMem->in += prodMem->in % TABLE_SIZE;

        // puts("Produced: " + prod_val);

        // //Release the mutex and mark the buffer as full
        // sem_post(&prodMem->mutex);
        // sem_post(&prodMem->full);

        // sleep(rand());
    }
    
    //Unlink the memory
    shm_unlink("shmfile");

    return NULL;
}


int main() {

    //Creation of the thread to make the program run on threads
    pthread_t prod_thread;

    pthread_create(&prod_thread, NULL, producer, NULL);


    pthread_join(prod_thread,NULL);
    

    return 0;
}



