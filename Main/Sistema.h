#pragma once
#include <string>
#include <iostream>
#include "ListaJugador.h"
#include "ListaCartas.h"

using namespace std;
class Sistema
{

public:
	Sistema();
	void setUltimaIdPersona(int id);
	void ejecutarSistema();
	void printCarta(string carta);
	void printCarta2(Jugador* jug);

private:

	void printMenus(float imprimirMenuNumero);
	int verificadorIngreso(int max);
	int idActualPersona;
	void iniciarPartida(int opcion);
	ListaJugador* listaJugadores;
	int jugadoresJugando;//indica cantidad de jugadores jugando en meza
	Jugador** jugadoresMesa_ptr;//almacena direccion hacia los jugadores
	Jugador* crupier;
	ListaCartas* listaCartas;
	void isCartas();//revisa si hay cartas suficientes para jugar si nos las hay revuelve el mazo
	
};