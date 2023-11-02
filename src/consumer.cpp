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


int main(int argc, char *argv[]) {
    //Vars
    int fd;
    char * shmpath;
    struct sharedMem *consMem;



    //Grab the shared mem path from command
    shmpath = argv[1];


    //open mem
    fd = shm_open(shmpath, O_RDWR, 0);



    //Truncate it to the size of the struct, ensures extra is not used
    ftruncate(fd, sizeof(*consMem));

    consMem = static_cast<sharedMem*>(mmap(NULL, sizeof(*consMem), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0));

    for (int i = 4; i >= 0; --i) {
        sem_wait(&(consMem->full));
        sem_wait(&(consMem->mutex));


        int con_item;
        con_item = consMem->table[consMem->out];
        std::cout << "Consumed: " <<  con_item << std::endl;
        

        std::cout << "Out value BEFORE: " << consMem->out << std::endl;

        consMem->out += consMem->out % TABLE_SIZE;

        std::cout << "Out value AFTER: " << consMem->out << std::endl;


        sem_post(&(consMem->mutex));
        sem_post(&(consMem->empty));

        sleep(rand()%10);
    }


    //Detatch mem
    shm_unlink(shmpath);


    return 0;

}