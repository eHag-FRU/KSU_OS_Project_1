/*!
*   \details  Producer in the producer/consumer problem, implemented with threading and shared buffer
*
*   \file producer.cpp
*   \author Elliott Hager
*   \date 10/24/2023
*   
*
**/


#include "../include/producer.hpp"


/**
 * @brief Function to drive producer thread
 * 
 * @return int 
 */
int main() {

    //Make the thread object
    pthread_t producerThread;

    //Construct the thread to be over the producer functionality
    pthread_create(&producerThread, NULL, producer, NULL);


    //Once done, joins the thread back to main to finish the process
    pthread_join(producerThread, NULL);

    return 0;
}




/**
 * @brief Function for thread to run as a producer into the shared memory buffer with semaphores
 * 
 * @param arg 
 * @return void* 
 */
void* producer(void* arg) {
   while(true) {
    std::cout << "In the producer" << std::endl;
    sleep(2);
   }
    
    return NULL;
}