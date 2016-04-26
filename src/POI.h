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
	bool visit;

public:
	POI();
	POI(string name, bool visit);
	string getName() const;
	bool getVisit() const ;
	void setVisit(bool visit);
	bool operator ==(const POI p1) const;
};

#endif /* POI_H_ */
