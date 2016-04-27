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
#include "graphviewer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;


void readDistances(Graph &graph,vector<POI> &points,GraphViewer &gv){
	string line;
	ifstream myfile ("Distances.txt");
	int id= 0;
	if(myfile.is_open()){
		while(getline(myfile, line)){
			stringstream ss(line);
			string source, dest, sdist;
			getline(ss, source, ';');
			getline(ss,dest,';');
			getline(ss,sdist, ';');
			double dist = atof(sdist.c_str());
			POI source1(source, false);
			POI dest2(dest, false);
			if((graph.addEdge(source1, dest2,dist)) == false){
				cout << "falhou!" << endl;
			}

			for(unsigned int i = 0; i < points.size(); i++){
				for(unsigned int j = 0; j < points.size();j++){
					if(points[i].getName() == source && points[j].getName() == dest){
						gv.addEdge(id,i,j,EdgeType::DIRECTED);
						id++;
					}
				}
			}
		}
	}
	gv.rearrange();
}

void readPointsOfInterest(vector<POI> &points, Graph &graph, GraphViewer &gv){
	string line;
	ifstream myfile ("AllPOI.txt");
	int id = 0;
	if(myfile.is_open()){
		while(getline(myfile, line)){
			stringstream ss(line);
			string poiName,x,y;
			getline(ss,poiName,';');
			getline(ss,x,';');
			getline(ss,y,';');
			double x1 = atof(x.c_str());
			double y1 = atof(y.c_str());
			POI p(poiName, false);
			p.setX(x1);
			p.setY(y1);
			points.push_back(p);
			graph.addVertex(p);
			gv.addNode(id,x1,y1);
			gv.setVertexLabel(id,poiName);
			id++;
		}
	}
	gv.rearrange();
}

void readUsers(vector<POI> &pointsToVisit, vector<Passenger> &passengers,GraphViewer &gv){
	string line;
	vector<POI> pois;
	ifstream myfile("POI.txt");
	if(myfile.is_open()){
		while(getline(myfile, line)){
			stringstream ss (line);
			string poiName;
			string user;
			getline(ss, user,';');
			getline(ss,poiName);
			POI poi (poiName,true);
			pois.push_back(poi);
			Passenger p(user,pois);
			pointsToVisit.push_back(poi);
			passengers.push_back(p);
		}
	}
}

void checkVisitedPoints(vector<POI> &points, vector<POI> &pointsToVisit,GraphViewer &gv){
	for(unsigned int i = 0; i < points.size(); i++){
		for(unsigned int j = 0; j< pointsToVisit.size(); j++){
			if(points[i].getName() == pointsToVisit[j].getName() && points[i].getVisit() == false){
				points[i].setVisit(true);
				gv.setVertexColor(i,"green");
			}
		}
	}
	gv.rearrange();
}

void newPassenger(vector<Passenger> &passengers, vector<POI> &points, vector<POI> &pointsToVisit, GraphViewer &gv){
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
			if(points[i].getName() == poi ){
				POI newPoi(poi,true);
				pois.push_back(newPoi);
				pointsToVisit.push_back(newPoi);
				gv.setVertexColor(i,"green");
				gv.rearrange();
			}
		}
	}

	Passenger newPass(name,pois);
	passengers.push_back(newPass);
}

void currentPassengers(vector<Passenger> &passengers){
	cout <<"Passageiros existentes: " ;
	for(unsigned int i= 0; i < passengers.size(); i++){
		cout << passengers[i].getName() << "; ";
	}
	cout << endl;
}

void currentPOI(vector<POI> &points){
	cout << "POI existentes: " ;
	for(unsigned int i = 0; i <points.size(); i++){
		cout << points[i].getName() << "; ";
	}
	cout << endl;
}

void visitPoints(vector<POI> &points){
	for(unsigned int i = 0; i < points.size(); i++){
		if(points[i].getVisit() == true){
			cout << points[i].getName() << " ";
		}
	}
	cout << endl;
}

void shortestPath(vector<POI> &pointsToVisit, vector<POI> &points, Graph &graph) {

	vector<POI> tmp= pointsToVisit;
	int distTotal=0;

	graph.dijkstraShortestPath(points[0]); //ponto inicial : Aliados

	cout << "O caminho percorrido será";

	while (!tmp.empty()) {
		int j;
		POI minPOI;
		double distMin = 10000;
		for (unsigned int i = 0; i < tmp.size(); i++) {
			if (graph.getVertex(tmp[i])->getDist() < distMin) {
				distMin = graph.getVertex(tmp[i])->getDist();
				minPOI = tmp[i];

				j = i;
			}
		}

		cout<< "; " << graph.getVertex(tmp[j])->getInfo();
		distTotal+=distMin;
		graph.dijkstraShortestPath(tmp[j]);
		tmp.erase(tmp.begin() + j);
	}

	cout<< ".\nA distancia percorrida é " << distTotal << "km." << endl;
}

void createGraphViewer(GraphViewer &gv){
	gv.setBackground("map.png");
	gv.createWindow(810,779);
	gv.defineEdgeColor("black");
	gv.defineVertexColor("blue");
	gv.rearrange();
}

int menus(vector<Passenger> &passengers, vector<POI> &points, vector<POI> &pointsToVisit, Graph &graph,GraphViewer &gv){
	int next;
	cout << "O que deseja fazer?" << endl;
	cout << " 1- Acrescentar passageiros." << endl;
	cout << " 2- Ver passageiros existentes." << endl;
	cout << " 3- Ver Pontos de Interesse existentes." << endl;
	cout << " 4- Ver Pontos de Interesse a visitar." << endl;
	cout << " 5- Calcular caminho mais curto." << endl;
	cout << " 9- Sair." << endl;
	cin >> next;

	if(next ==1) newPassenger(passengers,points,pointsToVisit,gv);
	if(next ==2) currentPassengers(passengers);
	if(next ==3) currentPOI(points);
	if(next ==4) visitPoints(pointsToVisit);
	if(next ==5) shortestPath(pointsToVisit,points, graph);
	if(next ==9) return -1;

}

int main() {
	Bus bus = Bus();
	Graph graph = Graph();
	POI poi = POI();
	Passenger passenger = Passenger();
	GraphViewer *gv = new GraphViewer(600,600,false);
	vector<Passenger> passengers;
	vector<POI> points;
	vector<POI> pointsToVisit;

	createGraphViewer(*gv);
	readPointsOfInterest(points, graph, *gv);
	readDistances(graph,points,*gv);
	readUsers(pointsToVisit, passengers,*gv);
	checkVisitedPoints(points,pointsToVisit,*gv);



	do{
	}while
		(menus(passengers,points,pointsToVisit, graph,*gv)!= -1);
	cout <<"Exit!" << endl;
	exit(0);
}




