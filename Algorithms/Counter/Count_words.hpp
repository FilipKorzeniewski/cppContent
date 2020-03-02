#ifndef Count_words_hpp
#define Count_words_hpp

#include "Counter.hpp"
#include <stdio.h>

int count_words(Counter<std::string>& cnt, std::ifstream& src){

    int total_number_of_words = 0;

    if(!src.is_open()){
        std::cout << "Failed to open file" << std::endl;
    }

    std::string word;
    while(src >> word){
        total_number_of_words++;
        cnt.push_back(word);
    }
    return total_number_of_words;
}

#endif /* Count_words_hpp */
