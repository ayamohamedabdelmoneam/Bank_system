#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include "Validation.h"
using namespace std;
#include <string>
class Person {
protected :
	string name, password;
	int id;
public:
	// default constructor :
	Person(){
		id = 0;
	}
	//para const
	Person(string name , string password , int id) {
		this->name=name;
		this->password=password;
		this->id = id ;
	}
	//setters
	void setName(string name1 ) {
		if (Validation::ValidateName(name1)) {
			name = name1;
		}
		else {
			cout << "Invalid Name" << endl;
		}
	}
	void setPassword(string password1) {
		if (Validation::ValidatePassword(password1)) {
			password = password1;
		}
		else {
			cout << "Invalid Password" << endl;
		}
	}
	void setId(int id1) {
		id = id1;
	}
	//getters
	string getName() {
		return name;
	}
	string getPassword() {
		return password;
	}
	int getId() {
		return id;
	}

	//login

	bool login(int id, string password) {
		return this->id == id && this->password == password;
	}
	virtual void display() {
	    cout << "Name is " << name << endl;
		cout << "ID = " << id << endl;

	}
};


#endif // PERSON_H
