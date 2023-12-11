#include "header.h"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<unistd.h>
#include<pthread.h>
#include <algorithm>
#include <time.h>
#include <conio.h>
#include <limits.h>

Permainan permainan;
Papan papan;
Pemain pemain1, pemain2, computer;
Time Timer;
clock_t start_time; // Global variable definition
const int TIME_LIMIT = 10; // Constant definition

void cetak_menu_awal(){
	system("cls");
	tampilan_tiktaktoe();
	tampilan_cetak_menu_awal();
}

void tampilan_tiktaktoe() {
     gotoxy(9,2);  printf("          __________   ___    _________          __________   _________    _________          __________   _________    __________ ");
    gotoxy(9,3);  printf("         |\\___   ___\\ /\\  \\  /\\   _____\\        |\\___   ___\\ /\\    __  \\  /\\  ______\\        |\\___   ___\\ /\\   ____ \\  /\\     ____\\   ");
    gotoxy(9,4);  printf("         \\|___\\  \\__| \\ \\  \\ \\ \\  \\____|        \\|___\\  \\__| \\ \\   \\_\\  \\ \\ \\ \\_____|        \\|___\\  \\__| \\ \\  \\  |\\ \\ \\ \\   \\____/ ");
    gotoxy(9,5);  printf("             \\ \\  \\    \\ \\  \\ \\ \\  \\                \\ \\  \\    \\ \\        \\ \\ \\ \\                 \\ \\  \\  \\ \\ \\  \\ \\ \\ \\ \\ \\   \\______ ");
    gotoxy(9,6);  printf("              \\ \\  \\    \\ \\  \\ \\ \\  \\                \\ \\  \\    \\ \\   ___  \\ \\ \\ \\                 \\ \\  \\  \\ \\ \\  \\ \\ \\ \\ \\ \\   ______\\ ");
    gotoxy(9,7);  printf("               \\ \\  \\    \\ \\  \\ \\ \\  \\                \\ \\  \\    \\ \\  \\ /\\  \\ \\ \\ \\                 \\ \\  \\  \\ \\ \\  \\ \\ \\ \\ \\ \\  \\_____/ ");
    gotoxy(9,8);  printf("                \\ \\  \\    \\ \\  \\ \\ \\  \\_____           \\ \\  \\    \\ \\  \\\\ \\  \\ \\ \\ \\______           \\ \\  \\  \\ \\ \\  \\_\\_\\ \\ \\ \\  \\______ ");
    gotoxy(9,9);  printf("                 \\ \\__\\    \\ \\__\\ \\ \\_______\\           \\ \\__\\    \\ \\__\\\\ \\__\\ \\ \\ \\______\\          \\ \\__\\  \\ \\ \\________\\ \\ \\_________\\ ");
    gotoxy(9,10); printf("                  \\|__|     \\|__|  \\|_______|            \\|__|     \\|__| \\|__| \\  \\_|______|          \\|__|   \\_\\|________|  \\|_________| ");

}

void tampilan_cetak_menu_awal(){
	gotoxy(55,12);printf("\033[1;32m ____       _______  ___      _______  __   __");
	gotoxy(55,13);printf("|    |     |       ||   |    |   _   ||  | |  |");
	gotoxy(55,14);printf(" |   |     |    _  ||   |    |  |_|  ||  |_|  |");
	gotoxy(55,15);printf(" |   |     |   |_| ||   |    |       ||       |");
	gotoxy(55,16);printf(" |   |     |    ___||   |___ |       ||_     _|");
	gotoxy(55,17);printf(" |   |     |   |    |       ||   _   |  |   |  ");
	gotoxy(55,18);printf(" |___|     |___|    |_______||__| |__|  |___|\033[0m");

	gotoxy(55,20);printf("\033[1;31m _______    _______  __   __  ___   _______");
	gotoxy(55,21);printf("|       |  |       ||  |_|  ||   | |       |");
	gotoxy(55,22);printf("|____   |  |    ___||       ||   | |_     _|");
	gotoxy(55,23);printf(" ____|  |  |   |___ |       ||   |   |   |");
	gotoxy(55,24);printf("| ______|  |    ___| |     | |   |   |   |");
	gotoxy(55,25);printf("| |_____   |   |___ |   _   ||   |   |   |");
	gotoxy(55,26);printf("|_______|  |_______||__| |__||___|   |___|\033[0m");

	gotoxy(67,28);printf("1 / 2 / 99 (M O R E)");
	gotoxy(65,29);printf("\033[1;37m+----------------------+");
	gotoxy(65,30);printf("|                      |");
	gotoxy(65,31);printf("+----------------------+");
	gotoxy(76,30);scanf("%d", &permainan.input_awal);getchar();
	
}

void keluar_permainan(){
	system("cls");
	
	gotoxy(55,2);printf("\033[1;37m _____  _   _     _     _   _  _  __ __   __  ___   _   _ ");
	gotoxy(55,3);printf("|_   _|| | | |   /_\\   | \\ | || |/ / \\ \\ / / / _ \\ | | | |");
	gotoxy(55,4);printf("  | |  | |_| |  //_\\\\  |  \\| ||  /    \\ V / | | | || | | |");
	gotoxy(55,5);printf("  | |  |  _  | / ___ \\ | |\\  ||   \\    | |  | |_| || |_| |");
	gotoxy(55,6);printf("  |_|  |_| |_|/_/   \\_\\|_| \\_||_|\\_\\   |_|   \\___/  \\___/ ");

	gotoxy(55,8);printf("                ____   ___   ____");
	gotoxy(55,9);printf("               |  __| / _ \\ |  _ \\");
	gotoxy(55,10);printf("               | |_  | | | || |_) |");
	gotoxy(55,11);printf("               |  _| | |_| ||  _ <");
	gotoxy(55,12);printf("               |_|    \\___/ |_| \\_\\");

	gotoxy(55,14); printf("       ____   _         _  __   _  ___  _   _   ____");
	gotoxy(55,15); printf("      |  _ \\ | |       /_\\ \\ \\ / /|_ _|| \\ | | / ___|");
	gotoxy(55,16); printf("      | |_) || |      //_\\\\ \\ V /  | | |  \\| || |  _ ");
	gotoxy(55,17); printf("      |  __/ | |___  / ___ \\ | |   | | | |\\  || |_| |");
	gotoxy(55,18); printf("      |_|    |_____|/_/   \\_\\|_|  |___||_| \\_| \\____|\033[0m");
}

void more(){
	system("cls");
	do{
		tampilan_tiktaktoe();
		tampilan_more();
		gotoxy(43,23);printf("I N V A L I D  C O D E !!");
		if (permainan.input_more == 1){
			how_to_play();break;
		}
		if (permainan.input_more == 2) {
            int highscore_choice;
            do {
                system("cls");
                printf("\n");
                gotoxy(10,12);printf("Highscore Menu: ");
				gotoxy(10,13);printf(" ____       __   __  __   __  __   __  _______  __    _    __   __  _______    _______  _______  __   __  _______  __   __  _______  _______  ______   ");
				gotoxy(10,14);printf("|    |     |  | |  ||  | |  ||  |_|  ||   _   ||  |  | |  |  | |  ||       |  |       ||       ||  |_|  ||       ||  | |  ||       ||       ||    _ |  ");
				gotoxy(10,15);printf(" |   |     |  |_|  ||  | |  ||       ||  |_|  ||   |_| |  |  |_|  ||  _____|  |       ||   _   ||       ||    _  ||  | |  ||_     _||    ___||   | ||  ");
				gotoxy(10,16);printf(" |   |     |       ||  |_|  ||       ||       ||       |  |       || |_____   |       ||  | |  ||       ||   |_| ||  |_|  |  |   |  |   |___ |   |_||_ ");
				gotoxy(10,17);printf(" |   |     |       ||       ||       ||       ||  _    |  |       ||_____  |  |      _||  |_|  ||       ||    ___||       |  |   |  |    ___||    __  |");
				gotoxy(10,18);printf(" |   |     |   _   ||       || ||_|| ||   _   || | |   |   |     |  _____| |  |     |_ |       || ||_|| ||   |    |       |  |   |  |   |___ |   |  | |");
				gotoxy(10,19);printf(" |___|     |__| |__||_______||_|   |_||__| |__||_|  |__|    |___|  |_______|  |_______||_______||_|   |_||___|    |_______|  |___|  |_______||___|  |_| ");
				
				gotoxy(10,21);printf(" _______    __   __  __   __  __   __  _______  __    _    __   __  _______    __   __  __   __  __   __  _______  __    _");
				gotoxy(10,22);printf("|       |  |  | |  ||  | |  ||  |_|  ||   _   ||  |  | |  |  | |  ||       |  |  | |  ||  | |  ||  |_|  ||   _   ||  |  | |");
				gotoxy(10,23);printf("|____   |  |  |_|  ||  | |  ||       ||  |_|  ||   |_| |  |  |_|  ||  _____|  |  |_|  ||  | |  ||       ||  |_|  ||   |_| |");
				gotoxy(10,24);printf(" ____|  |  |       ||  |_|  ||       ||       ||       |  |       || |_____   |       ||  |_|  ||       ||       ||       |");
				gotoxy(10,25);printf("| ______|  |       ||       ||       ||       ||  _    |  |       ||_____  |  |       ||       ||       ||       ||  _    |");
				gotoxy(10,26);printf("| |_____   |   _   ||       || ||_|| ||   _   || | |   |   |     |  _____| |  |   _   ||       || ||_|| ||   _   || | |   |");
				gotoxy(10,27);printf("|_______|  |__| |__||_______||_|   |_||__| |__||_|  |__|    |___|  |_______|  |__| |__||_______||_|   |_||__| |__||_|  |__|");
				
				gotoxy(74,29);printf("1 / 2 ");
                gotoxy(67,30);printf("Enter your choice: ");
				gotoxy(65,31);printf("\033[1;37m+----------------------+");
				gotoxy(65,32);printf("|                      |");
				gotoxy(65,33);printf("+----------------------+");
                gotoxy(78,32);scanf("%d", &highscore_choice);
                if (highscore_choice == 1) {
                    tampilkan_highscore(); // Tampilan highscore human vs computer
                    break;
                } else if (highscore_choice == 2) {
                    tampilkan_highscore_human_vs_human(); // Tampilan highscore human vs human
                    break;
                } else {
                    printf("Invalid choice! Please enter 1 or 2.\n");
                }
            } while (highscore_choice != 1 && highscore_choice != 2);
            break;
        }
    } while ((permainan.input_more != 1) || (permainan.input_more != 2));
}

