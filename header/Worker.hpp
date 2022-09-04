#ifndef _WORKER_HPP__
#define __WORKER_HPP__
#include <string>
using namespace std;
#include "EmployeeClass.hpp"
class Worker : public Employee
{
public:
    Worker(std::string aName, int aLevel, int aPassword, int amountHours)
    {
        name = aName;
        level = aLevel;
        password = aPassword;
        hours = amountHours;
        tips = 0;
    }

private:
    //std::string name;
    //unsigned int level;
    //unsigned int hours;
    //int password;
    //unsigned int tips;
};

#endif
