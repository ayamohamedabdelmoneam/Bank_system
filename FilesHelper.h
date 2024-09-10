#ifndef FILESHELPER_H
#define FILESHELPER_H
#include<iostream>
#include<string>
#include<vector>
#include "FileManager"

using namespace std;

class FilesHelper {
public:
    static void saveLast(string& fileName, int id) {
      ofstream file(fileName, ofstream::out | ofstream::trunc);
        file << id;
        file.close();
    }

    static int getLast(string& fileName) {
      ifstream file(fileName);
        int lastId = 0;
        if (file.is_open()) {
            file >> lastId;
            file.close();
        }
        return lastId;
    }

    static void saveClient( Client& client) {
        FileManager fm;
        fm.addClient(client);
    }

    static void saveEmployee(string& fileName, const string& lastIdFile, const Employee& employee) {
        FileManager fm;
        fm.addEmployee(employee);
        saveLast(lastIdFile, employee.getId());
    }

    static vector<Client> getClients() {
        FileManager fm;
        return fm.getAllClients();
    }

    static vector<Employee> getEmployees() {
        FileManager fm;
        return fm.getAllEmployees();
    }

    static vector<Employee> getAdmins() {
        FileManager fm;
        return fm.getAllAdmins();
    }

    static void clearFile(string& fileName, string& lastIdFile) {
        FileManager fm;
        if (fileName == "Clients.txt") fm.removeAllClients();
        else if (fileName == "Employees.txt") fm.removeAllEmployees();
        else if (fileName == "Admins.txt") fm.removeAllAdmins();
        saveLast(lastIdFile, 0);
    }
};

#endif // FILESHELPER_H
