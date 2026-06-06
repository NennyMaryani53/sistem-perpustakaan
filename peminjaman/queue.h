#ifndef QUEUE_H
#define QUEUE_H

#include <string>
using namespace std;

struct Antrian {
    string nama;
    string judulBuku;
};

void tambahAntrian();
void tampilAntrian();
void layaniAntrian();

#endif
