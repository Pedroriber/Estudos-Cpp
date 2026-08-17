
//#include <iostream>
//#include <string>
//using namespace std;
//
//int fatorial_while(int n);	
//int fatorial_for(int n);
//int fatorial_recursivo(int n);
//int busca_binaria(int vetor[], int tamanho, int valor);
//
//int main()
//{
//	/*string nome;
//	int numero;
//	cout << "qual o seu nome ?\n";
//	cin >> nome;
//	cout << "Olá " << nome << "\n";
//	cout << "Digite um numero: ";
//	cin >> numero;
//	if (numero % 2 == 0)
//	{
//		cout << "O numero é par\n";
//	}
//	else
//	{
//		cout << "O numero eh  impar\n";
//	}*/
//	/*cout << "Digite um numero para calcular o fatorial e o metodo (while, for, rec): ";
//	int numero;
//	char met;
//	cin >> numero >> met;
//	switch (met) {
//		case '1':
//			cout << "O fatorial eh (while): " << fatorial_while(numero) << "\n";
//			break;
//		case '2':
//			cout << "O fatorial eh (for): " << fatorial_for(numero) << "\n";
//			break;
//		case '3':
//			cout << "O fatorial eh (rec): " << fatorial_recursivo(numero) << "\n";
//			break;
//	}*/
//	cout << "Digite o valor a ser buscado na lista {2,5,8,10,15,21,30}: ";
//	int numero;
//	cin >> numero;
//	int v[] = {2,5,8,10,15,21,30};
//	busca_binaria(v, 7, numero);
//	main();
//	return 0;
//}
//
//int fatorial_while(int n)
//{
//	int resultado = 1;
//	while (n > 1) {
//		resultado *= n;
//		n--;
//	}
//	return resultado;
//}
//
//int fatorial_for(int n)
//{
//	int resultado = 1;
//	for (int i = n; i > 1; i--) {
//		resultado *= i;
//		
//	}
//	return resultado;
//}
//
//int fatorial_recursivo(int n) {
//	if (n >= 1) {
//		return n *= fatorial_recursivo(n - 1);
//
//	}
//}
//
//int busca_binaria(int vetor[], int tamanho, int valor) {
//	int low = 0;
//	int high = tamanho - 1;
//
//	while (low <= high) {
//		int meio = (low + high) / 2;
//		if (vetor[meio] == valor) {
//			cout << "O valor " << valor << " foi encontrado na posição " << meio << "\n";
//			return meio;
//		}
//		else if (vetor[meio] > valor) {
//			high = meio - 1;
//		}
//		else {
//			low = meio + 1;
//		}
//	}
//
//	cout << "O valor " << valor << " não foi encontrado na lista\n";
//	return -1;
//}

