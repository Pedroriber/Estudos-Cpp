#include<stdio.h>
#include<stdlib.h>

struct nodo {
	int chave;
	struct nodo* esq;
	struct nodo* dir;
};
typedef struct nodo Nodo;

Nodo* cria_no(int num) {
	Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
	novo->chave = num;
	novo->esq = NULL;
	novo->dir = NULL;
	return novo;
}

Nodo* insere_arvore_bin(Nodo** raiz, int num) {
	if (*raiz == NULL) {
		*raiz = cria_no(num);
	}
	else if (num < (*raiz)->chave) {
		insere_arvore_bin(&(*raiz)->esq, num);
	}
	else if (num > (*raiz)->chave) {
		insere_arvore_bin(&(*raiz)->dir, num);
	}
	return *raiz;
}

void percorre_arvore_bin_em_nivel(Nodo* raiz) {
	if (raiz == NULL) {
		printf("Arvore vazia!\n");
		return;
	}

	Nodo** fila = (Nodo**)malloc(1000 * sizeof(Nodo*));
	int inicio = 0, fim = 0;

	fila[fim++] = raiz;
	printf("Nos da arvore por nivel:\n");

	while (inicio < fim) {
		// 1. Pega o primeiro elemento da fila
		Nodo* atual = fila[inicio++];

		// 2. Imprime o valor do nó
		printf("%d ", atual->chave);

		// 3. Coloca os filhos existentes na fila para serem visitados depois
		if (atual->esq != NULL) {
			fila[fim++] = atual->esq;
		}
		if (atual->dir != NULL) {
			fila[fim++] = atual->dir;
		}
	}
	printf("\n");
	free(fila);
}
int main() {
	FILE* arquivo = fopen("dados.txt", "r");

	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo!\n");
		return 1;
	}

	// Opção 1: Ler linha por linha
	char linha[256];
	while (fgets(linha, sizeof(linha), arquivo) != NULL) {
		printf("%s", linha);
	}

	// Opção 2: Ler caractere por caractere
	// int c;
	// while ((c = fgetc(arquivo)) != EOF) {
	//     printf("%c", c);
	// }

	// Opção 3: Ler palavra por palavra
	// char palavra[50];
	// while (fscanf(arquivo, "%s", palavra) == 1) {
	//     printf("%s\n", palavra);
	// }

	fclose(arquivo);

	return 0;
}