void tampilan_more(){
	gotoxy(35,12);printf("\033[1;34m ____       __   __  _______  _     _    _______  _______    _______  ___      _______  __   __");
	gotoxy(35,13);printf("|    |     |  | |  ||       || | _ | |  |       ||       |  |       ||   |    |   _   ||  | |  |");
	gotoxy(35,14);printf(" |   |     |  |_|  ||   _   || || || |  |_     _||   _   |  |    _  ||   |    |  |_|  ||  |_|  |");
	gotoxy(35,15);printf(" |   |     |       ||  | |  ||       |    |   |  |  | |  |  |   |_| ||   |    |       ||       |");
	gotoxy(35,16);printf(" |   |     |       ||  |_|  ||       |    |   |  |  |_|  |  |    ___||   |___ |       ||_     _|");
	gotoxy(35,17);printf(" |   |     |   _   ||       ||   _   |    |   |  |       |  |   |    |       ||   _   |  |   |");
	gotoxy(35,18);printf(" |___|     |__| |__||_______||__| |__|    |___|  |_______|  |___|    |_______||__| |__|  |___|");

	gotoxy(35,20);printf("\033[0;33m _______    __   __  ___   _______  __   __    _______  _______  _______  ______    _______     ");
	gotoxy(35,21);printf("|       |  |  | |  ||   | |       ||  | |  |  |       ||       ||       ||   _  |  |       |");
	gotoxy(35,22);printf("|____   |  |  |_|  ||   | |    ___||  |_|  |  |  _____||      _||   _   ||  | | |  |    ___|");
	gotoxy(35,23);printf(" ____|  |  |       ||   | |   | __ |       |  | |_____ |     |  |  | |  ||  |_| |_ |   |___");
	gotoxy(35,24);printf("| ______|  |       ||   | |   ||  ||       |  |_____  ||     |_ |  |_|  ||    __  ||    ___|");
	gotoxy(35,25);printf("| |_____   |   _   ||   | |   |_| ||   _   |   _____| ||       ||       ||   |  | ||   |___");
	gotoxy(35,26);printf("|_______|  |__| |__||___| |_______||__| |__|  |_______||_______||_______||___|  |_||_______|");

	gotoxy(74,28);printf("\033[1;37m1 / 2 ");
	gotoxy(65,29);printf("+----------------------+");
	gotoxy(65,30);printf("|                      |");
	gotoxy(65,31);printf("+----------------------+");
	gotoxy(76,30);scanf("%d", &permainan.input_more);getchar();
}

void how_to_play(){
	system("cls");
	int back;
	gotoxy(50,2);printf("   _   _   _     _   _     _   _   _   _  ");
	gotoxy(50,3);printf("  / \\ / \\ / \\   / \\ / \\   / \\ / \\ / \\ / \\" );
	gotoxy(50,4);printf(" ( H | O | W ) ( T | O ) ( P | L | A | Y )");
	gotoxy(50,5);printf("  \\_/ \\_/ \\_/   \\_/ \\_/   \\_/ \\_/ \\_/ \\_/ \n");
	gotoxy(18,6);printf("   _     _     ===============================================================================\n");
	gotoxy(18,7);printf("  (c).-.(c)    || 1. Pilih cara bermain apakah ingin single player atau multi player.       ||\n");
	gotoxy(18,8);printf("   / ._. \\     || 2. Pilih papan yang ingin dimainkan apakah 3 x 3, 5 x 5, 7 x 7            ||\n");
	gotoxy(18,9);printf(" __\\( Y )/__   || 3. Masukan nama player                                                    ||\n");
	gotoxy(18,10);printf("(_.-/'-'\\-._)  || 4. Pemain pertama bermain terlebih dahulu dengan simbol X                 ||\n");
	gotoxy(18,11);printf("   ||   ||     || 5. Pemain kedua bermain dengan simbil O dan tidak boleh menempati tempat  ||\n");
	gotoxy(18,12);printf(" _.' `-' '._   ||    yang sama baik itu dengan pemain X atau tempat yang diisikan sebelumnya||    _     _   \n");
	gotoxy(18,13);printf("(.-./`-'\\.-.)  || 6. Teruslah bergiliran menggambar simbol masing-masing sampai salah satu  ||   (c).-.(c)  \n");
	gotoxy(18,14);printf(" `-'      `-'  ||    pemain telah menggambar tiga, empat atau lima simbol dalam satu deret  ||    / ._. \\   \n");
	gotoxy(23,15);printf("	 	 ||    atau sampai tidak ada pemain yang dapat menang                         ||  __\\( Y )/__ \n");
	gotoxy(23,16);printf("		 || 7. Apabila terdapat pemenang maka highscore akan bertambah 1              || (_.-/'-'\\-._)\n");
	gotoxy(23,17);printf("		 || 8. Apabila papan terpenuhi dan tidak ada yang membentuk deret maka        ||    ||   ||   \n");
	gotoxy(23,18);printf("		 ||    permainan dikatakan seri                                               ||  _.' `-' '._ \n");
	gotoxy(23,19);printf("		 || 9. Teruslah berlatih dan jadilah JUARA                                    || (.-./`-'\\.-.)\n");
	gotoxy(23,20);printf("		 ===============================================================================  `-'     `-'\n\n");
	do{
	gotoxy(72,28);printf("99 (B A C K)");
	gotoxy(65,29);printf("\033[1;37m+----------------------+");
	gotoxy(65,30);printf("|                      |");
	gotoxy(65,31);printf("+----------------------+");
	gotoxy(76,30);scanf("%d", &back);getchar();
	gotoxy(76,32);printf("I N V A L I D  C O D E !!");
	}while (back != 99);
	system("cls");
}

void pilih_pemain(){
    system("cls"); // Membersihkan layar konsol
    do {
        tampilan_tiktaktoe(); // Menampilkan antarmuka permainan Tic-Tac-Toe atau visual terkait
        tampilan_pilih_pemain(); // Menampilkan opsi atau pertanyaan untuk memilih pemain
    } while(permainan.penentu_player); // Melakukan pengulangan selama 'permainan.penentu_player' bernilai true
}

void tampilan_pilih_pemain(){
	gotoxy(55,12);printf("\033[1;32m ____       _______  ___   __    _  _______  ___      _______ ");
	gotoxy(55,13);printf("|    |     |       ||   | |  |  | ||       ||   |    |       |");
	gotoxy(55,14);printf(" |   |     |  _____||   | |   |_| ||    ___||   |    |    ___|");
	gotoxy(55,15);printf(" |   |     | |_____ |   | |       ||   | __ |   |    |   |___");
	gotoxy(55,16);printf(" |   |     |_____  ||   | |  _    ||   ||  ||   |___ |    ___|");
	gotoxy(55,17);printf(" |   |      _____| ||   | | | |   ||   |_| ||       ||   |___ ");
	gotoxy(55,18);printf(" |___|     |_______||___| |_|  |__||_______||_______||_______|\033[0m");

	gotoxy(55,20); printf("\033[1;34m _______    __   __  __   __  ___      _______  ___");//51
	gotoxy(55,21); printf("|       |  |  |_|  ||  | |  ||   |    |       ||   |");
	gotoxy(55,22); printf("|____   |  |       ||  | |  ||   |    |_     _||   |");
	gotoxy(55,23); printf(" ____|  |  |       ||  |_|  ||   |      |   |  |   |");
	gotoxy(55,24); printf("| ______|  |       ||       ||   |___   |   |  |   |");
	gotoxy(55,25);printf("| |_____   | ||_|| ||       ||       |  |   |  |   |");
	gotoxy(55,26);printf("|_______|  |_|   |_||_______||_______|  |___|  |___|\033[0m");

	gotoxy(84,28);printf("\033[1;37m1 / 2 ");
	gotoxy(75,29);printf("+----------------------+");
	gotoxy(75,30);printf("|                      |");
	gotoxy(75,31);printf("+----------------------+");
	gotoxy(86,30);scanf("%d", &permainan.input_cara_bermain);getchar();
	// Memeriksa input yang dimasukkan pengguna
    if((permainan.input_cara_bermain == 1) || (permainan.input_cara_bermain == 2)){
        permainan.penentu_player = false; // Jika input valid (1 atau 2), mengatur penentu_player menjadi false
    } else {
        permainan.penentu_player = true; // Jika input tidak valid, mengatur penentu_player menjadi true dan menampilkan pesan kesalahan
        gotoxy(65,32);printf("I N V A L I D  C O D E !!");
    }
    // Memeriksa input mode permainan yang dipilih
    if(permainan.input_cara_bermain == 1 || permainan.input_cara_bermain == 2) {
        permainan.penentu_player = false; // Jika input valid (1 atau 2), mengatur penentu_player menjadi false
        
        if (permainan.input_cara_bermain == 1) { // Jika pemain memilih mode single (input 1)
            // Menampilkan opsi tingkat kesulitan
            tampilan_tingkat_kesulitan();
            permainan.tingkatKesulitan = get_tingkat_kesulitan(); // Meminta pemain memilih tingkat kesulitan
        }
    } else {
        permainan.penentu_player = true; // Jika input tidak valid, mengatur penentu_player menjadi true dan menampilkan pesan kesalahan
        gotoxy(43,23);printf("I N V A L I D  C O D E !!");
    }
}

void pilih_dimensi_papan(){
    system("cls"); // Membersihkan layar konsol sebelum menampilkan tampilan pemilihan dimensi papan
    do {
        tampilan_pilih_dimensi_papan(); // Menampilkan tampilan untuk memilih dimensi papan
    } while (permainan.penentu_dimensi); // Melakukan perulangan selama variabel penentu_dimensi bernilai true
}

