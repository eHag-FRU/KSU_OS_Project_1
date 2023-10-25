/*
*   Producer in the producer/consumer problem,
*   implemented with threading and shared buffer
*
*
*   Author: Elliott Hager
*   Date: 10/24/2023
*   
*
**/

#ifndef PRODUCER_HPP
#define PRODUCER_HPP

    #include <pthread.h>
    #include <iostream>
    #include <unistd.h>


    int main();


    void* producer(void*);

#endif