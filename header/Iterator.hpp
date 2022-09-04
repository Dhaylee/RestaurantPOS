#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

#include <stack>
//
//class Base

enum ChildIndicator { right, end };

class Iterator {
    protected:
        Tables* self_ptr;

    public:
        Iterator(Tables* ptr) { 
            this->self_ptr = ptr; 
        }

        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool is_done() = 0;
        virtual Tables* current() = 0;
};
