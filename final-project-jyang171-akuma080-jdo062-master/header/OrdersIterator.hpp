#ifndef __ORDER_ITERATOR_HPP__
#define __ORDER_ITERATOR_HPP__

#include <stack>
#include <vector>
#include "Orders.hpp"
#include "Oreder.hpp"

class Orders;


class OrderIterator {

    public:
        OrderIterator(Orders* ptr) {
            this->self_ptr = ptr;
        }

        void first() {
                index = 0;
        }
        void next() {
                index += 1;
        }
        bool is_done(){
                return index == self_ptr->getOrders().size() - 1;
        }
        Order current() {
                return self_ptr->getOrders().at(index);
        }

    private:
        int index;
        Orders* self_ptr;
};

