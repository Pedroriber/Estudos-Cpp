/*
TEMPLATES - Programação genérica
considere a função abaixo:

int   min(int   a, int   b)
{
  return (b < a) ? b : a;
}

Como fazer ela funcionar para outros tipos de dados, como float, double, char, etc.?
A forma mais simples é criar uma função para cada tipo de dado, mas isso não é eficiente e não é escalável.
E fazer double/float min () abrange todos os numeros, mas força conversões desnecessarias

A forma mais elegante é usar templates, que permitem criar funções e classes genéricas que podem 
trabalhar com qualquer tipo de dado.
*/

template <typename T>
T min(T a, T b) {
	return (b < a) ? b : a;
}

int main() {
	int a = min<int>(1, 2); //<int> é má prática, pois poderia ser deduzido pelo programa.
	int b = min(1, 2);
}

//para compilar, a função deve estar visivel no arquivo que ela é usada
//então templates não podem ser definidos em arquivos de abstração .h/.cpp

//TEMPLATE DE CLASSE

const unsigned int STK_MAX = 50;

template<typename U>   
class Stack {
    friend class StackIterator;
public:
    Stack() {
        elems = new U[STK_MAX];
        reset();
    }
    Stack(int n) {
        elems = new U[n]
            reset();
    }
    ~Stack() {
        delete[] elems;
    }
private:
    int  top;
    U* elems;

public:
    void push(U val) {
        elems[top++] = val;
    }

    U pop() { return elems[--top]; }

    void reset() { top = 0; }

    bool empty() const {
        return top == 0;
    }
};


//O STK_MAX pode entrar no template tbm
//template<typename U, unsigned int MAX>
/*
int main()
{
  Stack<float, 10> pilha1;
  Stack<int  , 50> pilha2(100);
}

agora é obrigatorio informar o tamanho da pilha.
Mas é possível definir um valoe default:
template<typename U, unsigned int MAX = 50>

}

*/