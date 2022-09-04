#ifndef __IT_TEST_HPP__
#define __IT_TEST_HPP__

#include "gtest/gtest.h"
#include "Orders.hpp"
#include "Order.hpp"
#include "OrdersIterator.hpp"
#include "Worker.hpp"
TEST(ItTest, BasicTest){
	Employee* worker = new Worker();
	Orders orders = new Orders();
	orders.getOrders().push_back(new Order(worker, 1, 0.0));
	orders.getOrders().push_back(new Order(worker, 2, 0.0));
	OrdersIterator* iterator = orders->create_iterator();
	iterator->first();
	EXPECT_EQ(iterator->current().getOrderNum(), 1);	
	iterator->next();
	EXPECT_EQ(iterator->current().getOrderNum(), 2);
        iterator->next();
	EXPECT_EQ(iterator->current(), nullptr);
	EXPECT_EQ(iterator->is_done(), true);

}

#endif