void tampilan_pilih_dimensi_papan(){
	gotoxy(65,2);printf("\033[1;32m _______    __   __    _______");
	gotoxy(65,3);printf("|       |  |  |_|  |  |       |");
	gotoxy(65,4);printf("|___    |  |       |  |___    |");
	gotoxy(65,5);printf(" ___|   |  |       |   ___|   |");
	gotoxy(65,6);printf("|___    |   |     |   |___    |");
	gotoxy(65,7);printf(" ___|   |  |   _   |   ___|   |");
	gotoxy(65,8);printf("|_______|  |__| |__|  |_______|\033[0m");

	gotoxy(65,10);printf("\033[0;33m _______    __   __    _______ ");
	gotoxy(65,11);printf("|       |  |  |_|  |  |       |");
	gotoxy(65,12);printf("|   ____|  |       |  |   ____|");
	gotoxy(65,13);printf("|  |____   |       |  |  |____");
	gotoxy(65,14);printf("|_____  |   |     |   |_____  |");
	gotoxy(65,15);printf(" _____| |  |   _   |   _____| |");
	gotoxy(65,16);printf("|_______|  |__| |__|  |_______|\033[0m");

	gotoxy(65,18); printf("\033[0;31m _______    __   __    _______ ");
	gotoxy(65,19); printf("|       |  |  |_|  |  |       |");
	gotoxy(65,20); printf("|___    |  |       |  |___    |");
	gotoxy(65,21); printf("    |   |  |       |      |   |");
	gotoxy(65,22);printf("    |   |   |     |       |   |");
	gotoxy(65,23);printf("    |   |  |   _   |      |   |");
	gotoxy(65,24); printf("    |___|  |__| |__|      |___|\033[0m");

	gotoxy(65,27);printf("\033[1;37mS E L E C T   D I M E N S I O N ?");
	gotoxy(76,28);printf("3 / 5 / 7");
	gotoxy(68,29);printf("+----------------------+");
	gotoxy(68,30);printf("|                      |");
	gotoxy(68,31);printf("+----------------------+\033[0m");
	gotoxy(80,30);scanf("%d", &papan.ukuran);getchar();
// Meminta input pengguna untuk memasukkan ukuran/dimensi papan. Koordinat (80,30) merupakan posisi input di layar.

if((papan.ukuran == 3) || (papan.ukuran == 5) || (papan.ukuran == 7)){
    permainan.penentu_dimensi = false;
    // Jika ukuran papan yang dimasukkan pengguna valid (3, 5, atau 7), variabel penentu_dimensi diatur menjadi false.
} else {
    permainan.penentu_dimensi = true;
    // Jika ukuran papan yang dimasukkan tidak valid, variabel penentu_dimensi diatur menjadi true.
    gotoxy(65,32);printf("I N V A L I D  C O D E !!");
    // Menampilkan pesan kesalahan 'INVALID CODE!!' pada koordinat (65, 32) di layar.
}
}
void tampilan_nickname(){
    for(int i = 1; i <= permainan.input_cara_bermain; i++){
        system("cls");
        tampilan_tiktaktoe(); // Menampilkan tampilan untuk permainan Tik Tak Toe
        tampilan_input_nickname(); // Menampilkan tampilan untuk memasukkan nickname

        if(i == 1){
            gotoxy(66,31);scanf("%s", pemain1.nama);
            // Jika iterasi saat ini adalah pertama (i == 1), maka pemain 1 diminta memasukkan nickname melalui input di koordinat (66,31)
        }

        if(i == 2){
            gotoxy(66,31);scanf("%s", pemain2.nama);
            // Jika iterasi saat ini adalah kedua (i == 2), maka pemain 2 diminta memasukkan nickname melalui input di koordinat (66,31)
        }
    }
}

void tampilan_input_nickname(){
	gotoxy(70,28);printf("\033[1;37mP L A Y E R %d", permainan.jumlah_permain+1);
	gotoxy(68,29);printf("N I C K N A M E ?");
	gotoxy(65,30);printf("+----------------------+");
	gotoxy(65,31);printf("|                      |");
	gotoxy(65,32);printf("+----------------------+");
	gotoxy(65,33);printf("M A X  1 0  C H A R\033[0m");
	//gotoxy(50,15);fgets(pemain1.nama,10, stdin);
	permainan.jumlah_permain++;
}

/*================================================================================================================*/

void tampilan_tingkat_kesulitan() {
	system("cls");
	gotoxy(55,2);printf("\033[1;32m ____       __   __  __   __  ______   _______  __   __");
	gotoxy(55,3);printf("|    |     |  |_|  ||  | |  ||      | |   _   ||  | |  |");
	gotoxy(55,4);printf(" |   |     |       ||  | |  ||  _    ||  |_|  ||  |_|  |");
	gotoxy(55,5);printf(" |   |     |       ||  |_|  || | |   ||       ||       |");
	gotoxy(55,6);printf(" |   |     |       ||       || |_|   ||       ||       |");
	gotoxy(55,7);printf(" |   |     | ||_|| ||       ||       ||   _   ||   _   |");
	gotoxy(55,8);printf(" |___|     |_|   |_||_______||______| |__| |__||__| |__|\033[0m");

	gotoxy(55,10);printf("\033[0;33m _______    _______  _______  ______   _______  __    _  _______");
	gotoxy(55,11);printf("|       |  |       ||       ||      | |   _   ||  |  | ||       |");
	gotoxy(55,12);printf("|____   |  |  _____||    ___||  _    ||  |_|  ||   |_| ||    ___|");
	gotoxy(55,13);printf(" ____|  |  | |_____ |   |___ | | |   ||       ||       ||   | __");
	gotoxy(55,14);printf("| ______|  |_____  ||    ___|| |_|   ||       ||  _    ||   ||  |");
	gotoxy(55,15);printf("| |_____    _____| ||   |___ |       ||   _   || | |   ||   |_| |");
	gotoxy(55,16);printf("|_______|  |_______||_______||______| |__| |__||_|  |__||_______|\033[0m");

	gotoxy(55,18);printf("\033[0;31m  _______    _______  __   __  ___      ___   _______        ");
	gotoxy(55,19);printf("|       |  |       ||  | |  ||   |    |   | |       |       ");
	gotoxy(55,20);printf("|___    |  |  _____||  | |  ||   |    |   | |_     _|       ");
	gotoxy(55,21);printf(" ___|   |  | |_____ |  |_|  ||   |    |   |   |   |         ");
	gotoxy(55,22);printf("|___    |  |_____  ||       ||   |___ |   |   |   |         ");
	gotoxy(55,23);printf(" ___|   |   _____| ||       ||       ||   |   |   |          ");
	gotoxy(55,24);printf("|_______|  |_______||_______||_______||___|   |___|  \033[0m");
	
	gotoxy(74,27);printf("\033[1;37mMasukan Pilihan Tingkat Kesulitan:");
	gotoxy(83,28);printf("1 / 2 / 3");
	gotoxy(75,29);printf("+----------------------+");
	gotoxy(75,30);printf("|                      |");
	gotoxy(75,31);printf("+----------------------+\033[0m");
}

TingkatKesulitan get_tingkat_kesulitan() {
    int pilihan;
    gotoxy(86,30);scanf("%d", &pilihan);
    // Meminta input untuk memilih tingkat kesulitan pada koordinat (86,30) di layar.

    // Validasi pilihan
    while (pilihan < 1 || pilihan > 3) {
        gotoxy(63,32);printf("Pilihan tidak valid.");
        // Jika input tidak valid (di luar rentang 1-3), pesan kesalahan "Pilihan tidak valid." ditampilkan di koordinat (63,32) di layar.

        gotoxy(86,30);scanf("%d", &pilihan);
        // Pengguna diminta memasukkan input ulang untuk memilih tingkat kesulitan.
    }

    return (TingkatKesulitan)pilihan;
    // Mengembalikan nilai dari pilihan sebagai enum TingkatKesulitan setelah validasi berhasil.
}


void mulai_permainan(){
    /* Deklarasi variabel dan inisialisasi */
    int ulangi;
    // Menetapkan simbol untuk pemain 1, pemain 2, dan komputer
    pemain1.simbol = 'X';
    pemain2.simbol = 'O';
    computer.simbol = 'O';
    // Inisialisasi nilai awal untuk skor pemain 1, pemain 2, dan komputer
    pemain1.score = 0;
    pemain2.score = 0;
    computer.score = 0;
    char winner = ' '; // Penanda pemenang permainan

    /* Algoritma permainan */
    do {
        system("cls"); // Membersihkan layar
        cetak_papan(); // Mencetak papan permainan
        hapus_papan(); // Menghapus isi papan

        while ((winner == ' ') && (cek_papan_penuh())) {
            // Jika belum ada pemenang dan papan masih belum penuh, permainan berlanjut
            game_board_permainan(); // Menampilkan papan permainan
            giliran_pemain(pemain1); // Ganti giliran pemain 1
            winner = cek_menang(); // Mengecek apakah ada pemenang

            if ((winner != ' ') || !cek_papan_penuh()) {
                // Jika ada pemenang atau papan sudah penuh
                game_board_permainan(); // Menampilkan papan permainan
                if (!cek_papan_penuh()) {
                    gotoxy(46, 18);
                    printf("G A M E  T I E !");
                } else {
                    gotoxy(41, 18);
                    printf("W E  H A V E  W I N N E R !");
                }
                sleep(5); // Tunggu selama 5 detik
                break;
            }

            if (permainan.input_cara_bermain == 1) {
                // Jika mode permainan adalah melawan komputer
                if (permainan.tingkatKesulitan == 1) {
                    giliran_computer_easy(computer); // Giliran komputer di tingkat mudah
                } else if (permainan.tingkatKesulitan == 2) {
                    giliran_computer_medium(computer); // Giliran komputer di tingkat sedang
                } else if (permainan.tingkatKesulitan == 3) {
                    giliran_computer_hard(computer, pemain1); // Giliran komputer di tingkat sulit dengan algoritma minimax
                }

                winner = cek_menang(); // Mengecek apakah ada pemenang
                if ((winner != ' ') || !cek_papan_penuh()) {
                    game_board_permainan(); // Menampilkan papan permainan
                    if (!cek_papan_penuh()) {
                        gotoxy(46, 18);
                        printf("G A M E  T I E !");
                    } else {
                        gotoxy(41, 18);
                        printf("W E  H A V E  W I N N E R !");
                    }
                    sleep(5); // Tunggu selama 5 detik
                    break;
                }
            } else {
                // Jika mode permainan adalah antar dua pemain
                game_board_permainan(); // Menampilkan papan permainan
                giliran_pemain(pemain2); // Ganti giliran pemain 2
                winner = cek_menang(); // Mengecek apakah ada pemenang
                if ((winner != ' ') || !cek_papan_penuh()) {
                    if (!cek_papan_penuh()) {
                        gotoxy(46, 18);
                        printf("G A M E  T I E !");
                    } else {
                        gotoxy(41, 18);
                        printf("W E  H A V E  W I N N E R !");
                    }
                    sleep(5); // Tunggu selama 5 detik
                    break;
                }
            }
        }
        ulangi_permainan(winner); // Menanyakan apakah ingin memulai permainan baru
    } while (permainan.main_lagi == 1);

    // Menyimpan dan menampilkan skor jika pemain memiliki skor lebih dari 0
    if (pemain1.score != 0 || pemain2.score != 0) {
        if (permainan.input_cara_bermain == 1) {
            masukkan_score_baru(pemain1); // Mode Manusia vs Komputer
            tampilkan_highscore(); // Menampilkan skor tertinggi untuk Manusia vs Komputer
        } else {
            masukkan_score_baru_human_vs_human(pemain1); // Mode Manusia vs Manusia
            masukkan_score_baru_human_vs_human(pemain2);
            tampilkan_highscore_human_vs_human(); // Menampilkan skor tertinggi untuk Manusia vs Manusia
        }
    }
}

