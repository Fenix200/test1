#include <iostream>
#include "ClasePrueba.h"
#include "Jugador.h"
#include "ListaCartas.h"

using namespace std;
int main()
{
	ClasePrueba* prueba = new ClasePrueba(89);
	//añadi comentario
	//añadi otro comentario
	std:: cout << prueba->getDato()<<endl;

	Jugador* jug = new Jugador("juan", "194670", 5);
	/*
	jug->addVictoria();
	cout << jug->getVictorias()<<endl;
	int* victorias = &(jug->getVictorias());
	*victorias = 5;
	cout << jug->getVictorias();*/
	ListaCartas* cartas = new ListaCartas();
	int num = 0;
	/*
	while (num != -1) {
		cout << cartas->getCarta()<<endl;
		cout << "cartas restantes : " << cartas->getCartasRestantes() << endl;
		cin >> num;
	}*/
}
