
#include "Bus.h"

//using namespace std;

Bus::Bus(){}

Bus:: Bus(int numMaxPassengers, int numPassengers){
	this->numMaxPassengers = numMaxPassengers;
	this->numPassengers = numPassengers;
}

vector<Passenger> Bus::getPassengers() const{
	return passengers;
}

void Bus::addPassenger(Passenger passenger){
	passengers.push_back(passenger);
	numPassengers++;
}

int Bus::getNumMaxPassengers() const{
	return numMaxPassengers;
}

int Bus::getNumPassengers() const{
	return numPassengers;
}

void Bus::setNumPasengers(int newPassengers){
	newPassengers = numPassengers;
}

//std::string operator==() {
//	return std::string();
//}
//
//void Bus::removePassenger(Passenger passenger){
//	for(unsigned int i = 0; i <passengers.size(); i++){
//		if(passengers[i].getName() == passenger.getName()){
//			passengers.erase(passengers.begin() + (i-1));
//		}
//	}
//}
