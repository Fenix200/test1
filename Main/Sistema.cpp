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

			while(jugadoresJugando!=-1){
			printMenus(1);
			int ingreso_1 = verificadorIngreso(4);
			iniciarPartida(ingreso_1);
			}

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
		cout << "[3] Configuracion" << endl;

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
			cout << "Mesa Vacia O jugadores sin saldo" << endl;
			cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
			cin.ignore();
			getchar();
			break;
		}
		isCartas();
		jugar();
		listaJugadores->quitarCartasJugadores();

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
		cin.ignore();
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
				cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
				cin.ignore();
				getchar();
				break;
			}
			//almaceno la direccion de jugador
			jugadoresMesa_ptr[jugadoresJugando] = &(listaJugadores->getJugador(rut));
			jugadoresJugando++;
			break;

		}
		else {
			cout <<  "\nRut No encontrado..." << endl;
			cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
			cin.ignore();
			getchar();
		}

		break;
	}
	//eliminar Jugador
	case 3:
	{
		system("cls");
		if (jugadoresJugando == 0) {
			cout << "Nadie para eliminar D:" << endl;
			cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
			cin.ignore();
			getchar();
			break;
		}
		else if (jugadoresJugando == 1) {
			cout << "La mesa no se puede quedar sin nadie Termine partida" << endl;
			cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
			cin.ignore();
			getchar();
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
			cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
			cin.ignore();
			getchar();
			break;
		}
		//ahora si se encontro un jugador en mesa
		jugadoresMesa_ptr[pos] = jugadoresMesa_ptr[jugadoresJugando];
		jugadoresJugando--;
		cout << "Eliminado" << endl;
		cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
		cin.ignore();
		getchar();

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
		cout << "Revolviendo Cartas ...." << endl;
		std::chrono::duration<int, std::milli> timespan(3000);//es para que haya un pequeño delay al sacar cartas
		std::this_thread::sleep_for(timespan);
		cout << "Se revolvio el Mazo :D" << endl;
		listaCartas->recargarMazo();
	}

}

void Sistema::repartirA(Jugador* jugador_ptr)
{
	jugador_ptr->ingresarCarta(listaCartas->getCarta());
}

