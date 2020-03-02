#include <iostream>
#include "People.h"
#include "Government.h"
#include "Groups.h"

using namespace std;

int main()
{
    Government G1("pierwszy");

    G1.print_workers();

    G1.createISG(); G1.createSSG();
    G1.ISG->print_list(); G1.SSG->print_list();
    G1.ISG->compare_func(); G1.SSG->compare_func();
    G1.ISG->hire("Brian", 123456, 31, 5, 50);
    G1.SSG->hire("George", 987654, 55, 30, 300, 10);
    G1.ISG->hire("Jurek", 124326, 42, 8, 12);
    G1.SSG->hire("Edek", 981254, 32, 3, 215, 3);
    G1.ISG->awards();   G1.SSG->awards();
    G1.SSG->hire("Bodzio", 321254, 67, 40, 1000, 5);
    G1.ISG->hire("Tomek", 324326, 34, 15, 2500);


    G1.ISG->compare_func(); G1.SSG->compare_func();
    G1.number_of_people();

    G1.ISG->awards();   G1.SSG->awards();   //2 awards are given
    G1.ISG->awards();   G1.SSG->awards();

    G1.ISG->print_list(); G1.SSG->print_list();


    G1.ISG->fire(124326); G1.ISG->fire("Brian");   //firing 2 agents
    G1.ISG->fire(32313); G1.ISG->fire("Mateuszek"); //trying to fire agents that do not exist
    G1.SSG->fire(981254); G1.SSG->fire("Bodzio");   //firing 2 spies
    G1.SSG->fire(123124); G1.SSG->fire("Maras");    //trying to fire spies that do not exist

    G1.print_workers();

    G1.createISG(); G1.createSSG(); //trying to create 2nd secret and intelligence service

    G1.disbandISG(); G1.disbandSSG();   //disbanding actual ones

    G1.print_workers();


    //assigning and copying
    Government G2("drugi");
    G2.createISG(); G2.createSSG();
    G2.ISG->hire("Arnold",111111, 30, 15, 500);
    G2.SSG->hire("Damian", 997, 23, 4, 0, 2);

    std::cout<<std::endl<<"And now there is second Government drugi"<<std::endl;
    G2.print_workers();

    G1=G2;
    std::cout<<"And after assigning G2 to G1, G1 looks like:"<<std::endl;
    G1.print_workers();

    std::cout<<std::endl<<"now - after using copy constructor for copy G1 to G3"<<std::endl;

    Government G3(G1);

    G3.print_workers();

    cin.get();
    return 0;
}
