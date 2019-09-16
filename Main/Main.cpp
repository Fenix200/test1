#include <iostream>
#include "ClasePrueba.h"
int main()
{
	ClasePrueba* prueba = new ClasePrueba(89);

	std:: cout << prueba->getDato();
}
