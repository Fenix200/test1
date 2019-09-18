#pragma once
#include "Jugador.h"

#include <string>
using namespace std;

class ListaJugador
{

public:
	ListaJugador();
	bool agregarJugador(Jugador&);
	Jugador& getJugador(string rut);


private:

	Jugador* vectorJugadores;
	int cantActual;
	int cantMax;
	int idGlobal;
};
