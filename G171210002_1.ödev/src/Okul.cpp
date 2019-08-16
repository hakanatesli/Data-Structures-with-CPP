/**
* @file  Okul
* @description Okul classýnýn yapýcý fonksiyonu var. Ýçinde sinif dizisi tanýmlanmýþ.
* @course  1-B
* @assignment  1.ödev
* @date  30.10.2018
* @author  hakan ateþli g171210002@sakarya.edu.tr
*/
#include "Okul.hpp"
Okul::Okul()
{
	snf = new Sinif[4]();
}
Okul::~Okul()
{
	delete[] snf;
}