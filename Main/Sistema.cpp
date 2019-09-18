/*#include "Sistema.h"

Sistema::Sistema()
{
//nada aun
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
		case 1:
			int ingreso_1 = -1;
			while (ingreso_1 == -1) 
			{
				printMenus(1);
				ingreso_1 = verificadorIngreso(4);
				if (ingreso_1 != -1) {
					//aca ira Jugar0
				}
			}
			break;


		case 2:
			break;
		case 3:
			int ingreso_3 = -1;
			while (ingreso_3 == -1)
			{
				printMenus(3);
				ingreso_3 = verificadorIngreso(4);
				if (ingreso_3 != -1) {
					//aca ira Registrar0
				}
			}
			break;
		default:
			break;
		}
	
		getchar();

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
//retorna -1 a no ser que se ingrese una opcion entre 1 a max (1 incluido) en ese caso retorna el valor ingresado
int Sistema::verificadorIngreso(int max)
{
	int opcion = -1;
	try {
		cin >> opcion;
		if (opcion <= max && opcion >= 1) {
			return opcion;
		}
		cout << "Opcion no Valida Ingrese Numero de la lista!" << endl;
		return -1;
	}
	catch (...) {
		cout << "Opcion no Valida Ingrese Numero de la lista!" << endl;
		return -1;
	}
}

*/