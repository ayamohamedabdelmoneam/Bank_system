#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
using namespace std;
#include <string>
#include "Person.h"
#include "Validation.h"

class Client : public Person , public Validation{

private:
	// Attributes
	double balance;
public:
	// Default
	Client()
	{
		balance = 0.0;

	}
	// Parametrized constructor
	Client(string name , string password,int id ,double balance):Person(name,password,id) {
	    	this -> name = name;
		this -> password = password;
		this -> id = id;

		if (Validation::ValidateBalance(balance)) {
			this ->balance = balance;
		}
		else {
			cout << "Invalid salary , minimum salary = 5000 " << endl;
		}

	}


	void setBalance(double balance1) {
		if (Validation::ValidateBalance(balance1)) {
			balance = balance1;
		}
	}


	double getBalance() {
		return balance;
	}

	// methods

	void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
		}
		else {
			cout << "Amount must be positive " << endl;
		}
	}
	void withdraw(double amount) {
		if (amount <= balance) {
			balance -= amount;
		}
		else {
			cout << "Amount must be equal or less than balance \n";
		}
	}
	void transferTo(double amount, Client& c1) {
		if (amount <= balance) {
			balance -= amount;
			c1.deposit(amount);
			cout << "Transferred " << amount << " to " << c1.getName() << ". New balance: " << balance << endl;
		}
		else {
			cout << "Insufficient balance!\n";
		}
	}

	void checkBalance() const {
		cout << "Current balance: " << balance << endl;
	}



	void display()override {
		Person::display();
		cout << "balance = " << balance << endl;
		cout << "========================\n";
	}
};

#endif // CLIENT_H
