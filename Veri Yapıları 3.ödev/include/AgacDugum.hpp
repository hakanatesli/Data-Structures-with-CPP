/**
	* @file                 AgacDugum Baþlýk Dosyasý
	* @description   Düðümlerinde aðaç oluþacak olan aðacýn fonksiyon, deðiþken ve pointer tanýmlamalarý bulunmaktadýr
	* @course           1-B
	* @assignment   3. Ödev
	* @date               17.12.2018
	* @author           TAHA BERKAY SAKALLI G171210098@sakarya.edu.tr  HAKAN ATEÞLÝ G171210002@sakarya.edu.tr
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
	int Derinlik(AgacDugum *ilkdugum);//dugumlerinde aðaç bulunduran aðacýn derinliði
	void IlkAgacGezMinSil(AgacDugum *ilkdugum, int level);//aðaçlarý gezip min siliyor
	void IlkAgacGezMaxSil(AgacDugum *ilkdugum, int level);//aðaçlarý gezip max siliyor
	void DugumEkle(int dizideger);//dugum içinde agac ekleme
	void Ekle(int dizideger);//agac içinde dugum ekleme
	void minSilmek();//min silme fonksiyonunu çaðýrýyor
	void maxSilmek();//max silme fonksiyonunu çaðýrýyor
	void Levelyazdir();//level order yazdýrma
	void IlkAgacGez(AgacDugum *ilkdugum, int level);//dugumlerinde aðaç bulunduran aðacý geziyor
	AgacDugum();
	~AgacDugum();
};
#endif
