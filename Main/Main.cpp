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

	Jugador* jug = new Jugador("Juan", "19467",0);
	Jugador* jug2 = new Jugador("Juan2", "19467",1);

	string carta1 = "K";
	string carta2 = "A";
	string carta3 = "7";
	jug->ingresarCarta(carta2);
	jug->ingresarCarta(carta2);
	jug->ingresarCarta(carta2);
	jug->ingresarCarta(carta3);
	jug->ingresarCarta(carta2);
	jug->ingresarCarta(carta1);
	cout << jug->suma() << endl;
	Sistema* sis = new Sistema();

	cout << jug->getId();
	cout << jug2->getId();


}
