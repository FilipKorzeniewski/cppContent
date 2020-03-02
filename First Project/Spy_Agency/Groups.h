#ifndef GROUPS_H_INCLUDED
#define GROUPS_H_INCLUDED

#include <string.h>
#include <iostream>
#include "People.h"

class Base_Group{
public:
    Base_Group();
     virtual ~Base_Group(){};

    virtual void fire(int ID_of_worker) = 0;
    virtual void fire(std::string name_of_worker) = 0;
    void awards();
    void compare_func();
    void worker_counter();

protected:
    People* head;
    int number_of_workers;
};

class IntelligenceGroup:public Base_Group{
public:
   IntelligenceGroup();
   ~IntelligenceGroup();

    void hire(std::string namef, int workerIDf, int agef, int time_of_workingf,int value_of_filesf);
    void fire(int ID_of_worker) override;
    void fire(std::string name_of_worker) override;
    void Agent_counter();
    //void compare_func();
    void print_list();
    //void awards();
private:
    //Agent* head;
    //int number_of_Agents;

    friend class Government;
};

class ServiceGroup:public Base_Group{
public:
   ServiceGroup();
   ~ServiceGroup();

    void hire(std::string namef, int workerIDf, int agef, int time_of_workingf, int files_value, int time_in_prison);
    void fire(int ID_of_worker) override;
    void fire(std::string name_of_worker) override;
    void Spy_counter();
    //void compare_func();
    void print_list();
    //void awards();
private:
    //Spy* head;
    //int number_of_Spies;

    friend class Government;
};

#endif // GROUPS_H_INCLUDED

/*
class Groups {
public:
    Groups(string Group_name){
    //constructor
    }
    ~Groups(){
    //destructor of class
    }
    bool recruit_person(People& const person){
    //decides if person is recruited
    }

    bool fire_person(People& const person){
    //decides if person is hired
    }

    bool modify_data_of_person(People& person){
    //modifies data of person
    }

    void member_counter(){
        Group_size+=1;
    }

    int size_of_group(){
        return Group_size
    //returns the group size
    }

    void print_data_of_members(){
    //prints data of group members
    }

private:
    string name_of_Group;
    int Group_size=0;
};
class File_gather{
public:
    File_gather(){
    //constructor
    }

    friend class OfficeWorker;
private:
    int value_of_file;
    File_gather* next;
};
*/
