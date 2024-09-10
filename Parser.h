#ifndef PARSER_H
#define PARSER_H
#include<iostream>
#include<string>
#include <sstream>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

class Parser {
public:
    // a. Split the line into components based on a delimiter
    static void split(const string& line, string parts[], int& count, char delimiter = ',') {
        string temp = "";
        count = 0;
        for (char ch : line) {
            if (ch == delimiter) {
                parts[count++] = temp;
                temp = "";
            }
            else {
                temp += ch;
            }
        }
        parts[count++] = temp;
    }

    // b. Parse a string to a Client object
    static Client parseToClient(const string& line) {
        string parts[4];
        int count = 0;
        split(line, parts, count);

        if (count != 4) {
            throw invalid_argument("Invalid input for Client");
        }

        int id = stoi(parts[0]);
        string name = parts[1];
        string password = parts[2];
        double balance = stod(parts[3]);

        return Client(id, name, password, balance);
    }

    // c. Parse a string to an Employee object
    static Employee parseToEmployee(const string& line) {
        string parts[4];
        int count = 0;
        split(line, parts, count);

        if (count != 4) {
            throw invalid_argument("Invalid input for Employee");
        }

        int id = stoi(parts[0]);
        string name = parts[1];
        string password = parts[2];
        double salary = stod(parts[3]);

        return Employee(id, name, password, salary);
    }

    // d. Parse multiple lines to populate an Admin object
    static Admin parseToAdmin(const string lines[], int lineCount) {
        Admin admin;

        for (int i = 0; i < lineCount; ++i) {
            string parts[4];
            int count = 0;
            split(lines[i], parts, count);

            if (parts[3].find('.') != string::npos) {
                admin.clients[admin.clientCount++] = parseToClient(lines[i]);
            }
            else {
                admin.employees[admin.employeeCount++] = parseToEmployee(lines[i]);
            }
        }
        return admin;
    }
};
#endif // PARSER_H
