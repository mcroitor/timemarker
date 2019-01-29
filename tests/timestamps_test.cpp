/* 
 * File:   timestamps_test.cpp
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 28 ianuarie 2019, 13:42
 */

#include <stdlib.h>
#include <iostream>
#include "timemarker.h"

/*
 * Simple C++ Test Suite
 */
bool is_simple(size_t number) {
    size_t index = 2;
    do {
        if (number % index == 0) {
            return false;
        }
        ++index;
    } while (index < number);
    return true;
}

void test1() {
    std::cout << "timestamps_test test 1" << std::endl;
    mc::timemarker stamp;
    for(size_t index = 99999900; index != 100000000; ++index){
        if(is_simple(index) == true){
            std::cout << index << " ";
            stamp.mark();
        }
    }
    std::cout << std::endl << stamp << std::endl;
    std::cout << "durations: " << std::endl;
    for(mc::timemarker::duration d: stamp.durations()){
        std::cout << (std::chrono::duration_cast<std::chrono::milliseconds>(d)).count() << std::endl;
    }
}

void test2() {
    std::cout << "timestamps_test test 2" << std::endl;
    //std::cout << "%TEST_FAILED% time=0 testname=test2 (timestamps_test) message=error message sample" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% timestamps_test" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (timestamps_test)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (timestamps_test)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (timestamps_test)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (timestamps_test)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

