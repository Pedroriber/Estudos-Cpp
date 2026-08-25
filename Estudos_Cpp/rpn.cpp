#include<iostream>
#include<string>
#include<sstream>
#include"stack.h"
using namespace std;

//bool StrToFloat(const string &str, float *v) {
//	try {
//		*v= stof(str);
//		return true;
//	}
//	catch(invalid_argument){
//		return false;
//	}
//	catch (out_of_range) {
//		return false;
//	}
//}
//
//void StrToChar(const string& str, char *c) {
//	*c = str[0];
//	
//}

bool getOperandos (Stack<float>* s,float *n1, float *n2){
	if (s->empty()) {
		cout << "Pilha vazia!" << endl;
		return false;
	}

	*n2= s->pop();
	if (s->empty()) {
		s->push( *n2);
		cout << "É preciso dois operandos" << endl;
		return false;
	}
	*n1= s->pop();
	return true;
}