#include <memory>
#include "Controller.h"

/*
	Entrada a la ejecuci�n del programa.
*/
int main() {
	std::unique_ptr<Controller> controller(new Controller());
	controller->start();
}