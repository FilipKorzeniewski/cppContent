#include "People.h"
using std::string;
Agent::Agent(string namef,int workerIDf, int agef, int time_of_workingf, int files_value)
            :People(namef, workerIDf, agef, time_of_workingf, files_value){

    proffesion="Agent";
    point_counter();
    //next=NULL;
//constructor
}

Agent::~Agent(){}

void Agent::point_counter(){
    points_gathered=value_of_files+0.1*time_of_working;
}
