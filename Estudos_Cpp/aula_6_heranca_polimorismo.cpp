#include<iostream>
using namespace std;

//HERANÇA
//Exemplo Caixa

class Caixa {	
public:
	int altura, largura;
	void Altura(int a) { altura = a; }  // permite declação do tio obj.Altura(a)
	void Largura(int l) { largura = l; }

};

class CaixaColorida : public Caixa {
public:
	int cor;
	void Cor(int c) { cor = c; }
};

//int main(void) {
//	CaixaColorida cc;
//	cc.Cor(5);
//	cc.Largura(3); //herdado
//	cc.Altura(5); //herdado
//}

/*Não são herdados :
- construtores
- Destrutores
- membros privados
- Operadores new;
- Operadores de atribuição;
- Relacionamentos friend;

*/
//ESPECIFICADOR PROTECTED
/*
atributos protected são visiveis pelas classes derivadas, já os private não são
*/
class A {
private:
	int a;
protected:
	int b;
public:
	int c;

};
class B : public A {
public:
	//int geta() { return a; } ERRO. a é private
	int getb() { return b; }
	int getc() { return c; }

};

//int main()
//{
//
//	A ca;
//	B cb;
//
//	//ca.a = 1; // ERRO! a não é visível (private)
//	//ca.b = 2; // ERRO! b não é visível de fora (protected)
//	ca.c = 3; // válido (c é public)
//
//	//cb.a = 4; // ERRO! a não é visível nem internamente em B
//	//cb.b = 5; // ERRO! b continua protected em B
//	cb.c = 6; // válido (c continua public em B)
//
//};

//CONSTRUTORES EM HERANÇA
//Se a classe base possui construtor com parametros, a classe derivada deve ter um contrututor tbm
//que passa um valor pro construtor da classe base ou não 
//Se uma classe base não possui um construtor sem parâmetros, a classe derivada tem que, 
// obrigatoriamente, declarar um construtor, mesmo que esse construtor seja vazio


class Base {
protected:
	int valor;
public:
	Base(int a) { valor = a; }

};
class DerivadaCerta : public Base {
public:
	int pegaValor() { return valor; }
	DerivadaCerta() : Base(0) {}
	// CERTO: mesmo que nao haja nada a fazer
	// para inicializar a classe,
	// é necessário declarar um construtor
	// para dizer com que parâmetro
	// construir a classe Base

};

//HERANÇA PUBLICA vs PRIVADA
/*
Privada: todos os atributos são herdados como privado
Publica: Os Atributos publicos e protected permanecem como na classe base
*/


//POLIMORFISMO
/*
Um ponteiro da classe pai pode apontar para um objeto da classe filha, 
mas um ponteiro da classe filha não pode apontar automaticamente para um objeto da classe pai
*/
//int main () {
//	A a, * pa; // pa pode apontar para objetos do tipo A e derivados
//	B b, * pb; // pb pode apontar para objetos do tipo B e derivados
//
//	a = b;// copia a parte A de b para a (não é conversão)
//	b = a;// erro! a pode não ter todos elementos para copia-los em b
//
//	pa = &a; // ok
//	pa = &b; // ok, pa aponta para um objeto do tipo B
//	pb = pa; // erro! pb não pode apontar para um objeto do tipo A
//	pb = &b; // ok
//	pb = &a; // erro! pb não pode apontar para objetos do tipo A
//}

class C {
public: void f() {};
};

class D : public C {
public: void g() {};

};

//void chamaf(C* c) // pode ser chamada para A e derivados
//{
//	c->f();
//}

void chamag(D* d) // pode ser chamada para B e derivados
{
	d->g();
}

//int main()
//{
//
//	C c;
//	D d;
//	chamaf(&c); // ok, a tem a função f
//	chamaf(&d); // ✅
//	chamag(&c); // erro! a não tem a função g
//				// (a não pode ser convertido para o tipo B)
//	chamaf(&d); // ok, b tem a função f
//	chamag(&d); // ok, b tem a função g
//	chamag(&c); // ❌
//
//}

//Polimorfismo: Redefinição de Métodos em uma Hierarquia
//E se definíssemos dois métodos com mesmo nome nas classes A e B ?
class E{
public: void f() {};

};

class F : public E {
public:
	void f(int a) {};			// f(int) esconde f()
	void f(const char* str) {};

};

//int main2()
//{
//
//	F f;
//	f.f(10);	// ok, função f(int) de B
//	f.f("abc");	// ok, função f(char*) de B
//	f.f();		// erro! f(int) escondeu f()
//	f.E::f();	// ok
//
//}


//E se eu não alterar os argumentos de f()
class A2 {
public:
	void f() {
		cout << "A::f()" << endl;
	}
};

class B2 : public A2 {
public:
	void f() {
		cout << "B::f()" << endl;
	}
};
void chamaf(A2* a) {
	a->f();
}

//int main() {
//	B2 b;
//	chamaf(&b); //chama qual? A::f() ou B::f()
//	//chama A::f(), pois a chamada é resolvida pelo tipo do ponteiro (A*), e não pelo tipo real do objeto (B).
//}

//METODOS VIRTUAIS coração do polimorfismo

class Animal {
public:
	virtual void falar() {
		cout << "Som de animal" << endl;
	}
};

class Cachorro : public Animal {
public:
	void falar() override {
		cout << "Au au!" << endl;
	}
};

class Gato : public Animal {
public:
	void falar() override {
		cout << "Miau!" << endl;
	}
};

void fazerFalar(Animal* animal) {
	animal->falar();
}

//Classe ABSTRATA
//nos exemplos anteriores pode não fazer sentido criar uma saida pára as classes bases

class Animal2 {
public:
	virtual void falar() = 0;  //
};
class Poligono {
public:
	virtual void lados() = 0;
};

class Triangulo : public Poligono {
	void lados() override {
		cout << "Tenho 3 lados" << endl;
	}
};
class Quadrado : public Poligono {
	void lados() override {
		cout << "tenho 4 lados" << endl;
	}
};
void lados(Poligono* a) {
	a->lados();
}
int main() {
	Cachorro cachorro;
	Gato gato;
	Animal animal;

	fazerFalar(&cachorro);
	fazerFalar(&gato);
	fazerFalar(&animal);

	Triangulo tri;
	Quadrado quad;

	lados(&tri);
	lados(&quad);
}