/*================================================================================================================*/
void hapus_papan(){
    // Looping untuk mengakses setiap kotak pada papan
    for (int i = 0; i < papan.ukuran; i++){
        for(int j=0; j < papan.ukuran; j++){
            papan.kotak[i][j] = ' '; // Mengubah isi kotak menjadi spasi kosong
        }
    }
}

void game_board_permainan(){
    tampilan_color_X_O(); // Menampilkan simbol 'X' dan 'O' dalam warna yang berbeda
    tampilan_player_biner(); // Menampilkan indikator giliran pemain dalam mode permainan
    tampilan_nama_player(); // Menampilkan nama/nickname pemain
    tampilan_score(); // Menampilkan skor pemain
    tampilan_aksesoris_tiktaktoe(); // Menampilkan aksesoris lain pada tampilan permainan, misalnya tanda-tanda bantuan atau petunjuk permainan
}
void cetak_papan(){
    int l;

    // Mengisi papan dengan karakter '0' jika belum terisi atau berisi karakter yang bukan ' ', 'X', atau 'O'
    for(int i = 0; i < 7; i++){
        for (int j = 0; j < 7; j++){
            if((papan.kotak[i][j] != ' ') || (papan.kotak[i][j] != 'X') || (papan.kotak[i][j] != 'O')){
                papan.kotak[i][j] = '0';
            }
        }
    }

    // Menampilkan papan berdasarkan ukuran yang dipilih
    switch (papan.ukuran){
        case 3: /*Cetak papan 3 x 3*/
            // Menampilkan baris dan kolom papan 3x3
            for (int i = 7; i <= 13; i++){
                if (i % 2 == 1){
                    gotoxy(48,i);printf("+---+---+---+");
                }
                if (i % 2 == 0){
                    gotoxy(48,i);printf("|   |   |   |");
                }
            }
            // Menampilkan label kolom dan baris pada papan 3x3
            l = 1;
            printf("\033[1;31m");
            gotoxy(49,5); printf("C O L U M S");
            gotoxy(49,6); printf(" 1   2   3");
            gotoxy(44,8); printf("R");
            gotoxy(44,10); printf("O");
            gotoxy(44,12); printf("W");
            for (int i = 7; i <= 13; i++){
                if(i % 2 == 0){
                    gotoxy(46,i);printf("%d", l);
                    l++;
                }
            }
            break;

        case 5: /*Cetak papan 5 x 5*/
            // Menampilkan baris dan kolom papan 5x5
            for (int i = 5; i <= 15; i++){
                if (i % 2 == 1){
                    gotoxy(44,i);printf("+---+---+---+---+---+");
                }
                if (i % 2 == 0){
                    gotoxy(44,i);printf("|   |   |   |   |   |");
                }
            }
            // Menampilkan label kolom dan baris pada papan 5x5
            l = 1;
            printf("\033[1;31m");
            gotoxy(49,3); printf("C O L U M S");
            gotoxy(45,4); printf(" 1   2   3   4   5");
            gotoxy(40,8); printf("R");
            gotoxy(40,10); printf("O");
            gotoxy(40,12); printf("W");
            for (int i = 5; i <= 15; i++){
                if(i % 2 == 0){
                    gotoxy(42,i);printf("%d", l);
                    l++;
                }
            }
            break;

        case 7: /*Cetak papan 7 x 7*/
            // Menampilkan baris dan kolom papan 7x7
            for (int i = 3; i <= 17; i++){
                if (i % 2 == 1){
                    gotoxy(40,i);printf("+---+---+---+---+---+---+---+");
                }
                if (i % 2 == 0){
                    gotoxy(40,i);printf("|   |   |   |   |   |   |   |");
                }
            }
            // Menampilkan label kolom dan baris pada papan 7x7
            l = 1;
            printf("\033[1;31m");
            gotoxy(49,1); printf("C O L U M S");
            gotoxy(41,2); printf(" 1   2   3   4   5   6   7");
            gotoxy(36,8); printf("R");
            gotoxy(36,10); printf("O");
            gotoxy(36,12); printf("W");
            for (int i = 3; i <= 17; i++){
                if(i % 2 == 0){
                    gotoxy(38,i);printf("%d", l);
                    l++;
                }
            }
            break;
    }
}

void tampilan_color_X_O(){
    int a, b;

    // Menampilkan warna 'X' dan 'O' pada papan permainan sesuai ukurannya
    switch (papan.ukuran){
        case 3: /* Warna 'X' dan 'O' untuk papan 3 x 3 */
            a = 0;
            for (int i = 7; i <= 13; i++){
                b = 0;
                for (int j = 48; j <= 58; j++){
                    if ((i % 2 == 0) && (j % 4 == 2)){
                        if(papan.kotak[a][b] == 'X'){
                            gotoxy(j,i);printf("\033[0;31m%c\033[0m", papan.kotak[a][b]); // Warna merah untuk 'X'
                        } else if (papan.kotak[a][b] == 'O'){
                            gotoxy(j,i);printf("\033[0;32m%c\033[0m", papan.kotak[a][b]); // Warna hijau untuk 'O'
                        } else {
                            gotoxy(j,i);printf("\033[1;30m%c\033[0m", papan.kotak[a][b]); // Warna abu-abu untuk sel kosong
                        }
                        b++;
                    }
                }
                if (i % 2 == 0){
                    a++;
                }   
            }
            break;

        case 5: /* Warna 'X' dan 'O' untuk papan 5 x 5 */
            a = 0;
            for (int i = 5; i <= 15; i++){
                b = 0;
                for (int j = 44; j <= 64; j++){
                    if ((i % 2 == 0) && (j % 4 == 2)){
                        if(papan.kotak[a][b] == 'X'){
                            gotoxy(j,i);printf("\033[0;31m%c\033[0m", papan.kotak[a][b]); // Warna merah untuk 'X'
                        } else if (papan.kotak[a][b] == 'O'){
                            gotoxy(j,i);printf("\033[0;32m%c\033[0m", papan.kotak[a][b]); // Warna hijau untuk 'O'
                        } else {
                            gotoxy(j,i);printf("\033[1;30m%c\033[0m", papan.kotak[a][b]); // Warna abu-abu untuk sel kosong
                        }
                        b++;
                    }
                }
                if (i % 2 == 0){
                    a++;
                }   
            }
            break;

        case 7: /* Warna 'X' dan 'O' untuk papan 7 x 7 */
            a = 0;
            for (int i = 3; i <= 17; i++){
                b = 0;
                for (int j = 40; j <= 66; j++){
                    if ((i % 2 == 0) && (j % 4 == 2)){
                        if(papan.kotak[a][b] == 'X'){
                            gotoxy(j,i);printf("\033[0;31m%c\033[0m", papan.kotak[a][b]); // Warna merah untuk 'X'
                        } else if (papan.kotak[a][b] == 'O'){
                            gotoxy(j,i);printf("\033[0;32m%c\033[0m", papan.kotak[a][b]); // Warna hijau untuk 'O'
                        } else {
                            gotoxy(j,i);printf("\033[1;30m%c\033[0m", papan.kotak[a][b]); // Warna abu-abu untuk sel kosong
                        }
                        b++;
                    }
                }
                if (i % 2 == 0){
                    a++;
                }
            }
            break;
    }
}

void tampilan_player_biner(){
	gotoxy(17,6); printf("\033[1;34m010101");
	gotoxy(16,7); printf("11010111");
	gotoxy(16,8); printf("00010100");
	gotoxy(16,9); printf("11001011");
	gotoxy(17,10); printf("110110");
	gotoxy(14,11); printf("010100101010");
	gotoxy(13,12); printf("10101010101001");	
	gotoxy(13,13); printf("10101010101110");
	if (permainan.input_cara_bermain == 1){
		gotoxy(83,6); printf("\033[1;32m1000101110010101");
		gotoxy(83,7);printf("10            01");
		gotoxy(83,8);printf("00            01");
		gotoxy(83,9);printf("01            11");
		gotoxy(83,10);printf("10            10");
		gotoxy(83,11);printf("1010010010010101");
		gotoxy(83,12);printf("    01001011");
		gotoxy(83,13);printf("  101000101010");
	} else {
	gotoxy(87,6); printf("\033[1;32m010101");
	gotoxy(86,7); printf("11010111");
	gotoxy(86,8); printf("00010100");
	gotoxy(86,9); printf("11001011");
	gotoxy(87,10); printf("110110");
	gotoxy(84,11); printf("010100101010");
	gotoxy(83,12); printf("10101010101001");	
	gotoxy(83,13); printf("10101010101110");
	}
}
void tampilan_nama_player(){
    // Menampilkan nama pemain pada layar dengan posisi dan warna teks yang ditentukan
    gotoxy(16,4); printf("\033[1;37m%s", pemain1.nama); // Menampilkan nama pemain 1 pada posisi (16,4) dengan warna putih tebal
    if (permainan.input_cara_bermain == 1){
        gotoxy(84,4); printf("C O M P U T E R"); // Jika mode permainan adalah melawan komputer, menampilkan teks "COMPUTER" pada posisi (84,4)
    } else {
        gotoxy(86,4); printf("%s", pemain2.nama); // Jika mode permainan adalah dua pemain, menampilkan nama pemain 2 pada posisi (86,4)
    }
}
void tampilan_score(){
    // Menampilkan skor pemain pada layar dengan posisi yang telah ditentukan
    gotoxy(14,15); printf("S C O R E : %d", pemain1.score); // Menampilkan skor pemain 1 pada posisi (14,15)
    if (permainan.input_cara_bermain == 1){
        gotoxy(84,15); printf("S C O R E : %d", computer.score); // Jika mode permainan adalah melawan komputer, menampilkan skor komputer pada posisi (84,15)
    } else {
        gotoxy(84,15); printf("S C O R E : %d", pemain2.score); // Jika mode permainan adalah dua pemain, menampilkan skor pemain 2 pada posisi (84,15)
    }
}

