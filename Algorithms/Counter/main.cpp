#include <iostream>
#include "Tests.hpp"


int main()
{
    Sequence_push_test();
    Sequence_pop_test();
    Sequence_move_test();
    Sequence_operators_and_constructors_test();
    Counter_push_test();
    Counter_pop_test();
    Counter_specific_functions_test();
    Counter_operators_and_constructors_test();
    count_words_test();

    std::cin.get();
    return 0;
}

