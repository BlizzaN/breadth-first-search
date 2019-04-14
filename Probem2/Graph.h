// Graph ADT class specification of a directed graph
// abstracting adjacency list representation
#pragma once

#include "pch.h"
#include <list>

using namespace std;

class Graph {

private:
	int V;    // No. of vertices

    // Pointer to an array containing
    // adjacency lists
    list<int> *adj;
	

public:
    Graph(int V);   // Constructor
	~Graph();
    // function to add an edge to graph
    void addEdge(int v, int w);

    // function to check if there is an edge in graph
    bool isEdge(int v, int w);

    // function to get number of nodes
    int getNumNodes();

    // A utility function to print the adjacency list
    // representation of graph
    void printGraph();

    // A function to return the successors of a
    // node in graph
    list<int> successors(int vertex);

};
