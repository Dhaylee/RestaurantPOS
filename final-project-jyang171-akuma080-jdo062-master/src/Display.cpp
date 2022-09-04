#include <iostream>
#include "OrderIterator.hpp"
#include "Orders.hpp"
#include "Order.hpp"
void Display::initialMenu() {
std::cout<<"0: Open Register\n
	    1: Employees\n
	    9: Quit"<<std::endl;	
}

void Display::standardMenu() {
std::cout<<"1: Dine In\n
	    2: Phone Order\n
	    3: Takout\n
	    4: Check All Orders\n
	    5: Employees\n
	    6: Edit Menu\n
	    0: Close Register"<<std::endl;
}

void Display::dineInTableDisplay() {
std::cout<<//get all tables and display them//
	 <<std::endl;

std::cout<<"Enter table number you would like to edit: "<<std::endl;
}

void Display::phonePrompt() {
std::cout<<"Please input a phone number: ";
	//std::cin>>phoneNum;
}

void Display::namePrompt() {
std::cout<<"Please input name: ";
//std::cin>>name; ONLY TRIGGER IF PHONE NUMBER HAS NOT EXISTED BEFORE
}

void Display::initMenu(Order* order) {
std::cout<<"Order: "<< order->getOrderNumber()
	 <<"\n1: Appetizers\n
	    2: Ala Carte\n
	    3: Desserts\n
            4: Non-Alcoholic Drinks\n
            5: Alcoholic Drinks\n
            6: View and Edit Order\n
            7: Close Order\n
	    0: Exit to Main Menu"<<std::endl;
}


void Display::viewOrder(Order* order) {
std::cout<<"\nServer: "<< order->getServerName()
         <<"\n----------------------------" << std::endl;
	for(int i = 0; i < order->getFood().size(); i++){
		std::cout<<i+1<<" : "<<order->getFood().at(i).getFoodName<<" ("<<order->getFood().at(i).getFoodQuantity()<<")\n"<<std::endl;
	}
         <<"Enter item # to edit or 0 to back:"std::endl;

}
void Display::viewAllOrders(Orders orders){
OrdersIterator* iterator = orders.create_iterator();
for(int i = iterator->first(); !iterator->isdone(); iterator->next()){
	std::cout<<"\nOrderNum: " << iterator->current().getOrderNum()
         <<"\n----------------------------" << std::endl;
        for(int i = 0; i < iterator->current.getFood().size(); i++){
                std::cout<<i+1<<" : "<<iterator->current.getFood().at(i).getFoodName<<" ("iterator->current().getFood().at(i).getFoodQuantity()<<")\n"<<std::endl;
        }
}

void Display::foodItemEdit(Food food) {
std::cout<<"Changing Item: "<<food.getFoodName()
	 <<" ("<<good.getFoodQuantity()<<")\n
	    1: Change Quantity\n
	    2: Remove Item\n
	    0: Back"<<std::endl;
}

void Display::closingOrder() {
std::cout<<"1: Credit Card\n
	    2: Cash\n
	    0: Back"<<std::endl;
}

void Display::tipPrompt() {
std::cout<<"Enter tip amount: "<<std::endl;
}

void Display::cashPrompt() {
std::cout<<"Enter cash amount: "<<std::endl;
}

void Display::openRegister(double input, Employee x, Register reg) {
std::cout<<"Register Opening Report\n
        Opened: "<<reg.getStartingTime()
         <<"Opening by:        "<<x.getName()
         <<"\n\nStarting Cash:     "<<setprecision(2)<<input<<std::endl;
}

void Display::closeRegister(Register reg) {
std::cout<<"Register Closing Report\n"<<reg.getStartingTime()
         <<" - "<<reg.getCurrentTime()
 	 <<"\n\nTotal Orders:       "<<reg.getOrders()
	 <<"\n\nOpen by:       "<<reg.getOpenBy()
	 <<"\nOpen amount:        "<<reg.getStartingCash()
    	 <<"\n\nTotal Cash Sales:     "<<reg.getCashTotal()
	 <<"\nTotal Credit Sales:    "<<reg.getCreditTotal()
	 <<"\nTotal Tips:            "<<reg.getTips()
	 <<"\n\nExpected Amount:     "<<reg.getMoneyTotal()
         <<std::endl;
}
void Display::passwordPrompt(){
	std::cout<<"Please enter a password: " << std::endl;	
}

void Display::wrongInput(){
	std::cout<<"Invalid input. Please enter a valid input: " << std::endl;
}

void Display::cashStartPrompt() {
	std::cout<<"Enter starting cash amount: "<<std::endl;
}

void Display::incorrectTable() {
	std::cout<<"Please enter a valid table number!"<<std::endl;
}

void Display::onlyNums() {
	std::cout<<"Only numbers allowed!"<<std::endl;
}

void Display::confirmation() {
	std::cout<<"Are you sure? Enter y to continue. "<<std::endl;
}

void Display::changeQuantity() {
              std::cout<<"Change to what quantity?"<<std::endl;
}


void Display::changeQuantity() {
              std::cout<<"Change to what quantity?"<<std::endl;
}


void Display::displayFoodMenu(vector<food> food){
        for(int i = 0; i < food.size(); i++){
                std::cout<<i+1<<" : "<<food.at(i).getFoodName<<" ("<<food.at(i).getFoodPrice()<<")\n"<<std::endl;
        }
         <<"Enter item # to edit or 0 to back:"std::endl;
}
void Display::added(Food food){
	std::cout<<"Added: "<<food->getName<<std::endl;
}


