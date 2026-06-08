#ifndef QUEUE_H
#define QUEUE_H

#include <string>
using namespace std;

struct Antrian {
    int idAnggota;
    string nama;
    string judulBuku;
    string tanggalPinjam;
};

void loadPeminjaman();
void simpanPeminjaman();

void tambahAntrian();
void tampilAntrian();
void layaniAntrian();

#endif
