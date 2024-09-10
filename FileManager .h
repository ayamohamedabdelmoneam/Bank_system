#ifndef FILEMANAGER _H
#define FILEMANAGER _H
#include <iostream>
#include<string>
#include <fstream>
#include <vector>
#include <sstream>
#include "DataSourceInterface.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
using namespace std;

class FileManager
{

public:
    // Adding Client to Clients.txt
    void addClient( Client& client) override {
        ofstream file("Clients.txt", ios::app);
        if (file.is_open()) {
            file << client.toString() << endl;;
            file.close();
        }
    }

    // Adding Employee to Employees.txt
    void addEmployee( Employee& employee) override {
       ofstream file("Employees.txt", ios::app);
        if (file.is_open()) {
            file << employee.toString() << endl;
            file.close();
        }
    }

    // Adding Admin to Admins.txt
    void addAdmin( Admin& admin) override {
       ofstream file("Admins.txt", ios::app);
        if (file.is_open()) {
            file << admin.toString() << endl;
            file.close();
        }
    }
 // Retrieve all clients from Clients.txt
    vector<Client> getAllClients() override {
        vector<Client> clients;
        ifstream file("Clients.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                Client client;
                client.fromString(line); // Assuming fromString() method parses the string into a Client object
                clients.push_back(client);
            }
            file.close();
        } else {
            cerr << "Unable to open Clients.txt for reading" << endl;
        }
        return clients;
    }

    // Retrieve all employees from Employees.txt
    vector<Employee> getAllEmployees() override {
        vector<Employee> employees;
        ifstream file("Employees.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                Employee employee;
                employee.fromString(line); // Assuming fromString() method parses the string into an Employee object
                employees.push_back(employee);
            }
            file.close();
        } else {
            cerr << "Unable to open Employees.txt for reading" << endl;
        }
        return employees;
    }

    // Retrieve all admins from Admins.txt
    vector<Admin> getAllAdmins() override {
        vector<Admin> admins;
        ifstream file("Admins.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                Admin admin;
                admin.fromString(line); // Assuming fromString() method parses the string into an Admin object
                admins.push_back(admin);
            }
            file.close();
        } else {
            cerr << "Unable to open Admins.txt for reading" << endl;
        }
        return admins;
    }

    // Remove all clients from Clients.txt
    void removeAllClients() override {
        ofstream file("Clients.txt", ios::trunc);
        if (file.is_open()) {
            file.close();
        } else {
            cerr << "Unable to open Clients.txt for truncation" << endl;
        }
    }

    // Remove all employees from Employees.txt
    void removeAllEmployees() override {
        ofstream file("Employees.txt", ios::trunc);
        if (file.is_open()) {
            file.close();
        } else {
            cerr << "Unable to open Employees.txt for truncation" << endl;
        }
    }

    // Remove all admins from Admins.txt
    void removeAllAdmins() override {
        ofstream file("Admins.txt", ios::trunc);
        if (file.is_open()) {
            file.close();
        } else {
            cerr << "Unable to open Admins.txt for truncation" << endl;
        }
    }

};

#endif // FILEMANAGER _H
