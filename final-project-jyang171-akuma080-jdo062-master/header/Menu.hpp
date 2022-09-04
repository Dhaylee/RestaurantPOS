#ifndef MENU_H
#define MENU_H
#include <map>
#include "Display.cpp"
#include "Register.cpp"
#include "Manager.hpp"
#include "EmployeeClass.hpp"
#include "fstream"
#include "Food.hpp"
#include "Order.hpp"
#include "Table.hpp"

typedef void(*fp)();

class menu
{
	public:
		menu();
		~menu();
		
		void initMenu();
		void openRegister();
		void standardMenu();
		bool checkCashInput(std::string input);
		void dineIn();
		void phoneOrderPrompt();
		void takeout();
		void goToOrder(Order currOrder);
		void viewTheOrder(Order currOrder);
		void editItemMenu(Food food);
		void closingOrder(Order currOrder);
		void cashPayment(Order currOrder);
		void creditPayment(Employee employee, Order currOrder);
		void closingRegister();

	private:
		map<int, fp> initMenu;
		map<int, fp> standardMenu;
		map<int, fp> foodMenu;
		Register reg;
		Display display;
		Employee *openingEmployee, *currEmployee;
		Employee *manager, *worker1, *worker2, *worker3;
		
		vector<Order> orders;
		vector<Food> nonAlcoholic, alcoholic, 
				alaCarte, appetizer, dessert;
}
