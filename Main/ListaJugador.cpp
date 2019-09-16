/*#include "ListaJugador.h"

ListaJugador::ListaJugador() {
	this->cantMax = 100;
	this->cantActual = 1;
	this->vectorJugadores = new Jugador[cantMax];
	this->vectorJugadores[0] = Jugador("NULL", "-9999", -9999);

}

bool ListaJugador::agregarJugador(Jugador& jg) {
	if (cantActual < cantMax) {
		vectorJugadores[cantActual] = jg;
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

}*///da error

