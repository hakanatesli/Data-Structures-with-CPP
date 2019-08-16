/**
	* @file                 BinaryDugum Baþlýk Dosyasý
	* @description   Düðüm içinde oluþan aðaçlarýn düðümlerindeki fonksiyon, deðiþken ve pointer tanýmlamalarý bulunmaktadýr
	* @course           1-B
	* @assignment   3. Ödev
	* @date               17.12.2018
	* @author           TAHA BERKAY SAKALLI G171210098@sakarya.edu.tr  HAKAN ATEÞLÝ G171210002@sakarya.edu.tr
	*/
#ifndef BINARYDUGUM_HPP
#define BINARYDUGUM_HPP
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
class BinaryDugum
{
private:
	int Veri;
public:
	BinaryDugum *pSol;
	BinaryDugum *pSag;
	void Ekle(int deger);//dugum oluþturup veri ekleme fonksiyonu
	BinaryDugum(int veri);
	BinaryDugum();
	~BinaryDugum();
	int Min(BinaryDugum *KokDugum);//minimum degeri buluyor
	int Max(BinaryDugum *KokDugum);//maksimum degeri buluyor
	void MaxSil(BinaryDugum *ilkdugum);//maksimum degeri siliyor
	void MinSil(BinaryDugum *ilkdugum);//minimum degeri siliyor
	BinaryDugum *Silme(BinaryDugum *ilkDugum,int deger);//dugum siliyor
	void LevelOrder(BinaryDugum *ilkdugum);//level order fonksiyonu
	int Derinlik(BinaryDugum *root); // derinlik hesaplama fonksiyonu
	void LevelOrderYazdir(BinaryDugum *root, int level);//level order yazdirma fonksiyonu
};
#endif
