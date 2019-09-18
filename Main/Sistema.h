#pragma once
#include <string>
#include <iostream>

using namespace std;
class Sistema
{

public:
	Sistema();
	void setUltimaIdPersona(int id);
	void ejecutarSistema();


private:

	void printMenus(float imprimirMenuNumero);
	int verificadorIngreso(int max);
	int idActualPersona;
};