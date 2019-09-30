#pragma once
#include <string>
class Card
{
public:
	Card();
	Card(std::string numero, std::string pinta);
	std::string& getNumero();
	std::string& getPinta();

private:
	std::string numero;
	std::string pinta;

};

