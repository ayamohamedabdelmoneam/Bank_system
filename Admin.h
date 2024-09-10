#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
using namespace std;
#include <string>
#include "Person.h"
#include "Validation.h"

class Admin :public Employee, public Validation {
    private:
    vector<Client> clients;
    vector<Employee> employees;

public:
	Admin() {}
	Admin(string name, string password, int id, double salary) :Employee(name, password, id, salary) {
	}
	void display()override {
		Employee::display();
	}
	// a. Add a client
    void addClient(Client& client) {
        clients.push_back(client);
    }

    // b. Search for a client by id
    Client* searchClient(int id) {
        for (auto& client : clients) {
            if (client.id == id) {
                return &client;
            }
        }
        return nullptr;
    }

    // c. List all clients
    void listClients() {
        for (int i = 0; i < clientCount; ++i) {
            cout << "ID: " << clients[i].id << ", Name: " << clients[i].name << ", Balance: " << clients[i].balance << endl;
        }
    }

    // d. Edit a client
    void editClient(int id, string name, string password, double balance) {
        Client* client = searchClient(id);
        if (client != nullptr) {
            client->name = name;
            client->password = password;
            client->balance = balance;
        }
        else {
          cout << "Client not found\n";
        }
    }

    // e. Add an employee
    void addEmployee(Employee& employee) {
        employees.push_back(employee);
    }

    // f. Search for an employee by id
    Employee* searchEmployee(int id) {
        for (int i = 0; i < employeeCount; ++i) {
            if (employees[i].id == id) {
                return &employees[i];
            }
        }
        return nullptr;
    }

    // g. Edit an employee
    void editEmployee(int id, std::string name, std::string password, double salary) {
        Employee* employee = searchEmployee(id);
        if (employee != nullptr) {
            employee->name = name;
            employee->password = password;
            employee->salary = salary;
        }
        else {
            cout << "Employee not found\n";
        }
    }

    // h. List all employees
    void listEmployees() {
        for (int i = 0; i < employeeCount; ++i) {
            cout << "ID: " << employees[i].id << ", Name: " << employees[i].name << ", Salary: " << employees[i].salary << endl;
        }
    }
};


#endif // ADMIN_H
