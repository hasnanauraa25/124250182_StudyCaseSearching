#include <iostream>
#include <string>
using namespace std;

struct Book {
    string judul;
    int harga;
};
    const int n = 5;

Book buku[n] = {
    {"Matahari", 99000},
    {"Bulan", 95000},
    {"Komet", 80000},
    {"Bumi", 94000},
    {"Nebula", 90000}
};

void daftarBuku() {
    cout << "DAFTAR BUKU TERE LIYE:" <<endl;
    for (int i = 0; i < n; i++) {
        cout << "~ " << buku[i].judul <<endl;
    }
}

void SequentialTanpaSentinel(string cari){
    bool ditemukan = false;

    for (int i = 0; i < n; i++) {
        if (buku[i].judul == cari) {
            cout << "Buku ditemukan!" <<endl;
            cout << "Harga: " << buku[i].harga <<endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Buku tidak ditemukan!" <<endl;
    }
}

void SequentialDenganSentinel(string cari){
    Book bukuSentinel[n + 1];

    for (int i = 0; i < n; i++) {
        bukuSentinel[i] = buku[i];
    }

    bukuSentinel[n].judul = cari; // sentinel

    int i = 0;
    while (bukuSentinel[i].judul != cari) {
        i++;
    }

    if (i < n) {
        cout << "Buku ditemukan!" << endl;
        cout << "Harga: " << bukuSentinel[i].harga <<endl;
    } else {
        cout << "Buku tidak ditemukan!" <<endl;
    }
}

void binarySearch(string cari){
    int kiri = 0, kanan = n - 1;
    bool ditemukan = false;

    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if (buku[tengah].judul == cari) {
            cout << "Buku ditemukan!" <<endl;
            cout << "Harga: " << buku[tengah].harga <<endl;
            ditemukan = true;
            break;
        }
        else if (cari < buku[tengah].judul) {
            kanan = tengah - 1;
        }
        else {
            kiri = tengah + 1;
        }
    }

    if (!ditemukan) {
        cout << "Buku tidak ditemukan!" <<endl;
    }
}

int main() {
    int pilihan, metode;
    string cari;

    daftarBuku();

    cout << "\nMETODE CARI BUKU" <<endl;
    cout << "1. Sequential Search" <<endl;
    cout << "2. Binary Search" <<endl;
    cout << "Pilih: ";
    cin >> pilihan;
    cin.ignore();

    if (pilihan == 1) {

        cout << "1. Dengan Sentinel" <<endl;
        cout << "2. Tanpa Sentinel" <<endl;
        cout << "Pilih: ";
        cin >> metode;
        cin.ignore();

        cout << "Masukkan nama buku: ";
        getline(cin, cari);

        if (metode == 1) {
            SequentialDenganSentinel(cari);
        } else {
            SequentialTanpaSentinel(cari);
        }
    } 
    else if (pilihan == 2) {
        cout << "Input nama buku: ";
        getline(cin, cari);

        binarySearch(cari);
    }
}
