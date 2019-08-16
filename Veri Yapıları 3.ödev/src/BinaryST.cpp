/**
	* @file                 BinaryST Kaynak Dosyas�
	* @description   D���m i�inde olu�an a�a�lar�n fonksiyonlar� bulunmaktad�r
	* @course           1-B
	* @assignment   3. �dev
	* @date               17.12.2018
	* @author           TAHA BERKAY SAKALLI G171210098@sakarya.edu.tr  HAKAN ATE�L� G171210002@sakarya.edu.tr
	*/
#include "BinaryST.hpp"

void BinaryST::Ekle(int deger)
{
	//Agac�n i�inde d�g�m yoksa d���m olu�turuyor varsa d���mlere veri ekliyor
	if (DugumKok) {
		DugumKok->Ekle(deger);
	}
	else
	{
		DugumKok = new BinaryDugum(deger);
		ilk = DugumKok;
	}
}

void BinaryST::MinSilDugumAgac()
{
	//minimum degeri bulup siliyor
	cout << "min : " << DugumKok->Min(DugumKok) << endl;
	DugumKok->MinSil(DugumKok);
}

void BinaryST::MaxSilDugumAgac()
{
	//maksimum degeri bulup siliyor
	cout<<"max : "<< DugumKok->Max(DugumKok)<<endl;
	DugumKok->MaxSil(DugumKok);
}

void BinaryST::LevelOrder()
{
	//level order yazd�rma
	DugumKok->LevelOrder(DugumKok);
}

int BinaryST::Derin(BinaryDugum * ilk)
{
	//agac�n derinli�ini hesaplama
	if (ilk == NULL)
	{
		return 0;
	}

	int left = Derin(ilk->pSol);
	int right = Derin(ilk->pSag);
	return max(left, right) + 1;
}

BinaryST::BinaryST()
{
	DugumKok = NULL;
}

BinaryST::~BinaryST()
{
}
