#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include "Register.hpp"

class Display() {
	public:
		Display();
		~Display();
		
		void initialMenu();
		void standardMenu();
		void dineInTableDisplay();
		void phonePrompt();
		void namePrompt();
		void initMenu();
		void viewOrder(Table table);
		void viewOrder(Order order);
		void foodItemEdit(Food food);
		void closingOrder();
		void tipPrompt();
		void cashPrompt();
		void openRegister(double input, Employee x, Register reg);
		void closeRegister(Register reg);
		void passwordPrompt();
		void wrongInput();
		void cashStartPrompt();
		void incorrectTable();
		void onlyNums();
		void confirmation();
}
