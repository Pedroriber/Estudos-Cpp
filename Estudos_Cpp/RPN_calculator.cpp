#include<iostream>
#include<sstream>
#include"stack.h"
#include"rpn.h"

using namespace std;

int main() {
	Stack<float> s;
	while (true) {

		string str;
		cout << "> ";
		cin>> str;
		float val;
		if (StrToValue(str, &val)) {
			s.push(val);
		}
		else {
			char c;
			StrToValue(str, &c);
			float n1, n2;
			switch (c)
			{
				case '+':
					if (getOperandos(&s, &n1, &n2)) {
						s.push(n1 + n2);
					}
					break;

				case '-':
					if (getOperandos(&s, &n1, &n2)) {
						s.push(n1 - n2);
					}
					break;

				case '/':
					if (getOperandos(&s, &n1, &n2)) {
						s.push(n1 / n2);
					}
					break;

				case '*':
					if (getOperandos(&s, &n1, &n2)) {
						s.push(n1 * n2);
					}
					break;

				case 'q':
					return 0;

				default:
					cout << "Parametro Invalido" << endl;
			}
		}
		s.show();
	}
}

