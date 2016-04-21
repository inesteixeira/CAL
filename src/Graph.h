/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
using namespace std;

class Edge;
class Graph;

class Vertex {
	string info;
	vector<Edge> edges;
	bool visited;
	void addEdge(Vertex *dest, double w);
	bool removeEdgeTo(Vertex *d);
public:
	Vertex(string in);
	friend class Graph;
};

class Edge {
	Vertex * dest;
	double size;
public:

	Edge(Vertex *d, double w);
	Vertex *getDest() {
		return dest;
	}
	;
	friend class Graph;
	friend class Vertex;
};

class Graph {
	vector<Vertex *> vertexSet;
public:
	bool addVertex(const POI &in);
	bool addEdge(const POI &sourc, const POI &dest, double w);
	bool removeVertex(const POI &in);
	bool removeEdge(const POI &sourc, const POI &dest);
	vector<Vertex *> getVertexSet() const;
	int getNumVertex() const;
};

Vertex::Vertex(string name) :
		info(name), visited(false) {
}

void Vertex::addEdge(Vertex *dest, double w) {
	Edge newEdge(dest, w);
	edges.push_back(newEdge);
}

bool Vertex::removeEdgeTo(Vertex *d) {
	typename vector<Edge>::iterator it = edges.begin();
	typename vector<Edge>::iterator ite = edges.end();
	while (it != ite) {
		if (it->getDest() == d) {
			edges.erase(it);
			return true;
		} else
			it++;
	}
	return false;
}

Edge::Edge(Vertex *d, double w) :
		dest(d), size(w) {
}

int Graph::getNumVertex() const {
	return vertexSet.size();
}

vector<Vertex *> Graph::getVertexSet() const {
	return vertexSet;
}

bool Graph::addVertex(const POI &in) {
	typename vector<Vertex*>::iterator it = vertexSet.begin();
	typename vector<Vertex*>::iterator ite = vertexSet.end();
	for (; it != ite; it++)
		if ((*it)->info == in.getName())
			return false;
	Vertex*v1 = new Vertex(in.getName());
	vertexSet.push_back(v1);
	return true;
}

bool Graph::removeVertex(const POI &in) {
	typename vector<Vertex*>::iterator it = vertexSet.begin();
	typename vector<Vertex*>::iterator ite = vertexSet.end();
	for (; it != ite; it++) {
		if ((*it)->info == in.getName()) {
			Vertex * v = *it;
			vertexSet.erase(it);
			typename vector<Vertex*>::iterator it1 = vertexSet.begin();
			typename vector<Vertex*>::iterator it1e = vertexSet.end();
			for (; it1 != it1e; it1++) {
				(*it1)->removeEdgeTo(v);
			}
			delete v;
			return true;
		}
	}
	return false;
}

bool Graph::addEdge(const POI &sourc, const POI &dest, double w) {
	typename vector<Vertex*>::iterator it = vertexSet.begin();
	typename vector<Vertex*>::iterator ite = vertexSet.end();
	int found = 0;
	Vertex *vS, *vD;
	while (found != 2 && it != ite) {
		if ((*it)->info == sourc.getName()) {
			vS = *it;
			found++;
		}
		if ((*it)->info == dest.getName()) {
			vD = *it;
			found++;
		}
		it++;
	}
	if (found != 2)
		return false;
	vS->addEdge(vD, w);
	return true;
}

bool Graph::removeEdge(const POI &sourc, const POI &dest) {
	typename vector<Vertex*>::iterator it = vertexSet.begin();
	typename vector<Vertex*>::iterator ite = vertexSet.end();
	int found = 0;
	Vertex *vS, *vD;
	while (found != 2 && it != ite) {
		if ((*it)->info == sourc.getName()) {
			vS = *it;
			found++;
		}
		if ((*it)->info == dest.getName()) {
			vD = *it;
			found++;
		}
		it++;
	}
	if (found != 2)
		return false;
	return vS->removeEdgeTo(vD);
}

#endif /* GRAPH_H_ */
