fndef REGISTER_H
#define REGISTER_H

#include <time.h>

class Register {
    
private:
    double cashTotal;
    double creditCardTotal;
    double tipTotal;
    unsigned int orders;
    time_t startTime;
    string openBy;
    
public:
    Register();
    Register(double c); //Starting with cash in register
    
   // void openRegister();
   // void closeRegister();
    double getCashTotal();
    double getCreditTotal();
    double getMoneyTotal();
    double getTips();
    double getStartingCash();
    time_t getCurrTime();
    string getOpenBy();
    unsigned int getOrders();   

    void addCredit(double c);
    void addCash(double c);
    void addTip(double c);
};

#endif // REGISTERCLASS_H
