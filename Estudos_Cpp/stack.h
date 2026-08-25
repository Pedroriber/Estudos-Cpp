
#ifndef _STACK
#define _STACK
#include<iostream>
using namespace std;

const unsigned int STK_MAX = 100;
template<typename T>
class Stack {
	template<typename T>
	friend class StackIterator;
public:
	Stack() {
		elems = new T[STK_MAX];
		reset();
	}
	~Stack() {
		delete[] elems;
	}
private:
	int top;
	T* elems;

public:
	void push(T val) {
		elems[top++] = val;
	}
	T pop() {
		return elems[--top];
	}
	void reset() { top = 0; }

	bool empty() const {
		return top == 0;
	}

	void show() {
		StackIterator<T> it(this);
		while (!it.end()) {
			T valor = it.next();

			cout << valor << endl;
		}
		cout.precision(2);
	}

};

template<typename U>
class StackIterator {
private:
	int current;
	Stack<U>* st;
public:
	StackIterator(Stack<U>* s) {
		st = s;
		current = 0;
	}
	bool end() const {
		return st->top == current;
	}
	U next() {
		return st->elems[current++];
	}
};
#endif 