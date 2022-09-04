#ifndef __ORDERS_HPP__
#define __ORDERS_HPP__

#include "Food.hpp"
#include <string>
#include "EmployeeClass.hpp"
#include <vector>
#include "OrderIterator.hpp"

using namespace std;

class Orders {
private:
    vector<Order> orderVector;

public:
    Orders() {};
    OrderIterator* create_iterator() { return new OrderIterator(this); };

    vector<Order> getOrders() { return orderVector; };
    
};

#endif //__ORDERS_HPP__
