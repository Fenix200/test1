#include "Sistema.h"

Sistema::Sistema()
{
	listaJugadores = new ListaJugador();
	jugadoresJugando = 0;
	jugadoresMesa_ptr = new Jugador*[6];
	listaAdministradores = new ListaAdministradores();
	//Crupier es un "jugador" en este caso la posicion 0 de la lista jugador
	crupier = &(listaJugadores->getJugador("-9999"));
	listaCartas = new ListaCartas();
	leerArchivos();

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
			jugadoresOnfire();

			break;
		}
		case 3: {
			string user;
			string pass;
			cout << "\nINGRESE CON DOBLE ENTER\n"<<endl;
			cout << "\nIngrese rut Administrador = ";
			cin.ignore();
			getline(cin, user);
			cin.ignore();
			cout << "\nIngrese contrasenna Administrador = ";
			getline(cin,pass);
			cin.ignore();

			cout << user << " " << pass << endl;

			if (!listaAdministradores->buscarAdministrador(user, pass)) {
				cin.ignore();
				cout << "RUT O CONTRASENNA INCORRECTOS" << endl;
				cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
				_getch();
				break;
			}

			printMenus(3);
			int ingreso_3 = verificadorIngreso(4);
			//aca ira configuracion
			configuracion(ingreso_3);
			
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
		cout << "[1] Cargar Saldo a la billetera electronica" << endl;
		cout << "[2] Consultar Saldo" << endl;
		cout << "[3] Registrar Jugador" << endl;
		cout << "[4] Editar Jugador" << endl;
		return;
	}

}
//pregunta hasta que se ingrese un valor valido entre 0 y el valor indicado
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
//este verificador de ingreso admite un valor minimo
int Sistema::verificadorIngreso(int min, int max)
{
	while (true) {
		int opcion;

		cin >> opcion;
		if (!cin) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Opcion no valida ingresa Numero!" << endl;
		}
		else if (opcion <= max && opcion >= min) {
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
			cout << "Mesa Vacia o jugadores sin saldo" << endl;
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

		cout << "Ingrese NOMBRE (Se diferencia entre mayusculas y minusculas) : " << endl;
		getline(cin, nombre);

		if(listaJugadores->buscarJugador(rut) != -1){
			bool existeNombre = listaJugadores->getJugador(rut).getNombre().compare(nombre) == 0;
			bool existeId = to_string(listaJugadores->getJugador(rut).getId()).compare(id) == 0;
			bool existeSaldo = listaJugadores->getJugador(rut).getSaldo() > 5000;
			bool jugando = false;
			for (int a = 0; a < jugadoresJugando; a++) {
				if (0==id.compare(to_string(jugadoresMesa_ptr[a]->getId()))) {
					jugando = true;
					break;
				}
			}
			if (!existeId || !existeNombre || !existeSaldo || jugando) {
				system("cls");
				if (!existeSaldo) {
					cout << "Jugador No puede Ser Agregado... Revise Saldo" << endl;
				}
				if (jugando) {
					cout << "Jugador No puede Ser Agregado... ya jugando" << endl;
				}
				if (!existeNombre) {
					cout << "Jugador No puede Ser Agregado... nombre incorrecto" << endl;
				}
				if (!existeId) {
					cout << "Jugador No puede Ser Agregado... id incorrecta" << endl;
				}
				cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
				getchar();
				cin.ignore();

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
			cout << "0 jugando Nadie para eliminar D:" << endl;
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
		cin.ignore();
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
			cout << "Nadie encontrado para eliminar D:" << endl;
			cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
			cin.ignore();
			getchar();
			break;
		}
		//ahora si se encontro un jugador en mesa
		jugadoresMesa_ptr[pos] = jugadoresMesa_ptr[(jugadoresJugando-1)];
		jugadoresJugando--;
		cout << "Eliminado a " <<rut<< endl;
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
	if (jugadoresJugando == 0) {
		cout << "NADIE TIENE SALDO!" << endl;
		return;
	}


	int apuestas[6] = { 0,0,0,0,0,0 };
	int blackJacks[6] = { 0,0,0,0,0,0 };
	int retirados[6] = { 0,0,0,0,0,0 };
	int derrotados = 0;
	int cantRetirados = 0;
	bool retirarse = true;

	for (int i = 0; i < jugadoresJugando; i++) {
		system("cls");
		cout << "Bienvenido A BlackJack UCN, Porfavor haga su apuesta : " << endl;
		cout << "JUGADOR : " << jugadoresMesa_ptr[i]->getNombre() << endl;
		cout << "SALDO : " << jugadoresMesa_ptr[i]->getSaldo() << endl;
		if (jugadoresMesa_ptr[i]->getSaldo()==0) {
			cout << "JUGADOR: "<< jugadoresMesa_ptr[i]->getNombre()<<" ID: "<< jugadoresMesa_ptr[i] ->getId()<<" RUT: "<< jugadoresMesa_ptr[i] ->getRut()<< endl;
			cout << "SIN SALDO!!! PARA CONTINUAR, Debe Eliminarlo de la mesa :D, hasta pronto" << endl;
			cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
			cin.ignore();
			getchar();
			return;
		}
		cout << "Mi APuesta Es : " << endl;
		apuestas[i] = verificadorIngreso(jugadoresMesa_ptr[i]->getSaldo());


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
				jugadoresMesa_ptr[i]->setSaldo((jugadoresMesa_ptr[i]->getSaldo()) - apuestas[i]);//quitando saldo
				retirarse = true;
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
			if (crupier->suma() != 11 && retirarse) {
				cout << "[3] Me retiro" << endl;
			
			opcion = verificadorIngreso(3);
			}
			else {
				opcion = verificadorIngreso(2);
			}
			if (opcion == 1) {
				jugadoresMesa_ptr[i]->ingresarCarta(listaCartas->getCarta());
				retirarse = false;
			}
			if (jugadoresMesa_ptr[i]->suma() == 21) {
				system("cls");
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
				derrotados++;
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
				jugadoresMesa_ptr[i]->setSaldo((jugadoresMesa_ptr[i]->getSaldo()) + (apuestas[i]/2));
				retirados[i] = 2;
				cantRetirados++;
				break;
			}

		} while (true);
	}

	if ((cantRetirados + derrotados) == jugadoresJugando) {
		for (int i = 0; i < jugadoresJugando; i++) {
			system("cls");


			if (retirados[i] == 2) {
				double saldo = (apuestas[i] / 2);
				cout << jugadoresMesa_ptr[i]->getNombre() << " SE RETIRO y recupera la mitad =  " << saldo << endl;
			}
			else {
				cout << jugadoresMesa_ptr[i]->getNombre() << " PIERDE D: " << endl;
			}
			cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
			cin.ignore();
			getchar();
		}
		cout << "Fin de partida \nPRESIONE ENTER PARA CONTINUAR" << endl;
		cin.ignore();
		getchar();
		return;
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
			double saldo = (apuestas[i] / 2);
			cout << jugadoresMesa_ptr[i]->getNombre() << " SE RETIRO y recupera la mitad =  " << saldo << endl;
		
			//nada;
		}
		else if (crupier->suma() == jugadoresMesa_ptr[i]->suma() && retirados[i] != 1) {
			jugadoresMesa_ptr[i]->agregarSaldo((apuestas[i]));
			cout << jugadoresMesa_ptr[i]->getNombre() << " EMPATA y recupera su dinero =  " << (apuestas[i]) << endl;
		}
		else if (crupier->suma() > jugadoresMesa_ptr[i]->suma()) {
			cout << jugadoresMesa_ptr[i]->getNombre() << " PIERDE D: " << endl;
		}
		else if (blackJacks[i] == 1) {
			cout << jugadoresMesa_ptr[i]->getNombre() << " GANA CON BLACKJACK! : " << (apuestas[i] * 2) << endl;
			jugadoresMesa_ptr[i]->agregarSaldo((apuestas[i] * 2));
			jugadoresMesa_ptr[i]->addVictoria();
		}
		else {
			cout << jugadoresMesa_ptr[i]->getNombre() << " GANA : " << (apuestas[i] * 2) << endl;
			jugadoresMesa_ptr[i]->agregarSaldo((apuestas[i] * 2));
			jugadoresMesa_ptr[i]->addVictoria();
		}
		cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
		cin.ignore();
		getchar();
	}



}
//despliega en orden los 10 jugadores con mas victorias(en caso de ser menos imprime menos)
void Sistema::jugadoresOnfire()
{
	listaJugadores->ordenarMayoraMenorJugadores();
	int top10;
	bool hayMasde10 = true;
	if (listaJugadores->getCantActual() < 10) {
		top10 = listaJugadores->getCantActual();
		hayMasde10 = false;
	}
	else {
		top10 = 10;
	}
	int posicion = 1;
	for (int i = 0; i < top10; i++) {
		if (listaJugadores->getJugador(i).getNombre().compare("CRUPIER") != 0) {
			cout <<"["<<posicion<<"] "<< listaJugadores->getJugador(i).getNombre() << " Victorias = " << listaJugadores->getJugador(i).getVictorias() << endl;
			posicion++;
		}
		else if(hayMasde10) {
			top10++;
		}
	}
	cout << "\nPRESIONE ENTER PARA CONTINUAR" << endl;
	cin.ignore();
	getchar();
}


