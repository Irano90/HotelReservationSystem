#include "Hotel.h"
#include <iostream>
#include <algorithm>
using namespace std;

// Constructor
Hotel::Hotel() {}

// Menambahkan kamar baru ke daftar kamar
void Hotel::tambahKamar(const Kamar& kamar) {
    daftarKamar.push_back(kamar);
}

// Menambahkan tamu baru ke daftar tamu
void Hotel::tambahTamu(const Tamu& tamu) {
    daftarTamu.push_back(tamu);
}

// Membuat reservasi baru
bool Hotel::buatReservasi(const Tamu& tamu, int nomorKamar, const string& tanggalCheckIn, const string& tanggalCheckOut) {
    // Cari kamar berdasarkan nomor
    auto it = find_if(daftarKamar.begin(), daftarKamar.end(), [&](const Kamar& kamar) {
        return kamar.getNomorKamar() == nomorKamar && kamar.getStatus() == "tersedia";
    });

    if (it != daftarKamar.end()) {
        // Hitung durasi menginap
        int durasiMenginap = 1; // Placeholder untuk menghitung durasi dari tanggalCheckIn dan tanggalCheckOut

        // Buat reservasi baru
        Reservasi reservasi(tamu, *it, tanggalCheckIn, tanggalCheckOut, durasiMenginap);
        reservasi.setStatus("aktif");

        // Tambahkan ke daftar reservasi
        daftarReservasi.push_back(reservasi);

        // Ubah status kamar menjadi "dipesan"
        it->setStatus("dipesan");

        return true;
    } else {
        cout << "Kamar dengan nomor " << nomorKamar << " tidak tersedia." << endl;
        return false;
    }
}

// Membatalkan reservasi
bool Hotel::batalkanReservasi(int nomorReservasi) {
    auto it = find_if(daftarReservasi.begin(), daftarReservasi.end(), [&](const Reservasi& reservasi) {
        return reservasi.getNomorReservasi() == nomorReservasi && reservasi.getStatus() == "aktif";
    });

    if (it != daftarReservasi.end()) {
        // Ubah status reservasi menjadi "dibatalkan"
        it->setStatus("dibatalkan");

        // Cari kamar terkait dan ubah statusnya menjadi "tersedia"
        auto kamarIt = find_if(daftarKamar.begin(), daftarKamar.end(), [&](const Kamar& kamar) {
            return kamar.getNomorKamar() == it->getKamar().getNomorKamar();
        });

        if (kamarIt != daftarKamar.end()) {
            kamarIt->setStatus("tersedia");
        }

        return true;
    } else {
        cout << "Reservasi dengan nomor " << nomorReservasi << " tidak ditemukan atau sudah dibatalkan." << endl;
        return false;
    }
}

// Menampilkan daftar kamar yang tersedia
void Hotel::daftarKamarTersedia() const {
    cout << "Daftar kamar yang tersedia:" << endl;
    for (const auto& kamar : daftarKamar) {
        if (kamar.getStatus() == "tersedia") {
            kamar.tampilkanInfoKamar();
        }
    }
}
