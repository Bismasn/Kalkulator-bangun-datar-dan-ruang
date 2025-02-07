#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <unistd.h>

// declare phi untuk menghitung lingkaran, kerucut, tabung
#define phi 3.14

// nilai untuk dekorasi warna 
#define WARNA_KUNING_TEBAL "\e[1;33m"
#define WARNA_CYAN_TEBAL "\e[1;36m"
#define WARNA_CYAN "\e[0;36m"
#define WARNA_RESET "\e[0m"
#define WARNA_KUNING "\e[0;33m"
#define WARNA_HITAM "\e[0;30m"
using namespace std;

/* Enum adalah tipe data yang memungkinkan kita untuk membuat 
variable yang hanya dapat memiliki satu nilai dari beberapa kemungkinan nilai */
enum bangunDatar {
    PERSEGI, PERSEGI_PANJANG, LINGKARAN, SEGITIGA,
};
enum bangunRuang {
    KUBUS, BALOK, TABUNG, KERUCUT,
};
/* Contohnya seperti ini Enum yang saya buat diatas itu nanti bisa di ganti dengan sebuah angka untuk memilih sesuatu
dan bisa juga diuban menjadi sebuah string yang saya lakukan di bawah ini tanpa mengganggu nilai di atas.*/

/* Map Berfungsi sebagai pengubah nilai variabel enum supaya memudahkan kita menampilkan sesuatu di layar. 
nah disini saya rubah nilainya ke string*/
map<bangunDatar, string> namaBangunDatar = {
    {PERSEGI, "Persegi"},
    {PERSEGI_PANJANG, "Persegi Panjang"},
    {LINGKARAN, "Lingkaran"},
    {SEGITIGA, "Segitiga"},
    // Tambahkan pasangan bangun datar lainnya
};
map<bangunRuang, string> namaBangunRuang = {
    {KUBUS, "Kubus"},
    {BALOK, "Balok"},
    {TABUNG, "Tabung"},
    {KERUCUT, "Kerucut"},
    // Tambahkan pasangan bangun ruang lainnya
};
// baris di bawah ini saya membuat semua fungsi yang akan membantu kamu saat memodifikasi atau membaca kode saya.

// Fungsi untuk menghitung luas/volume dari bangun datar atau bangun ruang.
    // Fungsi Persegi
    double hitungLuasPersegi(double sisi) {
        return sisi * sisi;}
    double hitungKelilingPersegi(double sisi) {
        return 4 * sisi;}

    // Fungsi Persegi Panjang
    double hitungLuas_persegiPanjang(double panjang, double lebar) {
        return panjang * lebar;}
    double hitungKeliling_persegiPanjang (double panjang, double lebar){
        return 2 * (panjang + lebar);}

    // Fungsi Lingkaran
    double hitungLuas_Lingkaran(double jari) {
        return phi * jari * jari; }
    double hitungKeliling_Lingkaran(double jari) {
        return 2 * phi * jari; }
    double hitungDiameter(double jari) {
        return 2 * jari; }

    //Fungsi Luas Kubus
    double hitungLuasKubus(double sisi) {
        return sisi * sisi; }
    double hitungLuasPermukaanKubus(double sisi){
        return 6 * sisi * sisi; }
    
    // Fungsi Volume dan Keliling Kubus
    double hitungVolumeKubus(double sisi) {
        return sisi * sisi * sisi; }
    double hitungKelilingKubus(double sisi) {
        return 12 * sisi;}

    // Fungsi Luas Permukaan, Volume, dan Keliling Balok
    double hitungLuasPermukaanBalok(double panjang, double lebar, double tinggi) {
        return 2 * (panjang * lebar) + (panjang * tinggi) + (lebar * tinggi);}
    double hitungVolumeBalok(double panjang, double lebar, double tinggi) {
        return panjang * lebar * tinggi; }
    double hitungKelilingBalok(double panjang, double lebar, double tinggi) {
        return 4 * (panjang * lebar * tinggi); }
    
        /* Ada juga fungsi di dalam struct seperti ini.
        ini memungkinkan kita untuk menambahkan suatu fungsi untuk menghitung bangun yang banyak jenisnya.
        seperti bangun datar segitiga contohnya*/
        // Struct untuk Fungsi Segitiga
        struct Segitiga {
            string nama;
            string rumusLuas;
            string rumusKeliling;
            //Note : fungsi luas segitiga dari  ketiga ini adalah sama jadi saya membuat satu fungsi saja untuk semua segtiga di bawah.
            double luasSegitiga(double alas, double tinggi){
                return 0.5 * alas * tinggi;
            }
            //Fungsi Rumus Segitiga Sama Sisi
            double kelilingSegitigaSamaSisi(double sisi){
                return 3 * sisi;
            }
            //Fungsi Rumus Segitiga Sama Kaki
            double kelilingSegitigaSamaKaki(double miring, double alas){
                return (2 * miring) + alas;
            }
            //Fungsi Rumus Segitiga Siku - Siku
            double kelilingSegitigaSikuSiku (double miring, double alas, double tinggi){
                return tinggi + alas + miring;
            }
        };
        
        // Struct untuk bangun ruang tabung
        struct Tabung {
            string luasPermukaan;
            string luasTutupDanAlas;
            string luasSelimut;
            string volume;
            string keliling;
            // Fungsi Rumus Tabung
            double luasPermukaanTabung(double jari) {
                return 2 * phi * jari * jari; 
            }
            double luasTutupDanAlas_KelilingTabung(double jari) {
                return 2 * phi * jari;
            }
            double luasSelimutTabung(double jari, double tinggi) {
                return 2 * phi * jari * jari * tinggi;
            }
            double volumeTabung(double jari, double tinggi) {
                return phi * jari * jari * tinggi;
            }
        };
        
        // Struct untuk bangun ruang Kerucut
        struct Kerucut {
            string luasSelimut;
            string luasAlas;
            string luasPermukaan;
            string jariVolume;
            string jariSelimut;
            string volume;
            // Fungsi luas kerucut.
            double selimutKerucut(double jari, double tinggi){
                return phi * jari *sqrt(jari * jari + tinggi * tinggi) ;} // sqrt(jari * jari + tinggi *tinggi) => Rumus Garis Pelukis.
            double luasAlasKerucut(double jari){
                return phi * jari * jari; }
            double luasPermukaanKerucut(double jari, double tinggi) {
                return phi * jari * sqrt(jari * jari + tinggi * tinggi) + (phi * jari * jari);}
                
            // Fungsi Jari jari Kerucut.
                // Fungsi mencari jari jari kerucut yang di ketahui adalah volume
                int jariJariKerucutVolume(double volume, double tinggi) {
                    return sqrt((3 * volume) / (phi * tinggi)) ;
                }
                // Fungsi mencari jari jari kerucut yang di ketahui adalah luas Selimut
                int jariJariKerucutSelimut(double selimut, double luasSelimut ) {
                    return luasSelimut / phi * selimut;
                }
            // Fungsi volume kerucut
            double volumeKerucut(double jari, double tinggi) {
                return 0.33 * phi * jari * jari * tinggi;
            }
        };
        
        // Struct untuk menyimpan rumus yang akan di tampilkan
        // Struct ini tidak memyertakan fungsi apapun dan ini hanya memudahkan kita saat mengeluarkan nilai dari struct ini.
        struct Rumus {
            string nama;
            string rumusLuas;
            string rumusKeliling;
            string rumusVolume;
            string diameter;
            string rumusSelimutKerucut;
        };

    // Fungi Tampilkan menu dibawah ini berfungsi untuk mencetak menu bangun datar apa saja yang ada di program ini.
    void tampilkanMenuDatar() {
        cout << "Kamu memilih pilihan bangun datar." << endl << endl;
        cout << "========================================================" <<endl;
        cout << WARNA_CYAN << "Silahkan pilih beberapa menu dibawah ini untuk memulai : " << endl;
        for (const auto& pair : namaBangunDatar) {
            cout << static_cast<int>(pair.first) + 1 << ". " << pair.second << endl;
            // Static_cast<int> - ini berfungsi untuk mengubah variable enum menjadi variable tipe data integer.
            /* dikarenakan enum tersebut adalah array maka harus di tambah 1 terlebih dahulu
            supaya ketika user memilih angka 1 program tidak menampikan pilihan nomor 0 */
        }
        cout << "0. Kembali" << endl;
        cout << WARNA_KUNING << "========================================================" <<endl <<endl;
        
    }
    // Variable universal
    /* variable yang di berikan ini luar fungsi atau int main ini, berfungsi supaya memudahkan untuk digunakan di fungsi fungsi lainnya atau di int main juga.
    tujuannya agar nilai yang dimasukan user atau nilai yang didalam variable ini tidak berubah dan tetap sama ketika memakai program ini.*/
    int pilihan;
    string nama;
    // Fungsi nama user
    void tampilkanNama(){
        cin >> nama;
        cout << nama;
    }
    // Fungi Tampilkan menu dibawah ini berfungsi untuk mencetak menu bangun ruang apa saja yang ada di program ini.
