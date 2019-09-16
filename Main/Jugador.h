#pragma once
#include <string>


using namespace std;
class Jugador
{
public:
	Jugador(string nombre, string rut, int id);
	Jugador();
	std::string& getNombre();
	string& getRut();
	double& getSaldo();
	int& getId();
	int& getVictorias();
	void setNombre(string nombreNuevo);
	void setSaldo(double saldo);
	void addVictoria();


private:
	std::string rut;
	std::string nombre;
	double saldo;
	int id;
	int victorias;


};

