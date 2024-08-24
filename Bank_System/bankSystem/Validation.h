#ifndef VALIDATION_H
#define VALIDATION_H
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;
#include <string>
class Validation {
public :
	static bool isAlphabetic(string& name) {
		for (char ch : name) {
			if (!(ch >= 'A' && ch <= 'Z') && !(ch >= 'a' && ch <= 'z')) {
				return false;
			}
		}
		return true;
	}
	static bool	ValidateName(string name) {
		return name.length() >= 5 && name.length() <= 20 && isAlphabetic(name);
	}
	static bool ValidatePassword(string password) {
		return password.size() >= 5 && password.size() <= 20;
	}
	static bool ValidateBalance(double balance) {
		return balance >= 1500;
	}
	static bool ValidateSalary(double salary) {
		return salary >= 5000;
	}



};


#endif // VALIDATION_H
