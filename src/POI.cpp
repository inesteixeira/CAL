#include "POI.h"

POI::POI(){}

POI::POI(string name, int coordX, int coordY, int distance){
	this->name = name;
	this->coordX = coordX;
	this->coordY = coordY;
	this->distance =  distance;
}

int POI::getCoordX() const{
	return coordX;
}

int POI::getCoordY() const{
	return coordY;
}

int POI::getDistance() const{
	return distance;
}

string POI::getName() const{
	return name;
}







