#include <"headers/Menu.hpp">

#include "Manager.hpp"
#include "EmployeeClass.hpp"
#include <fstream>
#include <iostream>
#include <vector>

typedef void(*fp) ();

Menu::Menu() {
	//initMenu map
        initMenu[0] = openRegister;
        initMenu[1] = employees;
        initMenu[9] = quit;

	//standardMenu map
        standardMenu[1] = dineIn;
        standardMenu[2] = phoneOrderPrompt;
        standardMenu[3] = takeout;
        standardMenu[4] = checkAllOrders;
        standardMenu[5] = editMenu;
        


	vector<Food> nonAlcDrink;
        vector<Food> alcDrink;
        vector<Food> alaCarte;
        vector<Food> appetizers;
        vector<Food> desserts;

	//foodMenu map
        foodMenu[1] = addMenu(appetizers); 
        foodMenu[2] = addMenu(alaCarte);
        foodMenu[3] = addMenu(desserts);
        foodMenu[4] = addMenu(nonAlcDrink);
        foodMenu[5] = addMenu(alcDrink);
        foodMenu[6] = viewEditOrder;
        foodMenu[7] = closeOrder;
        foodMenu[0] = ;//go back twice
	
	Display display = new Display();
	Employee manager = new Manager("James", 1, 01, 8);
        Employee worker1 = new Worker("Albert", 2, 02, 8);
        Employee worker2 = new Worker("Daniel", 2, 03, 8);
        Employee worker3 = new Worker("David", 2, 04, 4);
        manager.add(worker1);
        manager.add(worker2);
        manager.add(worker3);
	Orders orders = new Orders();
	Employee openingEmployee*, currEmployee*;
	//put all food in their correct arrays 	
	
	ifstream inFile;
	string foodName;
	double foodPrice;
	int foodType;
	int orderNum = 0;

	inFile.open("foodItem.txt");
	if (!inFile) {
		cout << "Unable to open the file" << endl;
		exit(1); // terminate with error
	}
	while (inFile >> foodName >> foodPrice >> foodType) {
		if (foodType == 0) {
			nonAlcoholic.push_back(new Food(foodName,foodPrice));
		}
		else if (foodType == 1) {
			alcoholic.push_back(new Food(foodName, foodPrice));
		}
		else if (foodType == 2) {
			alaCarte.push_back(new Food(foodName, foodPrice));
		}
		else if (foodType == 3) {
			appetizer.push_back(new Food(foodName, foodPrice));
		}
		else if (foodType == 4) {
			dessert.push_back(new Food(foodName, foodPrice));
		}
	}
}

void Menu::initMenu() {
	char input;	

	display.initialMenu();
	//input funcion
	 
	while(getline(cin,input))
		try
		{
			initMenu.at(stoi(input))();
			display.initialMenu();
		}
		catch(...)
		{
			display.wrongInput();
		}
}

void Menu::openRegister() {
	bool cashInput = false;

	display.passwordPrompt();
	int password;
	std::cin >> password;
	if(manager.checkPassword(password));
		openingEmployee = manager.getEmployeeFromPassword(password);
	else
		return;
	
	display.cashStartPrompt();
	// Try to get a double input that is either number or double with period
	do{
		getline(cin,input);
		if(this.checkCashInput(input))
			cashInput = true;
		else
			display.wrongPrompt();
	} while (!cashInput);
	
	// Properly display open
	reg = new Register(stod(input));
	display.openRegister(reg.getStartingCash(), openingEmployee.getName(), reg.getStartingTime());

	// Set opening employee as opening employee
	currEmployee = openingEmployee;
	
	// Go to Standard Menu
	standardMenu();
}

void Menu::standardMenu() {
	string input;	

	do{
		display.standardMenu();
		
		while(getline(cin,input))
                try
                {
                        standardMenu.at(stoi(input))();                       
                }
                catch(...)
                {
                        display.wrongInput();
                }
	}while(true);
}

bool checkCashInput(std::string input){
	int location;
        for(int i = 0; i < input.length(); i ++){
        	if(input.at(i) == '.'){
                	location = i;
                }	
	}
        if(location + 2 > input.length()){
                return false;
        }
        std::string finalHalf = input.substr(location+1)
        std::string begHalf = input.substr(0, location)
        for( int i = 0; i < finalHalf.length(); i++){
                if( int(finalHalf.at(i))<48 || int(finalHalf.at(i)) > 57){
                	return false;
                }
        }
        for( int i = 0; i < begHalf.length(); i++){
                if( int(begHalf.at(i))<48 || int(begHalf.at(i)) > 57){
                	return false;
                }
        }
        return true;
}

void Menu::dineIn() {
	std::string input;
	
	bool currLoop = true;

	do{
		display.dineInTableDisplay();

		while(getline(cin,input))
		try
		{
			if(stoi(input) == 0)
				return;
			if(stoi(input) <= tables.size())
			{
				//iterate to table and create order
				//if table -> empty (no order)
				orderNum += 1;
				Order order = new Order(currEmployee, stoi(input), orderNum);
				orders.push_back(order);
				goToOrder(order); //or to the order at the table

				currLoop = false;
			}
			else
				display.incorrectTable();
		}
		catch(...)
		{
			display.incorrectTable();
		}
	
	}while(currLoop);
}

