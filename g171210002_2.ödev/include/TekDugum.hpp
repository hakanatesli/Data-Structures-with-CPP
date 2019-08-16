/**        
* @file  TekDugum.hpp  
* @description   Çift Yönlü Baðlý Liste ve Stack'i daha iyi kavramak için yapýlmýþ bir ödev.
* @course  1.öðretim B grubu 
* @assignment  2.Ödev
* @date  1.12.2018  
* @author  hakan ateþli g171210002@sakarya.edu.tr   
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
