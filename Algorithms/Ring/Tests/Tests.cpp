#include "Tests.hpp"
#include "BiRing.hpp"

void BiRing_push_test(){
    std::cout<<"******BiRing PUSH TEST******"<<std::endl<<std::endl;

    BiRing<int, int> A = BiRing<int, int>();
    std::cout<<std::endl<<"PUSH LEFT:"<<std::endl;
    A.pushFront(1, 3);
    A.pushFront(2, 4);
    A.pushFront(3, 5);
    std::cout<<std::endl<<"PRINT RIGHT"<<std::endl;
    A.printRight();
    std::cout<<std::endl<<"PRINT LEFT"<<std::endl;
    A.printLeft();
    std::cout<<std::endl<<"PUSH RIGHT:"<<std::endl;
    A.pushBack(4, 43);
    A.pushBack(5, 43);
    A.pushBack(6, 87);
    A.printRight();
    std::cout<<std::endl<<"PUSH AFTER ONE:"<<std::endl;
    A.pushAfter(4, 8, 7);
    A.pushAfter(6, 9, 43);

    //push not possible ones
    A.pushAfter(14, 4, 4);
    A.printRight();
    std::cout<<"---------------------------"<<std::endl;
};

void BiRing_pop_test(){

    std::cout<<std::endl<<std::endl<<"******BiRing POP TEST******"<<std::endl<<std::endl;
    std::cout<<std::endl<<"DESTROY RING TEST"<<std::endl;
    BiRing<int, int>* A = new BiRing<int, int>();
    A->destroy_Ring();
    std::cout<<std::endl<<"BEFORE CLEARING:"<<std::endl;
    A->pushBack(1, 32);
    A->pushBack(2, 43);
    A->pushBack(3, 65);
    A->printRight();
    std::cout<<std::endl<<"AFTER CLEARING:"<<std::endl;
    A->destroy_Ring();
    A->printRight();
    
    std::cout<<std::endl<<"BEFORE POP SPECIFIC:"<<std::endl;
    A->pushBack(4, 73);
    A->pushBack(5, 74);
    A->pushBack(6, 32);
    A->pushBack(7, 643);
    A->pushBack(8, 73);
    A->pushBack(9, 732);
    A->pushBack(10, 73);
    A->pushBack(11, 32);
    A->pushBack(12, 321);
    A->printRight();

    std::cout<<std::endl<<"POP SPECIFIC ONES (5,9 and non-existent 15):"<<std::endl;
    A->pop_specific(5);
    A->pop_specific(9);

    //pop non-existent
    A->pop_specific(15);
    A->printRight();
    delete A;

    std::cout<<"---------------------------"<<std::endl;
};

void BiRing_operators_and_constructors_test(){

    std::cout<<std::endl<<std::endl<<"******BiRing OPERATORS AND CONSTRUCTOR TEST******"<<std::endl<<std::endl;

    BiRing<int, int>* A = new BiRing<int, int>();
    BiRing<int, int>* B = new BiRing<int, int>();
    std::cout<<std::endl<<"BEFORE CHANGES:"<<std::endl;
    A->pushBack(1, 32);
    A->pushBack(2, 312);
    A->pushBack(3, 31);
    A->pushBack(4, 321);
    A->pushBack(5, 43);
    A->pushBack(6, 321);
    B->pushBack(11, 123);
    B->pushBack(12, 54);
    std::cout<<"BiRing A:"<<std::endl;
    A->printRight();
    std::cout<<"BiRing B:"<<std::endl;
    B->printRight();

    std::cout<<std::endl<<"B = A:"<<std::endl<<"A - list cleared"<<std::endl;
    *B = *A;
    A->destroy_Ring();
    std::cout<<"BiRing A:"<<std::endl;
    A->printRight();
    std::cout<<"BiRing B:"<<std::endl;
    B->printRight();

    std::cout<<std::endl<<"COPY CONSTRUCTOR - C(B):"<<std::endl;
    BiRing<int, int>* C = new BiRing<int, int>(*B);
    std::cout<<"BiRing C:"<<std::endl;
    C->printRight();

    std::cout<<"STARTING VALUES"<<std::endl;
    std::cout<<"BiRing A:"<<std::endl;
    A->destroy_Ring();
    A->pushBack(1, 54);
    A->pushBack(2, 423);
    A->printRight();
    std::cout<<"BiRing B:"<<std::endl;
    B->destroy_Ring();
    B->pushBack(3, 32);
    B->pushBack(4, 321);
    B->printRight();

    C->destroy_Ring();
    std::cout<<std::endl<<"C = A + B"<<std::endl;
    *C = *A + *B;
    
    std::cout<<"BiRing C:"<<std::endl;
    C->printRight();
    std::cout<<std::endl<<"B += A"<<std::endl;
    std::cout<<"BiRing B:"<<std::endl;
    *B += *A;
    B->printRight();
    delete A; delete B;

    std::cout<<"---------------------------"<<std::endl;

};

void ShuffleTest(){

    std::cout<<std::endl<<std::endl<<"******SHUFFLE TEST******"<<std::endl<<std::endl;
    BiRing<int, int>A = BiRing<int, int>();
    BiRing<int, int>B = BiRing<int, int>();
    BiRing<int, int>C = BiRing<int, int>();
    std::cout<<"STARTING VALUES:"<<std::endl;
    A.pushBack(1, 32);
    A.pushBack(2, 312);
    A.pushBack(3, 31);
    A.pushBack(4, 321);
    A.pushBack(5, 43);
    A.pushBack(6, 321);
    B.pushBack(11, 123);
    B.pushBack(12, 54);
    B.pushBack(13, 432);
    B.pushBack(14, 21);
    std::cout<<"BiRing A:"<<std::endl;
    A.printRight();
    std::cout<<"BiRing B:"<<std::endl;
    B.printRight();
    
    std::cout<<std::endl<<"WITH WRONG PARAMATERS"<<std::endl;
    
    std::cout<<std::endl<<"nbfirst < 0"<<std::endl;
    C = shuffle(A, B, -2, 5, 3);
    C.printRight();

    std::cout<<std::endl<<"nbsecond < 0"<<std::endl;
    C = shuffle(A, B, 3, -4, 2);
    C.printRight();

    std::cout<<std::endl<<"reps < 0"<<std::endl;
    C = shuffle(A, B, 3, 2, -5);
    C.printRight();
    std::cout<<std::endl<<"RIGHT PARAMETERS (2, 3, 5):"<<std::endl;
    shuffle(A, B, 2, 3, 5).printRight();
    
    
    std::cout<<std::endl<<"STARTING VALUES - char:"<<std::endl;
    BiRing<char, char>D = BiRing<char, char>();
    BiRing<char, char>E = BiRing<char, char>();

    D.pushBack('a', 'b');
    D.pushBack('b', 'd');
    D.pushBack('c', 'f');
    D.pushBack('d', 'h');
    E.pushBack('1', 'h');
    E.pushBack('2', 'd');
    E.pushBack('3', 'w');
    E.pushBack('4', 'a');
    std::cout<<"BiRing A:"<<std::endl;
    D.printRight();
    std::cout<<"BiRing B:"<<std::endl;
    E.printRight();

    std::cout<<std::endl<<"PARAMETERS (2, 3, 3):"<<std::endl;
    shuffle(D, E, 2, 3, 5).printRight();
    
    std::cout<<"---------------------------"<<std::endl;
    
};

