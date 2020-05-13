#include <memory>
#include "Controller.h"

/*
	Entrada a la ejecución del programa.
*/
int main() {
	std::unique_ptr<Controller> controller(new Controller());
	controller->start();
}