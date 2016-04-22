#include "POI.h"

POI::POI() {
}

POI::POI(string name) {
	this->name = name;
}


string POI::getName() const {
	return name;
}


