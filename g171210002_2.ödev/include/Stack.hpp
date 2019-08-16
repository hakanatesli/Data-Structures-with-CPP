/**        
* @file  Stack.hpp  
* @description   Çift Yönlü Baðlý Liste ve Stack'i daha iyi kavramak için yapýlmýþ bir ödev.
* @course  1.öðretim B grubu 
* @assignment  2.Ödev
* @date  1.12.2018  
* @author  hakan ateþli g171210002@sakarya.edu.tr   
*/
#ifndef STACK_HPP
#define	STACK_HPP
#include <iostream>
using namespace std;
#include "TekDugum.hpp"
class Stack {
private:
	TekDugum *stackBasi;
public:
	Stack(){
		stackBasi = NULL;
	}
	bool isEmpty() const {
		return stackBasi == NULL;
	}
	TekDugum* getstackBasi() {
		return stackBasi;
	}
	void Push(int yeni) {
		stackBasi = new TekDugum(yeni, stackBasi);
	}
	int Top(){
		return stackBasi->getVeri();
	}
	~Stack() {
		
	}
};

#endif
