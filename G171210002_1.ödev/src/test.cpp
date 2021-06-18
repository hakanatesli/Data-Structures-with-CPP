/**
* @file  test
* @description main fonksiyonu bulunmakta. iþlemlerimiz burada gerçekleþtiriliyor.
* @course  1-B
* @assignment  1.ödev
* @date  30.10.2018
* @author  hakan ateþli g171210002@sakarya.edu.tr
*/
#include "Yonetim.hpp"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	Yonetim *yonetim = new Yonetim();
	char okuma[24];
	int secim = 1;
	int i = 0;
	int k = -1;
	int l = 0;
	int m = 0;
	int null_deger;
	ifstream DosyaOku("Okul.txt");
	if (DosyaOku.is_open()) {
		while (!DosyaOku.eof()) {
			DosyaOku >> okuma[i];
			i++;
		}
	}
	else
		cout << "Dosya acilamadi";


	for (int j = 0; j < 24; j++) {
		if (okuma[j] == '1' || okuma[j] == '2' || okuma[j] == '3' || okuma[j] == '4') {
			k++;
			l = 0;
		}
		else {
			yonetim->okul->snf[k].ogr[l].Ad = okuma[j];
			l++;
		}
	}

	do
	{
		for (int i = 1; i < 5; i++) {
			cout << "Sinif:  " << i << "         ";
		}
		cout << endl;
		m++;

		do
		{
			null_deger = 0;
			for (int i = 1; i < 5; i++) {
				if (yonetim->okul->snf[i - 1].ogr[m - 1].Ad != ' ') {
					cout << yonetim->okul->snf[i - 1].ogr[m - 1].Ad << " " << &yonetim->okul->snf[i - 1].ogr[m - 1] << "        ";
				}
				else {
					cout << "                  ";
					null_deger++;
				}
			}
			m++;
			cout << endl;
		} while (null_deger != 4);
		m = 0;

		cout << "1-)Sinif Degistir\n" << "2-)Ogrenci Degistir\n" << "3-)Cikis\n" << "=>";
		cin >> secim;
		if (secim == 1) {
			int secim1, secim2;
			cout << "1.Sinif Adi:";
			cin >> secim1;
			cout << "2.Sinif Adi:";
			cin >> secim2;
		}
		else if (secim == 2) {
			char secim1, secim2;
			cout << "1.Ogrenci:";
			cin >> secim1;
			cout << "2.Ogrenci:";
			cin >> secim2;
		}
		else if (secim == 3) {
			break;
		}
		else {
			cout << "Tekrar seçim yapiniz!!" << endl;
			continue;
		}
		system("cls");
	} while (secim != 3);

	DosyaOku.close();
	delete yonetim;
	system("pause");
	return 0;
}
