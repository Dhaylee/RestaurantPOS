#ifndef __TABLES_ITERATOR_HPP__
#define __TABLES_ITERATOR_HPP__

#include <stack>
#include <vector>
#include "Tables.hpp"
#include "Table.hpp"

class Tables;


class TablesIterator {

    public:
        TablesIterator(Tables* ptr) {
            this->self_ptr = ptr;
        }
	
        void first() {
		index = 0;
	}
	void next() {
		index += 1;
	}
        bool is_done(){
		return index == self_ptr->getTables().size() - 1;
	}
        Table current() {
		return self_ptr->getTables().at(index);
	}

    private:
	int index;
	Tables* self_ptr;
};

#endif    
