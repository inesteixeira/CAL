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
#include <stdlib.h>

using namespace std;



void readDistances(){
	string line;
	ifstream myfile ("Distances.txt");
	if(myfile.is_open()){
		while(getline(myfile, line)){
			stringstream ss(line);
			string source, dest, sdist1, sdist2;
			double dist1;
			double dist2;
			getline(ss, source, ';');
			getline(ss,dest,';');
			getline(ss,sdist1, ';');
			getline(ss,sdist2, ';');
			dist1 = atof(sdist1.c_str());
			dist2 = atof(sdist2.c_str());
			//cout << "Source: " << source << " Dest: " << dest << " Dist1: " << dist1 << " Dist2: " << dist2 << endl;
		}
	}
}

void pointsOfInterest(vector<POI> &points){
	string line;
	ifstream myfile ("AllPOI.txt");
	if(myfile.is_open()){
		while(getline(myfile, line)){
			POI p(line);
			points.push_back(p);
		}
	}
	/*for(unsigned int i = 0; i < points.size(); i++){
		cout << points[i].getName() << endl;
	}*/
}

int main() {
	Bus bus = Bus();
	Graph graph = Graph();
	POI poi = POI();
	vector<POI> points;
	readDistances();
	pointsOfInterest(points);
	string line;
	ifstream myfile("POI.txt");
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			stringstream ss(line);
			string poiName;
			string user;
			ss >> user >> poiName ;
			Passenger p(user);
			bus.addPassenger(p);
			POI poi(poiName);
			graph.addVertex(poi);

		}
	}
	return 0;
}




