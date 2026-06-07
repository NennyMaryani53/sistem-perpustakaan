#include "stack.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

stack<string> riwayat;

// load dari file ke stack
void loadData() {
    ifstream file("riwayat/riwayat.txt");

    vector<string> data;
    string aktivitas;

    while(getline(file, aktivitas)) {
        data.push_back(aktivitas);
    }

    file.close();

    for(int i = 0; i < data.size(); i++) {
        riwayat.push(data[i]);
    }
}

// simpan stack ke file
void simpanData() {
    ofstream file("riwayat/riwayat.txt");

    stack<string> temp = riwayat;
    vector<string> data;

    while (!temp.empty()) {
        data.push_back(temp.top());
        temp.pop();
    }

    for(int i = data.size() - 1; i >= 0; i--) {
        file << data[i] << endl;
    }

    file.close();
}

// tambah aktivitas
void pushRiwayat(string aktivitas) {
    riwayat.push(aktivitas);

    simpanData();

    cout << "Riwayat berhasil ditambahkan.\n";
}

void tampilRiwayat() {
    if(riwayat.empty()) {
        cout << "Riwayat kosong.\n";
        return;
    }

    stack<string> temp = riwayat;

    cout << "\n====== Riwayat Aktivitas ======\n";

    while(!temp.empty()) {
        cout << "- " << temp.top() << endl;
        temp.pop();
    }
}

void undoAktivitas() {
    if(riwayat.empty()) {
        cout << "Tidak ada aktivitas untuk di-undo.\n";
        return;
    }

    cout << "Undo : " << riwayat.top() << endl;

    riwayat.pop();
    
    simpanData();
}
