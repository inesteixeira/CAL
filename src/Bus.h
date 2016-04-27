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
	/**
	 * @brief Bus constructor.
	 */
	Bus();
	/**
	 * @brief Bus constructor with the neccessary parameters.
	 */
	Bus(int numMaxPassengers, int numPassengers);
	/**
	 * @brief returns the max number of passengers.
	 */
	int getNumMaxPassengers() const;
	/**
	 * @brief returns the number of passengers.
	 */
	int getNumPassengers() const;
	/**
	 * @brief updates the number of passengers.
	 */
	void setNumPasengers(int numPassengers);
	/**
	 * @brief adds a passenger to the bus.
	 */
	void addPassenger(Passenger passenger);
	/**
	 * @brief removes the passenger from the bus,
	 */
	void removePassenger(Passenger passenger);
	/**
	 * @brief returns the vector of the passengers.
	 */
	vector<Passenger> getPassengers() const;
};

#endif /* BUS_H_ */
