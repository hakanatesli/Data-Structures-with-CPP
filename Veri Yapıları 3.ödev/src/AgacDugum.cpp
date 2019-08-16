/**
	* @file                 AgacDugum Kaynak Dosyasý
	* @description   Düðümlerinde aðaç oluþacak olan aðacýn fonksiyonlarý bulunmaktadýr
	* @course           1-B
	* @assignment   3. Ödev
	* @date               17.12.2018
	* @author           TAHA BERKAY SAKALLI G171210098@sakarya.edu.tr  HAKAN ATEÞLÝ G171210002@sakarya.edu.tr
	*/
#include "AgacDugum.hpp"

int AgacDugum::Derinlik(AgacDugum * ilkdugum)
{
	//Dugumlerinde aðaç bulunduran aðacýn derinliði
	if (ilkdugum == NULL)
	{
		return 0;
	}

	int left = Derinlik(ilkdugum->pSol);
	int right = Derinlik(ilkdugum->pSag);
	return max(left, right) + 1;
}

void AgacDugum::IlkAgacGezMinSil(AgacDugum * ilkdugum, int level)
{
	//Dugumlerinde aðaç bulunduran aðacý gezip, düðümlerinde bulunan aðaçlarýn minimum deðerlerini siliyor
	if (ilkdugum == NULL)return;
	if (level == 0)
	{
		AgacDugum *gez = new AgacDugum();
		gez = ilkdugum;

		gez->agac->MinSilDugumAgac();//düðüm içindeki aðacýn min deðerini siliyor
	}
	else if (level > 0)
	{
		IlkAgacGezMinSil(ilkdugum->pSol, level - 1);
		IlkAgacGezMinSil(ilkdugum->pSag, level - 1);
	}
}

void AgacDugum::IlkAgacGezMaxSil(AgacDugum * ilkdugum, int level)
{
	//Dugumlerinde aðaç bulunduran aðacý gezip, düðümlerinde bulunan aðaçlarýn maksimum deðerlerini siliyor
	if (ilkdugum == NULL)return;
	if (level == 0)
	{
		AgacDugum *gez = new AgacDugum();
		gez = ilkdugum;

		gez->agac->MaxSilDugumAgac();//düðüm içindeki aðacýn max deðerini siliyor
	}
	else if (level > 0)
	{
		IlkAgacGezMaxSil(ilkdugum->pSol, level - 1);
		IlkAgacGezMaxSil(ilkdugum->pSag, level - 1);
	}
}

void AgacDugum::DugumEkle(int dizideger)
{
	//Aðaç içinde düðüm, düðüm içinde de aðaç oluþturuyor
	//girilen sayýnýn deðerine göre düðümleri anaaðaç ýn saðýnda veya solunda oluþturuyor
	if (Gecici)
	{
		if (Gecici->DugumVeri > dizideger)
		{			
			AgacDugum *pYeni = new AgacDugum();
			pYeni->Ekle(dizideger);
			Gecici->pSol = pYeni;
			Gecici = pYeni;
			Gecici->DugumVeri = dizideger;
		}
		else if (Gecici->DugumVeri < dizideger)
		{
			AgacDugum *pYeni = new AgacDugum();
			pYeni->Ekle(dizideger);
			Gecici->pSag = pYeni;
			Gecici = pYeni;
			Gecici->DugumVeri = dizideger;
		}
	}
	else {
		Dugum = new AgacDugum();
		Dugum->DugumVeri = dizideger;
		Gecici = Dugum;
		Dugum->Ekle(dizideger);
	}
}

void AgacDugum::Ekle(int dizideger)
{
	//agacýn düðümlerine eleman ekliyor
	BinaryST *agacGezici = new BinaryST();

	agac = agacGezici;
	while (agacGezici->Derin(agacGezici->DugumKok) != dizideger + 1)
	{
		agacGezici->Ekle(rand() % 1000 + 1);
	}
	//while agacýn derinliði kadar dönüyor
}

void AgacDugum::minSilmek()
{
	//Tüm agaclarý gezerek minimum degerleri buluyor
	for (int i = 0; i <= Derinlik(Dugum); i++)
	{
		IlkAgacGezMinSil(Dugum, i);
	}
}

void AgacDugum::maxSilmek()
{
	//Tüm agaclarý gezerek maksimum degerleri buluyor
	for (int i = 0; i <= Derinlik(Dugum); i++)
	{
		IlkAgacGezMaxSil(Dugum, i);
	}
}

void AgacDugum::Levelyazdir()
{
	//Tüm agaclarý gezerek verileri level order olarak yazýyor
	for (int i = 0; i <= Derinlik(Dugum); i++)
	{
		IlkAgacGez(Dugum, i);
	}
}

void AgacDugum::IlkAgacGez(AgacDugum * ilkdugum, int level)
{
	//Dugumlerinde aðaç bulunduran aðacý, level order ile geziyor
	if (ilkdugum == NULL)return;
	if (level == 0)
	{
		AgacDugum *gez = new AgacDugum();
		gez = ilkdugum;

		gez->agac->LevelOrder(); // düðüm içindeki aðaçlarýn düðümündeki verileri level order ile yazdýrýyor
	}
	else if (level > 0)
	{
		IlkAgacGez(ilkdugum->pSol, level - 1);
		IlkAgacGez(ilkdugum->pSag, level - 1);
	}
}

AgacDugum::AgacDugum()
{
	Dugum = NULL;
	Gecici = NULL;
	pSag=NULL;
	pSol=NULL;
}

AgacDugum::~AgacDugum()
{
	delete Dugum, Gecici, pSag, pSol;
	delete agac;
}
