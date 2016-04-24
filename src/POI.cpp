#include "POI.h"

POI::POI() {
}

POI::POI(string name, bool visit) {
	this->name = name;
	this->visit = visit;
}


string POI::getName() const {
	return name;
}

bool POI::getVisit() const{
	return visit;
}

void POI::setVisit(bool visit1){
	this->visit = visit1;
}

