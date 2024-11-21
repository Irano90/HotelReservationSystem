#include "Reservasi.h"
#include <iostream>
using namespace std;

// Constructor default
Reservasi::Reservasi() 
    : durasiMenginap(0), status("aktif") {}

// Constructor dengan parameter
Reservasi::Reservasi(const Tamu& tamu, const Kamar& kamar, const string& tanggalCheckIn, 
                     const string& tanggalCheckOut, int durasi) 
    : tamu(tamu), kamar(kamar), tanggalCheckIn(tanggalCheckIn), 
      tanggalCheckOut(tanggalCheckOut), durasiMenginap(durasi), status("aktif") {}

// Menampilkan informasi reservasi
void Reservasi::tampilkanInfoReservasi() const {
    cout << "Informasi Reservasi:" << endl;
    cout << "Nama Tamu: " << tamu.getNama() << endl;
    cout << "Nomor Identitas: " << tamu.getNomorIdentitas() << endl;
    cout << "Kontak: " << tamu.getKontak() << endl;
    cout << "Nomor Kamar: " << kamar.getNomorKamar() << endl;
    cout << "Tipe Kamar: " << kamar.getTipeKamar() << endl;
    cout << "Tanggal Check-In: " << tanggalCheckIn << endl;
    cout << "Tanggal Check-Out: " << tanggalCheckOut << endl;
    cout << "Durasi Menginap: " << durasiMenginap << " malam" << endl;
    cout << "Status: " << status << endl;
    cout << "----------------------------" << endl;
}

// Getter untuk tamu
Tamu Reservasi::getTamu() const {
    return tamu;
}

// Getter untuk kamar
Kamar Reservasi::getKamar() const {
    return kamar;
}

// Getter untuk tanggal check-in
string Reservasi::getTanggalCheckIn() const {
    return tanggalCheckIn;
}

// Getter untuk tanggal check-out
string Reservasi::getTanggalCheckOut() const {
    return tanggalCheckOut;
}

// Getter untuk durasi menginap
int Reservasi::getDurasiMenginap() const {
    return durasiMenginap;
}

// Getter untuk status
string Reservasi::getStatus() const {
    return status;
}

// Setter untuk status
void Reservasi::setStatus(const string& stat) {
    status = stat;
}
