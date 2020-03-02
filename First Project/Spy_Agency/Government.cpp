#include "Government.h"
#include <cstdlib>
#include <iostream>

using std::string;

Government::Government(string Government_name){
    name_of_goverment=Government_name;
    ISG = NULL;
    SSG = NULL;
    number_of_all_members=0;
//constructs the government's name
}
Government::Government(const Government& obj){
    this->name_of_goverment=obj.name_of_goverment;

    this->~Government();
    if(obj.ISG){
        this->createISG();
        People* current=obj.ISG->head;
        People* tmp=NULL;
        while(current){
            if(!this->ISG->head){
                this->ISG->head=new Agent(current->name,current->workerID,current->age,current->time_of_working,current->value_of_files);
                tmp=this->ISG->head;
            }else{
                tmp->next=new Agent(current->name,current->workerID,current->age,current->time_of_working,current->value_of_files);
                tmp=tmp->next;
            }
        }
        current=current->next;
    }

    if(obj.SSG){
        this->createSSG();
        Spy* current=static_cast<Spy*>(obj.SSG->head);
        Spy* tmp=static_cast<Spy*>(this->SSG->head);
        while(current){
            if(!this->SSG->head){
                this->SSG->head=new Spy(current->name,current->workerID,current->age,current->time_of_working,current->value_of_files,current->prison_time);
                tmp=static_cast<Spy*>(this->SSG->head);
            }else{
                tmp->next=new Spy(current->name, current->workerID, current->age, current->time_of_working, current->value_of_files, current->prison_time);
                tmp=static_cast<Spy*>(tmp->next);
            }
        }
        current=static_cast<Spy*>(current->next);
    }
}

Government& Government::operator=(const Government& obj){
    this->~Government();
    if(obj.ISG){
        this->createISG();
        People* current=obj.ISG->head;
        People* tmp=NULL;
        while(current){
            if(!this->ISG->head){
                this->ISG->head=new Agent(current->name,current->workerID,current->age,current->time_of_working,current->value_of_files);
                tmp=this->ISG->head;
            }else{
                tmp->next=new Agent(current->name,current->workerID,current->age,current->time_of_working,current->value_of_files);
                tmp=tmp->next;
            }
        }
        current=current->next;
    }

    if(obj.SSG){
        this->createSSG();
        Spy* current=static_cast<Spy*>(obj.SSG->head);
        Spy* tmp=static_cast<Spy*>(this->SSG->head);
        while(current){
            if(!this->SSG->head){
                this->SSG->head=new Spy(current->name,current->workerID,current->age,current->time_of_working,current->value_of_files,current->prison_time);
                tmp=static_cast<Spy*>(this->SSG->head);
            }else{
                tmp->next=new Spy(current->name, current->workerID, current->age, current->time_of_working, current->value_of_files, current->prison_time);
                tmp=static_cast<Spy*>(tmp->next);
            }
        }
        current=static_cast<Spy*>(current->next);
    }
    return *this;
}

Government::~Government(){
    disbandISG(); disbandSSG();
//destructor of government
}
void Government::print_workers(){
    std::cout<<"List of Government "<<this->name_of_goverment<<":"<<std::endl;
    if(ISG){
        ISG->print_list();
    }else{
        std::cout<<"There is no Intelligence Service"<<std::endl;
    }
    if(SSG){
        SSG->print_list();
    }else{
        std::cout<<"There is no Secret Service"<<std::endl;
    }
}
bool Government::createISG(){
    if (!ISG){
        ISG=new IntelligenceGroup();
    }else{
        std::cout<<"There is already an Intelligence Service"<<std::endl;
    }
    return true;
//creates ISG if not exists
}

bool Government::createSSG(){
    if (!SSG){
        SSG=new ServiceGroup();
    }else{
        std::cout<<"There is already a Secret Service"<<std::endl;
    }
    return true;
//creates SSG if not exists
}

void Government::disbandISG(){
    if(ISG){
        if(ISG->head){
            People* tmp=ISG->head;
            People* current=ISG->head;
            while(current){
                current=current->next;
                delete tmp;
                tmp=current;
            }
        }
        delete ISG;
    }
    ISG=NULL;
//disbands the intelligence service if exists
}

void Government::disbandSSG(){
    if(SSG){
        if(SSG->head){
            People* tmp=SSG->head;
            People* current=SSG->head;
            while(current){
                current=current->next;
                delete tmp;
                tmp=current;
            }
        }
        delete SSG;
    }
    SSG=NULL;
//disbands the secret service if exists
}
void Government::number_of_people(){
    number_of_all_members=0;
    if(ISG){
        ISG->worker_counter();
        number_of_all_members=ISG->number_of_workers;
    }
    if(SSG){
        SSG->worker_counter();
        number_of_all_members+=SSG->number_of_workers;
    }

    std::cout<<std::endl<<"There are "<<number_of_all_members<<" members"<<std::endl;
//counts the number of people
}

int Government::getID(string namef){

    People* temp1=ISG->head;
    while(temp1){
        if(strcmp(namef.c_str(),temp1->name.c_str())==0){
            return temp1->workerID;
        }else{
            temp1=temp1->next;
        }
    }
    temp1=NULL;
    People* temp2=SSG->head;
    while(temp2){
        if(strcmp(namef.c_str(),temp2->name.c_str())==0){
            return temp2->workerID;
        }else{
            temp2=temp2->next;
        }
    }std::cout<<"There is no member with this name"<<std::endl;
    return 0;
}
