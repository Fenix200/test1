#include "Jugador.h"

Jugador::Jugador(string nombre, string rut, int id)
{
	this->nombre = nombre;
	this->rut = rut;
	this->id = id;
	this->victorias = 0;
	this->saldo = 0;
}

std::string& Jugador::getNombre()
{
	return this->nombre;
}

string& Jugador::getRut()
{
	return this->rut;
}

double& Jugador::getSaldo()
{
	return this->saldo;
}

int& Jugador::getId()
{
	return this->id;
}

int& Jugador::getVictorias()
{
	return this->victorias;
}

void Jugador::setNombre(string nombreNuevo)
{
	this->nombre = nombreNuevo;
}

void Jugador::setSaldo(double saldoNuevo)
{
	this->saldo = saldoNuevo;
}
//Este metodo suma 1 a la victoria de este jugador
void Jugador::addVictoria()
{
	this->victorias++;
}
