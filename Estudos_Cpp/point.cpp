
#include<iostream>
#include"point.h"
using namespace std;

void captura(ponto& p) {
	cout << "Digite as coordenadas do ponto (x y): ";
	cin >> p.x >> p.y;
}
void imprime(ponto p) {
	cout << "Ponto: (" << p.x << ", " << p.y << ")" << endl;
}

float distancia(ponto& p1, ponto& p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool interior(circulo* c, ponto* p) {
	return distancia(c->c, *p) < c->raio;
}
void captura_raio(circulo& c) {
	cout << "Digite as coordenadas do centro do círculo (x y): ";
	cin >> c.c.x >> c.c.y;
	cout << "Digite o raio do círculo: ";
	cin >> c.raio;

}