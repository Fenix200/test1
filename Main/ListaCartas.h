#pragma once
#include <string>
#include "Card.h"
#include <cstdlib>
#include <ctime>
#include <chrono>// librerias para dar pausas 
#include <thread>// librerias para dar pausas 

using namespace std;

class ListaCartas
{

public:
	ListaCartas();
	string getCarta();//devuelve una carta aleatoria de las restantes*/
	int& getCartasRestantes();
	void resetearSemilla();

private:

	Card* cartasFijas;
	int cantMax;
	int* posCartas;
	int cartasRestantes;
};
