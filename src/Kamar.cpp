#include "Kamar.h"
#include <iostream>
using namespace std;

// Constructor default
Kamar::Kamar() : nomorKamar(0), tipeKamar(""), hargaPerMalam(0.0), status("tersedia") {}

// Constructor dengan parameter
Kamar::Kamar(int nomor, const string& tipe, double harga, const string& stat)
    : nomorKamar(nomor), tipeKamar(tipe), hargaPerMalam(harga), status(stat) {}

// Menampilkan informasi kamar
void Kamar::tampilkanInfoKamar() const {
    cout << "Nomor Kamar: " << nomorKamar << endl;
    cout << "Tipe Kamar: " << tipeKamar << endl;
    cout << "Harga per Malam: " << hargaPerMalam << endl;
    cout << "Status: " << status << endl;
    cout << "----------------------------" << endl;
}

// Getter untuk nomor kamar
int Kamar::getNomorKamar() const {
    return nomorKamar;
}

// Getter untuk tipe kamar
string Kamar::getTipeKamar() const {
    return tipeKamar;
}

// Getter untuk harga per malam
double Kamar::getHargaPerMalam() const {
    return hargaPerMalam;
}

// Getter untuk status kamar
string Kamar::getStatus() const {
    return status;
}

// Setter untuk status kamar
void Kamar::setStatus(const string& stat) {
    status = stat;
}
