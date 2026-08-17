
#ifndef _STACK
#define _STACK
//funções membro de estruturas
struct Stack {
	int top;
	float* elems;
	void push(float val);
	void reset() {         // pode fazer inline
		top = 0;
	}


};

void Stack::push(float val) {   // ou pode fazer fora com escopo (::)
	elems[top++] = val;
}

Stack* createStack(int size) {
	Stack* s = new Stack;
	s->elems = new float[size];
	s->top = 0;
	return s;
}
//struct controle { 
//	private:
//		int a;
//		int f1(char* b);
//	protected:
//		int b;
//		int f2(float);
//	public:
//		int c;
//		float d;
//		void f3(controle*); };
//}
#endif 