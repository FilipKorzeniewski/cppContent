#include "People.h"
using std::string;
Spy::Spy(string namef,int workerIDf, int agef, int time_of_workingf, int files_value,int time_in_prison)
            :People(namef, workerIDf, agef, time_of_workingf, files_value){

    proffesion="Spy";
    prison_time=time_in_prison;
    point_counter();
    //next=NULL;
//constructor
}
Spy::~Spy(){}

void Spy::point_counter(){
    points_gathered=value_of_files+0.1*time_of_working-0.2*prison_time;
}
