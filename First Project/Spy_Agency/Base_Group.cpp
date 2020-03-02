#include "Groups.h"

Base_Group::Base_Group(){
    head=NULL;
    number_of_workers=0;
}

void Base_Group::awards(){
    compare_func();
    if(head){
        People* tmp=head;
        while(tmp){
            if(tmp->ranking==1){
                tmp->prizes+=1;
            }
            tmp=tmp->next;
        }
    }else{
        std::cout<<"There is noone to be granted"<<std::endl;
    }
//function is used for granting awards
}

void Base_Group::compare_func(){
    if (head){
        People* tmp=head;
        People* tmp2=head->next;
        while(tmp){
            while(tmp2){
                if(tmp->points_gathered>tmp2->points_gathered){
                    tmp2->ranking+=1;
                }else{
                    tmp->ranking+=1;
                }
                tmp2=tmp2->next;
            }if(tmp->next){
                tmp=tmp->next;
                tmp2=tmp->next;
            }else{break;}
        }
    }else{
        std::cout<<"There is nothing to compare"<<std::endl;
    }
}

void Base_Group::worker_counter(){
    People* tmp;
    if(head){;}
    else{return;}
    tmp=this->head;
    while(tmp){
        number_of_workers+=1;
        tmp=tmp->next;
    }
}
