/*
 * POI.h
 *
 *  Created on: 19/04/2016
 *      Author: Utilizador
 */


#ifndef POI_H_
#define POI_H_

#include <iostream>
#include <vector>



using namespace std;

class POI{
private:
	string name;
	int coordX, coordY;
	int distance;
	vector<int> interestedPassengers;

public:
	POI();
	POI(string name, int coordX, int coordY, int distance);
	string getName() const;
	int getCoordX() const;
	int getCoordY() const;
	int getDistance() const;
	vector<int> getInterestedPassengers();


};



#endif /* POI_H_ */