void Menu::phoneOrderPrompt() {
	std::string input;
	long int phoneNum;
	bool currloop = true;

	display.passwordPrompt();
        int password;
        std::cin >> password;
        if(!manager->checkPassword(password){
                std::cout << "Invalid password" << std::endl;
                return;
        }
        currEmployee = manager->getEmployeeFromPassword(password);

	display.phonePrompt();
	do{
		getline(cin,input);
		try
		{
			phoneNum = stol(input);
			currloop = false;				
		}
		catch(...)
		{
			display.onlyNum();
		}
	}(currloop)

	display.namePrompt();	
	getline(cin,input);
	orderNum += 1;
	Order order = new Order(*currEmployee, phoneNum, input, orderNum);
	orders.push_back(order);
	goToOrder(order);

	return;
}

void Menu::takeout() {
	display.passwordPrompt();
        int password;
	std::cin >> password;
	if(!manager->checkPassword(password){
		std::cout << "Invalid password" << std::endl;
		return;
	}
	currEmployee = manager.getEmployeeFromPassword(password);
	orderNum += 1;
	Order order = new Order(*currEmployee, orderNum);
	orders.push_back(order);
	goToOrder(order);

	return;
}

void Menu::goToOrder(Order currOrder) {
	display.initMenu(currOrder);
	while(getline(cin,input)){
        	try { 	
			if(stoi(input) == 0) return;
          		foodMenu.at(stoi(input))();  
			display.initMenu(currOrder);
        	}
        	catch(...)
        	{
            		display.wrongInput();
        	}
	}
}

void Menu::viewTheOrder(Order currOrder) {
	display.viewOrder(currOrder);
	while(getline(cin,input)){
                try {   
                        if(stoi(input) == 0) return;
			if(stoi(input) <= order->getFood().size() && stoi(input) > 0) {
				editItemMenu(order->getFood().at(stoi(input)));
			} 
                }
                catch(...)
                {
                        display.wrongInput();
                }
        }

}

void Menu::checkAllOrders(){
display.viewAllOrders(Orders orders);
while(getline(cin,input)){
	try {
            if(stoi(input) == 0) return;
            if(stoi(input) <= orders().size() && stoi(input) > 0) {
		OrdersIterator* iterator = orders->create_iterator();
		int ctr = stoi(input);
		while(ctr != 0 ){
			iterator->first();			
			iterator->next();
		}		
 	       	goToOrder(iterator->current());
		delete iterator;
            }
           catch(...)
                {
                        display.wrongInput();
                }
        }

}

void Menu::editItemMenu(Food food) {
	display.foodItemEdit(food);
	while(getline(cin,input)){
                try {   
                        if(stoi(input) == 0) return;
                        if(stoi(input) == 1 {
                                changeFoodQuantity(food);
                        } 
			if(stoi(input) == 2 {
                                delete food;
                        }
                }
                catch(...)
                {
                        display.wrongInput();
                }
        }
}

void Menu::changeFoodQuantity(Food food){
	display.changeQuantity();
	while(getline(cin,input)){
                try {
			if(stoi(input) <= 0) {
				delete food; 
				return;		
			}
                        food.setFoodQuantity(stoi(input));
			return;
                }
                catch(...)
                {
                        display.wrongInput();
                }
        }
	
}

void Menu::closingOrder(Order currOrder) {
	display.closingOrder();
	while(getline(cin,input)){
                try {
                        if(stoi(input) == 1) {
                                this.cashPayment(currOrder);
				return;
                        } 
			if(stoi(input) == 2) {
                                this.creditPayment(currOrder);
				return;
                        }
			
                }
                catch(...)
                {
                        display.wrongInput();
                }
        }	
	//check 1 or 2 for cash or credit or 0 to go back to order
	OrderIterator* order_it  = orders.create_iterator();
	order_it->first();
	int i = 0;
	while(!order_it->is_done()){
		if(order_it->current() == currOrder()){
			orders.erase(orders.begin() + i);
		}
		i++;
	}
}

void Menu::cashPayment(Order currOrder) {
	display.cashPrompt();
	//use function to verify, if number is a double in correct format
	std::string cashAmount;
	std::cin >> cashAmount;
	if(this.checkCashInput(cashAmount){
		currOrder.balance() = 0;
	} else {
		std::cout << "Invalid cash input" << std::endl;
		return;
	}
	double change = cashAmount - currOrder.balance;
	if(change > 0){
		std::cout << "Change was: " << change << std::endl;
		reg.addCash();
		this.closingOrder(currOrder);
	} else {
		this.closingOrder(currOrder);		
	}
	//deduct the order balance to 0 and if it is 0 close the order
	//show how much change from order
}

void Menu::creditPayment(Employee employee, Order currOrder) {
	display.tipPrompt();
	double tip;
	std::cin >> tip;
	employee.tip += tip;
	currOrder.getBalance() = 0;
	reg.addCredit();
	this.closingOrder(currOrder);
	
}

void Menu::closingRegister() {

	display.passwordPrompt();
	getline(cin,input);
	if(Employees.checkPw(input));
		openingEmployee = employeeList.getEmployee(input);
	else
		return
	
	display.confirmation();
	getline(cin,input);
	if(input == "y")
	{
		display.closingRegister(Register reg);
		initMenu();
	}
	else
		return 
}

void Menu::addMenu(Order* order, vector<Food> food){
	display.displayFoodMenu(food);
	while(getline(cin,input)){
                try {
			if(stoi(input) == 0) return;
                        if(stoi(input) <= food.size() && stoi(input) > 0) {
                                order->addFood(food.at(stoi(input) + 1);
				display.added(food);
                        }
                }
                catch(...)
                {
                        display.wrongInput();
                }
        }

}

void Menu::quit() {
	exit();
	//ask for employee pw
	//ask for are you sure
	display.closingRegister(reg);
	//go back to init Menu 
	display.passwordPrompt();
        int password;
        std::cin >> password;
        if(!manager->checkPassword(password){
                std::cout << "Invalid password" << std::endl;
                return;
        }
	display.closingRegister(Register reg);
	return;
	//go back to init Menu
}

