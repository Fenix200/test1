#pragma once
#include <string>


using namespace std;
class Jugador
{
public:
	Jugador(string nombre, string rut);
	Jugador(string nombre, string rut, int id);
	Jugador();
	string& getNombre();
	string& getRut();
	double& getSaldo();
	int& getId();
	int& getVictorias();
	int& getCantidadCartasActuales();
	int suma();
	void setNombre(string nombreNuevo);
	void setSaldo(double saldo);
	void agregarSaldo(double saldoAgregado);
	void addVictoria();
	void ingresarCarta(string &valorCarta);
	void vaciarCartas();
	



private:
	string** vecCartas_ptr;
	string rut;
	string nombre;
	double saldo;
	int id;
	
	int victorias;
	int cantMaxcartas;
	int cantActualcartas;

};

