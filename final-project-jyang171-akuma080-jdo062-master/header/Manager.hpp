#ifndef __MANAGER_HPP__
#define __MANAGER_HPP__
#include <string>
#include "EmployeeClass.hpp"
using namespace std;
class Manager : public Employee
{
public:
    Manager(std::string aName, int aLevel, int aPassword, int amountHours)
    {
        name = aName;
        level = aLevel;
        password = aPassword;
        hours = amountHours;
        tips = 0;
    }
    void add(Employee employee) override {
       	Employee* newEmployee = &employee;
	employees.push_back(newEmployee);
    }
    void remove(const Employee &employee) override {
	
    	for(int i = 0; i < employees.size(); i++){
		if(employees.at(i)->getPassword()  == employee.getPassword()){
			employees.erase(employees.begin() + i);
		}
	}

    }

    bool checkPassword(int aPassword) override {
	bool isValid = false;
        for(int i = 0; i < employees.size(); i++){
                if(employees.at(i)->getPassword() == aPassword){
                        isValid = true;
                }
        }
        return isValid;
    }
    Employee* getEmployeeFromPassword(int aPassword) override {
        for(int i = 0; i < employees.size(); i++){
                if(employees.at(i)->getPassword() == aPassword){
                        return employees.at(i);
                }
        }
    }
    vector<Employee*> getEmployees() override {
	return employees;
    }

private:
    //std::string name;
    //unsigned int level;
    //unsigned int hours;
    //int password;
    //unsigned int tips;
    vector<Employee*> employees;
};

#endif
