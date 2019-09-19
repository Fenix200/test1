#include <iostream>
#include "ClasePrueba.h"
#include "Jugador.h"
#include "ListaCartas.h"
#include <string>
#include "Sistema.h"

using namespace std;
int main()
//este es el main by Michel
{
	/*
	ClasePrueba* prueba = new ClasePrueba(89);
	//añadi comentario
	//añadi otro comentario 
	std:: cout << prueba->getDato()<<endl;
	/*
	jug->addVictoria();
	cout << jug->getVictorias()<<endl;
	int* victorias = &(jug->getVictorias());
	*victorias = 5;
	cout << jug->getVictorias();*/
	/*
	ListaCartas* cartas = new ListaCartas();
	for (int i = 0; i < 80; i++) {
		if (i % 50 == 0) {
			system("cls");
		}
		cout << cartas->getCarta() << endl;
		cout << "cartas restantes : " << cartas->getCartasRestantes() << endl;
	}*/
	
	ListaJugador* lJ = new ListaJugador();
	lJ->agregarJugador("Juan", "19467", 0);
	lJ->agregarJugador("Juan2", "194673", 1);
	
	Jugador** jug = new Jugador*[3];

	jug[0] = &(lJ->getJugador("19467"));

	cout << jug[0]->getRut();

	Sistema* sis = new Sistema();
	string Cs[2] = { "A","10" };
	int cantidad = 2;
	string C = "**";



	cout << "hola\n" << endl;

	Jugador* juga = new Jugador("Juan", "19467", 0);
	string carta1 = "A";
	string carta2 = "10";
	string carta3 = "K";
	juga->ingresarCarta(carta1);
	juga->ingresarCarta(carta2);
	juga->ingresarCarta(carta3);

	sis->printCarta2(juga);
}
