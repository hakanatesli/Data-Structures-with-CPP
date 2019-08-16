/**        
* @file  main.cpp  
* @description   Çift Yönlü Baðlý Liste ve Stack'i daha iyi kavramak için yapýlmýþ bir ödev.
* @course  1.öðretim B grubu 
* @assignment  2.Ödev
* @date  1.12.2018  
* @author  hakan ateþli g171210002@sakarya.edu.tr   
*/
#include <iostream>
#include <fstream>
#include "Liste.hpp"
using namespace std;

int main(int argc, char** argv) {

	int okunan;
	int i = 0;
	int secim = -1;
	Liste *liste = new Liste();

	ifstream DosyaOku("Sayi.txt");
	if (DosyaOku.is_open()) {
		while (!DosyaOku.eof()) {
			if (i == 0) {
				DosyaOku >> okunan;
				liste->ilk_elemanEkle(okunan);
				i++;
			}
			else {
				DosyaOku >> okunan;
				liste->elemanEkle(okunan);
			}
		}
	}
	else
		cout << "Dosya Okunamadi" << endl;

	do
	{
		cout << "1-)Sola Hareket\n" << "2-)Saga Hareket\n" << "3-)Bir Dugumun Durumlarini Yazdir\n" << "4-)Tum Durumlari Yazdir\n" << "5-)Cikis\n" << "=>";
		cin >> secim;
		system("cls");
		if (secim == 1) {
			liste->SolaKayma();
		}
		else if (secim == 2) {
			liste->SagaKayma();
		}
		else if (secim == 3) {
			int konum;
			cout << "Dugum Konumu:";
			cin >> konum;
			liste->dugumKonumu(konum);
		}
		else if (secim == 4) {
			for (int i = 1; i <= liste->getelemanSayisi(); i++) {
				liste->dugumKonumu(i);
			}
		}
		else if (secim == 5) {
			break;
		}
		else {
			cout << "Tekrar secim yapiniz!!" << endl;
			continue;
		}
	} while (secim != 5);

	DosyaOku.close();
	system("pause");
	return 0;
}
