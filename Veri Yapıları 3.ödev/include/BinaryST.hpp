/**
	* @file                 BinaryST Baþlýk Dosyasý
	* @description   Düðüm içinde oluþan aðaçlarýn fonksiyon, deðiþken ve pointer tanýmlamalarý bulunmaktadýr
	* @course           1-B
	* @assignment   3. Ödev
	* @date               17.12.2018
	* @author           TAHA BERKAY SAKALLI G171210098@sakarya.edu.tr  HAKAN ATEÞLÝ G171210002@sakarya.edu.tr
	*/
#ifndef BINARYST_HPP
#define BINARYST_HPP
#include <iostream>
#include "BinaryDugum.hpp"
using namespace std;
class BinaryST
{
public:
	BinaryDugum *ilk;
	BinaryDugum *DugumKok;
	void Ekle(int deger); // dugum ekleme
	void MinSilDugumAgac();//minimum deger silme
	void MaxSilDugumAgac();//maksimum degeri silme
	void LevelOrder();//levelorder çaðýrma
	int Derin(BinaryDugum *ilk);//derinlik hesaplama fonksiyonu
	BinaryST();
	~BinaryST();
};
#endif
