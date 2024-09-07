#ifndef FILEMANAGER _H
#define FILEMANAGER _H
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "DataSourceInterface.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
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


};

#endif // FILEMANAGER _H
