#include "Sistema.h"

Sistema::Sistema()
{
	listaJugadores = new ListaJugador();
	jugadoresJugando = 0;
	jugadoresMesa_ptr = new Jugador*[6];
	//Crupier es un "jugador" en este caso la posicion 0 de la lista jugador
	crupier = &(listaJugadores->getJugador("-9999"));
	listaCartas = new ListaCartas();

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

			jugadoresJugando = 0;
			//cuando jugadores jugando sea -1 es por que termino partida

			//while(jugadoresJugando!=-1){
			printMenus(1);
			int ingreso_1 = verificadorIngreso(4);
			//aca ira iniciarPartida	
			//}

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

void Sistema::iniciarPartida(int opcion)
{
	switch (opcion)
	{
	case 1: {
		if (jugadoresJugando == 0) {
			cout << "Mesa Vacia" << endl;
			break;
		}
		isCartas();

		break;

	}
	//agregar jugador
	case 2:
	{
		system("cls");
		if (jugadoresJugando > 6) {
			cout << "Mesa LLena" << endl;
			break;
		}
		
		string rut = "";
		string id = "";
		string nombre = "";

		cout << "Ingrese RUT : " << endl;
		getline(cin, rut);
		cout << "Ingrese ID : " << endl;
		getline(cin, id);
		cout << "Ingrese NOMBRE : " << endl;
		getline(cin, nombre);
		if(listaJugadores->buscarJugador(rut) != -1){
			bool existeNombre = listaJugadores->getJugador(rut).getNombre().compare(nombre) == 0;
			bool existeId = to_string(listaJugadores->getJugador(rut).getId()).compare(id) == 0;
			bool existeSaldo = listaJugadores->getJugador(rut).getSaldo() > 5000;
			if (!existeId || !existeNombre || !existeSaldo) {
				system("cls");
				cout << "Jugador No puede Ser Agregado... Revise Saldo" << endl;
				break;
			}
			//almaceno la direccion de jugador
			jugadoresMesa_ptr[jugadoresJugando] = &(listaJugadores->getJugador(rut));
			jugadoresJugando++;
			break;

		}
		else {
			cout <<  "\nRut No encontrado..." << endl;
		}

		break;
	}
	//eliminar Jugador
	case 3:
	{
		system("cls");
		if (jugadoresJugando == 0) {
			cout << "Nadie para eliminar D:" << endl;
			break;
		}
		else if (jugadoresJugando == 1) {
			cout << "La mesa no se puede quedar sin nadie Termine partida" << endl;
			break;
		}
		string rut = "";
		cout << "Ingrese RUT : " << endl;
		getline(cin, rut);
		//Buscar Jugador en meza
		int pos = -1;
		for (int i = 0; i < jugadoresJugando; i++) {
			if ((jugadoresMesa_ptr[i]->getRut().compare(rut) == 0)) {
				pos = i;
			}
		}
		if (pos == -1) {
			cout << "Nadie para eliminar D:" << endl;
			break;
		}
		//ahora si se encontro un jugador en mesa
		jugadoresMesa_ptr[pos] = jugadoresMesa_ptr[jugadoresJugando];
		jugadoresJugando--;

		break;
	}
	case 4:
	{
		jugadoresJugando = -1;
		break;
	}

	default:
		break;
	}


}

void Sistema::isCartas()
{
	
	int cartas = (listaCartas->getCartasTotales())*(15/26);
	int cartasRestantes = listaCartas->getCartasRestantes();
	if (cartasRestantes <= cartas) {
		system("cls");
		cout << "Se revolvio el Mazo :D" << endl;
		listaCartas->recargarMazo();
	}

}

void Sistema::printCarta(string carta)
{
	string C = carta;
	if (C.compare("10") != 0) {
		cout << "\n _________\n|" << C << "        |\n|         |\n|         |\n|   UCN   |\n|         |\n|         |\n|________" << C << "|";
	}
	else {
		cout << "\n _________\n|" << C << "       |\n|         |\n|         |\n|   UCN   |\n|         |\n|         |\n|_______" << C << "|";
	}
}

