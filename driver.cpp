#include "header.h"
#include <windows.h>
#include <stdio.h>


int main() {
    permainan.jumlah_permain = 0;
    papan.ukuran = 1;

    system("color");

    do {
        cetak_menu_awal();

        if ((permainan.input_awal != 1) && (permainan.input_awal != 2) && (permainan.input_awal != 99)) {
            gotoxy(50,60);
            printf("I N V A L I D  C O D E !!");
            Sleep(2000);
            
        }

        if (permainan.input_awal == 1) {
            pilih_pemain();
            pilih_dimensi_papan();
            tampilan_nickname();
            mulai_permainan();
        }

        if (permainan.input_awal == 2) {
            keluar_permainan();
            return 0;
        }

        if (permainan.input_awal == 99) {
            more();
        }
    } while ((permainan.input_awal != 1) && (permainan.input_awal != 2) && (permainan.input_awal != 99));

    return 0;
}
