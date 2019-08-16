/**
	* @file                 Test Dosyası
	* @description   Test Dosyasındaki değişkenler ve fonksiyonlar bulunmaktadır
	* @course           1-B
	* @assignment   3. Ödev
	* @date               17.12.2018
	* @author           TAHA BERKAY SAKALLI G171210098@sakarya.edu.tr  HAKAN ATEŞLİ G171210002@sakarya.edu.tr
	*/
#include <iostream>
#include <ctime>
#include "BinaryST.hpp"
#include "AgacDugum.hpp"
using namespace std;

int cevap;

int Menu() // menü fonksiyonu
{
	cout << "1-Maksimum degeri cikar" << endl;
	cout << "2-Minimum degeri cikar" << endl;
	cout << "3-Tum agaclari level order ile yazdir" << endl;
	cout << "4-Cikis" << endl;
	cout << "=>";
	cin >> cevap;
	return cevap;
}

int main()
{	
	srand(time(0));
	int Dizi[20]; // girilen sayının basamak değerlerini tutuyor
	int indeks=0;
	unsigned long long sayi;
	unsigned long long gecici;

	cout << "Sayi Giriniz : ";
	cin >> sayi;

	while (sayi > 0) // girilen sayının basamak değerlerini bir diziye atıyor
	{
		gecici = sayi % 10;
		Dizi[indeks] = gecici;
		indeks++;
		sayi = sayi / 10;			
	}
	int deger;

	AgacDugum *Dugum = new AgacDugum();

	while (indeks > 0)//dizinin sonundan elemanları çıkarıyor
	{
		Dugum->DugumEkle(Dizi[indeks - 1]);
		indeks--;
	}

	do {

		cevap = Menu();
		
		//system("CLS");
		
		if (cevap == 1)//max çıkar
		{
			Dugum->maxSilmek();
		}

		else if (cevap == 2) //min çıkar
		{
			Dugum->minSilmek();
		}

		else if (cevap == 3) // levelorder
		{
			Dugum->Levelyazdir();
		}

		else if (cevap == 4) // programdan çıkıyor ve heapte oluşan nesneleri siliyor
		{			
			Dugum->~AgacDugum();
			exit(0);
		}
		
		cout << "-------------------------------" << endl;
		cout << "-------------------------------" << endl;
	} while (cevap != 1 || cevap != 2 || cevap != 3 || cevap != 4);

	system("PAUSE");
	return 0;
}
