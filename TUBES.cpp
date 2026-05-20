#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Hotel {
    int idHotel;
    string namaHotel;
    string lokasi;
};

struct Kamar {
    int idKamar;
    int idHotel;
    string tipe;
    int harga;
    bool tersedia;
};

struct Reservasi {
    string namaUser;
    int idHotel;
    int idKamar;
    int lamaInap;
    int total;
};

Hotel hotel[100];
Kamar kamar[100];
Reservasi reservasi[100];

int jumlahHotel = 0;
int jumlahKamar = 0;
int jumlahReservasi = 0;

string adminUser[3] = {"admin1", "admin2", "admin3"};
string adminPass[3] = {"123", "456", "789"};


// ===================== FUNCTION & PROCEDURE =====================

void simpanHotel() {
    ofstream file("hotel.txt");

    for (int i = 0; i < jumlahHotel; i++) {
        file << hotel[i].idHotel << "|"
             << hotel[i].namaHotel << "|"
             << hotel[i].lokasi << endl;
    }

    file.close();
}

void bacaHotel() {
    ifstream file("hotel.txt");

    jumlahHotel = 0;

    while (file >> hotel[jumlahHotel].idHotel) {
        file.ignore();
        getline(file, hotel[jumlahHotel].namaHotel, '|');
        getline(file, hotel[jumlahHotel].lokasi);

        jumlahHotel++;
    }

    file.close();
}

void simpanKamar() {
    ofstream file("kamar.txt");

    for (int i = 0; i < jumlahKamar; i++) {
        file << kamar[i].idKamar << "|"
             << kamar[i].idHotel << "|"
             << kamar[i].tipe << "|"
             << kamar[i].harga << "|"
             << kamar[i].tersedia << endl;
    }

    file.close();
}

void bacaKamar() {
    ifstream file("kamar.txt");

    jumlahKamar = 0;

    while (file >> kamar[jumlahKamar].idKamar) {
        file.ignore();

        file >> kamar[jumlahKamar].idHotel;
        file.ignore();

        getline(file, kamar[jumlahKamar].tipe, '|');

        file >> kamar[jumlahKamar].harga;
        file.ignore();

        file >> kamar[jumlahKamar].tersedia;

        jumlahKamar++;
    }

    file.close();
}

void simpanReservasi() {
    ofstream file("reservasi.txt");

    for (int i = 0; i < jumlahReservasi; i++) {
        file << reservasi[i].namaUser << "|"
             << reservasi[i].idHotel << "|"
             << reservasi[i].idKamar << "|"
             << reservasi[i].lamaInap << "|"
             << reservasi[i].total << endl;
    }

    file.close();
}

void bacaReservasi() {
    ifstream file("reservasi.txt");

    jumlahReservasi = 0;

    while (getline(file, reservasi[jumlahReservasi].namaUser, '|')) {

        file >> reservasi[jumlahReservasi].idHotel;
        file.ignore();

        file >> reservasi[jumlahReservasi].idKamar;
        file.ignore();

        file >> reservasi[jumlahReservasi].lamaInap;
        file.ignore();

        file >> reservasi[jumlahReservasi].total;
        file.ignore();

        jumlahReservasi++;
    }

    file.close();
}

// ===================== BUBBLE SORT =====================

void bubbleSortHotel() {
    for (int i = 0; i < jumlahHotel - 1; i++) {
        for (int j = 0; j < jumlahHotel - i - 1; j++) {

            if (hotel[j].namaHotel > hotel[j + 1].namaHotel) {

                Hotel temp = hotel[j];
                hotel[j] = hotel[j + 1];
                hotel[j + 1] = temp;
            }
        }
    }
}

// ===================== INSERTION SORT =====================

void insertionSortKamar() {
    for (int i = 1; i < jumlahKamar; i++) {

        Kamar key = kamar[i];
        int j = i - 1;

        while (j >= 0 && kamar[j].harga > key.harga) {
            kamar[j + 1] = kamar[j];
            j--;
        }

        kamar[j + 1] = key;
    }
}

// ===================== SEQUENTIAL SEARCH =====================

void cariHotel() {
    string cari;
    bool ketemu = false;

    cin.ignore();
    cout << "Masukkan nama hotel : ";
    getline(cin, cari);

    for (int i = 0; i < jumlahHotel; i++) {

        if (hotel[i].namaHotel == cari) {

            cout << "\nHotel ditemukan\n";
            cout << "ID Hotel : " << hotel[i].idHotel << endl;
            cout << "Nama     : " << hotel[i].namaHotel << endl;
            cout << "Lokasi   : " << hotel[i].lokasi << endl;

            ketemu = true;
        }
    }

    if (!ketemu) {
        cout << "\nHotel tidak ditemukan\n";
    }
}

// ===================== BINARY SEARCH =====================

int binarySearchKamar(int cariID) {

    insertionSortKamar();

    int kiri = 0;
    int kanan = jumlahKamar - 1;

    while (kiri <= kanan) {

        int tengah = (kiri + kanan) / 2;

        if (kamar[tengah].idKamar == cariID) {
            return tengah;
        }

        else if (kamar[tengah].idKamar < cariID) {
            kiri = tengah + 1;
        }

        else {
            kanan = tengah - 1;
        }
    }

    return -1;
}

