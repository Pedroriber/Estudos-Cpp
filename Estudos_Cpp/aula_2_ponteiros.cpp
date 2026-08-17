

#include<iostream>
using namespace std;
void troca(int* a, int* b);
void troca_referencia(int& a, int& b);
void f(int a, int& b, int* c);

int main() {
	//int a = 10;
	//int* p = &a; // ponteiro p aponta para a variável a

	//cout << "Valor de a: " << a << endl; // imprime o valor de a
	//cout << "Endereço de a: " << &a << endl; // imprime o endereço de a
	//cout << "Valor de p (endereço de a): " << p << endl; // imprime o valor de p (endereço de a)
	//cout << "Valor apontado por p: " << *p << endl; // imprime o valor apontado por p (valor de a)
	//
	//*p = 20; // altera o valor de a através do ponteiro p

	//cout << "Novo valor de a: " << a << endl; // imprime o novo valor de a
	//return 0;

	// ALOCAÇÂO DINÂMICA DE MEMÓRIA

	/*int n;
	cout << "Digite o tamanho do vetor: ";
	cin >> n;

	float* vetor = new float[n];

	cout << "Digite os elementos do vetor: ";
	for (int i = 0; i < n; i++) {
		cin >> vetor[i];

	}
	float med;
	int soma = 0;
	for (int i = 0; i < n; i++) {
		soma += vetor[i];
	}
	med = soma / n;

	float var= 0.0f;
	for  (int i = 0; i < n; i++) {
		var = var + ((vetor[i] - med) * (vetor[i] - med));
	}
	var = var / n;

	cout << "A média é: " << med << endl;
	cout << "A variância é: " << var << endl;
	delete[] vetor;
	return 0;

	*/
	int x = 10;
	int y = 15;
	troca_referencia(x, y);

	cout << "x: " << x << ", y: " << y << endl;

	int b1 = 10, b2 = 20, b3 = 30;
	f(b1, b2, &b3);
	printf("b1=%d, b2=%d, b3=%d\n", b1, b2, b3);
}

void troca(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
// troca com referencia

void troca_referencia(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void f(int a, int& b, int* c) {
	a = 1;
	b = 2;
	*c = 3;

}