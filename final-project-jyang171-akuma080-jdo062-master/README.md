# Restaurant Order
  Authors: \<[Justin Do](https://github.com/Dhaiylee)\> \<[Akshay Kumar](https://github.com/akshayk2001)\> \<[Jianeng Yang](https://github.com/JohnnyY0618)\>
 
## Project Description
  * We are interested in how a restaurant pos system works, and send the result to the user. This is interesting because we can learn how a restaurant stays organized through a simple pos system.
  * For languages/tools/technologies, We plan to use are: (This list may change over the course of the project)
    * C++ - programming language 
    * Terminal base application
  * Input: orders (by user or waitress), employee information (hours, pay, or name), seating (which seats are occupied) 
  * Output: sales (total net intake of money based on cash and credit), receipts for a table when it is done
  * Our 3 design patterns are composite, Iterator, command.
    * Composite - The composite pattern allows users to work with individual objects (menus) and composite objects (submenus) in a consistent manner (inherited from the same superclass), which means we can ignore the differences between individual objects and composite objects (inherited from the same superclass). We will take in data inputted from the employee and distribute it to table classes which will categorize the different food types such as alcoholic drinks, regular drinks, main dishes, desserts, etc. 
    * Iterator - It provides a method for sequentially accessing the individual elements of an aggregate object without exposing its internal representation. The restaurant class uses an iterator class to create its own iterator instance for the caller to use, and the caller only needs this iterator instance to access all its menus. For example, we have two menus, one for breakfast and one for lunch, both with their own menus, which are now going to be combined. This means we order directly through the waitress iterator to print or get the information.
    * Command - Where the command pattern applies there are usually two roles, the requester and the enforcer/receiver. In a restaurant, for example, the customer and the chef represent the requester and the executor respectively, and the waiter in the restaurant is like a remote control. The customer orders from the waiter and the waiter passed the order to the chef, and the customer has to pass the order to the chef indirectly through the role of the waiter. It is flexible enough to collect more orders from the waiter and waitress before informing the kitchen.


## Class Diagram
  * Description: The display class inherits the data from menu class where most of the functions will be run on. The display class will take the data and neatly display them on the terminal with options for input using single digit numbers. The iterator design pattern is utilized in the menu class to create a display iterator which needs to go through the array of table objects which can be classified as either active or inactive. The command design is utilized when closing or opening a shift. Depending which one it is currently on, it will perform the correct function as you cannot double close or double open. The order class utilizes the composite design to handle the food objects or just to show that a table is active with people in seating. It will decide how each of the food items will be handled which will affect how the display will be shown. For example, alcoholic drinks need to be handled differently than non-alcoholic.
![Diagram](https://user-images.githubusercontent.com/72288397/99347426-f69bdc80-284b-11eb-89b5-fecc651df23d.png)
 
 ## Screenshots
![Screen Shot 2020-12-11 at 11 04 15 AM](https://user-images.githubusercontent.com/13615067/101946762-3f715780-3ba4-11eb-8a13-745cda21f7fb.png)
 ## Installation/Usage
git clone https://github.com/cs100/final-project-jyang171-akuma080-jdo062.git
cd final-project-jyang171-akuma080-jdo062/
This project uses cmake3 as well as make. These tools are available on Linux, and can be installed from their respective websites. After they’re installed, the following commands can be run to create executables. Optionally, Valgrind can also be installed to check for memory leaks in the program.
cmake3 .
make
The test executable will be generated under:
./test 
Then you can initiate the program and select your input to open the register. Once you have opened the register you can select from an array of options to either generate a takeout, dinein, or phone order, as well as check all orders, check employees, and edit menu. Any of these options will take you through another set of options which are explained in the printed statements to help guide you.
 ## Testing
After following the instructions in the Installation/Usage section to generate the executables, running ./test will run the unit tests for this program. These are used to verify functionality of each of the different classes in the program, confirming that each of them work as intended. Overall for this project, we had a few unit tests to test certain parts of our program.

 
