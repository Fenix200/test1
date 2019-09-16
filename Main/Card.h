#pragma once
#include <string>
class Card
{
public:
	Card();
	Card(std::string numero);
	std::string& getNumero();

private:
	std::string numero;

};

