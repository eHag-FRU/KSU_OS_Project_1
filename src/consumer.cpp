#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include "../include/membuff.hpp"


//pseudocode for consumer

// Main function of Consumer {
//     Initialize shared memory segment with key "shmfile" and attach to SharedData

//     For i from 0 to 19 {
//         Wait on semaphore full
//         Wait on semaphore mutex

//         Remove item from table at index "out"
//         Print "Consumed: " + item
//         Increment out modulo TABLE_SIZE

//         Signal semaphore mutex
//         Signal semaphore empty

//         Sleep for a random time // simulate variable time for consuming
//     }

//     Detach shared memory
// }


void* consumer(void* arg) {
    //Make the struct
    struct sharedMem* conMem;

    //Open the "file" that will be for shared memory
    int fd = shm_open("shmfile", O_CREAT | O_EXCL | O_RDWR, 0600);

    //Now we need to map to THIS program's LOCAL address space
    conMem = static_cast<sharedMem*>(mmap(NULL, sizeof(*conMem), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0));
    

     for (int i = 0; i <= 19; ++i) {
        sem_wait(&(conMem->full));
        sem_wait(&(conMem->mutex));

    //     int con_item;

    //     conMem->out += conMem->out % TABLE_SIZE;


    //     sem_post(&(conMem->mutex));
    //     sem_post(&(conMem->empty));

    //     sleep(rand());
    }


    //Detatch mem
    shm_unlink("shmfile");


    return NULL;

}





int main() {
    pthread_t consumerThread; //Makes consumer thread

    pthread_create(&consumerThread, NULL, consumer, NULL);  //Assigns the consumer function to the thread


    pthread_join(consumerThread, NULL); //Joins the thread

    return 0;

}