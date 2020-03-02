#include "People.h"
using std::string;

People::People(string namef,int workerIDf, int agef, int time_of_workingf, int files_value){
    name=namef;
    workerID=workerIDf;
    age=agef;
    time_of_working=time_of_workingf;
    ranking=1;
    prizes=0;
    value_of_files=files_value;
    next=NULL;
//constructor
}

People::~People(){
//destructor
}

