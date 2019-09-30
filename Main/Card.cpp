#include "Card.h"

Card::Card()
{
	//nada aqui
}

Card::Card(std::string numero, std::string pinta)
{
	this->numero = numero;
	this->pinta = pinta;
}



std::string& Card::getNumero()
{
	return this->numero;
}

std::string& Card::getPinta()
{
	return pinta;
}
