#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int  baris = 119;
string tabJudul = string(40, ' ');
string tabMenu = string(35, ' ');



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

string adminUser[3] = {"Fajri", "Liza", "Rozak"};
string adminPass[3] = {"123", "456", "789"};


// ===================== FUNCTION & PROCEDURE =====================

void garis (){
	for (int i = 0; i <=baris; i++){
		cout<<"=";
	}
}
void pause() {
    cout << "\n\n" << tabMenu << "Tekan ENTER untuk kembali...";
    cin.ignore();
    cin.get();
}
void header(string judul) {
    system("cls");
    garis();
    cout << endl << endl << endl << endl;
    cout << tabJudul << "===== " << judul << " =====" << endl;
}

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
void tampilSemuaHotel() {

    header("DAFTAR HOTEL");
    garis();

    if (jumlahHotel == 0) {
        cout << "\n" << tabMenu << "Belum ada data hotel\n";
        return;
    }

    for (int i = 0; i < jumlahHotel; i++) {

        cout << "\n" << tabMenu << "Hotel ke-" << i + 1 << endl;
        cout << tabMenu << "-----------------------------\n";

        cout << tabMenu << "ID Hotel : " << hotel[i].idHotel << endl;
        cout << tabMenu << "Nama     : " << hotel[i].namaHotel << endl;
        cout << tabMenu << "Lokasi   : " << hotel[i].lokasi << endl;
    }
    pause();
}


string statusKamar(bool tersedia) {
    if (tersedia)
        return "Tersedia";
    else
        return "Tidak tersedia";
}
void tampilKamarTersedia() {

    header("KAMAR TERSEDIA");
    garis();

    bool ada = false;

    for (int i = 0; i < jumlahKamar; i++) {

        if (kamar[i].tersedia) {

            cout << "\n" << tabMenu << "Kamar ke-" << i + 1 << endl;
            cout << tabMenu << "-----------------------------\n";

            cout << tabMenu << "ID Kamar : " << kamar[i].idKamar << endl;
            cout << tabMenu << "ID Hotel : " << kamar[i].idHotel << endl;
            cout << tabMenu << "Tipe     : " << kamar[i].tipe << endl;
            cout << tabMenu << "Harga    : Rp " << kamar[i].harga << endl;
            cout << tabMenu << "Status   : " 
                 << statusKamar(kamar[i].tersedia) << endl;

            ada = true;
        }
        pause();
    }

    if (!ada) {
        cout << "\n" << tabMenu << "Tidak ada kamar yang tersedia\n";
    }

    pause();
}


void tampilSemuaKamar() {

    header("SEMUA DATA KAMAR");
    garis();

    if (jumlahKamar == 0) {
        cout << "\n" << tabMenu << "Belum ada data kamar\n";
        return;
    }

    for (int i = 0; i < jumlahKamar; i++) {

        cout << "\n" << tabMenu << "Kamar ke-" << i + 1 << endl;
        cout << tabMenu << "-----------------------------\n";

        cout << tabMenu << "ID Kamar : " << kamar[i].idKamar << endl;
        cout << tabMenu << "ID Hotel : " << kamar[i].idHotel << endl;
        cout << tabMenu << "Tipe     : " << kamar[i].tipe << endl;
        cout << tabMenu << "Harga    : Rp " << kamar[i].harga << endl;
        cout << tabMenu << "Status   : " 
             << statusKamar(kamar[i].tersedia) << endl;
    }
    pause();
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

    header("CARI HOTEL");
    garis();

    string cari;
    bool ketemu = false;

    cin.ignore();

    cout << "\n" << tabMenu << "Masukkan nama hotel : ";
    getline(cin, cari);

    for (int i = 0; i < jumlahHotel; i++) {

        if (hotel[i].namaHotel == cari) {

            if (!ketemu) {
                cout << "\n" << tabMenu << "Hotel ditemukan:\n";
            }

            cout << "\n" << tabMenu << "Hotel ke-" << i + 1 << endl;
            cout << tabMenu << "---------------------------\n";

            cout << tabMenu << "ID Hotel : " << hotel[i].idHotel << endl;
            cout << tabMenu << "Nama     : " << hotel[i].namaHotel << endl;
            cout << tabMenu << "Lokasi   : " << hotel[i].lokasi << endl;

            ketemu = true;
        }
    }

    if (!ketemu) {
        cout << "\n" << tabMenu << "Hotel tidak ditemukan\n";
    }
    pause();
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

    cout << "\n" << tabMenu << "Reservasi ke-" << index + 1 << endl;
    cout << tabMenu << "------------------------------\n";

    cout << tabMenu << "Nama User : " << reservasi[index].namaUser << endl;
    cout << tabMenu << "ID Hotel  : " << reservasi[index].idHotel << endl;
    cout << tabMenu << "ID Kamar  : " << reservasi[index].idKamar << endl;
    cout << tabMenu << "Lama Inap : " << reservasi[index].lamaInap << " hari" << endl;
    cout << tabMenu << "Total     : Rp " << reservasi[index].total << endl;

    tampilReservasiRekursif(index + 1);
}
// ===================== USER =====================

