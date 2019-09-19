#pragma once
#include <string>
#include "Card.h"
#include <cstdlib>
#include <ctime>

using namespace std;

class ListaCartas
{

public:
	ListaCartas();
	string& getCarta();
	int& getCartasRestantes();
	void recargarMazo();
	int& getCartasTotales();

private:
	void resetearSemilla();
	Card* cartasFijas;
	int cantMax;
	int* posCartas;
	int cartasRestantes;
};
