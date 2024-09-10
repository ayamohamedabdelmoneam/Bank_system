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


	  // Add a new client
    void addClient(Client& client) {
        clients.push_back(client);
        cout << "Client added successfully!" << endl;
    }

    // Search for a client by ID
    Client* searchClient(int id) {
        for (auto& client : clients) {
            if (client.getId() == id) {
                return &client; // Return pointer to the found client
            }
        }
        return nullptr; // Return nullptr if client not found
    }

    // List all clients
    void listClient() {
        if (clients.empty()) {
            cout << "No clients available." << endl;
            return;
        }
        for (const auto& client : clients) {
            client.display(); // Assuming Client has a display() method
        }
    }

    // Edit client details by ID
    void editClient(int id, string name, string password, double balance) {
        Client* client = searchClient(id);
        if (client != nullptr) {
            client->setName(name);
            client->setPassword(password);
            client->setBalance(balance);
            cout << "Client details updated successfully!" << endl;
        } else {
            cout << "Client not found!" << endl;
        }
    }
};


#endif // EMPOLYEE_H
