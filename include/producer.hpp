/**
 * @file producer.hpp
 * @author Elliott Hager
 * @brief The producer header for the producer/consumer problem
 * @date 2023-11-05
 * 
 */

#ifndef PRODUCER_HPP
#define PRODUCER_HPP

    #include <stdio.h>
    #include <unistd.h>
    #include <pthread.h>
    #include <iostream>
    #include <fcntl.h>
    #include <sys/mman.h>

    int main(int, char**);

#endif