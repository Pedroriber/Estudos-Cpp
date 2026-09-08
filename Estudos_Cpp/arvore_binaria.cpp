
#include<iostream>
#include <cmath>
#include<queue>
using namespace std;


struct Tree {
	int valor;
	Tree* esquerda;
	Tree* direita;
};
Tree* cria_no(int num) {
	Tree* novo = new Tree;
	novo->valor = num;
	novo->esquerda = nullptr;
	novo->direita = nullptr;
	return novo;
}
Tree* busca_arvore_bin(Tree* raiz, int num) {

	if (raiz == NULL) {
		return NULL;
	}

	else if (num < raiz->valor) {
		return busca_arvore_bin(raiz->esquerda, num);
	}
	else if (num > raiz->valor) {
		return busca_arvore_bin(raiz->direita, num);
	}
	return raiz;
}
Tree* insere_arvore_bin(Tree** raiz, int num) {
	if (*raiz == NULL) {
		*raiz = cria_no(num);
	}
	else if (num < (*raiz)->valor) {
		insere_arvore_bin(&(*raiz)->esquerda, num);
	}
	else if (num > (*raiz)->valor) {
		insere_arvore_bin(&(*raiz)->direita, num);
	}
	return *raiz;
}
Tree* remove_arvore_bin(Tree** raiz, int num) {
	if (*raiz == NULL) {
		return NULL; // Árvore vazia ou elemento não encontrado
	}

	if (num < (*raiz)->valor) {
		return remove_arvore_bin(&((*raiz)->esquerda), num);
	}
	else if (num > (*raiz)->valor) {
		return remove_arvore_bin(&((*raiz)->direita), num);
	}
	else {
		if ((*raiz)->esquerda == NULL && (*raiz)->direita == NULL) {

			delete* raiz;
			*raiz = NULL;
		}
		else if ((*raiz)->esquerda == NULL) {
			Tree* aux = *raiz;
			*raiz = (*raiz)->direita;
			delete aux;
		}
		else if ((*raiz)->direita == NULL) {
			Tree* aux = *raiz;
			*raiz = (*raiz)->esquerda;
			delete aux;
		}
		else {
			// 1. Acha o menor da direita
			Tree* aux = (*raiz)->direita;
			while (aux->esquerda != NULL) {
				aux = aux->esquerda;
			}

			// 2. Copia o valor
			(*raiz)->valor = aux->valor;

			// 3. Remove o nó que forneceu o valor duplicado
			remove_arvore_bin(&((*raiz)->direita), aux->valor);
		}
		// Encontrou o elemento! (*raiz) é o nó a ser removido.
		// Aqui entram os testes para os 3 casos:

		// 1. Não tem filhos?
		// 2. Tem apenas filho na direita?
		// 3. Tem apenas filho na esquerda?
		// 4. Tem dois filhos?
	}
}
void percorre_arvore_bin_em_nivel(Tree* raiz) {

	if (raiz == NULL) {
		cout << "Arvore vazia!" << endl;
		return;
	}
	queue<Tree*> fila;
	fila.push(raiz);
	cout << "Nos da arvore por nivel:\n" << endl;
	while (!fila.empty()) {
		// 1. Pega o primeiro elemento da fila
		Tree* atual = fila.front();
		fila.pop(); // Remove o elemento já capturado

		// 2. Imprime o valor do nó
		cout << atual->valor << " ";

		// 3. Coloca os filhos existentes na fila para serem visitados depois
		if (atual->esquerda != NULL) {
			fila.push(atual->esquerda);
		}
		if (atual->direita != NULL) {
			fila.push(atual->direita);
		}
	}
	cout << endl;


}
int main() {
	/*ponto p;
	captura(p);
	imprime(p);

	circulo c;
	captura_raio(c);

	if (interior(&c, &p)) {
		cout << "O ponto está dentro do círculo." << endl;
	}
	else {
		cout << "O ponto está fora do círculo." << endl;

	}*/
	Tree* raiz = NULL;
	int opcao = 0;
	int valor = 0;


	do {
		cout << "\n===============================" << endl;
		cout << "   ARVORE BINARIA DE BUSCA     " << endl;
		cout << "===============================" << endl;
		cout << "1. Inserir valor" << endl;
		cout << "2. Buscar valor" << endl;
		cout << "3. Remover valor" << endl;
		cout << "4. Imprimir em nível" << endl;
		cout << "0. Sair" << endl;
		cout << "Escolha uma opcao: ";
		cin >> opcao;

		switch (opcao) {
		case 1:
			cout << "\nDigite os numeros que deseja inserir separados por espaco/enter." << endl;
			cout << "Digite -1 para parar a insercao:\n> ";

			// Laço contínuo até o usuário digitar o valor de parada (-1)
			while (cin >> valor && valor != -1) {
				if (busca_arvore_bin(raiz, valor) != NULL) {
					cout << "  [!] O valor " << valor << " ja existe e foi ignorado." << endl;
				}
				else {
					insere_arvore_bin(&raiz, valor);
					cout << "  [+] Valor " << valor << " inserido!" << endl;
				}
			}
			break;

		case 2:
			cout << "Digite o valor para buscar: ";
			cin >> valor;
			if (busca_arvore_bin(raiz, valor) != NULL) {
				cout << "-> SUCESSO: Valor " << valor << " encontrado na arvore!" << endl;
			}
			else {
				cout << "-> NAO ENCONTRADO: Valor " << valor << " nao existe na arvore." << endl;
			}
			break;

		case 3:
			cout << "Digite o valor para remover: ";
			cin >> valor;
			if (busca_arvore_bin(raiz, valor) == NULL) {
				cout << "-> NAO ENCONTRADO: Nao e possivel remover pois " << valor << " nao esta na arvore." << endl;
			}
			else {
				remove_arvore_bin(&raiz, valor);
				cout << "-> Valor " << valor << " removido com sucesso!" << endl;
			}
			break;

		case 4:
			percorre_arvore_bin_em_nivel(raiz);
			break;

		case 0:
			cout << "\nEncerrando o programa..." << endl;
			break;

		default:
			cout << "\n[!] Opcao invalida! Tente novamente." << endl;
			break;
		}

	} while (opcao != 0);

	return 0;
}