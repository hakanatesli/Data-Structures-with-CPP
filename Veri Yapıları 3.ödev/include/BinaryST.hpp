/**
	* @file                 BinaryST Ba�l�k Dosyas�
	* @description   D���m i�inde olu�an a�a�lar�n fonksiyon, de�i�ken ve pointer tan�mlamalar� bulunmaktad�r
	* @course           1-B
	* @assignment   3. �dev
	* @date               17.12.2018
	* @author           TAHA BERKAY SAKALLI G171210098@sakarya.edu.tr  HAKAN ATE�L� G171210002@sakarya.edu.tr
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
	void LevelOrder();//levelorder �a��rma
	int Derin(BinaryDugum *ilk);//derinlik hesaplama fonksiyonu
	BinaryST();
	~BinaryST();
};
#endif
