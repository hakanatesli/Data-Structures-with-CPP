/**
* @file  Sinif
* @description Sinif class�n�n yap�c� fonksiyonu var.��inde Ogrenci class� tan�mlanm��.
* @course  1-B
* @assignment  1.�dev
* @date  30.10.2018
* @author  hakan ate�li g171210002@sakarya.edu.tr
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