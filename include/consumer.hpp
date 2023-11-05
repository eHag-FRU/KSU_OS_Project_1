/**
 * @file consumer.hpp
 * @author Elliott Hager
 * @brief The consumer header for the producer/consumer problem
 * @date 2023-11-05
 * 
 */


#ifndef CONSUMER_HPP
#define CONSUMER_HPP

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>

int main(int, char *);

#endif