void Sistema::jugar()
{

	//verificar primero que todos tengan saldo

	for (int i = 0; i < jugadoresJugando; i++) {
		if (jugadoresMesa_ptr[i]->getSaldo() <= 0) {
			cout << "Jugador : " << jugadoresMesa_ptr[i]->getNombre() << " No tiene saldo Para Continuar" << endl;
			jugadoresMesa_ptr[i] = jugadoresMesa_ptr[jugadoresJugando];
			jugadoresJugando--;
			cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
			cin.ignore();
			getchar();
		}
	}

	if (jugadoresJugando == 0) {
		cout << "NADIE TIENE SALDO!" << endl;
		return;
	}

	int apuestas[6] = { 0,0,0,0,0,0 };
	int blackJacks[6] = { 0,0,0,0,0,0 };
	int retirados[6] = { 0,0,0,0,0,0 };

	for (int i = 0; i < jugadoresJugando; i++) {
		system("cls");
		cout << "Bienvenido A BlackJack UCN, Porfavor haga su apuesta : " << endl;
		cout << "JUGADOR : " << jugadoresMesa_ptr[i]->getNombre() << endl;
		cout << "SALDO : " << jugadoresMesa_ptr[i]->getSaldo() << endl;
		cout << "Mi APuesta Es : " << endl;
		apuestas[i] = verificadorIngreso(jugadoresMesa_ptr[i]->getSaldo());
		jugadoresMesa_ptr[i]->setSaldo((jugadoresMesa_ptr[i]->getSaldo()) - apuestas[i]);//quitando saldo

	}
	system("cls");
	cout << "Apuestas Realizadas Presione Cualquier tecla para continuar" << endl;
	cin.ignore();
	getchar();
	crupier->ingresarCarta(listaCartas->getCarta());
	for (int i = 0; i < jugadoresJugando; i++) {
		int opcion = 0;
		int inicio = 0;
		do{	
			system("cls");

			cout << "Turno Del Jugador : " << jugadoresMesa_ptr[i]->getNombre() << endl;
			cout << ".:: CRUPIER ::." << endl;
			printCarta(crupier);
			cout << "\n.:: CARTAS DE "<< jugadoresMesa_ptr[i]->getNombre() << "::." << endl;
			if (inicio == 0) {
				jugadoresMesa_ptr[i]->ingresarCarta(listaCartas->getCarta());
				jugadoresMesa_ptr[i]->ingresarCarta(listaCartas->getCarta());
				if (jugadoresMesa_ptr[i]->suma() == 21) {
					printCarta(jugadoresMesa_ptr[i]);
					cout << "BLACKJACK!" << endl;
					blackJacks[i] = 1;
					cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
					cin.ignore();
					getchar();
					break;
				}
				inicio = 1;
			}
			printCarta(jugadoresMesa_ptr[i]);
			int opcion = 0;
			cout << "Quieres Sacar una Carta Adicional? : " << endl;
			cout << "[1] SI" << endl;
			cout << "[2] NO" << endl;
			cout << "[3] Me retiro" << endl;
			opcion = verificadorIngreso(3);
			if (opcion == 1) {
				jugadoresMesa_ptr[i]->ingresarCarta(listaCartas->getCarta());
			}
			if (jugadoresMesa_ptr[i]->suma() == 21) {
				cout << "GANASTE!" << endl;
				printCarta(jugadoresMesa_ptr[i]);
				cout << "GANASTE!" << endl;
				cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
				cin.ignore();
				getchar();
				break;
			}
			if (jugadoresMesa_ptr[i]->suma() == -1) {
				cout << "Tienes Mas de 21 " << jugadoresMesa_ptr[i]->getNombre() <<" D:"<< endl;
				printCarta(jugadoresMesa_ptr[i]);
				retirados[i] = 1;
				cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
				cin.ignore();
				getchar();
				break;
			}

			if (opcion == 2) {
				break;
			}
	
			if (opcion == 3) {
				jugadoresMesa_ptr[i]->setSaldo((jugadoresMesa_ptr[i]->getSaldo()) - (apuestas[i]/2));
				retirados[i] = 2;
				break;
			}

		} while (true);
	}
	system("cls");
	cout << "Turno Del CRUPIER" << endl;
	while (true) {
		system("cls");
		cout << ".:: CRUPIER JUGANDO ::." << endl;
		printCarta(crupier);
		std::chrono::duration<int, std::milli> timespan(2000);//es para que haya un pequeño delay al sacar cartas
		std::this_thread::sleep_for(timespan);
		if (crupier->suma() <= 16) {
			crupier->ingresarCarta(listaCartas->getCarta());
		}
		else {
			printCarta(crupier);
			cout << "Ya No SE pide mas" << endl;
			cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
			cin.ignore();
			getchar();
			break;
		}

		if (crupier->suma() == -1) {
			cout << "El Crupier Se ha pasado!" << endl;
			printCarta(crupier);
			cout << "Pierde La Casa" << endl;
			cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
			cin.ignore();
			getchar();
			break;
		}

	}

	for (int i = 0; i < jugadoresJugando; i++) {
		system("cls");
		if (retirados[i] == 2) {
			cout << jugadoresMesa_ptr[i]->getNombre() << " SE RETIRO y recupera la mitad =  " << (apuestas[i] / 2) << endl;
			//nada;
		}
		else if (crupier->suma() >= jugadoresMesa_ptr[i]->suma() && blackJacks[i] != 1) {
			cout << jugadoresMesa_ptr[i]->getNombre() << " PIERDE D: " << endl;
		}
		else if (blackJacks[i] == 1) {
			cout << jugadoresMesa_ptr[i]->getNombre() << " GANA CON BLACKJACK : " << (apuestas[i] * 2) << endl;
			jugadoresMesa_ptr[i]->agregarSaldo((apuestas[i] * 2));
		}
		else {
			cout << jugadoresMesa_ptr[i]->getNombre() << " GANA : " << (apuestas[i] * 2) << endl;
			jugadoresMesa_ptr[i]->agregarSaldo((apuestas[i] * 2));
		}
		cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
		cin.ignore();
		getchar();
	}



}




void Sistema::printCarta(Jugador* jug)
{
	if (jug->getCantidadCartasActuales() == 0) {
		return;
	}
	
	int cantidad = jug->getCantidadCartasActuales();
	string C = "**";

	cout << endl;
	for (int i = 0; i < cantidad; i++) {
		cout << " _________ ";
		if (i == cantidad - 1) {
			cout << endl;
		}
	}
	for (int i = 0; i < cantidad; i++) {
		C = *jug->getListaCartas2()[i];
		if (C.compare("10") != 0) {
			cout << "|" << C << "        |";
		}
		else {
			cout << "|" << C << "       |";
		}
		if (i == cantidad - 1) {
			cout << endl;
		}
	}
	for (int i = 0; i < cantidad; i++) {
		cout << "|         |";
		if (i == cantidad - 1) {
			cout << endl;
		}
	}
	for (int i = 0; i < cantidad; i++) {
		cout << "|         |";
		if (i == cantidad - 1) {
			cout << endl;
		}
	}
	for (int i = 0; i < cantidad; i++) {
		cout << "|   UCN   |";
		if (i == cantidad - 1) {
			cout<<" -->TOTAL = " << jug->suma();
			cout << endl;
		}
	}
	for (int i = 0; i < cantidad; i++) {
		cout << "|         |";
		if (i == cantidad - 1) {
			cout << endl;
		}
	}
	for (int i = 0; i < cantidad; i++) {
		cout << "|         |";
		if (i == cantidad - 1) {
			cout << endl;
		}
	}
	for (int i = 0; i < cantidad; i++) {
		C = *jug->getListaCartas2()[i];
		if (C.compare("10") != 0) {
			cout << "|________" << C << "|";
		}
		else {
			cout << "|_______" << C << "|";
		}
		if (i == cantidad - 1) {
			cout << endl;
		}
	}
}

