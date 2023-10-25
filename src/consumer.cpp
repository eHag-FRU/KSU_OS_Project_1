/*!
*   /details Consumer in the producer/consumer problem, implemented with threading and shared buffer
*   
*
*   /author  Elliott Hager
*   /date  10/24/2023
*   
*
**/




#include "../include/consumer.hpp"

/**
 * @brief Main function, driving the consumer
 * 
 * @return int 
 */
int main() {
//Make the thread object
    pthread_t consumerThread;

    //Construct the thread to be over the producer functionality
    pthread_create(&consumerThread, NULL, consumer, NULL);


    //Once done, joins the thread back to main to finish the process
    pthread_join(consumerThread, NULL);

    return 0;
}


/**
 * @brief Function for consumer thread to use to process and "consume" the data in the shared memory
 * 
 * @param arg
 * @return void* 
 */
void* consumer(void* arg) {
    while(true) {
        sleep(1);
        std::cout << "Some Function!" << std::endl;
        
    }
    return NULL;
}