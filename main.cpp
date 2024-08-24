#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;
#include <string>
#include "Person.h"
#include "Validation.h"
#include "Empolyee.h"
#include "Client.h"
#include "Admin.h"


int main()
{
     // Test Client class
    Client client1(1, "Aya" , "Aya2000" , 2000)
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

    return 0;
}
