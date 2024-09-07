#ifndef DATASOURCEINTERFACE_H
#define DATASOURCEINTERFACE_H
#include <iostream>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;


class DataSourceInterface
{
   public:
    virtual void addClient( Client& client) = 0;
    virtual void addEmployee( Employee& employee) = 0;
    virtual void addAdmin( Admin& admin) = 0;

    virtual vector<Client> getAllClients() = 0;
    virtual vector<Employee> getAllEmployees() = 0;
    virtual vector<Admin> getAllAdmins() = 0;

    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeAllAdmins() = 0;
};

#endif // DATASOURCEINTERFACE_H
