#include "Sistema.h"

Sistema::Sistema()
{
//nada aun
}
void Sistema::setUltimaIdPersona(int id)
{
	
	id++;
	this->idActualPersona = id;

	
}
//metodo para ejecutar sistema
void Sistema::ejecutarSistema()
{
	int ingreso_0 = -1;

	//En el taller no indica que exista una opcion salir asi que while true
	while (true) {
		printMenus(0);
		ingreso_0 = verificadorIngreso(3);
		switch (ingreso_0)
		{
		case 1: {

			printMenus(1);
			int ingreso_1 = verificadorIngreso(4);
			//aca ira Jugar0	

			break;

		}
		case 2: {
			//Aca ira onFire0

			break;
		}
		case 3: {

			printMenus(3);
			int ingreso_3 = verificadorIngreso(4);
			//aca ira Registrar0
			break;
		}
		default:
			break;
		}
	}
}


//recibe un float que corresponde a un menu especifico y lo imprime
void Sistema::printMenus(float imprimir)
{	//menu principal
	if (imprimir == 0) {
		system("cls");
		cout << "Bienvenido Al Black Jack UCn!" << endl;
		cout << "------------------------------\n" << endl;
		cout << "Ingrese alguna opcion\n" << endl;
		cout << "[1] Iniciar partida" << endl;
		cout << "[2] Jugadores On-fire" << endl;
		cout << "[3] Configuración" << endl;

	}

	if (imprimir == 1) {
		system("cls");
		cout << "Ingrese alguna opcion\n" << endl;
		cout << "[1] Jugar" << endl;
		cout << "[2] Agregar Jugador" << endl;
		cout << "[3] Eliminar Jugador" << endl;
		cout << "[4] Terminar Partida" << endl;
		return;
	}
	if (imprimir == 2) {
		return;
	}
	if (imprimir == 3) {
		system("cls");
		cout << "Ingrese alguna opcion\n" << endl;
		cout << "[1] Cargar Saldo a la billetera electrónica" << endl;
		cout << "[2] Consultar Saldo" << endl;
		cout << "[3] Registrar Jugador" << endl;
		cout << "[4] Editar Jugador" << endl;
		return;
	}

}
//pregunta hasta que se ingrese un valor valido
int Sistema::verificadorIngreso(int max)
{
	while (true) {
		int opcion;

		cin >> opcion;
		if (!cin) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Opcion no valida ingresa Numero!" << endl;
		}
		else if (opcion <= max && opcion >= 1) {
			return opcion;
		}
		else {
			cout << "Opcion no valida" << endl;
		}
	}
}

