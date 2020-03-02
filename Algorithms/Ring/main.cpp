#include <iostream>
#include "Tests.hpp"

int main(int argc, const char * argv[]) {

    BiRing_push_test();
    BiRing_pop_test();
    BiRing_operators_and_constructors_test();
    ShuffleTest();
    
    return 0;
}
