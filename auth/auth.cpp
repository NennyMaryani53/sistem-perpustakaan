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
    string username, password;
    string id, user, pass, role;
    int lastId = 0;

    cout << "\n====== Register user ======\n";
    cout << "Username : ";
    cin >> username;

    cout << "Password : ";
    cin >> password;

    // ambil ID terakhir
    ifstream baca("auth/user.txt");

    if(!baca.is_open()) {
        cout << "File user.txt tidak ditemukan!\n";
        return;
    }

    while(getline(baca, id, '|')) {
        getline(baca, user, '|');
        getline(baca, pass, '|');
        getline(baca, role);

        // cek username duplikat
        if(username == user) {
            cout << "\nUsername sudah digunakan!\n";
            baca.close();
            return;
        }
        lastId = stoi(id);
    }

    baca.close();

    // simpan user baru
    ofstream file("auth/user.txt", ios::app);

    if(!file.is_open()) {
        cout << "Gagal membuka file user.txt!\n";
        return;
    }

    file << endl 
         << lastId + 1
         << "|" << username
         << "|" << password
         << "|user";

    file.close();

    cout << "\nRegistrasi berhasil!\n";
    cout << "ID User : " << lastId + 1 << endl;
}
