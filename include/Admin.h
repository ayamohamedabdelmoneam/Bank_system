#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
using namespace std;
#include <string>
#include "Person.h"
#include "Validation.h"

class Admin :public Employee, public Validation {
public:
	Admin() {}
	Admin(string name, string password, int id, double salary) :Employee(name, password, id, salary) {
	}
	void display()override {
		Employee::display();
	}
};


#endif // ADMIN_H
