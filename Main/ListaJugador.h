#pragma once
#include "Jugador.h"

#include <string>
using namespace std;

class ListaJugador
{

public:
	ListaJugador();
	bool agregarJugador(string nombre, string rut, int id);
	Jugador& getJugador(string rut);
	int buscarJugador(string rut);


private:

	Jugador* vectorJugadores;
	int cantActual;
	int cantMax;
	int idGlobal;
};
