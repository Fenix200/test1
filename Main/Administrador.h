#pragma once
#include <string>

using namespace std;
class Administrador
{
public:
	Administrador();
	Administrador(string rut, string password);
	string& getRutAdmin();
	string& getPassAdmin();

private:
	string rut;
	string pass;

};