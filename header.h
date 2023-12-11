#ifndef HEADER_H
#define HEADER_H

// Deklarasi header

#include <ctime> // Mengimpor header ctime untuk fungsi waktu

// Deklarasi tipe data
int skor_papan();
int minimax(char papan[7][7], int depth, int alpha, int beta, bool isMaximizer, char maximizingPlayerSymbol);
typedef enum { // Mendeklarasikan enum TingkatKesulitan
    EASY,
    MEDIUM,
    HARD
} TingkatKesulitan;

typedef struct { // Mendeklarasikan struct Pemain
    char nama[10]; // Nama pemain
    char simbol; // Simbol pemain
    int score; // Skor pemain
    int level; // Level pemain
} Pemain;

typedef struct { // Mendeklarasikan struct Papan
    char kotak[7][7]; // Larik kotak papan
    int ukuran; // Ukuran papan
} Papan;

typedef struct { // Mendeklarasikan struct Permainan
    int input_awal; // Input awal permainan
    int input_cara_bermain; // Input cara bermain
    int jumlah_permain; // Jumlah permainan
    int input_more; // Input more
    int main_lagi; // Apakah ingin bermain lagi
    bool invalid_move; // Apakah gerakan tidak valid
    bool penentu_player; // Apakah sudah menentukan pemain
    bool penentu_dimensi; // Apakah sudah menentukan dimensi papan
    bool penentu_main_lagi; // Apakah sudah menentukan apakah ingin bermain lagi
    bool cursor; // Apakah kursor aktif
    bool stoptimer1; // Apakah timer 1 sudah berhenti
    bool stoptimer2; // Apakah timer 2 sudah berhenti
    TingkatKesulitan tingkatKesulitan; // Tingkat kesulitan
} Permainan;

typedef struct { // Mendeklarasikan struct Time
    int second; // Detik
} Time;

// Deklarasi variabel global

extern Permainan permainan; // Variabel global permainan
extern Papan papan; // Variabel global papan
extern Pemain pemain1, pemain2, computer; // Variabel global pemain
extern Time Timer; // Variabel global timer
extern bool main_lagi; // Variabel global main_lagi
extern clock_t start_time; // Variabel global start_time
extern const int TIME_LIMIT; // Variabel global TIME_LIMIT

// Deklarasi fungsi

// Fungsi untuk mencetak menu awal
void cetak_menu_awal();

// Fungsi untuk mencetak teks "TIK TAK TOE"
void tampilan_tiktaktoe();

// Fungsi untuk mencetak teks "1 PLAY" dan "2 EXIT"
void tampilan_cetak_menu_awal();

// Fungsi untuk keluar dari permainan
void keluar_permainan();

// Fungsi untuk menampilkan opsi how to play dan high score
void more();

// Fungsi untuk mencetak teks "1 HOW TO PLAY" dan "2 HIGH SCORE"
void tampilan_more();

// Fungsi untuk menampilkan tata cara bermain
void how_to_play();

// Fungsi untuk memilih mode permainan (single atau multiplayer)
void pilih_pemain();

// Fungsi untuk mencetak teks "1 SINGLE", "2 MULTI" dan kotak persegi panjang untuk inputan
void tampilan_pilih_pemain();

// Fungsi untuk memilih dimensi papan
void pilih_dimensi_papan();

// Fungsi untuk mencetak teks "1 3x3", "2 5x5" dan kotak persegi panjang untuk inputan
void tampilan_pilih_dimensi_papan();

// Fungsi untuk meminta input nickname pemain
void tampilan_nickname();

// Fungsi untuk mencetak teks "MASUKKAN NICKNAME" dan kotak persegi panjang untuk inputan
void tampilan_input_nickname();

// Fungsi untuk memulai permainan
void mulai_permainan();

// Fungsi untuk menghapus isi papan
void hapus_papan();

// Fungsi untuk mencetak tampilan papan permainan
void game_board_permainan();

// Fungsi untuk mencetak tampilan papan
void cetak_papan();

// Fungsi untuk mencetak warna simbol X dan O
void tampilan_color_X_O();

// Fungsi untuk mencetak tampilan emotikon pemain
void tampilan_player_biner();

// Fungsi untuk mencetak tampilan nama pemain
void tampilan_nama_player();

// Fungsi untuk mencetak tampilan skor pemain
void tampilan_score();

// Fungsi untuk mencetak tampilan aksesoris tik tak toe
void tampilan_aksesoris_tiktaktoe();

// Fungsi untuk menentukan giliran pemain
void giliran_pemain(Pemain);

// Fungsi untuk menentukan giliran komputer (easy)
void giliran_computer_easy(Pemain pemain);

// Fungsi untuk menentukan giliran komputer (medium)
void giliran_computer_medium(Pemain pemain);

// Fungsi untuk menentukan giliran komputer (hard)
void giliran_computer_hard(Pemain pemain, Pemain lawan);

// Fungsi untuk memeriksa apakah kotak kosong
bool cek_tempat_kosong(int x, int y);

// Fungsi untuk memeriksa apakah ada pemenang
char cek_menang();

// Fungsi untuk memeriksa apakah papan penuh
bool cek_papan_penuh();

// Fungsi untuk mengulangi permainan
void ulangi_permainan(char winner);

// Fungsi untuk menampilkan pemenang
void tampilan_wins(Pemain pemain);

// Fungsi untuk menampilkan seri
void tampilan_tie();

// Fungsi untuk menampilkan juara
void tampilan_champion();

// Fungsi untuk menampilkan jempol
void tampilan_good();

// Fungsi untuk meminta input apakah ingin bermain lagi
void tampilan_input_main_lagi();

// Fungsi untuk memasukkan skor baru
void masukkan_score_baru (Pemain pemain_baru);
void masukkan_score_baru_human_vs_human (Pemain pemain_baru);

// Fungsi untuk menukar posisi pemain
void tukar_posisi_pemain(Pemain *pemain1, Pemain *pemain2);

// Fungsi untuk menampilkan high score
void tampilkan_highscore();

// Fungsi untuk menampilkan high score (human vs human)
void tampilkan_highscore_human_vs_human();

// Fungsi untuk menjalankan timer untuk pemain 1
void *timer_pemain1(void *arg);

// Fungsi untuk menjalankan timer untuk pemain 2
void *timer_pemain2(void *arg);

// Fungsi untuk mengatur posisi kursor
void gotoxy(int x, int y);

// Fungsi untuk menampilkan tingkat kesulitan
void tampilan_tingkat_kesulitan();

// Fungsi untuk mendapatkan tingkat kesulitan
TingkatKesulitan get_tingkat_kesulitan();

#endif /* HEADER_H */
