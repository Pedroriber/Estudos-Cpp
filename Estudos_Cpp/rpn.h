#ifndef _RPN_H
#define _RPN_H

using namespace std;

bool getOperandos(Stack<float>* s, float* nl, float* n2);

template<typename T>
bool StrToValue(const string& str, T* entrada) {
	istringstream stream(str);

	if (stream >> *entrada) {
		return true;
	}
	return false;
}
#endif