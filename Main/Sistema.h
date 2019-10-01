#pragma once
#include <string>
#include <iostream>
#include "ListaJugador.h"
#include "ListaCartas.h"
#include <conio.h>
#include <chrono>
#include <thread>
#include "ListaAdministradores.h"
#include<stdlib.h>
#include<fstream>


using namespace std;
class Sistema
{

public:
	Sistema();
	void setUltimaIdPersona(int id);
	void ejecutarSistema();
	void printCarta(Jugador* jug);

private:

	void printMenus(float imprimirMenuNumero);
	int verificadorIngreso(int max);
	int verificadorIngreso(int min,int max);
	
	int idActualPersona;//retorna la id actual
	void iniciarPartida(int opcion);
	ListaJugador* listaJugadores;
	int jugadoresJugando;//indica cantidad de jugadores jugando en meza
	Jugador** jugadoresMesa_ptr;//almacena direccion hacia los jugadores
	Jugador* crupier;
	ListaCartas* listaCartas;
	void isCartas();//revisa si hay cartas suficientes para jugar si nos las hay revuelve el mazo
	void repartirA(Jugador* jugador_ptr);//reparte una carta de la lista de cartas a la direccion de jugador ingresado
	void jugar();
	void jugadoresOnfire();
	void configuracion(int opcion);
	ListaAdministradores* listaAdministradores;

	bool leerArchivos();
	bool leerAdmin(string nombreArchivo);
	bool leerJugadores(string nombreArchivo);
	
	
};