void tampilan_aksesoris_tiktaktoe(){
	gotoxy(8,20);
	printf("010101 01 101010    010101   1001   101010    101010 0110010 010101      +--------------------+\n");
	printf("         10   10 01          10    01  10  01          01   10   01 10           |ROW    :            |\n");
	printf("        01   01 10          01   10101001 10          10   01   10 011001        +--------------------+\n");
	printf("       10   10 01          10   01    10 01          01   10   01 10             |COLUMS :            |\n");
	printf("      01   01 101010      01   10    01 101010      10   0101010 010101          +--------------------+\n");
}
void giliran_pemain(Pemain pemain){
    permainan.invalid_move = false; // Mengatur invalid_move ke false di awal setiap giliran pemain
    int baris, kolom;
    int remaining_time = TIME_LIMIT; // Waktu sisa yang tersedia untuk pemain
    gotoxy(91,19); // Posisi untuk menampilkan simbol pemain (X atau O) di layar
    if(pemain.simbol == 'X'){
        printf("\033[0;31m%c\033[0m", pemain.simbol); // Menampilkan simbol 'X' dengan warna merah
    } else {
        printf("\033[0;32m%c\033[0m", pemain.simbol); // Menampilkan simbol 'O' dengan warna hijau
    }
    start_time = clock(); // Memulai menghitung waktu giliran pemain

    // Loop giliran pemain, menunggu input atau waktu habis
    while (!kbhit()) {
        if ((clock() - start_time) / CLOCKS_PER_SEC >= 1) {
            start_time = clock(); // Reset waktu setiap detik
            remaining_time--;

            // Menampilkan sisa waktu yang tersisa pada layar
            gotoxy(50, 18);
            printf("                           "); // Menghapus tampilan sebelumnya
            gotoxy(50, 18);
            printf("00:0%d", remaining_time);

            if (remaining_time <= 0) {
                printf("\n\nWaktu habis! Pindah ke pemain berikutnya.\n");
                sleep(2); // Menunggu sebentar sebelum melanjutkan
                return;
            }
        }
    }
    
    // Loop untuk menerima input baris dan kolom dari pemain
    while (true) {
        gotoxy(91,21); // Menunjukkan di mana pemain harus memasukkan baris
        permainan.cursor = true; // Memperlihatkan kursor pada layar
        scanf("%d", &baris); // Menerima input baris dari pemain
        baris--;
        gotoxy(91,23); // Menunjukkan di mana pemain harus memasukkan kolom
        permainan.cursor = false; // Menyembunyikan kursor
        scanf("%d", &kolom); // Menerima input kolom dari pemain
        kolom--;
        getchar(); // Membersihkan input dari buffer

        if (cek_tempat_kosong(baris, kolom) && papan.kotak[baris][kolom] != '0') {
            // Jika tempat valid dan belum terisi, isi kotak dan keluar dari loop
            papan.kotak[baris][kolom] = pemain.simbol;
            break;
        } else {
            // Jika kotak sudah terisi atau invalid, minta input ulang
            gotoxy(83,25);
            printf("                     "); // Menghapus pesan sebelumnya
            if (papan.kotak[baris][kolom] == '0') {
                gotoxy(86,25);
                printf("Gerakan tidak valid!"); // Menampilkan pesan gerakan tidak valid
            } else {
                gotoxy(83,25);
                printf("Kotak sudah terisi"); // Menampilkan pesan bahwa kotak sudah terisi
            }
        }
    }
}

void giliran_computer_easy(Pemain pemain){
    int baris, kolom;
    int langkah_acak = 0;
    int maks_langkah_acak = 5; // Menetapkan jumlah maksimum langkah acak

    // Loop untuk memilih langkah komputer
    do {
        // Mendapatkan koordinat acak untuk langkah komputer
        baris = rand() % papan.ukuran;
        kolom = rand() % papan.ukuran;

        // Jika tempat yang dipilih kosong
        if(cek_tempat_kosong(baris, kolom)){
            // Menyimpan sementara posisi sebelum memasukkan simbol ke kotak
            char temp = papan.kotak[baris][kolom];

            // Memasukkan simbol ke kotak untuk mengevaluasi skor papan
            papan.kotak[baris][kolom] = pemain.simbol;

            // Evaluasi skor untuk langkah ini
            int skor = skor_papan();

            // Mengembalikan keadaan awal jika langkah ini merugikan
            if (skor < 0) {
                papan.kotak[baris][kolom] = temp;
            } else {
                // Jika langkah ini menguntungkan, pilih langkah ini
                break;
            }
        }

        // Jika langkah acak belum mencapai batas maksimum, lanjutkan langkah acak
        langkah_acak++;
    } while (langkah_acak < maks_langkah_acak);

    // Jika telah mencoba beberapa langkah acak, pilih langkah acak terakhir
    if (langkah_acak == maks_langkah_acak) {
        do {
            baris = rand() % papan.ukuran;
            kolom = rand() % papan.ukuran;
        } while (!cek_tempat_kosong(baris, kolom));

        papan.kotak[baris][kolom] = pemain.simbol;
    }
}

bool cek_tempat_kosong(int baris, int kolom){
    // Fungsi ini memeriksa apakah kotak pada baris dan kolom tertentu kosong atau tidak
    // Mengembalikan nilai true jika kotak kosong, false jika tidak

    if(papan.kotak[baris][kolom] == ' '){
        return true;  // Jika kotak kosong, kembalikan nilai true
    } else {
        return false; // Jika kotak sudah terisi, kembalikan nilai false
    }
}
void giliran_computer_medium(Pemain pemain){
    int baris = -1, kolom = -1;
    int bestSkor = INT_MIN; // Set bestSkor dengan nilai minimum yang mungkin

    // Loop semua sel kosong pada papan permainan
    for (int i = 0; i < papan.ukuran; ++i) {
        for (int j = 0; j < papan.ukuran; ++j) {
            if (papan.kotak[i][j] == ' ') {
                // Simpan sementara posisi
                char temp = papan.kotak[i][j];
                
                // Coba letakkan simbol komputer di kotak kosong
                papan.kotak[i][j] = pemain.simbol;

                // Evaluasi skor untuk langkah ini dengan menggunakan algoritma minimax
                int skor = minimax(papan.kotak, 7, INT_MIN, INT_MAX, false, pemain.simbol);

                // Batalkan langkah
                papan.kotak[i][j] = temp;

                // Jika skor langkah ini lebih baik, simpan sebagai langkah terbaik
                if (skor > bestSkor) {
                    bestSkor = skor;
                    baris = i;
                    kolom = j;
                }
            }
        }
    }

    // Lakukan langkah terbaik yang ditemukan
    if (baris != -1 && kolom != -1) {
        papan.kotak[baris][kolom] = pemain.simbol;
    } else {
        // Jika tidak ada langkah yang memberikan keuntungan langsung, lakukan pergerakan acak
        giliran_computer_easy(pemain);
    }
}

int skor_papan() {
    // Fungsi ini mengevaluasi skor papan permainan.
    // Jika terdapat pemenang, fungsi akan memberikan skor berdasarkan kondisi pemenang.
    // Misalnya, +10 jika komputer menang, -10 jika pemain menang, dan 0 jika permainan seri.

    char pemenang = cek_menang(); // Periksa apakah ada pemenang pada papan

    if (pemenang == computer.simbol) { // Jika komputer menang
        return 10;
    } else if (pemenang == pemain1.simbol || pemenang == pemain2.simbol) { // Jika pemain menang
        return -10;
    } else { // Jika tidak ada pemenang (seri)
        return 0;
    }
}

int minimax(char papan[7][7], int depth, int alpha, int beta, bool isMaximizer, char maximizingPlayerSymbol) {
    int skor = skor_papan();

    // Kasus dasar dari rekursi: jika permainan selesai atau mencapai kedalaman maksimum
    if (skor == 10 || skor == -10 || cek_papan_penuh() || depth == 0) {
        return skor;
    }

    // Implementasi metode Alpha-Beta Pruning
    if (isMaximizer) { // Jika saat ini giliran komputer (maximizer)
        int bestSkor = -1000;

        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j < 7; ++j) {
                if (papan[i][j] == ' ') {
                    papan[i][j] = maximizingPlayerSymbol; // Lakukan langkah komputer

                    // Rekursi untuk langkah pemain (minimizer)
                    bestSkor = std::max(bestSkor, minimax(papan, depth - 1, alpha, beta, false, maximizingPlayerSymbol));
                    alpha = std::max(alpha, bestSkor); // Update alpha

                    papan[i][j] = ' '; // Batalkan langkah

                    if (beta <= alpha) {
                        break; // Alpha-Beta Pruning
                    }
                }
            }
        }
        return bestSkor;
    } else { // Jika saat ini giliran pemain (minimizer)
        int bestSkor = 1000;

        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j < 7; ++j) {
                if (papan[i][j] == ' ') {
                    // Lakukan langkah pemain
                    papan[i][j] = maximizingPlayerSymbol == pemain1.simbol ? pemain2.simbol : pemain1.simbol;

                    // Rekursi untuk langkah komputer (maximizer)
                    bestSkor = std::min(bestSkor, minimax(papan, depth - 1, alpha, beta, true, maximizingPlayerSymbol));
                    beta = std::min(beta, bestSkor); // Update beta

                    papan[i][j] = ' '; // Batalkan langkah

                    if (beta <= alpha) {
                        break; // Alpha-Beta Pruning
                    }
                }
            }
        }
        return bestSkor;
    }
}
void giliran_computer_hard(Pemain pemain, Pemain lawan) {
    int bestSkor = -1000;
    int baris = -1, kolom = -1;

    for (int i = 0; i < papan.ukuran; ++i) {
        for (int j = 0; j < papan.ukuran; ++j) {
            if (papan.kotak[i][j] == ' ') {
                papan.kotak[i][j] = computer.simbol; // Coba langkah komputer

                int skor = minimax(papan.kotak, 7, -1000, 1000, false, computer.simbol); // Evaluasi skor dengan Minimax

                papan.kotak[i][j] = ' '; // Batalkan langkah

                if (skor > bestSkor) { // Jika skor lebih baik, update skor terbaik dan posisi
                    bestSkor = skor;
                    baris = i;
                    kolom = j;
                }
            }
        }
    }

    papan.kotak[baris][kolom] = computer.simbol; // Lakukan langkah terbaik yang ditemukan
}

