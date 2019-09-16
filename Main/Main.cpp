#include <iostream>
#include "ClasePrueba.h"
#include "Jugador.h"

using namespace std;
int main()
{
	ClasePrueba* prueba = new ClasePrueba(89);
	//añadi comentario
	//añadi otro comentario
	std:: cout << prueba->getDato()<<endl;

	Jugador* jug = new Jugador("juan", "194670", 5);

	jug->addVictoria();
	cout << jug->getVictorias()<<endl;
	int* victorias = &(jug->getVictorias());
	*victorias = 5;
	cout << jug->getVictorias();
}
