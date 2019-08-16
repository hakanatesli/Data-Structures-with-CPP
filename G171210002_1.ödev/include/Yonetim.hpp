#ifndef Yonetim_hpp
#define Yonetim_hpp
#include "Okul.hpp"
#include <iostream>
using namespace std;
class Yonetim
{
public:
	Yonetim();
	~Yonetim();
	Okul *okul;

	void SinifDegisimi(Yonetim yonetim, int secim1, int secim2) {
	}

	void OgrenciDegisim(Yonetim yonetim, char secim1, char secim2) {
	}
};
#endif