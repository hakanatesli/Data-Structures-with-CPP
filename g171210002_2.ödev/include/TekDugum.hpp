/**        
* @file  TekDugum.hpp  
* @description   �ift Y�nl� Ba�l� Liste ve Stack'i daha iyi kavramak i�in yap�lm�� bir �dev.
* @course  1.��retim B grubu 
* @assignment  2.�dev
* @date  1.12.2018  
* @author  hakan ate�li g171210002@sakarya.edu.tr   
*/
#ifndef TEKDUGUM_HPP
#define	TEKDUGUM_HPP
#include <iostream>
using namespace std;
class TekDugum {
private:
	int Veri;
public:
	TekDugum* ileri;
	TekDugum(const int& elm,TekDugum* ilr=NULL){
		ileri = ilr;
		Veri = elm;
	}
	int getVeri() {
		return this->Veri;
	}
};

#endif
