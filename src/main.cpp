/*
 * Sightseeing.cpp
 *
 *  Created on: 19/04/2016
 *      Author: Utilizador
 */

#include "Bus.h"
#include "Graph.h"
#include "Passenger.h"
#include "POI.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


int main(){
	Bus bus = Bus();
	Graph graph =  Graph();
	string line;
	ifstream myfile ("POI.txt");
	if(myfile.is_open()){
		while(getline(myfile, line)){
			stringstream ss(line);
			string poiName;
			string name;
			int coordX, coordY;
			ss >> name >> poiName >> coordX >> coordY;
			Passenger p(name);
			bus.addPassenger(p);
			POI poi(poiName, coordX, coordY);
			graph.addVertex(poi);

		}
	}
	return 0;
}

int calculateDistance(POI poi1, POI poi2){

}


