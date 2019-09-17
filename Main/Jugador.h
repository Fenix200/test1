#pragma once
#include <string>


using namespace std;
class Jugador
{
public:
	Jugador(string nombre, string rut, int id);
	Jugador();
	string& getNombre();
	string& getRut();
	double& getSaldo();
	int& getId();
	int& getVictorias();
	void setNombre(string nombreNuevo);
	void setSaldo(double saldo);
	void addVictoria();


private:
	string rut;
	string nombre;
	double saldo;
	int id;
	int victorias;


};