// ===================== REKURSIF =====================

void tampilReservasiRekursif(int index) {

    if (index == jumlahReservasi)
        return;

    cout << "\nReservasi ke-" << index + 1 << endl;
    cout << "Nama User : " << reservasi[index].namaUser << endl;
    cout << "ID Hotel  : " << reservasi[index].idHotel << endl;
    cout << "ID Kamar  : " << reservasi[index].idKamar << endl;
    cout << "Lama Inap : " << reservasi[index].lamaInap << endl;
    cout << "Total     : " << reservasi[index].total << endl;

    tampilReservasiRekursif(index + 1);
}

// ===================== USER =====================

void pesanKamar() {

    Reservasi r;

    cin.ignore();

    cout << "Nama User : ";
    getline(cin, r.namaUser);

    cout << "ID Hotel  : ";
    cin >> r.idHotel;

    cout << "ID Kamar  : ";
    cin >> r.idKamar;

    int index = binarySearchKamar(r.idKamar);

    if (index == -1) {
        cout << "Kamar tidak ditemukan\n";
        return;
    }

    if (!kamar[index].tersedia) {
        cout << "Kamar tidak tersedia\n";
        return;
    }

    cout << "Lama Inap : ";
    cin >> r.lamaInap;

    r.total = kamar[index].harga * r.lamaInap;

    reservasi[jumlahReservasi++] = r;

    kamar[index].tersedia = false;

    simpanReservasi();
    simpanKamar();

    cout << "\nReservasi berhasil!\n";
}

void lihatStruk() {

    tampilReservasiRekursif(0);
}

void cariKamar() {

    int id;

    cout << "Masukkan ID kamar : ";
    cin >> id;

    int index = binarySearchKamar(id);

    if (index != -1) {

        cout << "\nKamar ditemukan\n";
        cout << "ID Kamar : " << kamar[index].idKamar << endl;
        cout << "Tipe     : " << kamar[index].tipe << endl;
        cout << "Harga    : " << kamar[index].harga << endl;
    }

    else {
        cout << "Kamar tidak ditemukan\n";
    }
}

// ===================== ADMIN =====================

void editHotel() {

    Hotel h;

    cout << "ID Hotel : ";
    cin >> h.idHotel;

    cin.ignore();

    cout << "Nama Hotel : ";
    getline(cin, h.namaHotel);

    cout << "Lokasi : ";
    getline(cin, h.lokasi);

    hotel[jumlahHotel++] = h;

    bubbleSortHotel();

    simpanHotel();

    cout << "Hotel berhasil ditambahkan\n";
}

void editKamar() {

    Kamar k;

    cout << "ID Kamar : ";
    cin >> k.idKamar;

    cout << "ID Hotel : ";
    cin >> k.idHotel;

    cin.ignore();

    cout << "Tipe Kamar : ";
    getline(cin, k.tipe);

    cout << "Harga : ";
    cin >> k.harga;

    k.tersedia = true;

    kamar[jumlahKamar++] = k;

    insertionSortKamar();

    simpanKamar();

    cout << "Kamar berhasil ditambahkan\n";
}

void lihatReservasi() {

    tampilReservasiRekursif(0);
}

// ===================== LOGIN ADMIN =====================

bool loginAdmin() {

    string user, pass;

    cout << "Username : ";
    cin >> user;

    cout << "Password : ";
    cin >> pass;

    for (int i = 0; i < 3; i++) {

        if (user == adminUser[i] && pass == adminPass[i]) {
            return true;
        }
    }

    return false;
}

// ===================== MENU USER =====================

void menuUser() {

    int pilih;

    do {

        cout << "\n===== MENU USER =====\n";
        cout << "1. Cari Hotel\n";
        cout << "2. Pesan Kamar\n";
        cout << "3. Lihat Struk\n";
        cout << "4. Cari Kamar\n";
        cout << "0. Keluar\n";

        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih) {

            case 1:
                cariHotel();
                break;

            case 2:
                pesanKamar();
                break;

            case 3:
                lihatStruk();
                break;

            case 4:
                cariKamar();
                break;
        }

    } while (pilih != 0);
}

// ===================== MENU ADMIN =====================

void menuAdmin() {

    if (!loginAdmin()) {

        cout << "Login gagal\n";
        return;
    }

    int pilih;

    do {

        cout << "\n===== MENU ADMIN =====\n";
        cout << "1. Edit Hotel\n";
        cout << "2. Edit Kamar\n";
        cout << "3. Lihat List Reservasi\n";
        cout << "0. Keluar\n";

        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih) {

            case 1:
                editHotel();
                break;

            case 2:
                editKamar();
                break;

            case 3:
                lihatReservasi();
                break;
        }

    } while (pilih != 0);
}

// ===================== MAIN =====================

int main() {

    bacaHotel();
    bacaKamar();
    bacaReservasi();

    int pilih;

    do {

        cout << "\n===== PROGRAM PEMESANAN HOTEL =====\n";
        cout << "1. User\n";
        cout << "2. Admin\n";
        cout << "0. Keluar\n";

        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih) {

            case 1:
                menuUser();
                break;

            case 2:
                menuAdmin();
                break;
        }

    } while (pilih != 0);

    return 0;
}
