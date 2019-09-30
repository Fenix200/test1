#include "ListaJugador.h"


ListaJugador::ListaJugador() {
	this->cantMax = 100;
	this->cantActual = 1;
	this->vectorJugadores = new Jugador[cantMax];
	this->vectorJugadores[0] = Jugador("CRUPIER", "-9999", -9999);

}
//añade un nuevo jugador
bool ListaJugador::agregarJugador(string nombre, string rut, int id) {

	Jugador* jg = new Jugador(nombre, rut, id);
	if (cantActual < cantMax) {
		vectorJugadores[cantActual] = *jg;
		cantActual++;
		return true;
	}
	else {
		return false;
	}
}

bool ListaJugador::agregarJugador(string nombre, string rut, int id, int monto, int victorias)
{

	//asi evitamos conflicto al inscribir rut o id
	for (int i = 0; i < cantActual; i++) {
		if (vectorJugadores[i].getId() == id) {
			return false;
		}
		if (vectorJugadores[i].getRut().compare(rut) == 0) {
			return false;
		}
	}
	Jugador* jg = new Jugador(nombre, rut, id,monto,victorias);

	if (cantActual < cantMax) {
		vectorJugadores[cantActual] = *jg;
		cantActual++;
		return true;
	}
	else {
		return false;
	}
}

Jugador& ListaJugador::getJugador(string rut) {

	for (int i = 0; i < cantActual; i++) {
		if (vectorJugadores[i].getRut().compare(rut) == 0) {
			return vectorJugadores[i];
			break;
		}
	}
	return vectorJugadores[0];

}
//retorna por posicion recordar que posicion 1 es el crupier
Jugador& ListaJugador::getJugador(int posicion)
{
	return vectorJugadores[posicion];
}
//metodo que retorna la posicion de un jugador dado un rut sino lo encuentra retorna -1
int ListaJugador::buscarJugador(string rut)
{
	for (int i = 0; i < cantActual; i++) {
		if (rut.compare(vectorJugadores[i].getRut()) == 0) {
			return i;
		}
	}

	return -1;
}

int& ListaJugador::getCantActual()
{
	return cantActual;
}

void ListaJugador::quitarCartasJugadores()
{
	for (int i = 0; i < cantActual; i++) {
		vectorJugadores[i].vaciarCartas();
	}
}
// metodo para ordenar lita de vectores de mayor a menor (no altera las direcciones(ni las crea) de memoria solo modifica lo que contienen)
void ListaJugador::ordenarMayoraMenorJugadores()
{
	for (int a = 0; a < (cantActual-1); a++) {
		for (int b = a + 1; b < cantActual; b++) {
			if ((vectorJugadores[a].getVictorias()) < (vectorJugadores[b].getVictorias())) {
				Jugador aux = vectorJugadores[a];
				vectorJugadores[a] = vectorJugadores[b];
				vectorJugadores[b] = aux;
			}
		}
	}
}
