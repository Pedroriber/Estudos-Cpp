/*
Containers armazenam os dados, iteradores indicam como percorrê-los, 
e algoritmos usam esses iteradores para operar sobre os elementos.
*/


#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
int main() {

	vector<int> numeros = { 5, 2, 8, 1 };

	sort(numeros.begin(), numeros.end());   //sort() é um algoritmo

	for (auto it = numeros.begin(); //auto deduz o tipo 
		it != numeros.end();
		++it) {

		cout << *it << " ";
	}


	vector<string> names;
	string name;
	cout << "Digite o primeiro nome de cada aluno : \n";
	while (name != "sair")
	{
		cin >> name;
		if (name != "sair") {
			names.push_back(name);
		}
		

	}
	cout << "Nomes dos alunos: \n";
	for (string n : names) {
		
		cout << n << "\n" << endl;
	}
	
}

