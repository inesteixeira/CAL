#include "POI.h"

POI::POI() {
}

POI::POI(string name, bool visited) {
	this->name = name;
	this->visited = visited;
}


string POI::getName() const {
	return name;
}

bool POI::getVisited() const{
	return visited;
}

void POI::setVisited(bool visit){
	this->visited = visit;
}

