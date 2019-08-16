/**
* @file  Sinif
* @description Sinif classýnýn yapýcý fonksiyonu var.Ýçinde Ogrenci classý tanýmlanmýþ.
* @course  1-B
* @assignment  1.ödev
* @date  30.10.2018
* @author  hakan ateþli g171210002@sakarya.edu.tr
*/
#include "Sinif.hpp"
Sinif::Sinif()
{
	ogr = new Ogrenci[10]();
}
Sinif::~Sinif()
{
	delete[] ogr;
}