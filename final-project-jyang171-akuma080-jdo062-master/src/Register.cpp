nclude "Register.hpp"
#include <ctime>

Register::Register(string name) {
    this->cashTotal       = 0;
    this->creditCardTotal = 0;
    this->tipTotal        = 0;
    this->orders          = 0;
    this->startingCash    = 0;
    
    //get Current Time
    time_t currTime;
    this->startingTime    = time(NULL)

    this->openBy          = name;
}

Register::Register(double c, string name) {
    this->cashTotal       = c;
    this->creditCardTotal = 0;
    this->tipTotal        = 0;
    this->orders          = 0;
    this->startingCash    = c;
    
    //get Current Time
    time_t currTime;
    this->startingTime    = time(NULL)
   
    this->openBy          = name;
}

double Register::getCashTotal() {
    return this->cashTotal;
}

double Register::getCreditTotal() {
    return this->creditCardTotal;
}

double Register::getMoneyTotal() {
    return this->creditCardTotal + this->cashTotal + this->tipTotal;
}

double Register::getTips() {
    return this->tipTotal;
}

time_t Register::getCurrTime() {
    time_t currTime;
    return currTime = time(NULL);
}

double Register::getStartingCash() {
    return this->startingCash;
}

string Register::getOpenBy() {
    return this->openBy;
}

unsigned int Register::getOrders() {
    return this->orders;
}

void Register::addCredit(double c) {
    this->creditCardTotal += c
}

void Register::addCash(double c) {
    this->cashTotal += c
}

void Register::addTip(double c) {
    this->tipTotal += c
}

/* FOR DISPLAY
 * when closing register
 * 
 * Register Closing Report
 * (Start time) - (End time)
  
 * Total Orders         #orders
 * 
 * Open by                 name
 * Open amount              $$$ <-Starting Cash
 * 
 * Total Cash Sales         $$$
 * Total Credit Sales       $$$
 * Total Tips               $$$
 * 
 * Expected amount         $$$$
 */

/* FOR DISPLAY
 * when opening register
 * 
 * Register Opening Report
 * Opened: (Start Time)
 * Opening by               name
 * 
 * Starting Cash            $$$
 * /
