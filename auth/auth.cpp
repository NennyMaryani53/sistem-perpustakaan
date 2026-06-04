#include "auth.h"
#include<iostream>
#include<fstream>
using namespace std;

void login() {
    string username, password;
    string id, user, pass, role;

    cout << "\n==== LOGIN ====\n";
    cout << "Username : ";
    cin >> username;

    cout << "Password : ";
    cin >> password;

    ifstream file("auth/user.txt");

    while (getline(file, id, '|')) {
        getline(file, user, '|');
        getline(file, pass, '|');
        getline(file, role);

        if(username == user && password == pass) {
            file.close();
            cout << "\nLogin berhasil sebagai " << role << endl;
            return;
        }
    }

    cout << "\nUsername atau password salah!\n";
    file.close();
}

void registerUser() {

}