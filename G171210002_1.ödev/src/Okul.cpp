/**
* @file  Okul
* @description Okul class�n�n yap�c� fonksiyonu var. ��inde sinif dizisi tan�mlanm��.
* @course  1-B
* @assignment  1.�dev
* @date  30.10.2018
* @author  hakan ate�li g171210002@sakarya.edu.tr
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