void pesanKamar() {

    header("PESAN KAMAR");
    garis();

    Reservasi r;

    cin.ignore();

    cout << "\n" << tabMenu << "Nama User : ";
    getline(cin, r.namaUser);

    cout << tabMenu << "ID Hotel  : ";
    cin >> r.idHotel;

    cout << tabMenu << "ID Kamar  : ";
    cin >> r.idKamar;

    int index = binarySearchKamar(r.idKamar);

    if (index == -1) {
        cout << "\n" << tabMenu << "Kamar tidak ditemukan\n";
        return;
    }

    if (!kamar[index].tersedia) {
        cout << "\n" << tabMenu << "Kamar tidak tersedia\n";
        return;
    }

    cout << "\n" << tabMenu << "Detail Kamar:\n";
    cout << tabMenu << "ID Kamar : " << kamar[index].idKamar << endl;
    cout << tabMenu << "Tipe     : " << kamar[index].tipe << endl;
    cout << tabMenu << "Harga    : Rp " << kamar[index].harga << endl;

    cout << "\n" << tabMenu << "Lama Inap : ";
    cin >> r.lamaInap;

    r.total = kamar[index].harga * r.lamaInap;

    char konfirmasi;
    cout << "\n" << tabMenu << "Total Bayar : Rp " << r.total << endl;
    cout << tabMenu << "Konfirmasi pesan? (y/n): ";
    cin >> konfirmasi;

    if (konfirmasi != 'y' && konfirmasi != 'Y') {
        cout << "\n" << tabMenu << "Reservasi dibatalkan\n";
        return;
    }

    reservasi[jumlahReservasi++] = r;

    kamar[index].tersedia = false;

    simpanReservasi();
    simpanKamar();

    cout << "\n" << tabMenu << "Reservasi berhasil!\n";
    pause();
}

void lihatStruk() {

    header("STRUK RESERVASI");
    garis();

    if (jumlahReservasi == 0) {
        cout << "\n" << tabMenu << "Belum ada reservasi\n";
    } else {
        tampilReservasiRekursif(0);
    }

    pause();
}

void cariKamar() {

    header("CARI KAMAR");
    garis();

    int id;

    cout << "\n" << tabMenu << "Masukkan ID kamar : ";
    cin >> id;

    int index = binarySearchKamar(id);

    if (index != -1) {

        cout << "\n" << tabMenu << "Kamar ditemukan\n\n";

        cout << tabMenu << "ID Kamar : " << kamar[index].idKamar << endl;
        cout << tabMenu << "Tipe     : " << kamar[index].tipe << endl;
        cout << tabMenu << "Harga    : " << kamar[index].harga << endl;
        cout << tabMenu << "Status   : "
             << (kamar[index].tersedia ? "Tersedia" : "Tidak Tersedia") << endl;
    }

    else {
        cout << "\n" << tabMenu << "Kamar tidak ditemukan\n";
    }
    pause();
}

