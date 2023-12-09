#include"header.h"
#include<windows.h>
#include<stdio.h>

int main(){
	/*Deklarasi*/
	permainan.jumlah_permain = 0;
	papan.ukuran = 1;
	/*Algoritma*/
	system("color");
	do{
		cetak_menu_awal();
		if((permainan.input_awal != 1) || (permainan.input_awal != 2) || (permainan.input_awal != 99)){
		gotoxy(43,23);printf("I N V A L I D  C O D E !!");
		}
		if(permainan.input_awal == 1){
			pilih_pemain();
			pilih_dimensi_papan();
			tampilan_nickname();
			mulai_permainan();
		}
		if(permainan.input_awal == 2){
			keluar_permainan();//keluar permainan
			return 0;	
		}
		if(permainan.input_awal == 99){
			more();
		}
	}while((permainan.input_awal != 1) || (permainan.input_awal != 2) || (permainan.input_awal != 99));//loop ini berfungsi apabila player menginputkan selain dari 1 / 2 maka tidak akan keluar dan terjadinya looping
}