//submetodo de ejecutar sistema (apartado configuracion del programa
void Sistema::configuracion(int opcion)
{
	//cargarsaldo
	if (opcion == 1) {
		system("cls");
		cout << "Ingrese ID de Billetera para agregar saldo" << endl;
		int id = verificadorIngreso(0,idActualPersona);
		for (int i = 0; i < listaJugadores->getCantActual(); i++) {
			if (id == listaJugadores->getJugador(i).getId()) {
				system("cls");
				cout << "ID ENCONTRADA :" << id << "\nIngrese monto a Cargar, recuerde que debe ser \nMayor que 1 mil y \nMenor que 100 mil\n\nMONTO = ";
				int monto = verificadorIngreso(100000);
				if (monto >= 1000) {
					listaJugadores->getJugador(i).agregarSaldo(monto);
					cout << "Saldo AGREGADO EXITOSAMENTE :D" << endl;
					cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
					cin.ignore();
					getchar();
					return;
				}
				else {
					cout << "Saldo no puede ser menor a 1000, hasta luego" << endl;
					cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
					cin.ignore();
					getchar();
					return;
				}	
			}
		}
		cout << "ID NO ENCONTRADA" << endl;
		cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
		cin.ignore();
		getchar();
		return;
	}
	//consultar saldo
	else if (opcion == 2) {
		system("cls");
		cout << "Ingrese ID de Billetera para consultar Saldo" << endl;
		int id = verificadorIngreso(0,idActualPersona);
		for (int i = 0; i < listaJugadores->getCantActual(); i++) {
			if (id == listaJugadores->getJugador(i).getId()) {
				cout << listaJugadores->getJugador(i).getNombre()<< " Rut = "<< listaJugadores->getJugador(i).getRut() << " Saldo actual = " << listaJugadores->getJugador(i).getSaldo()<<endl;
				cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
				cin.ignore();
				getchar();
				return;
			}
		}
		cout << "ID NO ENCONTRADA" << endl;
		cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
		cin.ignore();
		getchar();
		return;
	}
	//registrar jugador
	else if (opcion == 3) {
		system("cls");
		cout << "Ingrese Datos de nuevo jugador (Ingrese con DOBLE ENTER) \n" << endl;
		string rut;
		cout << "\nIngrese RUT = "<<endl;
		cin.ignore();
		getline(cin, rut);
		cin.ignore();	
		if (listaJugadores->buscarJugador(rut) != -1) {
			cout << "RUT YA EXISTE!!!"<<endl;
			cin.ignore();
			cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
			_getch();
			return;
		}
		string nombreNuevo;
		cout << "\nIngrese Nombre = " << endl;
		getline(cin, nombreNuevo);
		cin.ignore();
		listaJugadores->agregarJugador(nombreNuevo, rut, idActualPersona);
		cout << "AGREGADO EXITOSAMENTE" << endl;
		cout << "RUT = " << rut << "\nNOMBRE = " << nombreNuevo <<"\nID = "<< idActualPersona<< endl;
		setUltimaIdPersona(idActualPersona);
		cin.ignore();
		cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
		_getch();
		return;

	}
	//editar nombre de jugador
	else if (opcion == 4) {
		system("cls");
		cout << "Ingrese RUT DEL JUGADOR para cambiar su nombre de usuario \n" << endl;
		string rut;
		cout << "Ingrese rut = ";
		cin.ignore();
		getline(cin, rut);
		if (listaJugadores->buscarJugador(rut) == -1) {
			cout << "RUT NO ENCONTRADO" << endl;
			cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
			cin.ignore();
			getchar();
			return;
		}

		string nombreNuevo;
		cout << "Ingrese Nombre Nuevo = ";
		getline(cin, nombreNuevo);
		cin.ignore();
		listaJugadores->getJugador(rut).setNombre(nombreNuevo);
		cout << "NOMBRE CAMBIADO\nPRESIONE ENTER PARA CONTINUAR" << endl;
		cin.ignore();
		getchar();
		return;

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
		cout << "|"<<"   UCN   "<<"|";
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



bool Sistema::leerArchivos()
{
	//leer admin es el archivo mas importante ya que si no es posible leerlo no es posible inscribir ni agregar saldo
	if (!leerAdmin("admin.txt")) {
		return false;
	}
	leerJugadores("jugadores.txt");
}

bool Sistema::leerAdmin(string nombreArchivo)
{
	ifstream archivo;


	archivo.open(nombreArchivo.c_str(), ios::in); //Abrimos el archivo en modo lectura

	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo "<<nombreArchivo;
		_getch();
		exit(1);
	}
	//Aca los datos a obtener linea por linea
	while (!archivo.eof()) { //mientras no sea final del archivo

		string rut;
		string pass;
		getline(archivo, rut, ',');
		getline(archivo, pass);
		listaAdministradores->agregarAdministrador(rut, pass);

	}


	archivo.close(); //Cerramos el archivo
	return true;
}

bool Sistema::leerJugadores(string nombreArchivo)
{
	int linea = 1;
	int id;
	int idFinal = -9999;

	ifstream archivo;


	archivo.open(nombreArchivo.c_str(), ios::in); //Abrimos el archivo en modo lectura

	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo" << nombreArchivo;
		return false;
	}
	//Aca los datos a obtener linea por linea
	while (!archivo.eof()) { //mientras no sea final del archivo

		string rut;
		string nombre;

		string idString;
		string montoString;
		string partidasGanadasString;
		
		getline(archivo, rut, ',');
		getline(archivo, nombre, ',');
		getline(archivo, idString, ',');
		getline(archivo, montoString, ',');
		getline(archivo, partidasGanadasString);

		int monto;
		int partidasGanadas;

		bool esPosibleInscribir = true;
		try {
			id = stoi(idString);
			monto = stoi(montoString);
			partidasGanadas = stoi(partidasGanadasString);
			//la ultima id sera siempre la mayor
			if (id > idFinal) {
				idFinal = id;
			}

		}
		catch (...) {
			esPosibleInscribir = false;
		}
		if (esPosibleInscribir) {
			if (!listaJugadores->agregarJugador(nombre, rut, id, monto, partidasGanadas)) {
				cout << "Error en linea: " << linea << " Del Archivo : " << nombreArchivo << endl;
				_getch();
			}
		}
		else {
			cout << "Error en linea: " << linea << " Del Archivo : " << nombreArchivo << endl;
			_getch();
		}

		linea++;
	}

	try {
		setUltimaIdPersona(idFinal);
	}
	catch(...){

	}
	archivo.close(); //Cerramos el archivo
	return true;
}
