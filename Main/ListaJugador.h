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
	Jugador& getJugador(int posicion);
	int buscarJugador(string rut);
	int& getCantActual();
	void quitarCartasJugadores();//les quita las cartas a los jugadores
	void ordenarMayoraMenorJugadores();


private:

	Jugador* vectorJugadores;
	int cantActual;
	int cantMax;
	int idGlobal;
};
