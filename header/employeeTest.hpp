#ifndef __EMPLOYEE_TEST_HPP__
#define __EMPLOYEE_TEST_HPP__

#include "gtest/gtest.h"
#include "EmployeeClass.hpp"
#include "Manager.hpp"
#include "Worker.hpp"

TEST(EmployeeTest, BasicEmployee){
	Employee* manager = new Manager("James", 1, 10, 8);
        Employee* worker1 = new Worker("Albert", 2, 11, 8);
        Employee* worker2 = new Worker("Daniel", 2, 12, 8);
        Employee* worker3 = new Worker("David", 2, 13, 4);
        manager->add(*worker1);
        manager->add(*worker2);
        manager->add(*worker3);
	EXPECT_EQ(manager->getName(), "James");
	EXPECT_EQ(manager->getEmployees().at(0)->getName(), "Albert");
	EXPECT_EQ(manager->getLevel(), 1);
	EXPECT_EQ(manager->getPassword(), 10);
        EXPECT_EQ(manager->getHours(), 8);
	EXPECT_EQ(worker1->getName(), "Albert");
        EXPECT_EQ(worker1->getLevel(), 2);
	EXPECT_EQ(worker1->getPassword(), 11);
        EXPECT_EQ(worker1->getHours(), 8);
	EXPECT_EQ(manager->checkPassword(12), true);
	EXPECT_EQ((manager->getEmployeeFromPassword(12))->getName(), "Daniel");
	manager->remove(*worker2);
	EXPECT_EQ(manager->checkPassword(12), false);
}

#endif

