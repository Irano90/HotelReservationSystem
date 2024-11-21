#include "Tamu.h"
#include <iostream>
using namespace std;

// Constructor default
Tamu::Tamu() : nama(""), nomorIdentitas(""), kontak("") {}

// Constructor dengan parameter
Tamu::Tamu(const string& nama, const string& nomorIdentitas, const string& kontak) 
    : nama(nama), nomorIdentitas(nomorIdentitas), kontak(kontak) {}

// Menampilkan informasi tamu
void Tamu::tampilkanInfoTamu() const {
    cout << "Informasi Tamu:" << endl;
    cout << "Nama: " << nama << endl;
    cout << "Nomor Identitas: " << nomorIdentitas << endl;
    cout << "Kontak: " << kontak << endl;
    cout << "Reservasi Aktif: " << endl;

    if (daftarReservasi.empty()) {
        cout << "  Tidak ada reservasi aktif." << endl;
    } else {
        for (const auto& reservasi : daftarReservasi) {
            cout << "  - Nomor Kamar: " << reservasi.getKamar().getNomorKamar()
                 << ", Check-In: " << reservasi.getTanggalCheckIn()
                 << ", Check-Out: " << reservasi.getTanggalCheckOut()
                 << ", Status: " << reservasi.getStatus() << endl;
        }
    }
    cout << "----------------------------" << endl;
}

// Menambahkan reservasi ke daftar tamu
void Tamu::tambahReservasi(const Reservasi& reservasi) {
    daftarReservasi.push_back(reservasi);
}

// Getter untuk nama tamu
string Tamu::getNama() const {
    return nama;
}

// Getter untuk nomor identitas tamu
string Tamu::getNomorIdentitas() const {
    return nomorIdentitas;
}

// Getter untuk kontak tamu
string Tamu::getKontak() const {
    return kontak;
}

// Getter untuk daftar reservasi tamu
vector<Reservasi> Tamu::getDaftarReservasi() const {
    return daftarReservasi;
}
