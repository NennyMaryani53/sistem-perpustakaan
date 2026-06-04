#ifndef ANGGOTA_H
#define ANGGOTA_H

#include <string>
using namespace std;

struct Anggota {
    int id;
    string nama;
    Anggota* next;
};

void tambahAnggota();
void tampilAnggota();
void cariAnggota();
void hapusAnggota();

#endif