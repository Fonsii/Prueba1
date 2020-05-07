#include <memory>
#include "Controller.h"

int main() {
	std::unique_ptr<Controller> controller(new Controller());
	controller->start();
}