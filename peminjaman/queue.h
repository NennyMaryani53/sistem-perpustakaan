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

void loadData();
void simpanData();
void tambahAntrian();
void tampilAntrian();
void layaniAntrian();

#endif