char cek_menang(){
    switch (papan.ukuran){
        case 3 : /*Cek Winner 3 x 3*/ 
				/*Check Row*/
				for (int i = 0; i < 3; i++){
					if((papan.kotak[i][1] != ' ') && (papan.kotak[i][0] == papan.kotak[i][1])&&(papan.kotak[i][1] == papan.kotak[i][2])){
						return papan.kotak[i][0];break;
					}
				}
				/*Check Colums*/
				for (int i = 0; i < 3; i++){
					if((papan.kotak[1][i] != ' ') && (papan.kotak[0][i] == papan.kotak[1][i])&&(papan.kotak[1][i] == papan.kotak[2][i])){
						return papan.kotak[0][i];break;
					}
				}
				/*Check Diagonals*/
				if((papan.kotak[1][1] != ' ') && (papan.kotak[0][0] == papan.kotak[1][1]) && (papan.kotak[1][1] == papan.kotak[2][2])){
					return papan.kotak[0][0];break;
				}
				if((papan.kotak[1][1] != ' ') && (papan.kotak[0][2] == papan.kotak[1][1]) && (papan.kotak[1][1] == papan.kotak[2][0])){
					return papan.kotak[0][2];break;
				}
				return ' '; break;
        case 5 : /*Cek Winner 5 x 5*/ 
				/*Cek Row */
    			for(int i = 0; i < 5; i++){
       				if(((papan.kotak[i][0] == papan.kotak[i][2]) || (papan.kotak[i][4] == papan.kotak[i][2])) && (((papan.kotak[i][1] == papan.kotak[i][2]) && (papan.kotak[i][2] == papan.kotak[i][3])) && (papan.kotak[i][2] != ' '))){
        				return papan.kotak[i][2];break;
					}
    			}
    			/*Cek Colums*/
				for (int i = 0; i < 5; i++){
        			if(((papan.kotak[0][i] == papan.kotak[2][i]) || (papan.kotak[4][i] == papan.kotak[2][i])) && (((papan.kotak[1][i] == papan.kotak[2][i]) && (papan.kotak[2][i] == papan.kotak[3][i])) && (papan.kotak[2][i] != ' '))){
					return papan.kotak[2][i];break;
    				}
				}
    			/*Cek Diagonals\*/
    			if((papan.kotak[1][0] != ' ') && (((papan.kotak[1][0] == papan.kotak[2][1]) && (papan.kotak[2][1] == papan.kotak[3][2])) && ((papan.kotak[3][2] == papan.kotak[4][3])) && (papan.kotak[4][3] == papan.kotak[1][0]))){
    				return papan.kotak[1][0];break;
				}
				if((papan.kotak[0][1] != ' ') && (((papan.kotak[0][1] == papan.kotak[1][2]) && (papan.kotak[1][2] == papan.kotak[2][3])) && ((papan.kotak[2][3] == papan.kotak[3][4])) && (papan.kotak[3][4] == papan.kotak[0][1]))){
    				return papan.kotak[0][1];break;
				}
				if((papan.kotak[2][2] != ' ') && (((papan.kotak[0][0] == papan.kotak [2][2]) || (papan.kotak[4][4] == papan.kotak [2][2])) && (((papan.kotak[1][1] == papan.kotak [2][2]) && (papan.kotak[2][2] == papan.kotak [3][3])) && (papan.kotak[3][3] == papan.kotak [1][1])))){
					return papan.kotak[2][2];break;
				}
				/*Cek Diagonals/*/
				if((papan.kotak[0][3] != ' ') && (((papan.kotak[0][3] == papan.kotak[1][2]) && (papan.kotak[1][2] == papan.kotak[2][1])) && ((papan.kotak[2][1] == papan.kotak[3][0]) && (papan.kotak[3][0] == papan.kotak[0][3])))){
    				return papan.kotak[0][3];break;
				}
				if((papan.kotak[1][4] != ' ') && (((papan.kotak[1][4] == papan.kotak[2][3]) && (papan.kotak[2][3] == papan.kotak[3][2])) && ((papan.kotak[3][2] == papan.kotak[4][1])) && (papan.kotak[4][1] == papan.kotak[1][4]))){
    				return papan.kotak[1][4];break;
				}
				if((papan.kotak[2][2] != ' ') && (((papan.kotak[0][4] == papan.kotak [2][2]) || (papan.kotak[4][0] == papan.kotak [2][2])) && (((papan.kotak[1][3] == papan.kotak [2][2]) && (papan.kotak[2][2] == papan.kotak [3][1])) && (papan.kotak[3][1] == papan.kotak [1][3])))){
					return papan.kotak[2][2];break;
				}
    			return ' ';break;
        case 7 :/*Cek Winner 7 x 7*/
				/*Cek Row */
    			for (int i = 0; i < 7; i++){
    				if((papan.kotak[i][3] != ' ') && ((papan.kotak[i][6] == papan.kotak[i][5]) && (papan.kotak[i][5] == papan.kotak[i][3]) || (papan.kotak[i][5] == papan.kotak[i][1]) && (papan.kotak[i][1] == papan.kotak[i][3]) || (papan.kotak[i][0] == papan.kotak[i][1]) && (papan.kotak[i][1] == papan.kotak[i][3])) && (papan.kotak[i][2] == papan.kotak[i][3]) && (papan.kotak[i][3] == papan.kotak[i][4]) && (papan.kotak[i][4] == papan.kotak[i][2])){
    					return papan.kotak[i][3];break;
					}
				}
    			/*Cek Diagonal\*/
				for (int i = 0; i < 7; i++){
    				if((papan.kotak[3][i] != ' ') && ((papan.kotak[6][i] == papan.kotak[5][i]) && (papan.kotak[5][i] == papan.kotak[3][i]) || (papan.kotak[5][i] == papan.kotak[1][i]) && (papan.kotak[1][i] == papan.kotak[3][i]) || (papan.kotak[0][i] == papan.kotak[1][i]) && (papan.kotak[1][i] == papan.kotak[3][i])) && (papan.kotak[2][i] == papan.kotak[3][i]) && (papan.kotak[3][i] == papan.kotak[4][i]) && (papan.kotak[4][i] == papan.kotak[2][i])){
    					return papan.kotak[3][i];break;
					}
				}
				/*Cek Diagonal/*/
				if((papan.kotak[4][2] != ' ') && (papan.kotak[2][0] == papan.kotak[3][1]) && (papan.kotak[3][1] == papan.kotak[4][2]) && (papan.kotak[4][2] == papan.kotak[5][3]) && (papan.kotak[5][3] == papan.kotak[6][4]) && (papan.kotak[6][4] == papan.kotak[2][0])){
					return papan.kotak[4][2];break;
				}
				if((papan.kotak[3][2] != ' ') && ((papan.kotak[1][0] == papan.kotak[3][2]) || (papan.kotak[6][5] == papan.kotak[3][2])) && ((papan.kotak[2][1] == papan.kotak[3][2]) && (papan.kotak[3][2] == papan.kotak[4][3]) && (papan.kotak[4][3] == papan.kotak[5][4]) && (papan.kotak[5][4] == papan.kotak[2][1]))){
					return papan.kotak[3][2];break;
				}
				if ((papan.kotak[3][3] != ' ') && (((papan.kotak[0][0] == papan.kotak[1][1]) && (papan.kotak[0][0] == papan.kotak[3][3])) || ((papan.kotak[1][1] == papan.kotak[5][5]) && (papan.kotak[5][5] == papan.kotak[3][3])) || ((papan.kotak[5][5] == papan.kotak[6][6]) && (papan.kotak[6][6] == papan.kotak[3][3]))) && (papan.kotak[2][2] == papan.kotak[3][3]) && (papan.kotak[3][3] == papan.kotak[4][4]) && (papan.kotak[4][4] == papan.kotak[2][2])){
					return papan.kotak[3][3];break;
				}
				if((papan.kotak[2][3] != ' ') && ((papan.kotak[0][1] == papan.kotak[2][3]) || (papan.kotak[5][6] == papan.kotak[2][3])) && ((papan.kotak[1][2] == papan.kotak[2][3]) && (papan.kotak[2][3] == papan.kotak[3][4]) && (papan.kotak[3][4] == papan.kotak[4][5]) && (papan.kotak[4][5] == papan.kotak[1][2]))){
					return papan.kotak[2][3];break;
				}
				if((papan.kotak[2][4] != ' ') && (papan.kotak[0][2] == papan.kotak[1][3]) && (papan.kotak[1][3] == papan.kotak[2][4]) && (papan.kotak[2][4] == papan.kotak[3][5]) && (papan.kotak[3][5] == papan.kotak[4][6]) && (papan.kotak[4][6] == papan.kotak[0][2])){
					return papan.kotak[2][4];break;
				}
				/*Cek Diagonal.*/
				if((papan.kotak[2][2] != ' ') && (papan.kotak[4][0] == papan.kotak[3][1]) && (papan.kotak[3][1] == papan.kotak[2][2]) && (papan.kotak[2][2] == papan.kotak[1][3]) && (papan.kotak[1][3] == papan.kotak[0][4]) && (papan.kotak[0][4] == papan.kotak[4][0])){
					return papan.kotak[2][2];break;
				}
				if((papan.kotak[3][2] != ' ') && ((papan.kotak[5][0] == papan.kotak[3][2]) || (papan.kotak[0][5] == papan.kotak[3][2])) && ((papan.kotak[4][1] == papan.kotak[3][2]) && (papan.kotak[3][2] == papan.kotak[2][3]) && (papan.kotak[2][3] == papan.kotak[1][4]) && (papan.kotak[1][4] == papan.kotak[4][1]))){
					return papan.kotak[3][2];break;
				}
				if ((papan.kotak[3][3] != ' ') && (((papan.kotak[6][0] == papan.kotak[5][1]) && (papan.kotak[6][0] == papan.kotak[3][3])) || ((papan.kotak[5][1] == papan.kotak[1][5]) && (papan.kotak[5][1] == papan.kotak[3][3])) || ((papan.kotak[1][5] == papan.kotak[0][6]) && (papan.kotak[0][6] == papan.kotak[3][3]))) && (papan.kotak[4][2] == papan.kotak[3][3]) && (papan.kotak[3][3] == papan.kotak[2][4]) && (papan.kotak[2][4] == papan.kotak[4][2])){
					return papan.kotak[3][3];break;
				}
				if((papan.kotak[4][3] != ' ') && ((papan.kotak[6][1] == papan.kotak[4][3]) || (papan.kotak[1][6] == papan.kotak[4][3])) && ((papan.kotak[5][2] == papan.kotak[4][3]) && (papan.kotak[4][3] == papan.kotak[3][4]) && (papan.kotak[3][4] == papan.kotak[2][5]) && (papan.kotak[2][5] == papan.kotak[5][2]))){
					return papan.kotak[4][3];break;
				}
				if((papan.kotak[4][4] != ' ') && (papan.kotak[6][2] == papan.kotak[5][3]) && (papan.kotak[5][3] == papan.kotak[4][4]) && (papan.kotak[4][4] == papan.kotak[3][5]) && (papan.kotak[3][5] == papan.kotak[2][6]) && (papan.kotak[2][6] == papan.kotak[6][2])){
					return papan.kotak[4][4];break;
				}
    			return ' ';break;
    }
}
bool cek_papan_penuh(){
    for(int i = 0; i < papan.ukuran; i++){
        for (int j = 0; j < papan.ukuran; j++){
            if(papan.kotak[i][j] == ' '){
                return true; // Ada kotak kosong, papan belum penuh
            }
        }
    }
    return false; // Semua kotak telah terisi, papan penuh
}

