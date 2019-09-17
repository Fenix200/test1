
#include "ListaAdministradores.h"
using namespace std;




ListaAdministradores::ListaAdministradores() {
	this->cantMax = 100;
	this->cantActual = 0;
	this->vectorAdministradores = new Administrador[cantMax];
	 
	

}

bool ListaAdministradores::agregarAdministrador(Administrador& adm) {
	if (cantActual < cantMax) {
		vectorAdministradores[cantActual] = adm;
		cantActual++;
		return true;
	}
	else {
		return false;
	}
}

bool ListaAdministradores::buscarAdministrador(string rut, string clave) {
	for (int i = 0; i < cantActual; i++) {
		if ((vectorAdministradores[i].getRutAdmin().compare(rut) == 0) and (vectorAdministradores[i].getPassAdmin().compare(clave) == 0)) {
			return true;
		}

	}
	return false;
}



