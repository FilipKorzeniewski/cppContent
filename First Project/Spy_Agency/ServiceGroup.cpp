#include "Groups.h"
using std::string; using std::cout; using std::endl;


ServiceGroup::ServiceGroup(){
    head=NULL;
    /*constructor*/}
ServiceGroup::~ServiceGroup(){}

void ServiceGroup::hire(string namef, int workerIDf, int agef, int time_of_workingf, int files_value, int time_in_prison){
    if(!head)
    {
        head = new Spy(namef, workerIDf, agef, time_of_workingf, files_value, time_in_prison);
    }
    else{
        People* tmp = head;
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = new Spy(namef, workerIDf, agef, time_of_workingf, files_value, time_in_prison);
    }
}
void ServiceGroup::fire(int ID_of_worker){
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
void ServiceGroup::fire(string name_of_worker){
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

void ServiceGroup::print_list(){

    cout<<endl<<"List of Spies:"<<endl;
    cout<<"Name"<<'\t'<<"Age"<<'\t'<<"Profession"<<'\t'<<"Worker ID"<<'\t'<<"Years of work"<<'\t'<<"Ranking"<<'\t'<<"Awards"<<'\t'<<"Years in prison"<<endl;
    if(head){
        Spy* tmp = static_cast<Spy*>(head);
        //tmp=head;
        while(tmp){
            cout<<tmp->name<<'\t'<<tmp->age<<'\t'<<tmp->proffesion<<'\t'<<'\t'<<tmp->workerID<<'\t'<<'\t'
                    <<tmp->time_of_working<<'\t'<<'\t'<<tmp->ranking<<'\t'<<tmp->prizes<<'\t'<<tmp->prison_time<<endl;
            tmp=static_cast<Spy*>(tmp->next);
        }
        cout<<endl;
    }
}

