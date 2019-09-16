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
	string getCarta();
	int& getCartasRestantes();
	void recargarMazo();

private:
	void resetearSemilla();
	Card* cartasFijas;
	int cantMax;
	int* posCartas;
	int cartasRestantes;
};
