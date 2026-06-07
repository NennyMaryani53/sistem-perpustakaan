#include "queue.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>

using namespace std;

queue<Antrian> antrianPeminjaman;

void loadData() {
    ifstream file("peminjaman/antrian.txt");
    
    string line;
    
    while (getline(file, line)) {
        stringstream ss(line);
    
        string idstr;

        Antrian a;
        
        getline(ss, idstr, '|');
        
        if(idstr.empty()) {
            continue;
        }

        a.idAnggota = stoi(idstr);
    
        getline(ss, a.nama, '|');
        getline(ss, a.judulBuku, '|');
        getline(ss, a.tanggalPinjam);
    
        antrianPeminjaman.push(a);
    }
    
    file.close();
}



void simpanData() {
    ofstream file("peminjaman/antrian.txt");

    queue<Antrian> temp = antrianPeminjaman;

    while(!temp.empty()) {
        file << temp.front().idAnggota << "|"
             << temp.front().nama << "|"
             << temp.front().judulBuku << "|"
             << temp.front().tanggalPinjam << endl;

        temp.pop();
    }

    file.close();
}

void tambahAntrian() {
    Antrian a;

    cout << "ID Anggota : ";
    cin >> a.idAnggota;
    cin.ignore();

    cout << "Nama Peminjam : ";
    getline(cin, a.nama);

    cout << "Judul Buku : ";
    getline(cin, a.judulBuku);

    cout << "Tanggal Pinjam : ";
    getline(cin, a.tanggalPinjam);

    antrianPeminjaman.push(a);

    simpanData();

    cout << "Peminjaman masuk antrian.\n";
}

void tampilAntrian() {
    if(antrianPeminjaman.empty()) {
        cout << "Antrian kosong.\n";
        return;
    }

    queue<Antrian> temp = antrianPeminjaman;

    cout << "\n====== Daftar Antrian ======\n";
    while (!temp.empty()) {
        cout << "ID Anggota : "
             << temp.front().idAnggota << endl;

        cout << "Nama       : "
             << temp.front().nama << endl;

        cout << "Buku       : "
             << temp.front().judulBuku << endl;

        cout << "Tanggal    : "
             << temp.front().tanggalPinjam << endl;

        cout << "----------------------------\n";
        temp.pop();
    }
}

void layaniAntrian() {
    if(antrianPeminjaman.empty()) {
        cout << "Antrian kosong.\n";
        return;
    }

    cout << "\n====== Melayani Antrian ======\n";
    cout << "ID Anggota : " << antrianPeminjaman.front().idAnggota << endl;
    cout << "Nama       : " << antrianPeminjaman.front().nama << endl;
    cout << "Buku       : " << antrianPeminjaman.front().judulBuku << endl;
    cout << "Tanggal    : " << antrianPeminjaman.front().tanggalPinjam << endl;

    antrianPeminjaman.pop();

    simpanData();

    cout << "\nAntrian berhasil dilayani\n";
}
