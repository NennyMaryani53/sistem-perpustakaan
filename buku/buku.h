#ifndef BUKU_H
#define BUKU_H

#include <string>
using namespace std;

struct Buku {
    int id;
    string judul;
    string penulis;
    int stok;
};

void loadBuku();
void simpanBuku();

void tambahBuku();
void tampilBuku();
void editBuku();
void hapusBuku();

#endif
