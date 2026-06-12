#include "buku.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

vector<Buku> daftarBuku;

// ================= LOAD =================
void loadBuku() {
    ifstream file("buku/buku.txt");

    if (!file.is_open()) return;

    daftarBuku.clear();

    string line;

    while (getline(file, line)) {
        stringstream ss(line);

        Buku b;
        string idStr, stokStr;

        getline(ss, idStr, '|');
        getline(ss, b.judul, '|');
        getline(ss, b.penulis, '|');
        getline(ss, stokStr, '|');

        b.id = stoi(idStr);
        b.stok = stoi(stokStr);

        daftarBuku.push_back(b);
    }

    file.close();
}

// ================= SIMPAN =================
void simpanBuku() {
    ofstream file("buku/buku.txt");

    for (Buku b : daftarBuku) {
        file << b.id << "|"
             << b.judul << "|"
             << b.penulis << "|"
             << b.stok << endl;
    }

    file.close();
}

void tambahBuku(){
    Buku b;

    cout << "ID Buku: ";
    cin >> b.id;
    cin.ignore();

    cout << "Judul Buku: ";
    getline(cin, b.judul);

    cout << "Penulis : ";
    getline(cin, b.penulis);

    cout << "Stok: ";
    cin >> b.stok;

    daftarBuku.push_back(b);

    simpanBuku();

    cout << "\nBuku berhasil ditambahkan!";

}

void tampilBuku(){
    if(daftarBuku.empty()){
        cout << "\nTidak ada buku yang tersedia.\n";
        return;
    }

    cout << "\n=== DAFTAR BUKU ===\n";
    for(Buku b : daftarBuku){
        cout << "ID: " << b.id << endl;
        cout << "Judul: " << b.judul << endl;
        cout << "Penulis: " << b.penulis << endl;
        cout << "Stok: " << b.stok << endl;
        cout << "-----------------------\n";
    }
}


void editBuku(){
    int id;
    cout << "Masukan ID buku: ";
    cin >> id;
    cin.ignore();

    for(Buku &b : daftarBuku){
        if(b.id == id){
            cout << "Judul Buku: ";
            getline(cin, b.judul);

            cout << "Penulis : ";
            getline(cin, b.penulis);

            cout << "Stok: ";
            cin >> b.stok;
            cin.ignore();
            simpanBuku();
            cout << "\nBuku berhasil diupdate.\n";
            return;
        }
    }
    cout << "\nBuku tidak ditemukan.\n";
}

void hapusBuku(){
    int id;
    cout << "Masukan ID buku: ";
    cin >> id;

    for(int i=0; i<daftarBuku.size(); i++){
        if(daftarBuku[i].id == id){
            daftarBuku.erase(daftarBuku.begin() + i);
            simpanBuku();
            cout << "\nBuku berhasil dihapus.\n";
            return;
        }
    }
    cout << "\nBuku tidak ditemukan.\n";

}
