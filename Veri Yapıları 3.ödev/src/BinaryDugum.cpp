/**
	* @file                 BinaryDugum Kaynak Dosyasý
	* @description   Düðüm içinde oluþan aðaçlarýn düðümlerindeki fonksiyonlar bulunmaktadýr
	* @course           1-B
	* @assignment   3. Ödev
	* @date               17.12.2018
	* @author           TAHA BERKAY SAKALLI G171210098@sakarya.edu.tr  HAKAN ATEÞLÝ G171210002@sakarya.edu.tr
	*/
#include "BinaryDugum.hpp"

BinaryDugum::BinaryDugum(int veri)
{
	pSol = pSag = NULL;
	this->Veri = veri;
}

BinaryDugum::BinaryDugum()
{
	pSol = pSag = NULL;
}

void BinaryDugum::Ekle(int deger)
{
	//agacýn içindeki her düðüme veri ekliyor
	if (Veri > deger) {
		if (pSol) {
			return pSol->Ekle(deger);
		}
		BinaryDugum *pYeni = new BinaryDugum(deger);
		pSol = pYeni;
	}

	else if (Veri < deger) {
		if (pSag) {
			return pSag->Ekle(deger);
		}
		BinaryDugum *pYeni = new BinaryDugum(deger);
		pSag = pYeni;
	}
}

BinaryDugum::~BinaryDugum()
{
}

int BinaryDugum::Min(BinaryDugum *KokDugum)
{
	//agacýn minimum degerini buluyor
	while (KokDugum->pSol != NULL)
	{
		KokDugum = KokDugum->pSol;
	}
	return KokDugum->Veri;
}

int BinaryDugum::Max(BinaryDugum *KokDugum)
{
	//agacýn maksimum degerini buluyor
	while (KokDugum->pSag != NULL)
	{
		KokDugum = KokDugum->pSag;
	}	
	return KokDugum->Veri;
}

void BinaryDugum::MaxSil(BinaryDugum * ilkdugum)
{
	//maksimum degeri siliyor
	Silme(ilkdugum, Max(ilkdugum));
}

void BinaryDugum::MinSil(BinaryDugum * ilkdugum)
{
	//minimum degeri siliyor
	Silme(ilkdugum, Min(ilkdugum));
}

BinaryDugum * BinaryDugum::Silme(BinaryDugum * ilkDugum, int deger)
{
	//agactaki istenen degerin silinmesini saðlýyor
	//ilkdüðüm parametresi agacýn ilk düðümüdür
	if (ilkDugum == NULL) return NULL;
	
	if (ilkDugum->Veri == deger) {
		if (ilkDugum->pSol == NULL && ilkDugum->pSag == NULL)
		{
			delete ilkDugum;
			return NULL;
		}

		if (ilkDugum->pSag != NULL) {
			ilkDugum->Veri = Min(ilkDugum->pSag);
			ilkDugum->pSag = Silme(ilkDugum->pSag, Min(ilkDugum->pSag));
			return ilkDugum;
		}
		ilkDugum->Veri = Max(ilkDugum->pSol);
		ilkDugum->pSol = Silme(ilkDugum->pSol, Max(ilkDugum->pSol));
		return ilkDugum;
	}
	if (ilkDugum->Veri < deger) {
		ilkDugum->pSag = Silme(ilkDugum->pSag, deger);
		return ilkDugum;
	}
	ilkDugum->pSol = Silme(ilkDugum->pSol, deger);
	return ilkDugum;
}

void BinaryDugum::LevelOrder(BinaryDugum * ilkdugum)
{
	//agacýn derinliði kadar dömüp levelOrderYazdir fonksiyonunu çaðýrýyor
	for (int i = 0; i <= Derinlik(ilkdugum); i++)
	{
		LevelOrderYazdir(ilkdugum, i);
	}
	cout << endl;
}

int BinaryDugum::Derinlik(BinaryDugum * root)
{
	//agacýn derinliðini hesaplýyor
	if (root == NULL)
	{
		return 0;
	}

	int left = Derinlik(root->pSol);
	int right = Derinlik(root->pSag);
	return max(left, right) + 1;
}

void BinaryDugum::LevelOrderYazdir(BinaryDugum * root, int level)
{
	//agacýn düðümlerindeki verileri levelorder olarak yazdýrýyor
	if (root == NULL)return;
	if (level == 1)
	{
		cout << root->Veri << " ";
	}
	else if (level > 1)
	{
		LevelOrderYazdir(root->pSol, level - 1);
		LevelOrderYazdir(root->pSag, level - 1);
	}
}
