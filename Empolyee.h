#ifndef EMPOLYEE_H
#define EMPOLYEE_H
#include <iostream>
using namespace std;
#include <string>
#include "Person.h"
#include "Validation.h"

class Employee :public Person, public Validation {
private:
	double salary;
public:
	Employee() {
		salary = 0.0;
	}
	Employee(string name , string password,int id ,double salary):Person(name,password,id) {
		this->salary = salary;
	}

	//setters
	void setSalary(double salary1) {
		if (Validation::ValidateSalary(salary1)) {
			salary = salary1;
		}
	}
	double getSalary() {
		return salary;
	}

	void display()override {
		Person::display();
		cout << "Salary = " << salary << endl;
		cout << "========================\n";
	}
};


#endif // EMPOLYEE_H
