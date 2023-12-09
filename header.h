#ifndef HEADER_H
#define HEADER_H

typedef struct{
    char nama[10];
    char simbol;
    int score;
}Pemain;

typedef struct{
    char kotak[7][7];
	int ukuran;
}Papan;

typedef struct{
	int input_awal;
	int input_cara_bermain;
	int jumlah_permain;
	int input_more;
	int main_lagi;
	bool invalid_move;
	bool penentu_player;
	bool penentu_dimensi;
	bool penentu_main_lagi;
	bool cursor;
	bool stoptimer1;
	bool stoptimer2;
}Permainan;

typedef struct{
	int second;
}Time;

extern Permainan permainan;
extern Papan papan;
extern Pemain pemain1, pemain2, computer;
extern Time Timer;

void cetak_menu_awal();
/*prosedur cetak menu awal dengan tujuan untuk memanggil prosedur yang ada dibawah
  IS : Tampilan untuk menampilkan menu belum tertampil
  FS : Tampilan menu sudah tertampil 
*/
void tampilan_tiktaktoe();
/*prosedur ini sebagai tampilan sebuah teks tik tak toe
  IS : Tampilan teks tik tak tou belum tertampil
  FS : Tampilan teks tik tak toe sudah tertampil 
*/
void tampilan_cetak_menu_awal();
/*prosedur ini untuk menampilkan teks "1 PLAY" dan "2 EXIT"
  IS : Tampilan teks "1 PLAY" dan "2 EXIT" belum tertampil
  FS : Tampilan teks "1 PLAY" dan "2 EXIT" sudah tertampil 
*/
	
void keluar_permainan();
/*prosedur ini untuk mencetak keluar permainan dengan tujuan untuk memanggil prosedur yang ada dibawah
  IS : Opsi untuk keluar permainan belum ada
  FS : Opsi untuk keluar permainan sudah ada 
*/
void more();
/*prosedur ini untuk menampilkan opsi dari how to play dan high score dari game tersebut
  IS : Opsi untuk melihat how to play dan high score belum ada
  FS : Opsi untuk melihat how to play dan high score sudah ada 
*/
	void tampilan_more();
/*prosedur ini untuk menampilkan teks 1 how to play dan 2 high score
  IS : Tampilan teks "1 HOW TO PLAY" dan "2 HIGH SCORE" belum tertampil
  FS : Tampilan teks "1 HOW TO PLAY" dan "2 HIGH SCORE" sudah tertampil 
*/

	void how_to_play();
/*prosedur ini digunakan untuk menampilkan tata cara bermain game ini
  IS : Tatacara bermain game belum ada
  FS : Tatacara bermain game sudah ada 
*/

void pilih_pemain();
/*prosedur pilih pemain dengan tujuan player memilih dengan siapa dia bermain singgle atau multiplayer 
  IS : Belum dapat menentukan mode permainan (singgle atau multiplayer)
  FS : Sudah dapat menentukan mode permainan (singgle atau multiplayer)
*/
	void tampilan_pilih_pemain();
/*prosedur ini untuk mencetak tampilan dari 1 single ,2 multi, dan kotak persegi panjang untuk inputan
  IS : Tampilan teks "1 SINGLE", "2 MULTI" dan kotak persegi panjang untuk inputan belum tertampil
  FS : Tampilan teks "1 SINGLE", "2 MULTI" dan kotak persegi panjang untuk inputan sudah tertampil
*/
	
void pilih_dimensi_papan();
/*prosedur pilih dimensi papan untuk mencetak papan yang sesuai inputannya yang menjadi sebuah jenis papan
  IS : Belum memilih dimensi / jenis papan yang dimainkan
  FS : Sudah memilih dimensi / jenis papan yang dimainkan
*/
	void tampilan_pilih_dimensi_papan();
/*prosedur ini untuk mencetak tampilan dari jenis papan dan memilih dimensi papan
  IS : Tampilan dari jenis papan dan memilih dimensi papan belum ada
  FS : Tampilan dari jenis papan dan memilih dimensi papan sudah ada
*/

void tampilan_nickname();
/*prosedur ini untuk menginputkan nickname pemain
  IS : Belum dapat untuk memberikan nickname pemain
  FS : Dapat memberikan nickname pemain
*/
	void tampilan_input_nickname();
/*prosedur ini untuk mencetak tampilan dari persegi inputan dan memanggil beberapa modul sebelumnya sebagai tampilan
  IS : Tampilan tempat untuk menginputkan pemilihan ukuran papan belum ada
  FS : Tampilan tempat menginputkan pemilihan ukuran papan sudah ada
*/

void mulai_permainan();
/*prosedur mulai permaian prosedur adalah sebuah alur dari sebuah permaianan mulai dari cetak papan hingga penampilan high score
  IS : Belum dapat memulai permainan
  FS : Permainan sudah dapat dimulai
*/
	void hapus_papan();
/*prosedur ini untuk menghapus papan menjadi ' ' atau kotak kosong 
  IS : Papan masih terisi
  FS : Papan sudah menjadi kosong
*/
	void game_board_permainan();
/*prosedur ini berfungsi untuk mencetak alur permaianan dan desain dari sebuah permainan
  IS : Tampilan-tampilan pada gameboard belum ada
  FS : Tampilan-tampilan pada gameboard sudah ada
*/
		void cetak_papan();
/*prosedur ini untuk mencetak tampilan dari papan game yang dipilih
  IS : Papan yang sudah dipiih belum muncul atau belum tercetak
  FS : Papan yang sudah dipiih sudah muncul atau tercetak
*/
		void tampilan_color_X_O();
