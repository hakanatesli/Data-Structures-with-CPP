/**
	* @file                 AgacDugum Kaynak Dosyas�
	* @description   D���mlerinde a�a� olu�acak olan a�ac�n fonksiyonlar� bulunmaktad�r
	* @course           1-B
	* @assignment   3. �dev
	* @date               17.12.2018
	* @author           TAHA BERKAY SAKALLI G171210098@sakarya.edu.tr  HAKAN ATE�L� G171210002@sakarya.edu.tr
	*/
#include "AgacDugum.hpp"

int AgacDugum::Derinlik(AgacDugum * ilkdugum)
{
	//Dugumlerinde a�a� bulunduran a�ac�n derinli�i
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
	//Dugumlerinde a�a� bulunduran a�ac� gezip, d���mlerinde bulunan a�a�lar�n minimum de�erlerini siliyor
	if (ilkdugum == NULL)return;
	if (level == 0)
	{
		AgacDugum *gez = new AgacDugum();
		gez = ilkdugum;

		gez->agac->MinSilDugumAgac();//d���m i�indeki a�ac�n min de�erini siliyor
	}
	else if (level > 0)
	{
		IlkAgacGezMinSil(ilkdugum->pSol, level - 1);
		IlkAgacGezMinSil(ilkdugum->pSag, level - 1);
	}
}

void AgacDugum::IlkAgacGezMaxSil(AgacDugum * ilkdugum, int level)
{
	//Dugumlerinde a�a� bulunduran a�ac� gezip, d���mlerinde bulunan a�a�lar�n maksimum de�erlerini siliyor
	if (ilkdugum == NULL)return;
	if (level == 0)
	{
		AgacDugum *gez = new AgacDugum();
		gez = ilkdugum;

		gez->agac->MaxSilDugumAgac();//d���m i�indeki a�ac�n max de�erini siliyor
	}
	else if (level > 0)
	{
		IlkAgacGezMaxSil(ilkdugum->pSol, level - 1);
		IlkAgacGezMaxSil(ilkdugum->pSag, level - 1);
	}
}

void AgacDugum::DugumEkle(int dizideger)
{
	//A�a� i�inde d���m, d���m i�inde de a�a� olu�turuyor
	//girilen say�n�n de�erine g�re d���mleri anaa�a� �n sa��nda veya solunda olu�turuyor
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
	//agac�n d���mlerine eleman ekliyor
	BinaryST *agacGezici = new BinaryST();

	agac = agacGezici;
	while (agacGezici->Derin(agacGezici->DugumKok) != dizideger + 1)
	{
		agacGezici->Ekle(rand() % 1000 + 1);
	}
	//while agac�n derinli�i kadar d�n�yor
}

void AgacDugum::minSilmek()
{
	//T�m agaclar� gezerek minimum degerleri buluyor
	for (int i = 0; i <= Derinlik(Dugum); i++)
	{
		IlkAgacGezMinSil(Dugum, i);
	}
}

void AgacDugum::maxSilmek()
{
	//T�m agaclar� gezerek maksimum degerleri buluyor
	for (int i = 0; i <= Derinlik(Dugum); i++)
	{
		IlkAgacGezMaxSil(Dugum, i);
	}
}

void AgacDugum::Levelyazdir()
{
	//T�m agaclar� gezerek verileri level order olarak yaz�yor
	for (int i = 0; i <= Derinlik(Dugum); i++)
	{
		IlkAgacGez(Dugum, i);
	}
}

void AgacDugum::IlkAgacGez(AgacDugum * ilkdugum, int level)
{
	//Dugumlerinde a�a� bulunduran a�ac�, level order ile geziyor
	if (ilkdugum == NULL)return;
	if (level == 0)
	{
		AgacDugum *gez = new AgacDugum();
		gez = ilkdugum;

		gez->agac->LevelOrder(); // d���m i�indeki a�a�lar�n d���m�ndeki verileri level order ile yazd�r�yor
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