void ulangi_permainan(char winner){
    do{
        system("cls"); // Membersihkan layar konsol untuk memulai permainan baru
        
        // Menampilkan pesan kemenangan untuk pemain X atau O, atau pesan seri
        if(winner == 'X'){
            tampilan_wins(pemain1); // Menampilkan pesan kemenangan untuk pemain 1 (X)
            tampilan_champion(); // Menampilkan pesan bahwa pemain menang
            pemain1.score++; // Menambah skor pemain 1
        } else if (winner == 'O'){
            if(permainan.input_cara_bermain == 1){
                tampilan_wins(pemain1); // Menampilkan pesan kemenangan untuk pemain 1 (O jika melawan komputer)
                gotoxy(31,7);printf("C O M P U T E R");
                computer.score++; // Menambah skor komputer jika melawan komputer
            }
            tampilan_wins(pemain2); // Menampilkan pesan kemenangan untuk pemain 2 (O jika melawan pemain lain)
            tampilan_champion(); // Menampilkan pesan bahwa pemain menang
            pemain2.score++; // Menambah skor pemain 2
        } else {
            tampilan_tie(); // Menampilkan pesan seri
            tampilan_good(); // Menampilkan pesan baik
        }
        
        tampilan_input_main_lagi(); // Menampilkan pesan untuk input untuk main lagi
    } while(permainan.penentu_main_lagi); // Melakukan perulangan jika pemain ingin bermain lagi
}

void tampilan_wins(Pemain player){
	gotoxy(31,7); printf("%s", player.nama);
	gotoxy(19,9); printf("\033[1;37m _     _  ___   __    _  _______");
	gotoxy(19,10); printf("| | _ | ||   | |  |  | ||       |");
	gotoxy(19,11); printf("| || || ||   | |   |_| ||  _____|");
	gotoxy(19,12); printf("|       ||   | |       || |_____ ");
	gotoxy(19,13); printf("|       ||   | |  _    ||_____  |");
	gotoxy(19,14); printf("|   _   ||   | | | |   | _____| |");
	gotoxy(19,15); printf("|__| |__||___| |_|  |__||_______|");
}
void tampilan_tie(){
	gotoxy(15,9);  printf(" _______  ___   _______");
	gotoxy(15,10); printf("|       ||   | |       |");
	gotoxy(15,11); printf("|_     _||   | |    ___|");
	gotoxy(15,12); printf("  |   |  |   | |   |___ ");
	gotoxy(15,13); printf("  |   |  |   | |    ___|");
	gotoxy(15,14); printf("  |   |  |   | |   |___");
	gotoxy(15,15); printf("  |___|  |___| |_______|	\033[0m");
}
void tampilan_champion(){
	gotoxy(61,3); printf("\033[0;33m 1010                          0110 ");
	gotoxy(61,4); printf("10  0110101010101010100000100100  11");
	gotoxy(61,5); printf("00   01010010101010010111001001   11");
	gotoxy(61,6); printf(" 111 01010100101001101010100101 101 ");
	gotoxy(61,7); printf("   111010101010001010100100101000   ");
	gotoxy(61,8); printf("      10010100100100000100100       ");
	gotoxy(61,9); printf("       001000100100101001001        ");
	gotoxy(61,10); printf("         10100010010100101          ");
	gotoxy(61,11); printf("            1010101101              ");
	gotoxy(61,12); printf("               0010                 ");
	gotoxy(61,13); printf("               1011                 ");
	gotoxy(61,14); printf("            0100100010              ");
	gotoxy(61,15); printf("          00111011010001            ");
	gotoxy(61,16); printf("       101011110010101001001        ");
	gotoxy(61,17); printf("       001001010100010111101        ");
	gotoxy(61,18); printf("    10101110001010110111000100\033[0m");
}
void tampilan_good(){
	gotoxy(65,3); printf("             00011                  ");
	gotoxy(65,4); printf("            1011001                 ");
	gotoxy(65,5); printf("            1001001                 ");
	gotoxy(65,6); printf("           01010101                 ");
	gotoxy(65,7); printf("           10011101111              ");
	gotoxy(65,8); printf("         01010110111001001001       ");
	gotoxy(65,9); printf(" 101   010101001101100001000101     ");
	gotoxy(65,10); printf(" 101010101011101100101010           ");
	gotoxy(65,11); printf(" 0101101010101110101000010101101    ");
	gotoxy(65,12); printf(" 1110000100111100000110100010010    ");
	gotoxy(65,13); printf(" 110001010100110101010110           ");
	gotoxy(65,14); printf(" 001010100111010101000101010010     ");
	gotoxy(65,15); printf(" 010101010000000011001010010010     ");
	gotoxy(65,16); printf(" 000  1010100001101010100           ");
	gotoxy(65,17); printf("        1010100001100001001011      ");
	gotoxy(65,18); printf("            101010010000010         ");
}
void tampilan_input_main_lagi(){
    gotoxy(23,17);printf("1. Y A");
    gotoxy(23,18);printf("2. T I D A K");
    gotoxy(23,19);printf("M A I N  L A G I ? "); 
	gotoxy(23,20);printf("+----------------------+");
	gotoxy(23,21);printf("|                      |");
	gotoxy(23,22);printf("+----------------------+");
	gotoxy(35,21);scanf("%d", &permainan.main_lagi); getchar();
   // Tambahkan validasi untuk memastikan input yang diberikan valid (1 atau 2)
while (permainan.main_lagi != 1 && permainan.main_lagi != 2) { // Loop sampai input valid diberikan
    gotoxy(23,22); printf("\n \n Masukkan tidak valid! Coba lagi: "); // Tampilkan pesan kesalahan
    gotoxy(35,20); scanf("%d", &permainan.main_lagi); getchar(); // Input nilai untuk main lagi
}

// Setel nilai penentu_main_lagi berdasarkan input yang valid
if (permainan.main_lagi == 1) {
    permainan.penentu_main_lagi = false; // Jika pemain ingin bermain lagi, setel penentu_main_lagi menjadi false
    mulai_permainan(); // Panggil fungsi untuk memulai permainan kembali
} else {
    permainan.penentu_main_lagi = true; // Jika pemain tidak ingin bermain lagi, setel penentu_main_lagi menjadi true
    if (permainan.input_cara_bermain == 1) { // Mode Human vs Computer
        if (pemain1.score != 0) {
            masukkan_score_baru(pemain1); // Jika ada skor, minta input untuk memasukkan skor baru untuk Human vs Computer
        }
        tampilkan_highscore(); // Tampilkan highscore untuk mode Human vs Computer
    } else { // Mode Human vs Human
        if (pemain1.score != 0 || pemain2.score != 0) {
            masukkan_score_baru_human_vs_human(pemain1); // Jika ada skor, minta input untuk memasukkan skor baru untuk Human vs Human
            masukkan_score_baru_human_vs_human(pemain2);
        }
        tampilkan_highscore_human_vs_human(); // Tampilkan highscore untuk mode Human vs Human
    }
    // Jika pemain tidak ingin bermain lagi, arahkan kembali ke menu awal
    cetak_menu_awal();
}
}

void masukkan_score_baru(Pemain pemain_baru) {
    Pemain data_file[100]; // Array untuk menyimpan data dari file
    FILE *fp;
    int i = 0, banyak_data = 0; // Variabel untuk iterasi dan jumlah data
    int posisi = 0; // Variabel untuk menyimpan posisi pemain dalam data_file
    int kesamaan_nama = 1; // Variabel untuk memeriksa kesamaan nama
    bool pernah_bermain = false; // Menandakan apakah pemain pernah bermain sebelumnya
    char ch = 0; // Variabel untuk membaca karakter dari file

    fp = fopen("HighScore_Human_vs_Computer.txt", "r"); // Buka file untuk membaca
    while (ch != EOF && fscanf(fp, "%s %d", &data_file[i].nama, &data_file[i].score) == 2) {
        ch = fgetc(fp); // Baca data dari file ke dalam array data_file
        i++;
    }
    fclose(fp); // Tutup file setelah selesai membaca
    banyak_data = i; // Tetapkan jumlah data yang terbaca dari file

    // Cari pemain baru dalam data_file
    for (i = 0; i < banyak_data; i++) {
        kesamaan_nama = strcmp(pemain_baru.nama, data_file[i].nama); // Bandingkan nama pemain baru dengan data yang ada
        if (kesamaan_nama == 0) { // Jika nama sudah ada dalam data
            if (pemain_baru.level == 3) { // Jika level permainan adalah hard (tingkat kesulitan 3)
                data_file[i].score += (pemain_baru.score + 2); // Tambahkan +2 ke skor
            } else {
                data_file[i].score += pemain_baru.score; // Tambahkan skor pemain baru
            }
            pernah_bermain = true; // Setel bahwa pemain sudah pernah bermain sebelumnya
            posisi = i; // Simpan posisi pemain dalam data_file
            break; // Hentikan pencarian
        }
    }

    // Jika pemain baru belum ada dalam data
    if (!pernah_bermain) {
        posisi = banyak_data; // Posisi pemain baru adalah di akhir data_file
        strcpy(data_file[posisi].nama, pemain_baru.nama); // Salin nama pemain baru ke data_file
        if (pemain_baru.level == 3) { // Jika level permainan adalah hard (tingkat kesulitan 3)
            data_file[posisi].score = pemain_baru.score + 2; // Skor awal +2 untuk level hard
        } else {
            data_file[posisi].score = pemain_baru.score; // Gunakan skor pemain baru
        }
        banyak_data++; // Tambahkan jumlah data karena ada pemain baru
    }

    // Urutkan data_file berdasarkan skor pemain
    for (i = posisi; i > 0; i--) {
        if (data_file[i].score > data_file[i - 1].score) {
            Pemain temp = data_file[i];
            data_file[i] = data_file[i - 1];
            data_file[i - 1] = temp;
        }
    }

    fp = fopen("HighScore_Human_vs_Computer.txt", "w"); // Buka file untuk menulis data baru
    for (i = 0; i < banyak_data; i++) {
        fprintf(fp, "%s %d\n", data_file[i].nama, data_file[i].score); // Tulis data baru ke dalam file
    }
    fclose(fp); // Tutup file setelah selesai menulis
}

