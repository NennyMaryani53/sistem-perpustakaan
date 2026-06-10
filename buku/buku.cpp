#include "buku.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

namespace {
    const string FILE_BUKU = "buku/buku.txt";
}

vector<Buku> daftarBuku;

void loadBuku(){
    ifstream file(FILE_BUKU);

    if(!file.is_open()){
        return;
    }

    daftarBuku.clear();

    string baris;

    while(getline(file, baris)){
        stringstream ss(baris);

        Buku b;
        string stokStr;

        getline(ss, baris, '|');
        b.id = stoi(baris);

        getline(ss, b.judul, '|');
        getline(ss, b.penulis, '|');
        getline(ss, stokStr, '|');

        b.stok = stoi(stokStr);

        daftarBuku.push_back(b);
   }

   file.close();
}

void simpanBuku() {
    ofstream file(FILE_BUKU, ios::trunc);

    for(Buku b: daftarBuku){
        file << b.id << "|"
             << b.judul << "|"
             << b.penulis << "|"
             << b.stok << endl;
    }
     file.close();

}

void tambahBuku() {
    Buku b;
     cout << "ID buku :";
     cin >> b.id;
     cin.ignore();

     cout << "Judul Buku :";
     getline(cin, b.judul);

     cout << "Penulis :";
     getline(cin, b.penulis);

     cout << "Stok :";
     cin >> b.stok;

     daftarBuku.push_back(b);

     simpanBuku();

     cout << "\nBuku berhasil ditambahkan.\n";

}

void tampilBuku(){
    if(daftarBuku.empty()){
        cout << "\nData buku kosong.\n";
        return;
    }

    cout << "\n=== Daftar Buku ===\n";
    for(Buku b: daftarBuku){
        cout << "ID : " << b.id << endl;
        cout << "Judul : " << b.judul << endl;
        cout << "Penulis : " << b.penulis << endl;
        cout << "Stok : " << b.stok << endl;
        cout << "--------------------\n";
    } 

}

void editBuku(){

}

void hapusBuku(){

}
