
#include<iostream>
#include"point.h"
using namespace std;
void impr(int a, int b = 0, int c = 0);
void display(int a);
void display(double a);
void display(const char* a);

//ACESSO PUBLICO E PRIVADO
struct Controle {
private:
	int valor;
	void f1() { valor = 0; }
	int f2() { return valor; }
public:
	void f3() { f1(); }
	int f4() { return f2(); }
};

//CLASSES EM C++

//classe é por default private
//struct é por default public	

class circle1 {
	double x, y;  //private
	double rad;   //private
public:
	/*void translation();
	void scale();
	double area();
	double perim();*/
};

//CLASSES FRIEND
// classe com acesso a membros privados ou publicos de outra classe
class point
{
	friend class circle; // circle é friend de point
	double x, y;

};
class circle
{

	double rad;
	point  cnt;
public:

	// …
	void setCenter(double x, double y, double raio)
	{
		cnt.x = x;	// x é private.
		cnt.y = y;	// y é private.
		rad = raio;
	}
	void print()
	{
		cout << "x = " << cnt.x << endl;		// x é private.
		cout << "y = " << cnt.y << endl;		// y é private.
		cout << "rad = " << rad << endl;
	}
};

//CONSTRUTORES E DESTRUTORES
class A {
public:
	A() { cout << "construtor" << endl; }
	~A() { cout << "destrutor" << endl; }

};

//CONSTRUTOR DE COPIA
class B {
public:
	B() {
		cout << "construtor" << endl;
	}
	int x;
	B(const B& other) {
		cout << "construtor de copia" << endl; x = other.x;
	}
	~B() {
		cout << "destrutor de B" << endl;
	}
};

//MÉTODOS CONST
//metodos que não alteram o estado do objeto

class C {
public: int value;
	  C(int v) : value(v) {}
	  int getValue() const { return value; } // método const
	  void setValue(int v) { value = v; } // método não const
};

void f(const C c) {
	cout << c.getValue() << endl; // ok
	//c.setValue(10); // erro: não é possível chamar um método não const em um objeto const
}

//PARAMETROS IMPLICITO THIS
class D {
public: int i;
	  D& inc() {
		  i++;
		  return *this;
	  } // retorna uma referência para o objeto atual
};

//THIS PARA DIFERENCIAR ATRIBUTO DE PARÂMETRO
class Pessoa {
private:
	string nome;

public:
	void setNome(string nome) {
		this->nome = nome;    //ao inves de nome = nome
	}
};

//VARIAVEL STATIC
class E {
public:
	int a;
	static int b; // variável estática compartilhada por todas as instâncias da classe

};
int E::b = 0; // inicialização da variável estática fora da classe

//METODOS STATIC
// métodos estáticos podem ser chamados sem criar uma instância da classe
//"Esse método precisa de um objeto específico para funcionar?"
class Pessoa2 {
public:
	static int quantidade;

	Pessoa2() {
		quantidade++;
	}

	static void mostrarQuantidade() {
		cout << "Pessoas criadas: "
			<< quantidade << endl;
	}
};

int Pessoa2::quantidade = 0;
int main() {
	/*display(10);
	display(3.14);
	display("Hello, World!");
	impr(10);
	impr(10, 20);
	ponto p;
	captura(p);
	imprime(p);
	circulo c;
	captura_raio(c);
	if (interior(&c, &p)) {
		std::cout << "O ponto está dentro do círculo." << std::endl;
	}
	else {
		std::cout << "O ponto está fora do círculo." << std::endl;
	}*/
	Controle c;
	//c.f1(); // Erro: f1 é privada	
	//cout << c.f2(); // Erro: f2 é privada

	c.f3(); // Ok: f1 é publica	
	cout << c.f4(); // Ok: f2 é publica


	circle circ;
	circ.setCenter(1.0, 2.0, 5);
	circ.print();

	A a1;			//contrutor de a1 é chamado
	A* a3;			// nenhum construtor é chamado

	A a2;			//construtor de a2 é chamado	
	a3 = new A;		//construtor de a3 é chamado

	delete a3;		// destrutor de a3 é chamado
	// fim da execução, destrutor de a2 e a1 são chamados na 
	//ordem inversa da criação

	B b1;			//construtor de b1 é chamado
	b1.x = 10;
	cout << "b1.x = " << b1.x << endl;

	B b2 = b1;		//construtor de copia de b2 é chamado
	cout << "b2.x = " << b2.x << endl;

	C c1(5);
	c1.setValue(10); // ok, chama o método não const setValue()
	f(c1); // ok, chama o método const getValue()

	D d1;
	d1.i = 5;
	d1.inc().inc(); // chama inc() duas vezes em sequência (permitido pelo retorno de referência)
	cout << "d1.i = " << d1.i << endl; // imprime 7

	E e1, e2;
	e1.a = 0;
	e1.b = 1;   // altera a variável estática b para 1 em e1 e e2

	cout << "e1.a = " << e1.a << ", e1.b = " << e1.b << ", e2.b = " << e2.b << endl; // imprime 0, 1

	Pessoa2::mostrarQuantidade();

	Pessoa2 p1;
	Pessoa2 p2;
	Pessoa2 p3;

	Pessoa2::mostrarQuantidade();

	return 0;

}

//PARMETROS DEFAULT

void impr(int a, int b, int c) {
	cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
}

//SOBRECARGA DE FUNÇÕES

void display(int a) {
	cout << "Display int: " << a << endl;
}
void display(double a) {
	cout << "Display double: " << a << endl;
}
void display(const char* a) {
	cout << "Display string: " << a << endl;
}





