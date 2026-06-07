#include "binary_search.h"
#include <iostream>

using namespace std;

string daftarBuku[] = {
    "Atomic Habits",
    "Bumi Manusia",
    "Laskar Pelangi",
    "Negeri 5 Menara",
    "Pemograman C++"
};

int jumlahBuku = 5;

int binarySearch(string judul) {
    int kiri = 0;
    int kanan = jumlahBuku - 1;

    while(kiri <= kanan) {
        int tengah = (kiri + kanan) /2;

        if(daftarBuku[tengah] == judul) {
            return tengah;
        }

        if(daftarBuku[tengah] < judul) {
            kiri = tengah + 1;
        }else {
            kanan = tengah - 1;
        }
    }

    return -1;
}
