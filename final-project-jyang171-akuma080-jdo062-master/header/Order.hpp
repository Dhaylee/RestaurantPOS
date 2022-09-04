#ifndef __ORDER_HPP__
#define __ORDER_HPP__

#include "Food.hpp"
#include <string>
#include "EmployeeClass.hpp"
#include <vector>
#include "OrderIterator.hpp"
using namespace std;

class Order {
private:
	int num;     
    Employee* e = nullptr;
    long int phoneNumber = 0;
    string customerName = "";
    int tableNum = 0;
    double totoal_price = 0.0;
    vector<Food> foodVector;
    int orderNumber = 0;
    double balance = 0.0;

public:
	Order() {};
    Order(Employee* employee, int orderNum, double b) {
        e = employee;
        tableNum = 0; // table, phoneName and customerName are zero indicate takeout order
        phoneNumber = 0;
        customerName = "";
        orderNumber = orderNum;
        balance = b;
    }
    Order(Employee* employee, int tableNum, int orderNum, double b) {
        e = employee;
        tableNum = tableNum;  // no customer name and phone number so it is dine in
        orderNumber = orderNum;
        balance = b;
    }
    Order(Employee* employee, long int phoneNum, string customerName, int orderNum, double b) {
        e = employee;
        phoneNumber = phoneNum;  // have phone number and customer name it is phone order
        customerName = customerName;
        orderNumber = orderNum;
        balance = b;
    }

    string getServerName() {
        return e->getName();
    };

    long int getPhoneNumber() {
        return phoneNumber;
    };

    string getCustomerName() {
        return customerName;
    };

    vector<Food> getFood() {
        return foodVector;
    };

    void addFood(Food food) {
        foodVector.push_back(food);
    };
    int getOrderNumber() {
        return orderNumber;
    };
    double getBalance() {
        return balance;
    };
};


#endif //__ORDER_HPP__
