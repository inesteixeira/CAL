#include <iostream>
using namespace std;


POI::POI(string name, int coordX, int coordY, int distance, vector<Passenger> interestedPassengers){
	this->name = name;
	this->coordX = coordX;
	this->coordY = coordY;
	this->distance =  distance;
	this->interestedPassengers = interestedPassengers;
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

vector<Passenger> POI::getInterestedPassengers() const{
	return interestedPassengers;
}






