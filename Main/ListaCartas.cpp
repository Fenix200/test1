#include "ListaCartas.h"

//Este construtor llena los mazos de cartas
ListaCartas::ListaCartas()
{
	int cartas = 0;//solo sirve para ir contando las cartas llenadas y llenar el vector de posiciones
	int mazos = 2;
	cantMax = 52*mazos;//establece que habran 104 cartas 52*2 = 104
	posCartas = new int[cantMax];
	this->cartasFijas = new Card[cantMax];

	//llenado de numeros 2 a 10 (9 cartas * 4 pintas * 2 mazos =72)
	for (int a = 0; a < 4*mazos; a++) {
		for (int i = 2; i < 11; i++)
		{
			Card* carta = new Card(std::to_string(i));
			cartasFijas[cartas] = *carta;
			posCartas[cartas] = cartas;
			cartas++;
		}
	}
	//llenando Ases 4 ases x 2 mazos = 8
	for (int i = 0; i < 4*mazos; i++) {
		Card* carta = new Card("A");
		cartasFijas[cartas] = *carta;
		posCartas[cartas] = cartas;
		cartas++;
	}
	//llenando J Q y K
	for (int i = 0; i < 4 * mazos; i++) {
		Card* carta = new Card("J");
		cartasFijas[cartas] = *carta;
		posCartas[cartas] = cartas;
		cartas++;
	}
	for (int i = 0; i < 4 * mazos; i++) {
		Card* carta = new Card("Q");
		cartasFijas[cartas] = *carta;
		posCartas[cartas] = cartas;
		cartas++;
	}
	for (int i = 0; i < 4 * mazos; i++) {
		Card* carta = new Card("K");
		cartasFijas[cartas] = *carta;
		posCartas[cartas] = cartas;
		cartas++;
	}

	this->cartasRestantes = cartas;
	resetearSemilla();
}
//Proporciona una carta aleatoria y luego la "Elimina"
string ListaCartas::getCarta()
{
	//resulta que si pedias cartas muy rapido se bugeaba asi que dare una pausa de 250 milisegundos cada vez que se pida una carta
	std::chrono::duration<int, std::milli> timespan(250);
	std::this_thread::sleep_for(timespan);

	//reseteare la semilla aleatoria cada 20 cartas repartidas
	if (cartasRestantes % 20 == 0) {
		resetearSemilla();
	}

	//primero busco un numero aleatorio entre 0 y la cant actual de cartas
	int num = rand() % cartasRestantes;
	//obtengo una posicion aleatoria de las restantes en el posCartas
	int posAleatoria = posCartas[num];
	//obtengo el valor de la carta correspondiente a esa posicion
	string carta = cartasFijas[posAleatoria].getNumero();
	
	//Descarto la posicion que salio intercambiandola con la ultima actual y le resto -1 a la cantidad actual
	posCartas[posAleatoria] = posCartas[cartasRestantes];
	cartasRestantes--;
	return carta;
}

int& ListaCartas::getCartasRestantes()
{
	return this->cartasRestantes;
}
//La funcion rand() de cstdlib funciona con una "semilla" para generar valores aleatorios este metodo la actualizara
void ListaCartas::resetearSemilla()
{
	srand(time(NULL));
}
