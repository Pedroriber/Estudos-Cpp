#include<iostream>
#include"stack.h"
#include"rpn.h"


const unsigned int STK_MAX = 3;
template<typename T>
class Stack {
public:
	Stack() {
		elems = new T[STK_MAX];
		reset();
	}
	~Stack() {
		delete[] elems
	}
private:
	int top;
	T* elems;

public:
	void push(T val) {
		elems[top++] = val;
	}
	void pop() {
		return elems[--top];
	}
	void reset() { top = 0; }

	bool empty() const {
		return top == 0;
	}

};