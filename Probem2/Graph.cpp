//============================================================================
// Name        : Graph.cpp
// Description : Graph ADT implementation using an
//               array of lists from STL 
//============================================================================

#include "pch.h"

#include <iostream>
#include "Graph.h"


Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];

}

Graph::~Graph() {
	delete [] adj;
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.

}
bool Graph::isEdge(int v, int w){

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	        if (w == *i) return (true);

	return (false);
}


int Graph::getNumNodes() {

	return V;

}

void Graph::printGraph() {

    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex  \n"
             << v << " :";

        //loop over adj[v]
        for (auto x : adj[v])
           cout << "-> " << x;

        printf("\n");
    }
}


list<int> Graph::successors(int v) {

	list <int> v_sucessors;
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		v_sucessors.push_front(*i);

	return v_sucessors;
}

