/*
*******************************************
Student #1 data :
ID : 2201****
Name : Sacabambaspis
*/

#include <iostream>
#include <string>
using namespace std;

struct Students {
    int id;
    string name;
    string phoneNum;
    string email;
};

int main() {
    Students std[5];
    for (int i = 0; i < 5; i++)  {
        cout << "Enter ID for student #" << i+1 << " : ";
        cin >> std[i].id;
        cin.ignore();
        
        cout << "Enter name for student #" << i + 1 << ": ";
        getline(cin, std[i].name);

        cout << "Enter phone number for student #" << i + 1 << ": ";
        getline(cin, std[i].phoneNum);

        cout << "Enter email for student #" << i + 1 << ": ";
        getline(cin, std[i].email);

    }
    
    for (int i = 0; i < 5; i++) {
        cout << "*******************************************";
        cout << "Student #" << i+1 << " Data :\n";
        cout << "ID : " << std[i].id << endl;
        cout << "Name : " << std[i].name << endl;
        cout << "Phone Number : " << std[i].phoneNum << endl;
        cout << "Email : " << std[i].email << endl;
    }
    return 0;
}