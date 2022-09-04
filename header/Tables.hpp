#ifndef __TABLES_HPP__
#define __TABLES_HPP__

#include <string>
#include "EmployeeClass.hpp"
#include <vector>
#include "TablesIterator.hpp"
#inlcude "Table.hpp"

#define MAX_TABLE_NUM 20  // max number of table of the resturant

using namespace std;

class Tables {
private:
    vector<Table> tableVector;

public:
    Tables() {
        for (int i = 1; i <= MAX_TABLE_NUM; i++) {
            tableVeactor.push_back(new Table(i, 0));
        }
    };

    TablesIterator* create_iterator() { return new TablesIterator(this); };

    vector<Table> getTables() { return tableVector; };

};

#endif //__TABLES_HPP__
