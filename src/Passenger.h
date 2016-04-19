/*
 * Passenger.h
 *
 *  Created on: 19/04/2016
 *      Author: Utilizador
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <iostream>
#include <vector>
#include "POI.h"



using namespace std;

class Passenger{
private:
	string name;
	int id;
	vector<POI> pointsOfInterest;

public:
	Passenger();
	Passenger(string name);
	string getName() const;
	int getId() const;
	vector<POI> getPointsOfInterest() const;
	void addPointOfInterest(POI pointOfInterest);
	void removePointOfInterest(POI pointOfInterest);


};




#endif /* PASSENGER_H_ */
