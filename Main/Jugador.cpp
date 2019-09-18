#include "Jugador.h"

Jugador::Jugador(string nombre, string rut, int id)
{
	this->nombre = nombre;
	this->rut = rut;
	this->id = id;
	this->victorias = 0;
	this->saldo = 0;
	cantMaxcartas = 21;
	cantActualcartas = 0;
	this->vecCartas_ptr = new std::string* [cantMaxcartas];


}
Jugador::Jugador()
{
}


std::string& Jugador::getNombre()
{
	return this->nombre;
}

string& Jugador::getRut()
{
	return this->rut;
}

double& Jugador::getSaldo()
{
	return this->saldo;
}

int& Jugador::getCantidadCartasActuales()
{
	return this->cantActualcartas;
}

int& Jugador::getId()
{
	return this->id;
}

int& Jugador::getVictorias()
{
	return this->victorias;
}

void Jugador::setNombre(string nombreNuevo)
{
	this->nombre = nombreNuevo;
}

void Jugador::setSaldo(double saldoNuevo)
{
	this->saldo = saldoNuevo;
}
//Este metodo suma 1 a la victoria de este jugador
void Jugador::addVictoria()
{
	this->victorias++;
}

void Jugador::ingresarCarta(string& valorCarta)
{

	vecCartas_ptr[cantActualcartas] = &valorCarta;
	cantActualcartas++;

}

void Jugador::vaciarCartas()
{
	
	this->cantActualcartas = 0;
}

//Metodo que suma las cartas del jugador tomando en cuenta que valor del A a conveniencia
int Jugador::suma(){
	int suma = 0;
	for (int i =0; i <cantActualcartas; i++){
		if (((*vecCartas_ptr[i]).compare("A")!=0) and ((*vecCartas_ptr[i]).compare("J")!=0) 
			and ((*vecCartas_ptr[i]).compare("Q")!=0) and ((*vecCartas_ptr[i]).compare("K")!=0))
		{
			
			suma += stoi(*vecCartas_ptr[i]);
        }
		else
		{
			if ((*vecCartas_ptr[i]).compare("A") != 0) 
			{
				suma += 10;
			}
			else
			{
				if((suma+11)<=21){
					suma += 11;
				}
				else if((suma+1)<=21){
					suma += 1;
				}
				else{
					return -1;
				}
				

			}//cierre 2 else
	

		
		}//cierre else	
	}//for

	if (suma <= 21) {
		return suma;
	}

	return -1;
}//metodo

