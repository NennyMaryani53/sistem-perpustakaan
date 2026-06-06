#include "anggota.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Anggota* head = NULL;

// load dari file ke Linked List
void loadData() {
    ifstream file("anggota/anggota.txt");

    string line;

    while(getline(file, line)) {
        stringstream ss(line);

        string idstr, nama;

        getline(ss, idstr, '|');
        getline(ss, nama);

        Anggota* baru = new Anggota;
        baru->id = stoi(idstr);
        baru->nama = nama;
        baru->next = NULL;

        if(head == NULL) {
            head = baru;
        }else{
            Anggota* temp = head;

            while(temp->next != NULL)
                temp = temp->next;

            temp->next = baru;
        }
    }

    file.close();
}

// simpan Linked List ke file
void simpanData() {
    ofstream file("anggota/anggota.txt");
    
    Anggota* temp = head;

    while(temp != NULL) {
        file << temp->id << "|" << temp->nama << endl;
        temp = temp->next;
    }

    file.close();
}

void tambahAnggota() {
    Anggota* baru = new Anggota;

    cout << "ID Anggota : ";
    cin >> baru->id;
    cin.ignore();

    cout << "Nama Anggota : ";
    getline(cin, baru->nama);

    baru->next = NULL;

    if(head == NULL) {
        head = baru;
    }else{
        Anggota* temp = head;

        while(temp->next != NULL) 
            temp = temp->next;

        temp->next = baru;
    }

    simpanData();

    cout << "Anggota berhasil ditambahkan.\n";
}

void tampilAnggota() {
    if(head == NULL) {
        cout << "Data anggota kosong.\n";
        return;
    }

    Anggota* temp = head;

    cout << "\n====== Daftar Anggota ======\n";
    while(temp != NULL) {
        cout << "ID   : " << temp->id << endl;
        cout << "Nama : " << temp->nama << endl;
        cout << "------------------\n";

        temp = temp->next;
    }
}

void cariAnggota() {
    int idCari;

    cout << "Masukkan ID : ";
    cin >> idCari;

    Anggota* temp = head;

    while(temp != NULL) {
        if(temp->id == idCari) {
            cout << "\nData ditemukan\n";
            cout << "ID   : " << temp->id << endl;
            cout << "Nama : " << temp->nama << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Anggota tidak ditemukan.\n";
}

void hapusAnggota() {
    int idHapus;

    cout << "Masukkan ID yang akan di hapus : ";
    cin >> idHapus;

    if(head == NULL) {
        cout << "Data kosong.\n";
        return;
    }

    if(head->id == idHapus) {
        Anggota* hapus = head;
        head = head->next;

        delete hapus;
        simpanData();

        cout << "Anggota berhasil dihapus.\n";
        return;
    }

    Anggota* temp = head;

    while(temp->next != NULL && temp->next->id != idHapus) {
        temp = temp->next;
    }

    if(temp->next == NULL) {
        cout << "Anggota tidak ditemukan.\n";
        return;
    }

    Anggota* hapus = temp->next;
    temp->next = hapus->next;

    delete hapus;

    simpanData();

    cout << "Anggota berhasil dihapus.\n";
}
