/**        
* @file  CiftDugum.hpp  
* @description   Çift Yönlü Baðlý Liste ve Stack'i daha iyi kavramak için yapýlmýþ bir ödev.
* @course  1.öðretim B grubu 
* @assignment  2.Ödev
* @date  1.12.2018  
* @author  hakan ateþli g171210002@sakarya.edu.tr   
*/
#ifndef CIFTDUGUM_HPP
#define	CIFTDUGUM_HPP
#include <iostream>
using namespace std;
#include "Stack.hpp"
class CiftDugum {
private:
	int Veri;
public:
	Stack *stack;
	CiftDugum* sonraki;
	CiftDugum* onceki;
	CiftDugum(int veri){
		stack = new Stack();
		this->Veri = veri;
		stack->Push(veri);
	}

	int getVeri() {
		return this->Veri;
	}

	void setVeri(int veri) {
		this->Veri = veri;
	}
};
#endif
