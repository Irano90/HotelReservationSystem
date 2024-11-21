# HotelReservationSystem
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Kelas Kamar
class Kamar {
protected:
    string nomorKamar;
    string tipeKamar;
    double hargaPerMalam;
    string status; // "tersedia" atau "dipesan"

public:
    Kamar(string nomor, string tipe, double harga) {
        nomorKamar = nomor;
        tipeKamar = tipe;
        hargaPerMalam = harga;
        status = "tersedia";
    }

    void tampilkanInfoKamar() {
        cout << "Nomor Kamar: " << nomorKamar << endl;
        cout << "Tipe Kamar: " << tipeKamar << endl;
        cout << "Harga per Malam: " << fixed << setprecision(2) << hargaPerMalam << endl;
        cout << "Status: " << status << endl;
    }

    string getStatus() {
        return status;
    }

    string getNomorKamar() {
        return nomorKamar;
    }

    void ubahStatus(string statusBaru) {
        status = statusBaru;
    }
};

// Kelas Turunan KamarSuite
class KamarSuite : public Kamar {
private:
    string fasilitasTambahan;

public:
    KamarSuite(string nomor, double harga, string fasilitas)
        : Kamar(nomor, "Suite", harga), fasilitasTambahan(fasilitas) {}

    void tampilkanInfoKamar() {
        Kamar::tampilkanInfoKamar();
        cout << "Fasilitas Tambahan: " << fasilitasTambahan << endl;
    }
};

// Kelas Tamu
class Tamu {
private:
    string nama;
    string nomorIdentitas;
    string kontak;
    vector<string> daftarReservasi; // Menyimpan nomor kamar yang dipesan

public:
    Tamu(string namaTamu, string identitas, string kontakTamu) {
        nama = namaTamu;
        nomorIdentitas = identitas;
        kontak = kontakTamu;
    }

    void tampilkanInfoTamu() {
        cout << "Nama: " << nama << endl;
        cout << "Nomor Identitas: " << nomorIdentitas << endl;
        cout << "Kontak: " << kontak << endl;
        cout << "Reservasi Aktif:" << endl;
        for (const auto &reservasi : daftarReservasi) {
            cout << " - Kamar: " << reservasi << endl;
        }
    }

    void tambahReservasi(string nomorKamar) {
        daftarReservasi.push_back(nomorKamar);
    }

    string getNama() {
        return nama;
    }
};

// Kelas Hotel
class Hotel {
private:
    vector<Kamar *> daftarKamar;
    vector<Tamu *> daftarTamu;

public:
    void tambahKamar(Kamar *kamar) {
        daftarKamar.push_back(kamar);
    }

    void tambahTamu(Tamu *tamu) {
        daftarTamu.push_back(tamu);
    }

    void daftarKamarTersedia() {
        cout << "Daftar Kamar Tersedia:" << endl;
        for (auto kamar : daftarKamar) {
            if (kamar->getStatus() == "tersedia") {
                kamar->tampilkanInfoKamar();
                cout << "------------------" << endl;
            }
        }
    }

    void buatReservasi(string namaTamu, string nomorKamar) {
        Tamu *tamu = nullptr;
        for (auto t : daftarTamu) {
            if (t->getNama() == namaTamu) {
                tamu = t;
                break;
            }
        }

        if (!tamu) {
            cout << "Tamu tidak ditemukan!" << endl;
            return;
        }

        Kamar *kamar = nullptr;
        for (auto k : daftarKamar) {
            if (k->getNomorKamar() == nomorKamar && k->getStatus() == "tersedia") {
                kamar = k;
                break;
            }
        }

        if (!kamar) {
            cout << "Kamar tidak tersedia!" << endl;
            return;
        }

        kamar->ubahStatus("dipesan");
        tamu->tambahReservasi(nomorKamar);
        cout << "Reservasi berhasil dibuat untuk tamu " << namaTamu << " di kamar " << nomorKamar << "." << endl;
    }
};

int main() {
    Hotel hotel;
    int pilihan;

    while (true) {
        cout << "\n=== Sistem Manajemen Reservasi Hotel ===" << endl;
        cout << "1. Tambah Kamar" << endl;
        cout << "2. Daftar Kamar Tersedia" << endl;
        cout << "3. Tambah Tamu Baru" << endl;
        cout << "4. Buat Reservasi" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            string nomor, tipe;
            double harga;
            cout << "Nomor Kamar: ";
            getline(cin, nomor);
            cout << "Tipe Kamar (Single/Double/Suite): ";
            getline(cin, tipe);
            cout << "Harga per Malam: ";
            cin >> harga;
            cin.ignore();

            if (tipe == "Suite") {
                string fasilitas;
                cout << "Fasilitas Tambahan: ";
                getline(cin, fasilitas);
                hotel.tambahKamar(new KamarSuite(nomor, harga, fasilitas));
            } else {
                hotel.tambahKamar(new Kamar(nomor, tipe, harga));
            }

            cout << "Kamar berhasil ditambahkan!" << endl;

        } else if (pilihan == 2) {
            hotel.daftarKamarTersedia();

        } else if (pilihan == 3) {
            string nama, identitas, kontak;
            cout << "Nama: ";
            getline(cin, nama);
            cout << "Nomor Identitas: ";
            getline(cin, identitas);
            cout << "Kontak: ";
            getline(cin, kontak);
            hotel.tambahTamu(new Tamu(nama, identitas, kontak));
            cout << "Tamu berhasil didaftarkan!" << endl;

        } else if (pilihan == 4) {
            string namaTamu, nomorKamar;
            cout << "Nama Tamu: ";
            getline(cin, namaTamu);
            cout << "Nomor Kamar: ";
            getline(cin, nomorKamar);
            hotel.buatReservasi(namaTamu, nomorKamar);

        } else if (pilihan == 0) {
            cout << "Terima kasih telah menggunakan sistem!" << endl;
            break;

        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
    }

    return 0;
}

