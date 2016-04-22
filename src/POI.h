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
	bool visited;

public:
	POI();
	POI(string name, bool visited);
	string getName() const;
	bool getVisited() const ;
	void setVisited(bool visited);
};

#endif /* POI_H_ */
