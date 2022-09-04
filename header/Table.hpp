#ifndef __TABLE_HPP__
#define __TABLE_HPP__

#include <iostream>
#include "EmployeeClass.hpp"
#include "Order.hpp"
#include "OrderIterator.hpp"
#include "Orders.hpp"

using namespace std;
#define MAX_TABLE_NUM 20  // max number of table of the resturant

class Table {
private:
	int tableNum = 0;
	int numPeople = 0;
	Employee* employee = nullptr;
	Order* order;
	Orders* orders = new Orders();

public:
	Table() {};
	Table(int tNum, int numP) {
		tableNum = tNum;
		numPeople = numP;
		order = new Order();
		orders->getOrders().push_back(order);
	};

	int getTableNumber() {
		return tableNum;
	};
	int getNumberPeople() {
		return numPeople;
	};

	Order getTableOrder() {
		return *order;
	};
};

#endif //__TABLE_HPP__A
