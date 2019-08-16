/**        
* @file  Stack.hpp  
* @description   �ift Y�nl� Ba�l� Liste ve Stack'i daha iyi kavramak i�in yap�lm�� bir �dev.
* @course  1.��retim B grubu 
* @assignment  2.�dev
* @date  1.12.2018  
* @author  hakan ate�li g171210002@sakarya.edu.tr   
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
