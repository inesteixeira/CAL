/*
 * Bus.h
 *
 *  Created on: 19/04/2016
 *      Author: Utilizador
 */

#ifndef BUS_H_
#define BUS_H_
#include <iostream>
#include <vector>
#include "Passenger.h"

using namespace std;

class Bus {
private:
	int numMaxPassengers;
	int numPassengers;
	vector<Passenger> passengers;
public:
	Bus();
	Bus(int numMaxPassengers, int numPassengers);
	int getNumMaxPassengers() const;
	int getNumPassengers() const;
	void setNumPasengers(int numPassengers);
	void addPassenger(Passenger passenger);
	void removePassenger(Passenger passenger);
	vector<Passenger> getPassengers() const;
};

#endif /* BUS_H_ */
