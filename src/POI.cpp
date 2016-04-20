#include "POI.h"

POI::POI(){}

POI::POI(string name, int coordX, int coordY){
	this->name = name;
	this->coordX = coordX;
	this->coordY = coordY;
}

int POI::getCoordX() const{
	return coordX;
}

int POI::getCoordY() const{
	return coordY;
}

/*int POI::getDistance() const{
	return distance;
}*/

string POI::getName() const{
	return name;
}







