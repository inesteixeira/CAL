#include "POI.h"

POI::POI() {
}

POI::POI(string name, string spot) {
	this->name = name;
	this->spot=spot;
}

string POI::getSpot() const {
	return spot;
}


/*int POI::getDistance() const{
 return distance;
 }*/

string POI::getName() const {
	return name;
}