// ===================== ADMIN =====================

void editHotel() {

    Hotel h;
    header("EDIT HOTEL");
    cout<<endl;
    cout <<tabMenu <<"ID Hotel : ";
    cin >> h.idHotel;

    cin.ignore();

    cout <<tabMenu<< "Nama Hotel : ";
    getline(cin, h.namaHotel);

    cout <<tabMenu<< "Lokasi : ";
    getline(cin, h.lokasi);

    hotel[jumlahHotel++] = h;

    bubbleSortHotel();

    simpanHotel();

    cout << "Hotel berhasil ditambahkan\n";
    system("cls");
}
void hapusHotel() {

    header("HAPUS HOTEL");
    garis();

    if (jumlahHotel == 0) {
        cout << "\n" << tabMenu << "Belum ada data hotel\n";
        pause();
        return;
    }

    int id;
    cout << "\n" << tabMenu << "Masukkan ID Hotel yang ingin dihapus: ";
    cin >> id;

    int index = -1;
    for (int i = 0; i < jumlahHotel; i++) {
        if (hotel[i].idHotel == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "\n" << tabMenu << "Hotel tidak ditemukan\n";
        pause();
        return;
    }

    for (int i = 0; i < jumlahKamar; i++) {
        if (kamar[i].idHotel == id) {
            cout << "\n" << tabMenu 
                 << "Hotel tidak bisa dihapus karena masih memiliki kamar!\n";
                 
            pause();
            return;
        }
    }

    // ?? hapus data (geser array)
    for (int i = index; i < jumlahHotel - 1; i++) {
        hotel[i] = hotel[i + 1];
    }

    jumlahHotel--;

    cout << "\n" << tabMenu << "Hotel berhasil dihapus\n";
    simpanHotel();
    pause();
}
void editKamar() {
	header("EDIT KAMAR");
    Kamar k;

    cout <<tabMenu<<"ID Kamar : ";
    cin >> k.idKamar;

    cout <<tabMenu<<"ID Hotel : ";
    cin >> k.idHotel;

    cin.ignore();

    cout <<tabMenu<<"Tipe Kamar : ";
    getline(cin, k.tipe);

    cout <<tabMenu<<"Harga : ";
    cin >> k.harga;

    k.tersedia = true;

    kamar[jumlahKamar++] = k;

    insertionSortKamar();

    simpanKamar();

    cout << "Kamar berhasil ditambahkan\n";
    system("cls");
}
void hapusKamar() {

    header("HAPUS KAMAR");
    garis();
    cout << endl;
	tampilSemuaKamar();
    int id;
    cout << "\n" << tabMenu << "Masukkan ID kamar: ";
    cin >> id;

    int index = -1;

    // Cari kamar
    for (int i = 0; i < jumlahKamar; i++) {
        if (kamar[i].idKamar == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "\n" << tabMenu << "Kamar tidak ditemukan\n";
        return;
    }

    // Cek apakah tersedia
    if (!kamar[index].tersedia) {
        cout << "\n" << tabMenu << "Kamar tidak bisa dihapus (sudah dipesan)\n";
        return;
    }

    // Hapus (geser array)
    for (int i = index; i < jumlahKamar - 1; i++) {
        kamar[i] = kamar[i + 1];
    }

    jumlahKamar--;

    simpanKamar();

    cout << "\n" << tabMenu << "Kamar berhasil dihapus\n";
    pause();
}
void hapusReservasi() {
    header("HAPUS RESERVASI");

    if (jumlahReservasi == 0) {
        cout << "\n" << tabMenu << "Belum ada reservasi\n";
        return;
    }

    
    cout << endl;
    tampilReservasiRekursif(0);

    int pilih;
    cout << "\n" << tabMenu << "Masukkan nomor reservasi: ";
    cin >> pilih;

    int index = pilih - 1;

    if (index < 0 || index >= jumlahReservasi) {
        cout << "\n" << tabMenu << "Pilihan tidak valid\n";
        return;
    }

    int idKamar = reservasi[index].idKamar;

    for (int i = 0; i < jumlahKamar; i++) {
        if (kamar[i].idKamar == idKamar) {
            kamar[i].tersedia = true;
            break;
        }
    }

    for (int i = index; i < jumlahReservasi - 1; i++) {
        reservasi[i] = reservasi[i + 1];
    }

    jumlahReservasi--;

    simpanReservasi();
    simpanKamar();

    cout << "\n" << tabMenu << "Reservasi berhasil dihapus\n";
    pause();
}
void lihatReservasi() {

    header("DATA RESERVASI");
    garis();

    if (jumlahReservasi == 0) {
        cout << "\n" << tabMenu << "Belum ada reservasi\n";
    } else {
        tampilReservasiRekursif(0);
    }

    pause();
}
// ===================== LOGIN ADMIN =====================

bool loginAdmin() {
	
	header("MENU LOGIN");
    string user, pass;
    cout<<endl;

    cout <<tabMenu<<"Username : ";
    cin >> user;
    cout <<tabMenu<<"Password : ";
    cin >> pass;

    for (int i = 0; i < 3; i++) {

        if (user == adminUser[i] && pass == adminPass[i]) {
            return true;
        }
    }

    return false;
    system("cls");
}

// ===================== MENU USER =====================

void menuUser() {

    int pilih;

    do {
    	header("MENU USER");	
		cout <<tabMenu<< "1. Cari Hotel\n";
		cout<<tabMenu<<"2. Pesan Kamar\n";
		cout << tabMenu<<"3. Lihat Struk\n";
		cout << tabMenu<<"4. Cari Kamar\n";
		cout << tabMenu<<"5. Lihat Semua Hotel\n";
		cout << tabMenu<<"6. Lihat Kamar Tersedia\n";
		cout << tabMenu<<"7. Lihat Semua Kamar\n";
		cout << tabMenu<<"0. Keluar\n";

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
            case 5:
			    tampilSemuaHotel();
			    break;

			case 6:
    			tampilKamarTersedia();
   				 break;
   			case 7:
   				 tampilSemuaKamar();
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
    system("cls");

    int pilih;

    do {
    	header("MENU ADMIN");	
        cout <<tabMenu<<"1. Edit Hotel\n";
        cout <<tabMenu<<"2. Edit Kamar\n";
        cout <<tabMenu<<"3. Lihat List Reservasi\n";
        cout<<tabMenu << "4. Hapus Kamar\n";
        cout<<tabMenu << "5. Hapus Hotel\n";
        cout<<tabMenu << "6. Hapus Reservasi\n";
        cout<<tabMenu << "7. Lihat Semua Hotel\n";
		cout<<tabMenu << "8. Lihat Kamar Tersedia\n";
		cout<<tabMenu << "9. Lihat Semua Kamar\n";
        cout <<tabMenu<<"0. Keluar\n";

        cout << "Pilih : ";
        cin >> pilih;
        system("cls");
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
            case 4:
    			hapusKamar();
    			break;
    		case 5:
  			  	hapusHotel();
 		   		break;
    		case 6:
  			  	hapusReservasi();
 		   		break;
 		   	case 7:
			    tampilSemuaHotel();
			    break;

			case 8:
    			tampilKamarTersedia();
   				 break;
   			case 9:
   				 tampilSemuaKamar();
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
		header("PROGRAM PEMESANAN HOTEL");	
        cout <<tabMenu<<"1. User\n";
        cout <<tabMenu<<"2. Admin\n";
        cout <<tabMenu<<"0. Keluar\n";

        cout << "Pilih : ";
        cin >> pilih;
        system("cls");

        switch (pilih) {

            case 1:
                menuUser();
                break;

            case 2:
                menuAdmin();
                break;
        }


    } 
	while (pilih != 0);

}
