
#ifndef _POINT
#define _POINT

struct ponto {
	float x;
	float y;
};

void captura(ponto& p);
void imprime(ponto p);
float distancia(ponto& p1, ponto& p2);

struct circulo {
	ponto c;
	float raio;
};

void captura_raio(circulo& c);
bool interior(circulo* c, ponto* p);

#endif 