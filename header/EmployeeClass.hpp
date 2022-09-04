#ifndef __employeeClass_HPP__
#define __employeeClass_HPP__
#include <string>
using namespace std;
class Employee
{
public:
    Employee(){ };
    std::string getName() const
    {
	return name;
    }
    int  getPassword() const
    {
        return password;
    }
    int getLevel() const
    {
        return level;
    }
    int getHours() const
    {
        return hours;
    }
    int getTips() const
    {
        return tips;
    }
    void setName(std::string aName)
    {
        name = aName;
    }
    void setPassword(int aPassword)
    {
        password = aPassword;
    }
    void setTips(int aTip)
    {
        tips = aTip;
    }
    void setHours(int aHours)
    {
        hours = aHours;
    }
    void setLevel(int aLevel)
    {
        level = aLevel;
    }
    virtual vector<Employee*> getEmployees() { };
    virtual void add(Employee employee) { };
    virtual void remove(const Employee &employee) { };
    virtual Employee* getEmployeeFromPassword(int password){ };
    virtual bool checkPassword(int password) { };

protected:
    std::string name;
    unsigned int level;
    unsigned int hours;
    int password;
    unsigned int tips;
};

#endif

