#include "Groups.h"
using std::string; using std::cout; using std::endl;

IntelligenceGroup::IntelligenceGroup(){
    head=NULL;
    /*constructor*/}
IntelligenceGroup::~IntelligenceGroup(){}

void IntelligenceGroup::print_list(){
    People* tmp=head;
    cout<<endl<<"List of Agents:"<<endl;
    cout<<"Name"<<'\t'<<"Age"<<'\t'<<"Proffesion"<<'\t'<<"Worker ID"<<'\t'<<"Years of work"<<'\t'<<"Ranking"<<'\t'<<"Awards"<<endl;
    while(tmp){
        cout<<tmp->name<<'\t'<<tmp->age<<'\t'<<tmp->proffesion<<'\t'<<'\t'<<tmp->workerID<<'\t'<<'\t'<<tmp->time_of_working<<'\t'<<'\t'<<tmp->ranking<<'\t'<<tmp->prizes<<endl;
        tmp=tmp->next;
    }
    cout<<endl;
}

void IntelligenceGroup::hire(string namef, int workerIDf, int agef, int time_of_workingf, int files_value){
    if(!head)
    {
        head = new Agent(namef, workerIDf, agef, time_of_workingf, files_value);
    }
    else{
        People* tmp = head;
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = new Agent(namef, workerIDf, agef, time_of_workingf, files_value);
    }
}
void IntelligenceGroup::fire(int ID_of_worker){
    int checker=0;

    if(head){
        People* tmp=NULL;
        People* current=head;
        if(!current->next){
            if(current->workerID==ID_of_worker){
                delete current;
                head=NULL;
                checker=1;
            }
        }
        while(current->next){
            if(current->workerID==ID_of_worker){
                tmp=current->next;
                delete head;
                head=tmp;
                tmp=NULL;
                checker=1;
                break;
            }else if(ID_of_worker==current->next->workerID){
                tmp=current->next;
                current->next=current->next->next;
                delete tmp;
                break;
                checker=1;
            }else{
                current=current->next;
            }
        }
    }else{
        std::cout<<"There are no workers"<<std::endl;
        checker=1;
    }

    if (checker==0){
        std::cout<<"There is no worker with ID: "<<ID_of_worker<<std::endl;
    }
}
void IntelligenceGroup::fire(string name_of_worker){
    int checker=0;

    if(head){
        People* tmp=NULL;
        People* current=head;
        if(!current->next){
            if((strcmp(current->name.c_str(),name_of_worker.c_str()))==0){
                delete current;
                head=NULL;
                checker=1;
            }
        }
        while(current->next){
            if((strcmp(current->name.c_str(),name_of_worker.c_str()))==0){
                tmp=current->next;
                delete head;
                head=tmp;
                tmp=NULL;
                checker=1;
                break;
            }else if((strcmp(current->next->name.c_str(),name_of_worker.c_str()))==0){
                tmp=current->next;
                current->next=current->next->next;
                delete tmp;
                break;
                checker=1;
            }else{
                current=current->next;
            }
        }
    }else{
        std::cout<<"There are no workers"<<std::endl;
        checker=1;
    }

    if (checker==0){
        std::cout<<"There is no worker with name "<<name_of_worker<<std::endl;
    }
}
