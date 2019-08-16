/**
	* @file                 AgacDugum Ba�l�k Dosyas�
	* @description   D���mlerinde a�a� olu�acak olan a�ac�n fonksiyon, de�i�ken ve pointer tan�mlamalar� bulunmaktad�r
	* @course           1-B
	* @assignment   3. �dev
	* @date               17.12.2018
	* @author           TAHA BERKAY SAKALLI G171210098@sakarya.edu.tr  HAKAN ATE�L� G171210002@sakarya.edu.tr
	*/
#ifndef AGACDUGUM_HPP
#define AGACDUGUM_HPP
#include <iostream>
#include "BinaryST.hpp"
#include "BinaryDugum.hpp"
using namespace std;

class AgacDugum
{
private:
	int DugumVeri;
public:
	AgacDugum *pSag;
	AgacDugum *pSol;
	AgacDugum *Dugum;
	AgacDugum *Gecici;
	BinaryST *agac = new BinaryST();
	int Derinlik(AgacDugum *ilkdugum);//dugumlerinde a�a� bulunduran a�ac�n derinli�i
	void IlkAgacGezMinSil(AgacDugum *ilkdugum, int level);//a�a�lar� gezip min siliyor
	void IlkAgacGezMaxSil(AgacDugum *ilkdugum, int level);//a�a�lar� gezip max siliyor
	void DugumEkle(int dizideger);//dugum i�inde agac ekleme
	void Ekle(int dizideger);//agac i�inde dugum ekleme
	void minSilmek();//min silme fonksiyonunu �a��r�yor
	void maxSilmek();//max silme fonksiyonunu �a��r�yor
	void Levelyazdir();//level order yazd�rma
	void IlkAgacGez(AgacDugum *ilkdugum, int level);//dugumlerinde a�a� bulunduran a�ac� geziyor
	AgacDugum();
	~AgacDugum();
};
#endif
