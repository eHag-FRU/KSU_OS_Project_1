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




#include "consumer.hpp"

int main() {
//Make the thread object
    pthread_t consumerThread;

    //Construct the thread to be over the producer functionality
    pthread_create(&consumerThread, NULL, consumer, NULL);


    //Once done, joins the thread back to main to finish the process
    pthread_join(consumerThread, NULL);

    return 0;
}



void* consumer(void* arg) {
    while(true) {
        sleep(1);
        std::cout << "Some Function!" << std::endl;
        
    }
    return NULL;
}