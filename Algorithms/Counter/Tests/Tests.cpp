#include "Tests.hpp"
#include "Counter.hpp"
#include "Count_words.hpp"

void Sequence_push_test(){
    std::cout<<"******SEQUENCE PUSH TEST******"<<std::endl<<std::endl;

    Sequence<int>* A= new Sequence<int>();
    std::cout<<"PUSH FRONT:"<<std::endl;
    A->push_front(1);
    A->push_front(2);
    A->push_front(3);
    A->print();
    std::cout<<"PUSH BACK:"<<std::endl;
    A->push_back(4);
    A->push_back(5);
    A->push_back(6);
    A->print();
    std::cout<<"PUSH SPECIFIC ONE:"<<std::endl;
    A->push_specific(2,7);
    A->push_specific(4,8);

    //push not possible ones
    A->push_specific(20,4);
    A->print();
    std::cout<<"---------------------------"<<std::endl;
}

void Sequence_pop_test(){

    std::cout<<"******SEQUENCE POP TEST******"<<std::endl<<std::endl;

    Sequence<int>* A = new Sequence<int>();
    std::cout<<"BEFORE POP:"<<std::endl;
    A->push_back(1);
    A->push_back(2);
    A->push_back(3);
    A->push_back(4);
    A->push_back(5);
    A->push_back(6);
    A->push_back(7);
    A->push_back(8);
    A->push_back(9);
    A->push_back(10);
    A->push_back(11);
    A->push_back(12);
    A->print();

    std::cout<<"POP FRONT:"<<std::endl;
    A->pop_front();
    A->pop_front();
    A->pop_front();
    A->print();

    std::cout<<"POP BACK:"<<std::endl;
    A->pop_back();
    A->pop_back();
    A->pop_back();
    A->print();

    std::cout<<"POP SPECIFIC ONES:"<<std::endl;
    A->pop_specific(2);
    A->pop_specific(4);

    //pop non-existent
    A->pop_specific(15);
    A->print();

    std::cout<<"---------------------------"<<std::endl;
}

void Sequence_move_test(){

    std::cout<<"******SEQUENCE MOVE TEST******"<<std::endl<<std::endl;

    Sequence<int>* A = new Sequence<int>();
    std::cout<<"BEFORE MOVES:"<<std::endl;
    A->push_back(1);
    A->push_back(2);
    A->push_back(3);
    A->push_back(4);
    A->push_back(5);
    A->push_back(6);

    A->print();

    std::cout<<"MOVE FRONT:"<<std::endl;
    A->move_front(3);
    A->move_front(4);
    A->print();

    std::cout<<"MOVE BACK:"<<std::endl;
    A->move_back(3);
    A->move_back(4);

    //not possible to work
    A->move_back(12);
    A->move_front(13);
    A->print();
    std::cout<<"---------------------------"<<std::endl;
}

void Sequence_operators_and_constructors_test(){

    std::cout<<"******SEQUENCE OPERATORS AND CONSTRUCTOR TEST******"<<std::endl<<std::endl;

    Sequence<int>* A = new Sequence<int>();
    Sequence<int>* B = new Sequence<int>();
    std::cout<<"BEFORE CHANGES:"<<std::endl;
    A->push_back(1);
    A->push_back(2);
    A->push_back(3);
    A->push_back(4);
    A->push_back(5);
    A->push_back(6);
    B->push_back(11);
    B->push_back(12);
    std::cout<<"Sequence A:"<<std::endl;
    A->print();
    std::cout<<"Sequence B:"<<std::endl;
    B->print();

    std::cout<<"B = A:"<<std::endl<<"A - list cleared"<<std::endl<<std::endl;
    *B = *A;
    A->clear_the_list();
    std::cout<<"Sequence A:"<<std::endl;
    A->print();
    std::cout<<"Sequence B:"<<std::endl;
    B->print();

    std::cout<<"COPY CONSTRUCTOR - C(B):"<<std::endl;
    Sequence<int>* C = new Sequence<int>(*B);
    std::cout<<"Sequence C:"<<std::endl;
    C->print();

    std::cout<<"STARTING VALUES"<<std::endl;
    std::cout<<"Sequence A:"<<std::endl;
    A->clear_the_list();
    A->push_back(1);
    A->push_back(2);
    A->print();
    std::cout<<"Sequence B:"<<std::endl;
    B->clear_the_list();
    B->push_back(3);
    B->push_back(4);
    B->print();

    std::cout<<"B += A"<<std::endl;
    std::cout<<"Sequence B:"<<std::endl;
    *B += *A;
    B->print();

    C->clear_the_list();
    std::cout<<"C = A + B"<<std::endl;
    std::cout<<"Sequence B:"<<std::endl;
    *C = *A + *B;
    std::cout<<"Sequence C:"<<std::endl;
    C->print();
    std::cout<<"---------------------------"<<std::endl;
}

void Counter_push_test(){

    std::cout<<"******COUNTER PUSH TEST******"<<std::endl<<std::endl;

    Counter<int>* A= new Counter<int>();
    std::cout<<"PUSH FRONT:"<<std::endl;
    A->push_front(1);
    A->push_front(2);
    A->push_front(2);
    A->push_front(3);
    A->print();
    std::cout<<"PUSH BACK:"<<std::endl;
    A->push_back(4);
    A->push_back(5);
    A->push_back(5);
    A->push_back(6);

    A->print();
    std::cout<<"PUSH SPECIFIC ONE:"<<std::endl;
    A->push_specific(3,4);
    A->push_specific(2,7);
    A->push_specific(4,8);

    //push not possible ones
    A->push_specific(20,4);
    A->print();
    std::cout<<"---------------------------"<<std::endl;
}

