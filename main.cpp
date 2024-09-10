#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include <sstream>
#include<vector>
#include "Person.h"
#include "Validation.h"
#include "Empolyee.h"
#include "Client.h"
#include "Admin.h"
#include"FileManager"
#include "FilesHelper.h"
#include "DataSourceInterface.h"
#include "Parser.h"

using namespace std;

int main()
{
     // Test Client class
 Client client1("Aya" , "Aya2000" , 1, 2000);
    client1.display();
    client1.deposit(500);
    client1.withdraw(300);
    client1.checkBalance();
    Employee e("abdallah", "abdo123", 999, 4500), c1;
	Admin a;
	int id;
	cout << "please enter id : " << endl;
	cin >> id;
	string password;
	cout << "please enter the password : " << endl;
	cin >> password;
	if (e.login(id, password)) {
		e.display();
	}


    // Create an employee
    Employee emp1(201, "Aya", "adminPass", 7000);

    // Display employee info
    cout << "Employee Info: ";
    emp1.display();
Client client1(1, "Aya", "password123", 5000.0);
    Client client2(2, "Mohamed", "password456", 7000.0);

    FilesHelper::saveClient(client1);
    FilesHelper::saveClient(client2);

 vector<Client> clients = FilesHelper::getClients();
    for (const auto& client : clients) {
        client.display();
    }

    return 0;
}
