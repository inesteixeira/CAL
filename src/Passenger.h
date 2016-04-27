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

class Passenger {
private:
	string name;
	int id;
	vector<POI> pointsOfInterest;

public:
	/**
	 * @brief Passenger contructor.
	 */
	Passenger();
	/**
	 * @brief Passenger constructor with the neccessary parameters.
	 */
	Passenger(string name,vector<POI> pointsOfInterest);
	/**
	 * @brief returns the name of the passenger.
	 */
	string getName() const;
	/**
	 * @brief returns the id of the passenger.
	 */
	int getId() const;
	/**
	 * @brief returns the vector of the Points of Interest that the passenger wants to see.
	 */
	vector<POI> getPointsOfInterest() const;
	/**
	 * @brief adds a points of interest to the vector of POI that the passengers wants to see.
	 */
	void addPointOfInterest(POI pointOfInterest);
	/**
	 * @brief removes a POI from the vector.
	 */
	void removePointOfInterest(POI pointOfInterest);

};

#endif /* PASSENGER_H_ */
