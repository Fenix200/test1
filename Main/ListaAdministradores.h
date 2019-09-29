
#pragma once
#include "Administrador.h"
#include <string>
using namespace std;


class ListaAdministradores
{
public:
	ListaAdministradores();
	bool agregarAdministrador(string rut, string clave);
	bool buscarAdministrador(string rut, string clave);

private:

	Administrador* vectorAdministradores;
	int cantActual;
	int cantMax;




};

