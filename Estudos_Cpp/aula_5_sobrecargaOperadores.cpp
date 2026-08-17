//A sobrecarga de operadores em C++ permite redefinir o comportamento de símbolos 
//nativos(como + , -, == ) para classes personalizadas.Em vez de usar chamadas longas como 
//obj1.soma(obj2), você pode usar uma escrita natural como obj1 + obj2

//Para sobrecarregar um operador, você define uma função membro ou uma função amiga com a 
// palavra-chave operator seguida pelo operador que deseja sobrecarregar.

//Ex: Classe ponto, não sabemos como somar dois pontos, mas podemos definir o operador +
// para somar as coordenadas x e y de dois pontos.
#include <iostream>
using namespace std;

class Ponto {
public:
    int x;
    int y;

	Ponto operator+(const Ponto& outro) const { //cria um referencia constante para o outro ponto e 
        Ponto resultado;                         //marca o método como const, 
        resultado.x = x + outro.x;               //indicando que não modifica o objeto atual
        resultado.y = y + outro.y;

        return resultado;
    }
};
class Ponto_semConst {
public:
    int x;
    int y;

    Ponto operator+(Ponto outro) {          //é criada um copia do segundo ponto
        Ponto resultado;

        resultado.x = x + outro.x;
        resultado.y = y + outro.y;

        return resultado;
    }
};

class Ponto_friend {
    double x;
    double y;

public:
	Ponto_friend(double x = 0, double y = 0) : x(x), y(y) {}
    friend Ponto_friend operator+(const Ponto_friend& a, const Ponto_friend& b);
    
    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

Ponto_friend operator+(const Ponto_friend& a, const Ponto_friend& b) {
    Ponto_friend resultado;
    resultado.x = a.x + b.x;
    resultado.y = a.y + b.y;
    return resultado;
}



int main() {
	Ponto p1{ 1, 2 }; //aggregate initialization, só pra membros publicos
    Ponto p2{3, 4};
    Ponto p3 = p1 + p2; // usa o operador + sobrecarregado
    cout << "Ponto resultante: (" << p3.x << ", " << p3.y << ")" << endl;

	Ponto_friend pf1(2, 7);
    Ponto_friend pf2(3, 4);
    Ponto_friend pf3 = pf1 + pf2;
    pf3.display();

	return 0;
    
}