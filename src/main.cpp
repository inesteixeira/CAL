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

void readUsers(vector<POI> &pointsToVisit, vector<Passenger> &passengers){
	string line;
	vector<POI> pois;
	ifstream myfile("POI.txt");
	if(myfile.is_open()){
		while(getline(myfile, line)){
			stringstream ss (line);
			string poiName;
			string user;
			ss >> user >> poiName;
			POI poi (poiName,false);
			pois.push_back(poi);
			Passenger p(user,pois);
			pointsToVisit.push_back(poi);
			passengers.push_back(p);
		}
	}
}

void checkVisitedPoints(vector<POI> &points, vector<POI> &pointsToVisit){
	for(unsigned int i = 0; i < points.size(); i++){
		for(unsigned int j = 0; j< pointsToVisit.size(); j++){
			if(points[i].getName() == pointsToVisit[j].getName() && points[i].getVisit() == false){
				points[i].setVisit(true);
			}
		}
	}
}

void newPassenger(vector<Passenger> &passengers, vector<POI> &points, vector<POI> &pointsToVisit){
	string name, poi;
	int numPois;
	vector<POI> pois;
	cout << "Qual é o nome do passageiro? " ; cin >> name;
	cout << "Quantos pontos de interesse quer visitar?"; cin >> numPois;
	cout << "Que pontos de interesse quer visitar?" << endl;
	for(unsigned int i = 0; i < points.size(); i++){
		cout << points[i].getName() << " " ;
	}
	cout << endl;
	for(int j = 0; j < numPois; j++){
		cin >> poi;
		for(unsigned int i = 0; i < points.size(); i++){
			if(points[i].getName() == poi){
				POI newPoi(poi,true);
				pois.push_back(newPoi);
			}
		}
	}
	Passenger newPass(name,pois);
	passengers.push_back(newPass);
}

void currentPassengers(vector<Passenger> &passengers){
	cout <<"Passageiros existentes: " ;
	for(unsigned int i= 0; i < passengers.size(); i++){
		cout << passengers[i].getName() << " ";
	}
	cout << endl;
}

void currentPOI(vector<POI> &points){
	cout << "POI existentes: " ;
	for(unsigned int i = 0; i <points.size(); i++){
		cout << points[i].getName() << " ";
	}
	cout << endl;
}
void shortestPath(vector<POI> &pointsToVisit, vector<POI> &points){
	checkVisitedPoints(points, pointsToVisit);
}
int menus(vector<Passenger> &passengers, vector<POI> &points, vector<POI> &pointsToVisit){
	int next;
	cout << "O que deseja fazer?" << endl;
	cout << " 1- Acrescentar passageiros." << endl;
	cout << " 2- Ver passageiros existentes." << endl;
	cout << " 3- Ver Pontos de Interesse existentes." << endl;
	cout << " 4- Calcular o caminho mais curto." << endl;
	cout << " 9- Sair." << endl;
	cin >> next;

	if(next ==1) newPassenger(passengers,points,pointsToVisit);
	if(next ==2) currentPassengers(passengers);
	if(next ==3) currentPOI(points);
	if(next ==4) shortestPath(pointsToVisit,points);
	if(next ==9) return -1;

}
int main() {
	Bus bus = Bus();
	Graph graph = Graph();
	POI poi = POI();
	Passenger passenger = Passenger();
	vector<Passenger> passengers;
	vector<POI> points;
	vector<POI> pointsToVisit;
	readDistances(graph);
	readPointsOfInterest(points, graph);
	readUsers(pointsToVisit, passengers);
	do{
	}while
		(menus(passengers,points,pointsToVisit)!= -1);
	cout <<"Exit!" << endl;
	exit(0);
}




