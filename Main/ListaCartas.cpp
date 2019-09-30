#include "ListaCartas.h"

//Este construtor llena los mazos de cartas
ListaCartas::ListaCartas()
{

	int cartas = 0;//solo sirve para ir contando las cartas llenadas y llenar el vector de posiciones
	int mazos = 2;//aca se puede establecer la cantidad de mazos con los que se jugara
	cantMax = 52*mazos;//establece que habran 104 cartas 52*2 = 104
	posCartas = new int[cantMax];
	this->cartasFijas = new Card[cantMax];
	
	//cantidad de mazos
	for (int a = 0; a < mazos; a++) {
		//4 pintas
		for (int b = 0; b < 4; b++) {
			string pinta = "";
			//corazon
			if (b == 0) {
				pinta = "Corazones";
			}
			//diamante
			else if (b == 1) {
				pinta = " Diamante";
			}
			//trebol
			else if (b == 2) {
				pinta = "  Trebol ";
			}
			//Pica
			else {
				pinta = "   Pica  ";

			}
			//13 Cartas
			for (int p = 0; p < 13; p++) {
				
				//AS
				if (p == 0) {

					Card* carta = new Card("A", pinta);	
					cartasFijas[cartas] = *carta;
					posCartas[cartas] = cartas;
					cartas++;
				}
				//J
				else if (p == 10) {
					Card* carta = new Card("J", pinta);
					cartasFijas[cartas] = *carta;
					posCartas[cartas] = cartas;
					cartas++;
				}
				//Q
				else if (p == 11) {
					Card* carta = new Card("Q", pinta);
					cartasFijas[cartas] = *carta;
					posCartas[cartas] = cartas;
					cartas++;
				}
				//K
				else if (p == 12) {
					Card* carta = new Card("K", pinta);
					cartasFijas[cartas] = *carta;
					posCartas[cartas] = cartas;
					cartas++;
				}
				//2,3,4,5,6,7,8,9,10
				else {
					Card* carta = new Card(std::to_string((p + 1)), pinta);
					cartasFijas[cartas] = *carta;
					posCartas[cartas] = cartas;
					cartas++;
				}


			}

		}
	}

	//se le resta 1 ya que la variable cartas restantes se utiliza para ir buscando cartas
	//y el vector cartas va desde 0 a 103(104-1 =103)
	this->cartasRestantes = cartas-1;
	resetearSemilla();

}


//Proporciona una carta aleatoria y luego la "Elimina"
string& ListaCartas::getCarta()
{

	//reseteare la semilla aleatoria cada 20 cartas repartidas
	if (cartasRestantes % 20 == 0) {
		resetearSemilla();
	}
		
	//primero busco un numero aleatorio entre 0 y la cant actual de cartas
	int num = rand() % cartasRestantes;
	//obtengo una posicion aleatoria de las restantes en el posCartas
	int posAleatoria = posCartas[num];
	//obtengo el valor de la carta correspondiente a esa posicion
	int posFinal = posAleatoria;
	
	//Descarto la posicion que salio intercambiandola con la ultima actual y le resto -1 a la cantidad actual
	posCartas[posAleatoria] = posCartas[cartasRestantes];
	cartasRestantes--;
	return cartasFijas[posFinal].getNumero();//retorna el valor de la carta por referencia (&)
}

int& ListaCartas::getCartasRestantes()
{
	return this->cartasRestantes;
}
//este metodo recarga el mazo (por si quedan pocas cartas restantes)
void ListaCartas::recargarMazo()
{
	for (int i = 0; i < cantMax; i++) {
		posCartas[i] = i;
	}
	cartasRestantes = cantMax-1;
}
int& ListaCartas::getCartasTotales()
{
	return cantMax;
}
//La funcion rand() de cstdlib funciona con una "semilla" para generar valores aleatorios este metodo la actualizara
void ListaCartas::resetearSemilla()
{
	srand(time(NULL));
}