void tampilkanMenuRuang() {
    cout << "Kamu memilih pilihan bangun Ruang." << endl << endl;
    cout << "========================================================" <<endl;
    cout << WARNA_CYAN << "Silahkan pilih beberapa menu dibawah ini untuk memulai : " << endl;
    for (const auto& pair : namaBangunRuang) {
        cout << static_cast<int>(pair.first) + 1 << ". " << pair.second << endl;
            // Static_cast<int> - ini berfungsi untuk mengubah variable enum menjadi variable tipe data integer.
            /* dikarenakan enum tersebut adalah array maka harus di tambah 1 terlebih dahulu
            supaya ketika user memilih angka 1 program tidak menampikan pilihan nomor 0 */
    }
    cout << "0. Kembali" << endl;
    cout << WARNA_KUNING << "========================================================" <<endl <<endl;
}

// Fungsi anti looping di bawah ini akan mencegah kamu saat membuat desission atau pemilihan. yang akan membuat program yang di jalankan akan looping terus menerus ketika salah memilih angka maupun huruf.
// Program ini hanya menggunakan sebuah angka untuk memilih pilihan di dalamnya.
void antilooping() {
        if(cin.fail()){ // jika salah menekan atau memasukkan huruf kecuali ketika memasukan nama. program akan mencetak apa yang ada di sini.
        cout << "Pilihan tidak valid, silahkan masukan angka!" << endl;
        cin >> pilihan ;
    }else { // jika user memasukan angka yang tidak ada dalam program ini. Program akan mencetak apa yang ada di sini.
        cout << WARNA_CYAN << "Pilihan tersebut belum tersedia!" << endl << endl;;
        cout << WARNA_KUNING << "=======================================" << endl;
    }
}
int main(int argc, char** argv) {
    // Code di bawah ini adalah nilai yang akan di isi di struct yang sudah saya buat di awal.
    Segitiga segitiga[] = {
        {},
        {"Segitiga Sama Sisi", "Rumus : 1/2 x alas x tinggi", "Rumus : 3 x Panjang Sisi"},
        {"Segitiga Sama Kaki", "Rumus : 1/2 x alas x tinggi", "Rumus : (2 x sisi miring) + alas"},
        {"Segitiga Siku Siku", "Rumus : 1/2 x alas x tinggi", "Rumus : Sisi miring^2 = tinggi^2 + alas^2"},
    };
    Kerucut kerucut[] = {
        {"Rumus : phi x jari(r) x akar( jari(r) x jari(r) + tinggi(t) x tinggi(t))",
         "Rumus : phi x jari(r) x jari(r)",
         "Rumus : Luas alas + Luas Selimut",
         "Rumus : Akar 2 (3 x volume) / (phi x tinggi)",
         "Rumus : Luas selimut / phi x selimut",
         "Rumus : 1/3 x phi x jari(r) x jari(r) x tinggi(t)",}
    };
    Tabung tabung[] = {
        {"Rumus : 2 x phi x jari(r) x jari(r)", "Rumus : 2 x phi z jari(r)", "Rumus : 2 x phi x jari(r) x jari(r) x tinggi", "Rumus : phi x jari(r) x jari(r) x tinggi", "Rumus : 2 X phi x jari(r)",}
    };
    Rumus rumusUniversal[] = {
        {"Persegi", "Rumus : sisi x sisi atau S x S", "Rumus : 4 x sisi atau 4 x S"},
        {"Persegi Panjang", "Rumus : Panjang x Lebar atau P x L", "Rumus : 2 x (Panjang x Lebar) atau 2 x (P x L)"},
        {"Lingkaran", "Rumus : phi x jari(r) x jari(r) atau phi x r x r", "Rumus : 2 x phi x jari(r) atau 2 x phi x r", "error", "Rumus : 2 x jari - jari"},
        {"Kubus", "Rumus luas permukaan : sisi x sisi atau S x S\nRumus Luas sisi : 6 x sisi(s) x sisi(s)", "Rumus : 12 x sisi atau  12 x s", "Rumus : sisi x sisi x sisi atau s x s x s"},
        {"Balok", "Rumus : 2 x (Panjang x Lebar) + (Panjang x Tinggi) + (Lebaar x Tinggi)", "Rumus : 4 x (Panjang x Lebar x Tinggi) atau 4 x (P x L x T)", "Rumus : Panjang x lebar x tinggi atau P x L x T"},
    };
        system("cls"); // system cls ini berfungsi untuk membersihkan terminal ketaka program dijalankan.
            cout << WARNA_HITAM << "================================================================" << WARNA_RESET << endl;
            cout << WARNA_CYAN << "|| Kalkulator Bangun Datar dan Bangun Ruang                   ||"<< WARNA_RESET << endl;
            cout << WARNA_KUNING_TEBAL << "|| Note : Memilih di program ini hanya menggunakan angka saja ||"<< WARNA_RESET << endl;
            cout << WARNA_CYAN << "|| Terima kasih sudah membaca semoga sukses :D                ||"<< WARNA_RESET << endl;
            cout << WARNA_HITAM << "================================================================"<< WARNA_HITAM << endl <<endl;
            cout << WARNA_KUNING << "Loading." ;
            cout.flush(); // code ini berfungsi memaksakan program untuk segera menampilkan output ke konsol tanpa ada buffer

        for (int i = 0; i < 10; ++i) { // mengulang menampilkan titik ( . ) sebanyak 10 kali.
            cout << ".";
            cout.flush();  // code ini berfungsi memaksakan program untuk segera menampilkan output ke konsol tanpa ada buffer
            sleep(1); // Tunggu 1 detik
        } 
        // tampilan awal program ketika di jalankan.
        system("cls"); // system cls ini berfungsi untuk membersihkan terminal ketaka program dijalankan.
        cout << "Loading selesai!" << endl;
        cout << WARNA_HITAM << "============================================================================" << WARNA_RESET << endl;
        cout << WARNA_KUNING << "||" << WARNA_CYAN << " Selamat Datang Di Program Kalkulator Menghitung Bangun Datar dan Ruang "<< WARNA_KUNING << "||" << WARNA_RESET << endl;
        cout << WARNA_KUNING << "|| Tolong Masukan Nama Anda : ";
        tampilkanNama(); // memanggil fungsi tampilkanNama untuk di jalankan
        system("cls"); // system cls ini berfungsi untuk membersihkan terminal ketaka program dijalankan.
        
    // Memasuki Tampilan Utama Program
    while (true) {
        system("cls"); // system cls ini berfungsi untuk membersihkan terminal ketaka program dijalankan.
        int tampilkan;
        cout << "Haloo " << WARNA_CYAN_TEBAL << nama << WARNA_KUNING << " siap untuk menghitung?" << endl << endl;
        cout << "==================================" << endl;
        cout << WARNA_CYAN << "Pilih bangun yang akan dihitung : " << endl;
        cout << "1. Bangun Datar" << endl << "2. Bangun Ruang" << endl << "0. Keluar" << WARNA_KUNING << endl;
        cout << "==================================" << endl << endl;
        cout << "Masukan Angka : ";
        cin >> tampilkan ;

        /* Validdasi Inputan user ketika memilih tampilan, kalau tidak sesuai
        maka ia keluar dari program dan mencetak apa yang ada di bawah ini */
        while (cin.fail()) {
        cout << endl << endl;
        cout << WARNA_HITAM << "=================================================" << WARNA_KUNING << endl;
        cout << WARNA_CYAN << "Kamu keluar dari program ini." << endl;
        cout << "Karena Kamu tidak memasukan pilihan berupa "<< WARNA_KUNING_TEBAL << "angka " << endl;
        cout << WARNA_HITAM << "=================================================" << WARNA_KUNING << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
            if (tampilkan == 0 ) { // ketika user memilih angka 0 otomatis akan keluar dari program.
             break;
            }

        // Program bangun datar bisma
        do // menampilkan output yang didalamnya terlebih dahulu baru user memilih apakah mereka akan mengulang atau tidak.
        {

        if (tampilkan == 1) {
            system("cls"); 
            tampilkanMenuDatar(); // Code ini akan memanggil fungsi tampilkanMenuDatar untuk menampilkan menunya.
            cout << "Masukan Angka : ";
            cin >> pilihan;
            if (pilihan == 0) { // pilihan angka "0" ini akan membuat user kembali ke menu utama.
                break;
            }
        // Code dibawah comment ini berfungsi untuk mengubah interger bangun datar menjadi 0 kembali.
        bangunDatar bangun = static_cast<bangunDatar>(pilihan - 1);
            // User akan di minta untuk memilih bangun datar apa yang akan di hitung dengan memasukan angka.
            /* Disini saya menggunakan switch case untuk decisionnya atau pengkondisian karena nilai yang akan dipilih cuma 1 saja
            tapi untuk di dalam switch casenya saya gunakan if esle untuk memudahkan pengkondisian*/
            // Input nilai sesuai bangun yang dipilih
            switch (bangun) {
                case PERSEGI: {
                    system("cls");
                    double sisi;
                    cout << "Kamu memilih bangun datar " << rumusUniversal[0].nama  << endl << endl;
                    cout << "==================================" << endl;
                    cout << WARNA_CYAN << "Mau menghitung Luas atau Keliling?" << endl;
                    cout << "1. Luas Persegi" << endl << "2. Keliling Persegi" << endl << "3. Keduanya" << WARNA_KUNING << endl;
                    cout << "==================================" << endl << endl;
                    cout << "Masukan Angka : " ;
                    cin >> pilihan;
                    if (pilihan == 1) {
                        double sisi;
                        cout << "Masukan Angka panjang sisi persegi: ";
                        cin >> sisi;
                        cout << endl;
                        cout << "=======================================" << endl;
                        cout << WARNA_CYAN << "Luas persegi: " << hitungLuasPersegi(sisi) << "cm" << endl;
                        cout << rumusUniversal[0].rumusLuas << WARNA_KUNING << endl;
                        cout << "=======================================" << endl;
                    } else if (pilihan == 2) {
                        cout << "Masukan Angka panjang sisi persegi: ";
                        cin >> sisi;
                        cout << endl;
                        cout << "=======================================" << endl;
                        cout << WARNA_CYAN << "Keliling persegi: " << hitungKelilingPersegi(sisi) << "cm" << endl;
                        cout << rumusUniversal[0].rumusKeliling << WARNA_KUNING << endl;
                        cout << "=======================================" << endl;
                    } else if(pilihan == 3){
                        cout << "Masukan Angka panjang sisi persegi: ";
                        cin >> sisi;
                        cout << endl;
                        cout << "=======================================" << endl;
                        cout << WARNA_CYAN << "Keliling persegi: " << hitungKelilingPersegi(sisi) << "cm" << endl;
                        cout << "Luas persegi: " << hitungLuasPersegi(sisi) << "cm" << WARNA_KUNING << endl;
                        cout << "=======================================" << endl;
                    }else {
                        antilooping();
                    }
                    break;
                }
                case PERSEGI_PANJANG: {
                    system("cls");
                    double panjang;
                    double lebar;
                    cout << "Kamu memilih bangun datar " << rumusUniversal[1].nama << endl << endl;
                    cout << "==================================" << endl;
                    cout << WARNA_CYAN << "Mau menghitung luas atau Keliling?" << endl;
                    cout << "1. Luas Persegi Panjang" << endl << "2. Keliling Persegi Panjang" << endl << "3. Keduanya" << WARNA_KUNING << endl;
                    cout << "==================================" << endl << endl;
                    cout << "Masukan Angka : ";
                    cin >> pilihan;
                    if (pilihan == 1) {
                        cout << "Masukan Angka panjang persegi panjang : ";
                        cin >> panjang;
                        cout << "Masukan Angka lebar persegi panjang : ";
                        cin >> lebar;
                        cout << endl;
                        cout << "=======================================" << endl;
                        cout << WARNA_CYAN << "Luas persegi panjang : " << hitungLuas_persegiPanjang(panjang, lebar) << "cm" << endl;
                        cout << rumusUniversal[1].rumusLuas << WARNA_KUNING << endl;
                       // cout << "Cara Pengerjaan dari inputan diatas : " << endl << panjang << "cm" << " x " << lebar << "cm = "<<hitungLuas_persegiPanjang(panjang, lebar) << endl;
                        cout << "=======================================" << endl;
                    } else if (pilihan == 2) {
                        cout << "Masukan Angka panjang persegi panjang : ";
                        cin >> panjang;
                        cout << "Masukan Angka lebar persegi panjang : ";
                        cin >> lebar;
                        cout << endl;
                        cout << "=======================================" << endl;
                        cout << WARNA_CYAN << "Keliling persegi panjang : " << hitungKeliling_persegiPanjang(panjang, lebar) << "cm" << endl;
                        cout << rumusUniversal[1].rumusKeliling << WARNA_KUNING << endl;
                        cout << "=======================================" << endl;
                        //cout << "Cara Pengerjaan dari inputan diatas : " << endl << "2 x " << panjang << "cm" << " x " << lebar << "cm" << endl;
                    } else if (pilihan == 3) {
                        cout << "Masukan Angka panjang persegi panjang : ";
                        cin >> panjang;
                        cout << "Masukan Angka lebar persegi panjang : ";
                        cin >> lebar;
                        cout << endl;
                        cout << "=======================================" << endl;
                        cout << WARNA_CYAN << "Luas persegi panjang : " << hitungLuas_persegiPanjang(panjang, lebar) << "cm" << endl;
                        cout << "Keliling persegi panjang : " << hitungKeliling_persegiPanjang(panjang, lebar)  << "cm" << WARNA_KUNING << endl;
                        cout << "=======================================" << endl;
                }else {
                        antilooping();
                    }
                    break;
                }
                case LINGKARAN: {
                    system("cls");
                    double jari;
                    cout << "Kamu memilih bangun datar " << rumusUniversal[2].nama << endl << endl;
                    cout << "======================================================================" <<endl;
                    cout << WARNA_CYAN << "Apakah kamu sudah tau jari - jari lingkaran yang akan dihitung berapa?" << endl << "1. Sudah" << endl << "2. Belum" << WARNA_KUNING << endl;
                    cout << "======================================================================" <<endl << endl;
                    cout << "Masukan Angka : ";
                    cin >> pilihan;
                        if(pilihan == 1){
                            cout << "Ternyata kamu sudah tau jari jari lingkaran" << endl << endl;
                            cout << "============================================" <<endl;
                            cout << WARNA_CYAN << "Mau menghitung Luas atau Keiling?" << endl;
                            cout << "1. Luas Lingkaran" << endl << "2. Keliling Lingkaran" << endl << "3. Keduanya" << WARNA_KUNING << endl;
                            cout << "============================================" <<endl << endl;
                            cout << "Masukan Angka : ";
                            cin >> pilihan;
                            if (pilihan == 1) {
                            cout << "Masukan jari jari lingkaran: ";
                            cin >> jari;
                            cout << endl;
                            cout << "=======================================================" << endl;
                            cout << WARNA_CYAN << "Luas lingkaran : " << hitungLuas_Lingkaran(jari) << " cm" << endl;
                            cout << rumusUniversal[2].rumusLuas << WARNA_KUNING << endl;
                            cout << "=======================================================" << endl;
                            } else if (pilihan == 2) {
                                cout << "Masukan jari jari lingkaran : ";
                                cin >> jari;
                                cout << endl;
                                cout << "=======================================================" << endl;
                                cout << WARNA_CYAN << "Keliling lingkaran : " << hitungKeliling_Lingkaran(jari) << " cm" << endl;
                                cout << rumusUniversal[2].rumusKeliling << WARNA_KUNING << endl;
                                cout << "=======================================================" << endl;
                            } else if (pilihan == 3) {
                                cout << "Masukan jari jari lingkaran: ";
                                cin >> jari;
                                cout << endl;
                                cout << "=======================================" << endl;
                                cout << WARNA_CYAN << "Luas lingkaran : " << hitungLuas_Lingkaran(jari) << " cm" << endl;
                                cout << "Keliling lingkaran : " << hitungKeliling_Lingkaran(jari) << " cm" << WARNA_KUNING << endl;
                                cout << "=======================================" << endl;
                            }else {
                                antilooping();
                            }
                        } else if (pilihan == 2){
                            double diameter;
                            cout << endl;
                            cout << "===============================================================" << endl;
                            cout << WARNA_CYAN << "Kamu pasti mempunyai Diameter dari lingkaran tersebut" << WARNA_KUNING << endl;
                            cout << "===============================================================" << endl;
                            cout << "Masukan Diameter dari lingkaran kamu : ";
                            cin >> diameter;
                            cout << endl;
                            cout << "===============================================================" << endl;
                            cout << WARNA_CYAN << "Jari- jari lingkaran kamu adalah :" << hitungDiameter(diameter) << " cm" << endl;
                            cout << rumusUniversal[2].diameter << WARNA_KUNING << endl;
                            cout << "===============================================================" << endl << endl;
                            cout << WARNA_CYAN << "Apakah kamu ingin menghitung luas atau keliling lingkaran?" << endl;
                            cout << "1. Luas lingkaran" << endl << "2. Keliling lingkaran" << endl << "3. Keduanya" << WARNA_KUNING << endl;
                            cout << "=======================================" << endl << endl;
                             cout << "Masukan Angka : " ;
                            cin >> pilihan;
                            if (pilihan == 1) {
                            cout << "Masukan jari jari lingkaran: ";
                            cin >> jari;
                            cout << endl;
                            cout << "=======================================" << endl;
                            cout << WARNA_CYAN << "Luas lingkaran : " << hitungLuas_Lingkaran(jari) << " cm" << endl;
                            cout << rumusUniversal[2].rumusLuas << WARNA_KUNING << endl;
                            cout << "=======================================" << endl;
                            } else if (pilihan == 2) {
                                cout << "Masukan jari jari lingkaran : ";
                                cin >> jari;
                                cout << endl;
                                cout << "==============================================" << endl;
                                cout << WARNA_CYAN << "Keliling lingkaran : " << hitungKeliling_Lingkaran(jari) << " cm" << endl;
                                cout << rumusUniversal[2].rumusKeliling << WARNA_KUNING << endl;
                                cout << "==============================================" << endl;
                            } else if (pilihan == 3) {
                                cout << "Masukan jari jari lingkaran: ";
                                cin >> jari;
                                cout << endl;
                                cout << "==============================================" << endl;
                                cout << WARNA_CYAN << "Luas lingkaran : " << hitungLuas_Lingkaran(jari) << " cm" << endl;
                                cout << "Keliling lingkaran : " << hitungKeliling_Lingkaran(jari) << " cm" << WARNA_KUNING << endl;
                                cout << "==============================================" << endl;
                            }else {
                                antilooping();
                            }
                        } else {
                            antilooping();
                        }
                        break;
                    }
                case SEGITIGA: {
                    system("cls");
                    double alas, tinggi, sisi, miring;
                    cout << "Kamu memilih bangun datar segitiga" << endl <<endl;
                    cout << "=============================================================================" << endl;
                    cout <<WARNA_CYAN << "Pilih Salah Satu Menu Di Bawah ini" << endl;

                    for (int i = 1; i < 4; i++) {
                        cout << i <<". "<< segitiga[i].nama <<" || ";}
                    cout << WARNA_KUNING << endl;
                    
                    cout << "=============================================================================" << endl << endl;
                    cout << "Masukan Angka : " ;
                    cin >> pilihan;
                    if (pilihan == 1) {
                    system("cls");
                    cout << "Kamu memilih menghitung segitiga sama sisi" << endl << endl;
                    cout << "=======================================" << endl;
                    cout << WARNA_CYAN << "Mau menghitung Luas atau Keliling?" << endl;
                    cout << "1. Luas segitiga sama sisi" << endl << "2. Keliling segitiga sama sisi" << WARNA_KUNING << endl;
                    cout << "=======================================" << endl << endl;
                    cout << "Masukan Angka : ";
                    cin >> pilihan;
                        if (pilihan == 1) {
                        cout << "Masukan Angka alas segitiga : ";
                        cin >> alas;
                        cout << "Masukan Angka tinggi segitiga : ";
                        cin >> tinggi;
                        cout << endl;
                        cout << "=======================================" << endl;
                        cout << WARNA_CYAN << "Luas Segitiga Sama Sisi : " << segitiga[0].luasSegitiga(alas, tinggi) << " cm" << endl;
                        cout << segitiga[1].rumusLuas << WARNA_KUNING << endl;
                        cout << "=======================================" << endl;
                        } else if (pilihan == 2) {
                            cout << "Masukan Angka sisi segitiga : ";
                            cin >> sisi;
                            cout << endl;
                            cout << "=======================================" << endl;
                            cout << WARNA_CYAN << "Keliling Segitiga Sama Sisi  : " << segitiga[0].kelilingSegitigaSamaSisi(sisi) << " cm" << endl;
                            cout << segitiga[1].rumusKeliling << WARNA_KUNING << endl;
                            cout << "=======================================" << endl;
                        } else {
                            antilooping();
                        }
                    } else if (pilihan == 2) {
                    system("cls");
                    cout << "Kamu memilih menghitung segitiga sama kaki" << endl << endl;
                    cout << "=======================================" << endl;
                    cout << WARNA_CYAN << "Mau menghitung Luas atau Keliling?" << endl;
                    cout << "1. Luas segitiga sama kaki" << endl << "2. Keliling segitiga sama kaki" << WARNA_KUNING << endl;
                    cout << "=======================================" << endl << endl;
                    cout << "Masukan Angka : ";
                    cin >> pilihan;
                        if (pilihan == 1) {
                        cout << "Masukan Angka alas segitiga : ";
                        cin >> alas;
                        cout << "Masukan Angka tinggi segitiga : ";
                        cin >> tinggi;
                        cout << endl;
                        cout << "=======================================" << endl;
                        cout << WARNA_CYAN << "Luas segitiga sama kaki : " << segitiga[0].luasSegitiga(alas, tinggi) << " cm" << endl;
                        cout << segitiga[2].rumusLuas << WARNA_KUNING << endl;
                        cout << "=======================================" << endl;
                        } else if (pilihan == 2) {
                            cout << "Masukan Angka sisi miring segitiga : ";
                            cin >> miring;
                            cout << "Masukan Angka alas segitiga  : ";
                            cin >> alas;
                            cout << endl;
                            cout << "=======================================" << endl;
                            cout << WARNA_CYAN << "Keliling segitiga sama kaki: " << segitiga[0].kelilingSegitigaSamaKaki(miring, alas) << " cm" << endl;
                            cout << segitiga[2].rumusKeliling << WARNA_KUNING << endl;
                            cout << "=======================================" << endl;
                        } else{
                            antilooping();
                        }
                    } else if (pilihan == 3) {
                        system ("cls");
                        cout << "Kamu memilih menghitung segitiga siku-siku" << endl << endl;
                        cout << "=======================================" << endl;
                        cout << WARNA_CYAN << "Mau menghitung Luas atau Keliling?" << endl;
                        cout << "1. Luas segitiga siku-siku" << endl << "2. Keliling segitiga siku-siku" << WARNA_KUNING << endl;
                        cout << "=======================================" << endl << endl;
                        cout << "Masukan Angka : ";
                        cin >> pilihan;
                        if (pilihan == 1) {
                            cout << "Masukan Angka alas segitiga : ";
                            cin >> alas;
                            cout << "Masukan Angka tinggi segitiga : ";
                            cin >> tinggi;
                            cout << endl;
                            cout << "=======================================" << endl;
                            cout << WARNA_CYAN << "Luas segitiga siku - siku : " << segitiga[0].luasSegitiga(alas, tinggi) << " cm" << endl;
                             cout << segitiga[3].rumusLuas << WARNA_KUNING << endl;
                            cout << "=======================================" << endl;
                        } else if (pilihan == 2) {
                            cout << "Masukan Angka tinggi segitiga : ";
                            cin >> tinggi;
                            cout << "Masukan Angka alas segitiga : ";
                            cin >> alas;
                            cout << "Masukan Angka miring segitiga : ";
                            cin >> miring;
                            cout << endl;
                            cout << "=======================================" << endl;
                            cout << WARNA_CYAN << "Keliling segitiga siku - siku : " << segitiga[0].kelilingSegitigaSikuSiku(miring, alas, tinggi) << " cm" << endl;
                            cout << segitiga[3].rumusKeliling << WARNA_KUNING << endl;
                            cout << "=======================================" << endl;
                        } else {
                                antilooping();
                        }
                    } else {
                        antilooping();
                    }
                        break;
                    }
                default: {
                    antilooping();
                }
            }
        cout << endl;
         cout << WARNA_CYAN << "Ketik 1 untuk mengulang ke bangun datar" << WARNA_KUNING << endl; // sebelum mengakhiri mengunakan kalkulator bangun datar ini user diminta untuk memasukan sebuah angka kalau ingin mengulang menghitung bangun datar.
         cout << "Masukan Angka : ";
         cin >>  tampilkan;
        }
    } while (tampilkan == 1);
                
      do // Program bangun ruang bisma
        {
        if (tampilkan == 2) {
            system("cls");
            tampilkanMenuRuang();  // Code ini akan memanggil fungsi tampilkanMenuRuang untuk menampilkan menunya.
            int pilihan;
            cout << "Masukan Angka : ";
            cin >> pilihan;
            if (pilihan == 0) { // pilihan angka "0" ini akan membuat user kembali ke menu utama.
                break;
            }

        bangunRuang bangun = static_cast<bangunRuang>(pilihan - 1);
            // Input nilai sesuai bangun yang dipilih
            // User akan di minta untuk memilih bangun datar apa yang akan di hitung dengan memasukan angka.
            /* Disini saya menggunakan switch case untuk decisionnya atau pengkondisian karena nilai yang akan dipilih cuma 1 saja
            tapi untuk di dalam switch casenya saya gunakan if esle untuk memudahkan pengkondisian*/
            switch (bangun) {
                case KUBUS: {
                    system("cls");
                    double sisi;
                    cout << "Kamu memilih Bangun Ruang Kubus" << endl << endl;
                    cout << "========================================================" << endl;
                    cout << WARNA_CYAN << "Mau menghitung Luas, Volume, atau Keliling?" << endl;
                    cout << "1. Luas kubus" << endl << "2. Volume Kubus" << endl << "3. Keliling Kubus" << endl << "4. Hitung Semua" << endl;
                    cout << WARNA_KUNING << "========================================================" << endl << endl;
                    cout << "Masukan Angka : " ;
                    cin >> pilihan;
                    if (pilihan == 1) {
                    cout << "Masukan panjang sisi kubus : ";
                    cin >> sisi;
                    cout << endl;
                    cout << "========================================================" << endl;
                    cout << WARNA_CYAN << "Luas sisi kubus : " << hitungLuasKubus(sisi) << "cm" << endl;
                    cout << "Luas permukaan kubus : " << hitungLuasPermukaanKubus(sisi) << "cm" << endl;
                    cout << rumusUniversal[3].rumusLuas << endl;
                    cout << WARNA_KUNING << "========================================================" << endl;
                    } else if (pilihan == 2) {
                        cout << "Masukan panjang sisi Kubus : ";
                        cin >> sisi;
                        cout << endl;
                        cout << "========================================================" << endl;
                        cout << WARNA_CYAN << "Volume kubus :  " << hitungVolumeKubus(sisi) << "cm" << endl;
                        cout << rumusUniversal[3].rumusVolume << endl;
                        cout << WARNA_KUNING << "========================================================" << endl;
                    } else if (pilihan == 3) {
                        cout << "Masukan panjang sisi Kubus : ";
                        cin >> sisi;
                        cout << endl;
                        cout << "========================================================" << endl;
                        cout << WARNA_CYAN <<  "Keliling kubus : " << hitungKelilingKubus(sisi) << "cm" << endl;
                        cout << rumusUniversal[3].rumusKeliling << endl;
                        cout << WARNA_KUNING << "========================================================" << endl;
                    } else if (pilihan == 4) {
                        cout << "Masukan panjang sisi Kubus : ";
                        cin >> sisi;
                        cout << endl;;
                        cout << "========================================================" << endl;
                        cout << WARNA_CYAN << "Luas Permukaan Kubus: " << hitungLuasPermukaanKubus(sisi) << "cm" << endl;
                        cout << "Volume kubus :  " << hitungVolumeKubus(sisi) << "cm" << endl;
                        cout << "Keliling kubus : " << hitungKelilingKubus(sisi) << "cm" << endl;
                        cout << WARNA_KUNING << "========================================================" << endl;
                    } else {
                       antilooping();
                    }
                    break;
                }
                case BALOK: {
                    system("cls");
                    double panjang;
                    double lebar;
                    double tinggi;
                    cout << "Kamu memilih Bangun Ruang Balok" << endl << endl;
                    cout <<  "========================================================" << endl;
                    cout << WARNA_CYAN << "Mau menghitung Luas, Volume, atau Keliling?" << endl;
                    cout << "1. Luas permukaan balok" << endl << "2. Volume balok" << endl << "3. Keliling balok" << endl << "4. Hitung semua" << endl;
                    cout << WARNA_KUNING <<  "========================================================" << endl;
                    cout << "Masukan Angka : " ;
                    cin >> pilihan;
                    if (pilihan == 1) {
                    cout << "Masukan Angka panjang balok : ";
                    cin >> panjang;
                    cout << "Masukan Angka lebar balok : ";
                    cin >> lebar;
                    cout << "Masukan Angka tinggi balok : ";
                    cin >> tinggi;
                    cout << endl;
                    cout << "========================================================" << endl;
                    cout << WARNA_CYAN << "Luas permukaan balok : " << hitungLuasPermukaanBalok(panjang, lebar, tinggi) << " cm" << endl;
                    cout << rumusUniversal[4].rumusLuas << endl;
                    cout << WARNA_KUNING << "========================================================" << endl;
                    } else if (pilihan == 2) {
                        cout << "Masukan Angka panjang balok : ";
                        cin >> panjang;
                        cout << "Masukan Angka lebar balok : ";
                        cin >> lebar;
                        cout << endl;
                        cout << "========================================================" << endl;
                        cout << WARNA_CYAN << "Volume balok : " << hitungVolumeBalok(panjang, lebar, tinggi) << " cm" << endl;
                        cout << rumusUniversal[4].rumusVolume << endl;
                        cout << WARNA_KUNING << "========================================================" << endl;
                    } else if (pilihan == 3){
                        cout << "Masukan Angka panjang balok : ";
                        cin >> panjang;
                        cout << "Masukan Angka lebar balok : ";
                        cin >> lebar;
                        cout << "Masukan Angka tinggi balok : ";
                        cin >> tinggi;
                        cout << endl;
                        cout << "========================================================" << endl;
                        cout << WARNA_CYAN <<  "Keliling balok : " << hitungKelilingBalok(panjang, lebar, tinggi) << " cm" << endl;
                        cout << rumusUniversal[4].rumusKeliling << endl;
                        cout << WARNA_KUNING <<  "========================================================" << endl;
                    } else if (pilihan == 4) {
                        cout << "Masukan panjang balok : ";
                        cin >> panjang;
                        cout << "Masukan lebar balok : ";
                        cin >> lebar;
                        cout << "Masukan tinggi balok : ";
                        cin >> tinggi;
                        cout << endl;
                        cout << "========================================================" << endl;
                        cout << WARNA_CYAN << "Luas Permukaan Balok : " << hitungLuasPermukaanBalok(panjang, lebar, tinggi) << " cm" << endl;
                        cout << "Volume Balok : " << hitungVolumeBalok(panjang, lebar, tinggi) << " cm" << endl;
                        cout << "Keliling Balok : " << hitungKelilingBalok(panjang, lebar, tinggi) << " cm" << endl;
                        cout << WARNA_KUNING << "========================================================" << endl;
                    } else {
                        antilooping();
                    }
                    break;
                }
                case TABUNG: {
                    system("cls");
                    double jari;
                    double tinggi;
                    cout << "Kamu memilih Bangun Ruang Tabung" << endl << endl;
                    cout <<  "========================================================" << endl;
                    cout << WARNA_CYAN << "Mau menghitung Luas, Volume, atau Keliling?" << endl;
                    cout << "1. Luas tabung" << endl << "2. Volume tabung" << endl << "3. Keliling alas tabung"<< endl;
                    cout << WARNA_KUNING <<  "========================================================" << endl;
                    cout << "Masukan Angka : " ;
                    cin >> pilihan;
                    if (pilihan == 1) {
                        cout << "Kamu memilih luas tabung!" << endl << endl;
                        cout <<  "========================================================" << endl;
                        cout << WARNA_CYAN << "Pilih Salah Satu Menu Di Bawah ini" <<endl;
                        cout << "1. Luas permukaan" << endl << "2. Luas tutup dan alas" << endl << "3. luas selimut" << endl << "4. Hitung semua luas" << endl;
                        cout << WARNA_KUNING <<  "========================================================" << endl << endl;
                        cout << "Masukan Angka : " ;
                        cin >> pilihan;
                        if (pilihan == 1) {
                            cout << "Masukan Angka jari jari lingkaran tabung : ";
                            cin >> jari;
                            cout << endl;
                            cout << "========================================================" << endl;
                            cout << WARNA_CYAN << "Luas permukaan tabung : " << tabung[0].luasPermukaanTabung(jari) << " cm" << endl;
                            cout << tabung[0].luasPermukaan << endl;
                            cout << WARNA_KUNING << "========================================================" << endl;
                        } else if (pilihan == 2) {
                            cout << "Masukan Angka jari jari lingkaran tabung : ";
                            cin >> jari;
                            cout << endl;
                            cout << "========================================================" << endl;
                            cout << WARNA_CYAN << "Luas tutup dan alas tabung : " << tabung[0].luasTutupDanAlas_KelilingTabung(jari) << " cm" << endl;
                            cout << tabung[0].luasTutupDanAlas << endl;
                            cout << WARNA_KUNING << "========================================================" << endl;
                        } else if (pilihan == 3) {
                            cout << "Masukan Angka jari jari lingkaran tabung : ";
                            cin >> jari;
                            cout << "Masukan Angka tinggi tabung : ";
                            cin >> tinggi;
                            cout << endl;
                            cout << "========================================================" << endl;
                            cout << WARNA_CYAN << "Luas selimut tabung : " << tabung[0].luasSelimutTabung(jari, tinggi) << " cm" << endl;
                            cout << tabung[0].luasSelimut << endl;
                            cout << WARNA_KUNING << "========================================================" << endl;
                        } else if (pilihan == 4) {
                            cout << "Masukan Angka jari jari lingkaran tabung : ";
                            cin >> jari;
                            cout << "Masukan Angka tinggi tabung : ";
                            cin >> tinggi;
                            cout << endl;
                            cout << "========================================================" << endl;
                            cout << WARNA_CYAN << "Luas permukaan tabung : " << tabung[0].luasPermukaanTabung(jari) << " cm" << endl;
                            cout << "Luas tutup dan alas tabung : " << tabung[0].luasTutupDanAlas_KelilingTabung(jari) << " cm" << endl;
                            cout << "Luas selimut tabung : " << tabung[0].luasSelimutTabung(jari, tinggi) << " cm" << endl;
                            cout << WARNA_KUNING << "========================================================" << endl;
                        } else {
                            antilooping();
                        }
                    } else if (pilihan == 2) {
                        cout << "Masukan Angka jari jari tabung : ";
                        cin >> jari;
                        cout << "Masukkan Angka tinggi Balok : ";
                        cin >> tinggi;
                        cout << endl;
                        cout << "========================================================" << endl;
                        cout << WARNA_CYAN << "Volume tabung : " << tabung[0].volumeTabung(jari, tinggi) << " cm" << endl;
                        cout << tabung[0].volume << endl;
                        cout << WARNA_KUNING << "========================================================" << endl;
                    } else if (pilihan == 3){
                        cout << "Masukan Angka jari jari tabung : ";
                        cin >> jari;
                        cout << endl;
                        cout << "========================================================" << endl;
                        cout << WARNA_CYAN <<  "Keliling alas tabung : " << tabung[0].luasTutupDanAlas_KelilingTabung(jari) << " cm" << endl;
                        cout << tabung[0].keliling << endl;
                        cout << WARNA_KUNING <<  "========================================================" << endl;
                    } else {
                        antilooping();
                    }
                    break;
                }
                case KERUCUT: {
                    system("cls");
                    double jari, tinggi;
                    cout << "Kamu memilih bangun ruang Kerucut" << endl <<endl;
                    cout << "========================================================" << endl;
                    cout << WARNA_CYAN << "Mau menghitung luas atau volume?" << endl;
                    cout << "1. Luas kerucut" << endl << "2. Volume kerucut" << endl;
                    cout <<  WARNA_KUNING << "========================================================" << endl << endl;
                    cout << "Masukan Angka : ";
                    cin >> pilihan;
                    if (pilihan == 1) {
                    cout << "Kamu memilih menghitung luas bangun ruang kerucut" << endl << endl;
                    cout << "========================================================" << endl;
                    cout << WARNA_CYAN << "Pilih Salah Satu Menu Di Bawah Ini" << endl;
                    cout << "1. Luas permukaan kerucut" << endl << "2. Luas selimut kerucut" << endl << "3. Luas alas kerucut"  << endl << "4. Luas Keseluruhan" << endl;
                    cout << WARNA_KUNING << "========================================================" << endl << endl;
                    cout << "Masukan Angka : " ; 
                    cin >> pilihan;
                        if (pilihan == 1) {
                        cout << "Masukan Angka jari lingkaran kerucut : ";
                        cin >> jari;
                        cout << "Masukan Angka tinggi kerucut : ";
                        cin >> tinggi;
                        cout << endl;
                        cout << "========================================================" << endl;
                        cout << WARNA_CYAN << "Luas permukaan kerucut : " << kerucut[0].luasPermukaanKerucut(jari, tinggi)<< " cm" << endl;
                        cout << kerucut[0].luasPermukaan << endl;
                        cout << WARNA_KUNING << "========================================================" << endl;
                        } else if (pilihan == 2) {
                            cout << "Masukan Angka jari lingkaran kerucut : ";
                            cin >> jari;
                            cout << "Masukan Angka tinggi kerucut : ";
                            cin >> tinggi;
                            cout << endl;
                            cout << "========================================================" << endl;
                            cout << WARNA_CYAN << "Luas selimut kerucut : " << kerucut[0].selimutKerucut(jari, tinggi) << " cm" << endl;
                            cout << kerucut[0].luasSelimut << endl;
                            cout << WARNA_KUNING << "========================================================" << endl;
                        } else if (pilihan == 3) {
                            cout << "========================================================" << endl;
                            cout << WARNA_CYAN << "Apakah kamu sudah mengetahui jari jari dari lingkaran kerucut ?\n""1. Sudah\n""2. Belum" << endl;
                            cout << WARNA_KUNING << "========================================================" << endl << endl;
                            cout << "Masukan Angka : ";
                            cin >> pilihan;
                            if (pilihan == 1){
                            cout << "Jadi kamu sudah mengetahui jari jari lingkaram kerucut kamu" << endl;
                            cout << "Masukan Angka jari lingkaran kerucut : ";
                            cin >> jari;
                            cout << endl;
                            cout << "========================================================" << endl;
                            cout << "Luas alas kerucut : " << kerucut[0].luasAlasKerucut(jari) << " cm" << endl;
                            cout << kerucut[0].luasAlas << endl;
                            cout << "========================================================" << endl;
                            }else if (pilihan == 2) {
                                cout << "========================================================" << endl;
                                cout << "Apa yang diketahui dari soal kamu?\n" << "1. Diameter\n2. Luas selimut\n3. volume kerucut" << endl;
                                cout << "========================================================" << endl;
                                cout << "Masukan Angka : " ;
                                cin >> pilihan;
                                if(pilihan == 1){
                                double diameter;
                                cout << "Masukan diameter linggkaran kerucut : ";
                                cin >> diameter;
                                cout << endl;
                                cout << "========================================================" << endl;
                                cout << "Jari jari lingkaran kerucut : " << hitungDiameter(jari) << " cm" << endl;
                                cout << rumusUniversal[2].diameter << endl;
                                cout << "========================================================" << endl;
                                } else if (pilihan == 2) {
                                    double luasSelimut, selimut;
                                    cout << "Masukan Luas Selimut Kerucut : ";
                                    cin >> luasSelimut;
                                    cout << "Masukan Selimut Kerucut : " ;
                                    cin >> selimut;
                                    cout << endl;
                                    cout << "========================================================" << endl;
                                    cout << "Jari - Jari Lingkaran Kerucut Kamu Adalah : " << kerucut[0].jariJariKerucutSelimut(selimut, luasSelimut) << endl;
                                    cout << kerucut[0].jariSelimut << endl;
                                    cout << "========================================================" << endl;
                                } else if (pilihan == 3) {
                                    double volume;
                                    cout << "Masukan Volume Kerucut : ";
                                    cin >> volume;
                                    cout << "Masukan Tinggi Kerucut : ";
                                    cin >> tinggi;
                                    cout << endl;
                                    cout << "========================================================" << endl;
                                    cout << "Jari - Jari Lingkarang Kerucut Kamu Adalah : " << kerucut[0].jariJariKerucutVolume(volume, tinggi) << endl;
                                    cout << kerucut[0].jariVolume << endl;
                                    cout << "========================================================" << endl;
                                } else {
                                    antilooping();
                                }
                            }else if (pilihan == 4) {
                                cout << "Kamu memilih hitung semua luas kerucut";
                                cout << "Masukkan Angka jari lingkaran kerucut : ";
                                cin >> jari;
                                cout << "Masukan Angka tinggi kerucut : ";
                                cin >> tinggi;
                                cout << endl;
                                cout << "========================================================" << endl;
                                cout << WARNA_CYAN << "Luas permukaan kerucut : " << kerucut[0].luasPermukaanKerucut(jari, tinggi)<< " cm" << endl;
                                cout <<  "Luas selimut kerucut : " << kerucut[0].selimutKerucut(jari, tinggi) << " cm" << endl;
                                cout << "Luas alas kerucut : " << kerucut[0].luasAlasKerucut(jari) << " cm" << endl;
                                cout << WARNA_KUNING << "========================================================" << endl;
                            }else{
                                antilooping();
                            }
                        }
                    } else if (pilihan == 2) {
                        cout << "Kamu memilih menghitung volume bangun ruang kerucut" << endl;
                        cout << "Masukan jari - jari alas kerucut : ";
                        cin >> jari;
                        cout << "Masukan tinggi kerucut : ";
                        cin >> tinggi;
                        cout << endl;
                        cout << "========================================================" << endl;
                        cout << WARNA_CYAN << "Volume kerucut adalah : " << kerucut[0].volumeKerucut(jari, tinggi) << endl;
                        cout << kerucut[0].volume << endl;
                        cout << WARNA_KUNING << "========================================================" << endl;
                    } else {
                        antilooping();
                    }
                        break;
                    }
                default: {
                    antilooping();
                }
            }
        cout << endl;
        cout << WARNA_CYAN << "Ketik 2 untuk mengulang ke bangun Ruang" << WARNA_KUNING << endl;  // sebelum mengakhiri mengunakan kalkulator bangun datar ini user diminta untuk memasukan sebuah angka kalau ingin mengulang menghitung bangun datar.
        cout << "Masukan Angka : ";
        cin >>  tampilkan;
        }
    } while (tampilkan == 2);
    }
     return 0;
}