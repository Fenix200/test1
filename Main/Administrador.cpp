#include "Administrador.h"


Administrador::Administrador(string rut, string password)
{
	this->rut = rut;
	this->pass = password;

}

string& Administrador::getRutAdmin()
{
	return this->rut;
}

string& Administrador::getPassAdmin()
{
	return this->pass;
}
