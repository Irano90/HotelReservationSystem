#include <iostream>
#include <vector>
#include <string>
#include "Kamar.h"
#include "Tamu.h"
#include "Reservasi.h"
#include "Hotel.h"

using namespace std;

void tampilkanMenu() {
    cout << "===============================" << endl;
    cout << "Sistem Manajemen Reservasi Hotel" << endl;
    cout << "===============================" << endl;
    cout << "1. Tambah Kamar Baru" << endl;
    cout << "2. Daftarkan Tamu Baru" << endl;
    cout << "3. Buat Reservasi" << endl;
    cout << "4. Batalkan Reservasi" << endl;
    cout << "5. Daftar Kamar Tersedia" << endl;
    cout << "6. Tampilkan Informasi Tamu" << endl;
    cout << "7. Keluar" << endl;
    cout << "Pilih menu: ";
}

int main() {
    Hotel hotel;  // Membuat objek hotel
    int pilihan;
    
    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                // Tambah Kamar Baru
                int nomorKamar;
                string tipeKamar;
                double harga;
                cout << "Masukkan nomor kamar: ";
                cin >> nomorKamar;
                cout << "Masukkan tipe kamar (Single/Double/Suite): ";
                cin >> tipeKamar;
                cout << "Masukkan harga per malam: ";
                cin >> harga;

                Kamar kamar(nomorKamar, tipeKamar, harga, "tersedia");
                hotel.tambahKamar(kamar);
                cout << "Kamar berhasil ditambahkan!" << endl;
                break;
            }
            case 2: {
                // Daftarkan Tamu Baru
                string nama, nomorIdentitas, kontak;
                cout << "Masukkan nama tamu: ";
                cin >> nama;
                cout << "Masukkan nomor identitas: ";
                cin >> nomorIdentitas;
                cout << "Masukkan kontak tamu: ";
                cin >> kontak;

                Tamu tamu(nama, nomorIdentitas, kontak);
                hotel.tambahTamu(tamu);
                cout << "Tamu berhasil didaftarkan!" << endl;
                break;
            }
            case 3: {
                // Buat Reservasi
                string nomorIdentitas;
                int nomorKamar;
                string tanggalCheckIn, tanggalCheckOut;
                cout << "Masukkan nomor identitas tamu: ";
                cin >> nomorIdentitas;
                cout << "Masukkan nomor kamar: ";
                cin >> nomorKamar;
                cout << "Masukkan tanggal check-in (DD/MM/YYYY): ";
                cin >> tanggalCheckIn;
                cout << "Masukkan tanggal check-out (DD/MM/YYYY): ";
                cin >> tanggalCheckOut;

                Tamu tamu = hotel.cariTamu(nomorIdentitas);  // Cari tamu berdasarkan nomor identitas
                Kamar kamar = hotel.cariKamar(nomorKamar);   // Cari kamar berdasarkan nomor kamar

                if (tamu.getNama() != "" && kamar.getNomorKamar() != 0) {
                    Reservasi reservasi(tamu, kamar, tanggalCheckIn, tanggalCheckOut, 1);
                    hotel.buatReservasi(reservasi);
                    cout << "Reservasi berhasil dibuat!" << endl;
                } else {
                    cout << "Tamu atau Kamar tidak ditemukan!" << endl;
                }
                break;
            }
            case 4: {
                // Batalkan Reservasi
                string nomorIdentitas;
                int nomorKamar;
                cout << "Masukkan nomor identitas tamu: ";
                cin >> nomorIdentitas;
                cout << "Masukkan nomor kamar: ";
                cin >> nomorKamar;

                hotel.batalkanReservasi(nomorIdentitas, nomorKamar);
                cout << "Reservasi berhasil dibatalkan!" << endl;
                break;
            }
            case 5: {
                // Daftar Kamar Tersedia
                hotel.daftarKamarTersedia();
                break;
            }
            case 6: {
                // Tampilkan Informasi Tamu
                string nomorIdentitas;
                cout << "Masukkan nomor identitas tamu: ";
                cin >> nomorIdentitas;
                hotel.tampilkanInfoTamu(nomorIdentitas);
                break;
            }
            case 7:
                cout << "Terima kasih! Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi!" << endl;
        }

        cout << endl;

    } while (pilihan != 7);

    return 0;
}
