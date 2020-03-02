#ifndef GOVERNMENT_H_INCLUDED
#define GOVERNMENT_H_INCLUDED

#include <string.h>
#include "Groups.h"

class Government{
public:
    Government(std::string Government_name);
    Government(const Government& obj);
    Government& operator=(const Government& obj);
    ~Government();

    bool createISG();
    bool createSSG();
    void print_workers();
    void disbandISG();
    void disbandSSG();
    void number_of_people();
    int getID(std::string namef);

    IntelligenceGroup *ISG;  //pointer to intelligence service
    ServiceGroup *SSG;       //pointer to secret service
private:
    std::string name_of_goverment;
    int number_of_all_members; //keeps the number of ISG and SSG group number
};

#endif // GOVERNMENT_H_INCLUDED