void Counter_pop_test(){

    std::cout<<"******COUNTER POP TEST******"<<std::endl<<std::endl;

    Counter<int>* A = new Counter<int>();
    std::cout<<"BEFORE POP:"<<std::endl;
    A->push_back(1);
    A->push_back(2);
    A->push_back(3);
    A->push_back(4);
    A->push_back(1);
    A->push_back(2);
    A->push_back(3);
    A->push_back(4);
    A->push_back(5);
    A->push_back(6);
    A->push_back(7);
    A->push_back(8);
    A->push_back(9);
    A->push_back(9);
    A->push_back(9);
    A->push_back(10);
    A->push_back(11);
    A->push_back(12);
    A->print();

    std::cout<<"POP FRONT:"<<std::endl;
    A->pop_front();
    A->pop_front();
    A->pop_front();
    A->print();

    std::cout<<"POP BACK:"<<std::endl;
    A->pop_back();
    A->pop_back();
    A->pop_back();
    A->print();

    std::cout<<"POP SPECIFIC ONES:"<<std::endl;
    A->pop_specific(4);
    A->pop_specific(8);

    //pop non-existent
    A->pop_specific(15);
    A->print();

    std::cout<<"DECREASE NUMBER FUNC:"<<std::endl;
    A->decrease_numb(9);
    A->decrease_numb(5);
    A->print();

    std::cout<<"---------------------------"<<std::endl;
}

void Counter_specific_functions_test(){
    std::cout<<"******COUNTER SPECIFIC FUNCTIONS TEST******"<<std::endl<<std::endl;

    std::cout<<"STARTING VALUES:"<<std::endl;
    Counter<int>* A = new Counter<int>();
    A->push_back(1);
    A->push_back(2);
    A->push_back(3);
    A->push_back(4);
    A->push_back(2);
    A->push_back(4);
    A->print();

    std::cout<<"SWAP KEY:"<<std::endl;
    A->swap_key(2,9);
    A->swap_key(14,5); //here nothing happen
    A->print();

    std::cout<<"HOW MANY:"<<std::endl;
    std::cout<<"There are "<<A->howMany(9)<<" elements with key 9"<<std::endl<<std::endl;

    std::cout<<"CHANGE NUMBER OF OCCURENCES FUNCTION:"<<std::endl;
    A->change_num_of_occurr(9, 15);
    A->print();

    std::cout<<"DOES EXIST FUNCTION:"<<std::endl;
    if(A->doesExist(9)!=-1) std::cout<<"EXISTS"<<std::endl<<std::endl;

}

void Counter_operators_and_constructors_test(){

    std::cout<<"******COUNTER OPERATORS AND CONSTRUCTOR TEST******"<<std::endl<<std::endl;

    Counter<int>* A = new Counter<int>();
    Counter<int>* B = new Counter<int>();
    std::cout<<"BEFORE CHANGES:"<<std::endl;
    A->push_back(1);
    A->push_back(2);
    A->push_back(3);
    A->push_back(4);
    A->push_back(5);
    A->push_back(4);
    B->push_back(4);
    B->push_back(12);
    std::cout<<"Counter A:"<<std::endl;
    A->print();
    std::cout<<"Counter B:"<<std::endl;
    B->print();

    std::cout<<"B = A:"<<std::endl<<"A - list cleared"<<std::endl<<std::endl;
    *B = *A;
    A->clear_the_list();
    std::cout<<"Counter A:"<<std::endl;
    A->print();
    std::cout<<"Counter B:"<<std::endl;
    B->print();

    std::cout<<"COPY CONSTRUCTOR - C(B):"<<std::endl;
    Counter<int>* C = new Counter<int>(*B);
    std::cout<<"Counter C:"<<std::endl;
    C->print();

    std::cout<<"STARTING VALUES"<<std::endl;
    std::cout<<"Counter A:"<<std::endl;
    A->clear_the_list();
    A->push_back(1);
    A->push_back(2);
    A->push_back(2);
    A->print();
    std::cout<<"Counter B:"<<std::endl;
    B->clear_the_list();
    B->push_back(3);
    B->push_back(2);
    B->push_back(3);
    B->push_back(4);
    B->print();

    std::cout<<"B += A"<<std::endl;
    std::cout<<"Counter B:"<<std::endl;
    *B += *A;
    B->print();

    std::cout<<"Counter A - new values"<<std::endl;
    A->clear_the_list();
    A->push_back(2);
    A->push_back(2);
    A->push_back(97);
    A->print();

    std::cout<<"C = A + B"<<std::endl;
    std::cout<<"Counter B:"<<std::endl;
    *C = *A + *B;
    std::cout<<"Counter C:"<<std::endl;
    C->print();
    std::cout<<"---------------------------"<<std::endl;
}

void count_words_test(){

    Counter<std::string> A;
    std::ifstream fin;
    fin.open("ForCounting.txt");
    count_words(A, fin);
    A.print();
}
