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



void readDistances(Graph &graph){
	string line;
	ifstream myfile ("Distances.txt");
	if(myfile.is_open()){
		while(getline(myfile, line)){
			stringstream ss(line);
			string source, dest, sdist1, sdist2;
			getline(ss, source, ';');
			getline(ss,dest,';');
			getline(ss,sdist1, ';');
			getline(ss,sdist2, ';');
			double dist1 = atof(sdist1.c_str());
			double dist2 = atof(sdist2.c_str());
			POI source1(source, false);
			POI dest2(dest, false);
			if(!(graph.addEdge(source1, dest2,dist1))) return;
			if(!(graph.addEdge(dest2, source1, dist2))) return ;
		}
	}
}

void readPointsOfInterest(vector<POI> &points, Graph graph){
	string line;
	ifstream myfile ("AllPOI.txt");
	if(myfile.is_open()){
		while(getline(myfile, line)){
			POI p(line, false);
			points.push_back(p);
			graph.addVertex(p);
		}
	}
}

void readUsers(vector<POI> &pointsToVisit){
	string line;
	ifstream myfile("POI.txt");
	if(myfile.is_open()){
		while(getline(myfile, line)){
			stringstream ss (line);
			string poiName;
			string user;
			ss >> user >> poiName;
			Passenger p(user);
			POI poi (poiName,false);
			pointsToVisit.push_back(poi);
		}
	}
}

void checkVisitedPoints(vector<POI> &points, vector<POI> &pointsToVisit){
	for(unsigned int i = 0; i < points.size(); i++){
		for(unsigned int j = 0; j< pointsToVisit.size(); j++){
			if(points[i].getName() == pointsToVisit[j].getName() && points[i].getVisited() == false){
				points[i].setVisited(true);
			}
		}
	}
	for(unsigned int i = 0; i < points.size(); i++){
		cout << points[i].getName() << " " << points[i].getVisited() << endl;
	}
}

int main() {
	Bus bus = Bus();
	Graph graph = Graph();
	POI poi = POI();
	vector<POI> points;
	vector<POI> pointsToVisit;
	readDistances(graph);
	readPointsOfInterest(points, graph);
	readUsers(pointsToVisit);
	checkVisitedPoints(points, pointsToVisit);
	return 0;
}