/*prosedur ini sebagai tampilan warna dalam simbol X berwarna merah dan simbol O berwarna hijau
  IS : Warna simbol belum berubah atau masih putih
  FS : Warna simbol menjadi memiliki warna (simbol X berwarna merah dan simbol O berwarna hijau)
*/
		void tampilan_player_biner();	
/*prosedur ini untuk mencetak tampilan dari emotikon dari orang atau computer yang didesain menggunakan angka 0 dan 1
  IS : Tidak aaa emotikon dari player
  FS : Ada emotikon dari player
*/
		void tampilan_nama_player();
/*prosedur ini untuk mencetak tampilan dari nama player yang sudah diinputkan
  IS : Tampilan nama player belum muncul
  FS : Tampilan nama player muncul
*/
		void tampilan_score();
/*prosedur ini untuk mencetak tampilan dari score dari tiap pemain
  IS : Tampilan score dari tiap player belum muncul
  FS : Tampilan score dari tiap player muncul
*/
		void tampilan_aksesoris_tiktaktoe();
/*prosedur ini untuk mencetak tampilan dari teks tik tak toe
  IS : Tampilan teks "TIK TAK TOE" tidak ada
  FS : Tampilan teks "TIK TAK TOE" ada
*/	
void giliran_pemain(Pemain);
/*prosedur ini berfungsi untuk menentukan giliran pemain bermain untuk bergerak (antara player 1 dan 2)
  IS : Tidak ada pergiliran move dari player 1 dan 2
  FS : Ada pergiliran move dari player 1 dan 2
*/	
void giliran_computer(Pemain);
/*prosedur ini berfungsi untuk membuat pergerakan komputer
  IS : Tidak ada pergerakan dari komputer`  
  FS : Ada pergerakan dari komputer
*/	
bool cek_tempat_kosong(int, int);
/*function ini berfungsi untuk mengecek apakah kotak yang di inputkan oleh pemain itu kosong atau tidak
  IS : Belum mengetahui apakah kotak itu terisi apa tidak
  FS : Mengetahui apakah kotak itu terisi apa tidak
*/
	char cek_menang();
/*function ini berfungsi untuk mengecek pemenang dari game sesuai dengan dimensi papan
  IS : Belum mengetahui siapa pemenang game
  FS : Mengetahui siapa pemenang game
*/
	bool cek_papan_penuh();
/*function ini berfungsi untuk mengecek papan apakah papan tersebut sudah terisi semua atau tidak
  IS : Belum mengetahui papan tersebut sudah terisi semua atau tidak
  FS : Mengetahui papan tersebut sudah terisi semua atau tidak
*/
	
void ulangi_permainan(char winner);
/*prosedur ini berfungsi untuk mengulangi permainan berdasarkan input yang di masukan
  IS : Belum ada opsi pengulangan permainan
  FS : Terdapat opsi pengulangan permainan
*/
	void tampilan_wins(Pemain);
/*prosedur ini untuk mencetak tampilan dari teks wins jika ada pemenang
  IS : Tidak ada tampilan teks "WIN'S"
  FS : Tampilan teks "WIN'S" tertampil
*/
	void tampilan_tie();
/*prosedur ini untuk mencetak tampilan dari teks tie jika seri
  IS : Tidak ada tampilan teks "TIE"
  FS : Tampilan teks "TIE" tertampil
*/
	void tampilan_champion();
/*prosedur ini untuk mencetak tampilan piala
  IS : Tidak ada tampilan piala
  FS : Tampilan piala tertampil
*/
	void tampilan_good();
/*prosedur ini untuk mencetak tampilan dari emotikon memberikan jempol dengan arti goodjob
  IS : Tidak ada tampilan jempol
  FS : Tampilan jempol tertampil
*/
	void tampilan_input_main_lagi();
/*prosedur ini untuk mencetak dan membaca masukan dari player apakah ingin bermain lagi atau tidak
  IS : Tidak ada opsi untuk bermain lagi
  FS : Ada opsi untuk bermain lagi
*/
	void masukkan_score_baru (Pemain pemain_baru);
/*prosedur ini untuk memasukkan score pemain setelah selesai bermain ke dalam file
  IS : Tidak ada tempat untuk menyimpan score pemain
  FS : Ada tempat untuk menyimpan score pemain
*/
	void tukar_posisi_pemain(Pemain *pemain1, Pemain *pemain2);
/*prosedur ini untuk menukar isi dua tipe data Pemain sesuai tingginya score
  IS : Posisi pemain belum tertukar
  FS : Posisi pemain sudah tertukan
*/
	void tampilkan_highscore();
/*prosedur ini untuk mencetak tampilan dari high score yang pernah bermain
  IS : Tampilan high score dalam game belum tertampil
  FS : Tampilan high score dalam game tertampil
*/

void *timer_pemain1(void *arg);
/*prosedur ini untuk mencetak tampilan dari timer untuk pemain 1
  IS : Tampilan dari timer untuk pemain 1 belum tertampil
  FS : Tampilan dari timer untuk pemain 1 tertampil
*/
void *timer_pemain2(void *arg);
/*prosedur ini untuk mencetak tampilan dari timer untuk pemain 2
  IS : Tampilan dari timer untuk pemain 2 belum tertampil
  FS : Tampilan dari timer untuk pemain 2 tertampil
*/

void gotoxy(int x, int y);
/*prosedur ini untuk menentukan tata letak sesuai koordinat x dan y yang diberikan
  IS : Tampilan tata letak masih default atau masih diujung kiri atas
  FS : Tampilan tata letak sudah sesuai dengan koordinat (x dan y) yang dimasukkan
*/

#endif /* HEADER_H */