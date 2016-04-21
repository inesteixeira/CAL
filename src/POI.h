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

class POI {
private:
	string name;
	string spot;
	//int distance;

public:
	POI();
	POI(string name, string spot);
	string getName() const;
	string getString() const;
	//int getDistance() const;

};

#endif /* POI_H_ */
