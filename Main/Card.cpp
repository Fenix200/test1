#include "Card.h"

Card::Card()
{
	//nada aqui
}

Card::Card(std::string numero)
{
	this->numero = numero;
}


std::string& Card::getNumero()
{
	return this->numero;
}
