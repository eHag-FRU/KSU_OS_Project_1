/*
*   Consumer in the producer/consumer problem,
*   implemented with threading and shared buffer
*
*
*   Author: Elliott Hager
*   Date: 10/24/2023
*   
*
**/

#ifndef CONSUMER_HPP
#define CONSUMER_HPP
    #include <pthread.h>
    #include <unistd.h>
    #include <iostream>

    int main();

    void* consumer(void*);




#endif