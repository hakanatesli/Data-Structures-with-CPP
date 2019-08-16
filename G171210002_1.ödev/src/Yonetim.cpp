/**
* @file  Yonetim
* @description Yonetim classýnýn yapýcý fonksiyonu var.Ýçinde okul classý tanýmlanmýþ.
* @course  1-B
* @assignment  1.ödev
* @date  30.10.2018
* @author  hakan ateþli g171210002@sakarya.edu.tr
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