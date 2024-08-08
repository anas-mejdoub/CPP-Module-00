#include <iostream>
#include "t.hpp"
#include <sys/time.h>  
Test::Test()
{
    std::cout << "an obj will be created\n";
    i = 0;
}

void Test::plus_one()
{
    i++;
}

int main()
{
    // Test obj;

    // obj.plus_one();
    // obj.plus_one();

    // Test obj2;
    // obj2 = obj;
    // obj2.plus_one();
    // obj2.i = 99;
    // std::cout << "obj2 is " << obj2.i << "\n";
    // std::cout << "obj is " << obj.i;
    struct timeval tv;

    // Get the current time
    gettimeofday(&tv, nullptr);

    // Time in seconds since the epoch
    long seconds_since_epoch = tv.tv_sec;

    // Time in microseconds since the epoch
    long microseconds_since_epoch = seconds_since_epoch * 1000000 + tv.tv_usec;

    std::cout << "Seconds since epoch: " << seconds_since_epoch << std::endl;
    std::cout << "Microseconds since epoch: " << microseconds_since_epoch << std::endl;
}