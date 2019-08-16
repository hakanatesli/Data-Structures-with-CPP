/**        
* @file  Liste.hpp  
* @description   Çift Yönlü Baðlý Liste ve Stack'i daha iyi kavramak için yapýlmýþ bir ödev.
* @course  1.öðretim B grubu 
* @assignment  2.Ödev
* @date  1.12.2018  
* @author  hakan ateþli g171210002@sakarya.edu.tr   
*/
#ifndef LISTE_HPP
#define	LISTE_HPP
#include <iostream>
using namespace std;
#include "CiftDugum.hpp"
class Liste {
private:
	CiftDugum *ilkEleman, *sonEleman;
	int elemanSayisi;
public:
	Liste(){
		ilkEleman = NULL;
		sonEleman = NULL;
		elemanSayisi = 0;
	}
	int getelemanSayisi() {
		return this->elemanSayisi;
	}

	void ilk_elemanEkle(int yeniVeri) {
		if (ilkEleman == NULL) {
			elemanSayisi++;
			ilkEleman = new CiftDugum(yeniVeri);
			ilkEleman->onceki = ilkEleman;
			ilkEleman->sonraki = ilkEleman;
			sonEleman = ilkEleman;
		}
	}

	void elemanEkle(int yeniVeri) {
		elemanSayisi++;
		CiftDugum *yeni = new CiftDugum(yeniVeri);
		yeni->sonraki = sonEleman->sonraki;
		yeni->onceki = sonEleman;
		sonEleman->sonraki->onceki = yeni;
		sonEleman->sonraki = yeni;
		sonEleman = yeni;
	}

	void SagaKayma() {
		int gecici = -1, gecici2;
		CiftDugum *gec;
		gec = ilkEleman;
		while (gec->getVeri() != -1) {
			if (gecici == -1) {
				gecici = gec->getVeri();
				gec->setVeri(-1);
				gec = gec->sonraki;
			}
			else {
				gecici2 = gec->getVeri();
				gec->setVeri(gecici);
				gec->stack->Push(gec->getVeri());
				gecici = gecici2;
				gec = gec->sonraki;
			}
		}
		gec->setVeri(gecici);
		gec->stack->Push(gec->getVeri());
	}

	void SolaKayma() {
		int gecici = -1, gecici2;
		CiftDugum *gec;
		gec = sonEleman;
		while (gec->getVeri() != -1) {
			if (gecici == -1) {
				gecici = gec->getVeri();
				gec->setVeri(-1);
				gec = gec->onceki;
			}
			else {
				gecici2 = gec->getVeri();
				gec->setVeri(gecici);
				gec->stack->Push(gec->getVeri());
				gecici = gecici2;
				gec = gec->onceki;
			}
		}
		gec->setVeri(gecici);
		gec->stack->Push(gec->getVeri());
	}


	void dugumKonumu(int konum) {
		if (konum > elemanSayisi||konum < 1) {
			cout << "Bu konumda dugum bulunmamaktadir." << endl;
		}
		else {
			CiftDugum *gec = ilkEleman;
			for (int i = 1; i < konum; i++) {
				gec = gec->sonraki; 
			}
			TekDugum *yedek = gec->stack->getstackBasi();
			cout << gec->getVeri() << "       :        ";
			while (yedek!=NULL) {
				cout << yedek->getVeri() << "     ";
				yedek = yedek->ileri;
			}
			cout << endl;
		}
	}
};
#endif