void tampilkan_highscore(){
    system("cls");

    int back; // Variabel untuk input pengguna
    tampilan_champion(); // Tampilkan tampilan juara
    int j = 1; // Variabel untuk nomor urutan

    Pemain data_file[10]; // Array untuk menyimpan data pemain
    FILE *fp;
    int total=0, banyak_data; // Variabel untuk jumlah data
    int posisi=0; // Variabel untuk posisi dalam data_file
    int kesamaan_nama; // Variabel untuk membandingkan nama
    bool pernah_bermain = false; // Menandakan apakah pemain pernah bermain sebelumnya
    char ch = 0; 

    // Buka file untuk membaca data highscore
    fp=fopen("HighScore_Human_vs_Computer.txt","r");
    // Baca data dari file ke dalam array data_file
    while(ch!=EOF && total < 10){
        fscanf(fp,"%s%d",&data_file[total].nama,&data_file[total].score);  
        ch=fgetc(fp);
        total++;  
    }
    fclose(fp); // Tutup file setelah selesai membaca
    total--; // Kurangi jumlah total karena loop membaca data terakhir yang tidak valid

    // Tampilkan header tabel highscore
    gotoxy(13,2); printf(" N O       N I C K N A M E       S C O R E");
    for (int i = 3; i < 24; i++){
        if (i % 2 == 1){
            gotoxy(13,i); printf("+-----+-------------------------+----------+");
        } else if (j < 10){
            gotoxy(13,i); printf("| %d.  |                         |          |", j);
            if(j-1<total){
                gotoxy(22,i); printf("%s", data_file[j-1].nama); // Tampilkan nama pemain
                gotoxy(50,i); printf("%d", data_file[j-1].score); // Tampilkan skor pemain
            }
            j++;
        } else {
            gotoxy(13,i); printf("| %d. |                         |          |", j);
        }
    }

    do{
        // Tampilkan pesan untuk input kode kembali
        gotoxy(49,28);printf("99 (B A C K)");
        gotoxy(43,29);printf("\033[1;37m+----------------------+");
        gotoxy(43,30);printf("|                      |");
        gotoxy(43,31);printf("+----------------------+");
        gotoxy(54,30);scanf("%d", &back);getchar();
        gotoxy(43,32);printf("I N V A L I D  C O D E !!");
        
        // Periksa input dan arahkan sesuai input
        cetak_menu_awal();
        if ((permainan.input_awal != 1) || (permainan.input_awal != 2) || (permainan.input_awal != 99)) {
            gotoxy(43, 23);
            printf("I N V A L I D  C O D E !!");
        }
        if (permainan.input_awal == 1) {
            pilih_pemain();
            pilih_dimensi_papan();
            tampilan_nickname();
            mulai_permainan();
        }
        if (permainan.input_awal == 2) {
            keluar_permainan();
        }
        if (permainan.input_awal == 99) {
            more();
        }
    } while ((permainan.input_awal != 1) || (permainan.input_awal != 2) || (permainan.input_awal != 99));
}

void masukkan_score_baru_human_vs_human(Pemain pemain_baru) {
    Pemain data_file[100];
    FILE *fp;
    int i = 0, banyak_data = 0;
    int posisi = 0;
    int kesamaan_nama = 1;
    bool pernah_bermain = false;
    char ch = 0;

    fp = fopen("HighScore_Human_vs_Human.txt", "r"); // Membuka file untuk mode Human vs Human
    // Membaca data dari file ke dalam array data_file
    while (ch != EOF && fscanf(fp, "%s %d", &data_file[i].nama, &data_file[i].score) == 2) {
        ch = fgetc(fp);
        i++;
    }
    fclose(fp); // Menutup file setelah selesai membaca
    banyak_data = i; // Jumlah data yang telah dibaca

    // Memeriksa data yang sudah ada untuk pemain baru
    for (i = 0; i < banyak_data; i++) {
        kesamaan_nama = strcmp(pemain_baru.nama, data_file[i].nama);
        if (kesamaan_nama == 0) {
            data_file[i].score += pemain_baru.score; // Menambahkan skor pemain baru ke skor yang sudah ada
            pernah_bermain = true;
            posisi = i;
            break;
        }
    }

    // Jika pemain belum pernah bermain sebelumnya
    if (!pernah_bermain) {
        posisi = banyak_data;
        strcpy(data_file[posisi].nama, pemain_baru.nama);
        data_file[posisi].score = pemain_baru.score;
        banyak_data++;
    }

    // Melakukan sorting ulang berdasarkan skor
    for (i = posisi; i > 0; i--) {
        if (data_file[i].score > data_file[i - 1].score) {
            Pemain temp = data_file[i];
            data_file[i] = data_file[i - 1];
            data_file[i - 1] = temp;
        }
    }

    fp = fopen("HighScore_Human_vs_Human.txt", "w"); // Membuka file untuk mode Human vs Human
    // Menulis kembali data yang telah diubah ke dalam file
    for (i = 0; i < banyak_data; i++) {
        fprintf(fp, "%s %d\n", data_file[i].nama, data_file[i].score);
    }
    fclose(fp); // Menutup file setelah selesai menulis
}

void tampilkan_highscore_human_vs_human() {
    system("cls"); // Membersihkan layar konsol untuk menampilkan highscore
    int back;
    tampilan_champion(); // Menampilkan judul atau tampilan khusus lainnya jika diperlukan
    int j = 1;

    Pemain data_file[10]; // Maksimum 10 pemain yang akan ditampilkan
    FILE *fp;
    int total = 0, banyak_data;
    int posisi = 0;
    int kesamaan_nama;
    bool pernah_bermain = false;
    char ch = 0;

    fp = fopen("HighScore_Human_vs_Human.txt", "r"); // Membuka file untuk membaca highscore mode Human vs Human
    // Membaca data dari file ke dalam array data_file
    while (ch != EOF && total < 10) {
        fscanf(fp, "%s%d", &data_file[total].nama, &data_file[total].score);
        ch = fgetc(fp);
        total++;
    }
    fclose(fp); // Menutup file setelah selesai membaca
    total--; // Mengurangi 1 karena total diincrement setelah membaca data terakhir, sehingga menghasilkan jumlah data yang salah

    gotoxy(13, 2);
    printf(" N O       N I C K N A M E       S C O R E");
    // Menampilkan data highscore ke layar konsol
    for (int i = 3; i < 24; i++) {
        if (i % 2 == 1) {
            gotoxy(13, i);
            printf("+-----+-------------------------+----------+");
        } else if (j < 10) {
            gotoxy(13, i);
            printf("| %d.  |                         |          |", j);
            if (j - 1 < total) {
                gotoxy(22, i);
                printf("%s", data_file[j - 1].nama);
                gotoxy(50, i);
                printf("%d", data_file[j - 1].score);
            }
            j++;
        } else {
            gotoxy(13, i);
            printf("| %d. |                         |          |", j);
        }
    }
    
    // Meminta input dari pengguna untuk kembali ke menu utama atau lebih banyak aksi lainnya
    do {
        gotoxy(49, 28);
        printf("99 (B A C K)");
        gotoxy(43, 29);
        printf("\033[1;37m+----------------------+");
        gotoxy(43, 30);
        printf("|                      |");
        gotoxy(43, 31);
        printf("+----------------------+");
        gotoxy(54, 30);
        scanf("%d", &back);
        getchar();
        gotoxy(43, 32);
        printf("I N V A L I D  C O D E !!"); // Pesan kesalahan jika input tidak valid
        cetak_menu_awal(); // Menampilkan kembali menu awal
        // Melakukan aksi sesuai dengan input yang diberikan
        if ((permainan.input_awal != 1) || (permainan.input_awal != 2) || (permainan.input_awal != 99)) {
            gotoxy(43, 23);
            printf("I N V A L I D  C O D E !!"); // Pesan kesalahan jika input tidak valid
        }
        if (permainan.input_awal == 1) {
            pilih_pemain();
            pilih_dimensi_papan();
            tampilan_nickname();
            mulai_permainan();
        }
        if (permainan.input_awal == 2) {
            keluar_permainan();
        }
        if (permainan.input_awal == 99) {
            more();
        }
    } while ((permainan.input_awal != 1) || (permainan.input_awal != 2) || (permainan.input_awal != 99));
}

void tukar_posisi_pemain(Pemain *pemain1, Pemain *pemain2){
    Pemain temp; // Buat variabel sementara untuk menyimpan nilai pemain
    temp = *pemain1; // Simpan nilai pemain1 ke dalam variabel sementara
    *pemain1 = *pemain2; // Pindahkan nilai pemain2 ke pemain1
    *pemain2 = temp; // Pindahkan nilai yang disimpan dari pemain1 ke pemain2
}

void gotoxy(int x, int y){
    COORD coord; // Membuat objek COORD untuk menampung koordinat
    coord.X = x; // Menetapkan nilai x ke koordinat X dalam objek COORD
    coord.Y = y; // Menetapkan nilai y ke koordinat Y dalam objek COORD
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // Mengatur posisi kursor pada koordinat tertentu di layar konsol
}
