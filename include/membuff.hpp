//Define structure SharedData {
    //Array table[0..TABLE_SIZE-1]
    //Integer in = 0
    //Integer out = 0
    //Semaphore mutex = 1
    //Semaphore empty = TABLE_SIZE
    //Semaphore full = 0
//}

#ifndef MEMBUFF_HPP
#define  MEMBUFF_HPP
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <pthread.h>
    #include <sys/shm.h>
    #include <sys/ipc.h>
    #include <semaphore.h>

    #define TABLE_SIZE 2

    struct sharedMem {

        int table[TABLE_SIZE];

        int in;
        int out;

        sem_t mutex;
        sem_t empty;
        sem_t full;

    };


#endif