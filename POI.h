/*
 * POI.h
 *
 *  Created on: 19/04/2016
 *      Author: Utilizador
 */

#ifndef POI_H_
#define POI_H_

#include <Passenger.h>
using namespace std;
class POI{
private:
	string name;
	int coordX, coordY;
	int distance;
	vector<Passenger> interestedPassengers;

public:
	POI(string name, int coordX, int coordY, int distance, vector<Passenger> interestedPassengers);
	string getName() const;
	int getCoordX() const;
	int getCoordY() const;
	int getDistance() const;
	vector<Passenger> getInterestedPassengers() const;


};



#endif /* POI_H_ */
