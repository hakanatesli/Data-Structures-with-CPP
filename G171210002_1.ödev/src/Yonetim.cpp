/**
* @file  Yonetim
* @description Yonetim class�n�n yap�c� fonksiyonu var.��inde okul class� tan�mlanm��.
* @course  1-B
* @assignment  1.�dev
* @date  30.10.2018
* @author  hakan ate�li g171210002@sakarya.edu.tr
*/
#include "Yonetim.hpp"
Yonetim::Yonetim()
{
	okul = new Okul();
}
Yonetim::~Yonetim()
{
	delete okul;
}