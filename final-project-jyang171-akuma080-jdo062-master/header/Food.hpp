#ifndef __FOOD_HPP__
#define __FOOD_HPP__

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;
class Order;

class Food
{
private:
	int quantity;      // food quantity
	string foodName;   // food names
	string foodType;   // food types
	double foodPrice;  //  food price
public:
	Food() {};
	Food(string name, double price) { 
		foodName = name;
		foodPrice = price;
		quantity = 1;
	}
	string getFoodName() {
		return foodName;
	};
	int getFoodQuantity() {
		return quantity;
	};
	double getFoodPrice() {
		return foodPrice;
	};
	void setFoodQuantity(int n) {
		if (n > 0) {
			quantity = n;
		}
	};
};

#endif //__FOOD_HPP__
