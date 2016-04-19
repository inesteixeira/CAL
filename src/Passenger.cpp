
#include "Passenger.h"

using namespace std;

Passenger::Passenger() {
}

Passenger::Passenger(string name){
	this->name = name;
}

string Passenger::getName() const{
	return name;
}

int Passenger::getId() const{
	return id;
}

vector<POI> Passenger::getPointsOfInterest() const{
	return pointsOfInterest;
}

void Passenger::addPointOfInterest(POI pointOfInterest){
	pointsOfInterest.push_back(pointOfInterest);
}

void Passenger::removePointOfInterest(POI pointOfInterest){
	for(unsigned int i = 0; i< pointsOfInterest.size(); i++){
		if(pointsOfInterest[i].getName() == pointOfInterest.getName())
			pointsOfInterest.erase(pointsOfInterest.begin() + (i-1));
	}
}


