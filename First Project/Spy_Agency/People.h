#ifndef PEOPLE_H_INCLUDED
#define PEOPLE_H_INCLUDED

#include <string>

class People{
public:
    People(std::string namef,int workerIDf, int agef, int time_of_workingf, int files_value);
    ~People();
protected:
    std::string name;
    int workerID;
    int age;
    int time_of_working;
    int ranking;
    int prizes;
    std::string proffesion;
    int value_of_files;
    int points_gathered;
    People* next;

    friend class Government;
    friend class Base_Group; friend class IntelligenceGroup; friend class ServiceGroup;
};

class Spy: public People{
public:
    Spy(std::string namef,int workerIDf, int agef, int time_of_workingf, int files_value,int time_in_prison);
    ~Spy();
    void point_counter();
private:
    //int points_gathered;
    int prison_time;

    friend class ServiceGroup;
    friend class Government;
};

class Agent: public People{
public:
    Agent(std::string namef, int workerIDf, int agef, int time_of_workingf, int files_value);
    ~Agent();

    void point_counter();
private:
    //int points_gathered;

    friend class IntelligenceGroup;
    friend class Government;
};

#endif // PEOPLE_H_INCLUDED
