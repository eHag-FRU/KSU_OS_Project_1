/*!
*   \details Consumer in the producer/consumer problem, implemented with threading and shared buffer 
*
*   \file consumer.hpp
*   \author  Elliott Hager
*   \date 10/24/2023
*   
*
*/

#ifndef CONSUMER_HPP
#define CONSUMER_HPP
    #include <pthread.h>
    #include <unistd.h>
    #include <iostream>
    #include <semaphore.h>

    int main();

    void* consumer(void*);




#endif