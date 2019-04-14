// Probem2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Problem2.h"
#include "Graph.h"
#include <iostream>
#include <stack>
#include <queue>


using namespace std;

//Check if node is in the set, if it´s in the set it´s also a visited node
bool visitedNode(unordered_set<int> &nodeSet, int &node) {
	auto it = nodeSet.find(node);
	//Return true if node has already been visisted
	if (it != nodeSet.end()) {
		return true;
	}
	else {
		nodeSet.insert(node);
	}
	return false;
}
queue<int> bfsTraversal(Graph &g, int startVertex) {

	queue<int> queue;	
	unordered_set<int> nodeSet;	

	unordered_map<int, int> nodeMap;	
	int n;	

	queue.push(startVertex);	
	nodeMap[startVertex] = 0;	

	while (!queue.empty()) { 
		n = queue.front();	
		queue.pop();	

		//Loop through all the successors from the node which is popped from the queue
		for (auto node : g.successors(n)) {		
			//If node has not been visited
			if (!(visitedNode(nodeSet, node))) {	
				queue.push(node);	

				//Add node to map and get the value of previous node and increment by one
				//this is because it calculates the length from starting node
				nodeMap[node] = (nodeMap.find(n)->second) + 1;	
			}		
		}
	}
	for (auto n : nodeMap) { //V
		//If node length is even, it is a friend
		if (n.second % 2 == 0) {	
			if (startVertex != n.first) {	
				cout << n.first << " ";	
			}
		}
	}

	cout << endl;	
	return queue;	
}

int main()
{
	
	Graph g(10); // Number of nodes
	//Node pointing at
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(2,4);
	g.addEdge(2,6);
	g.addEdge(3,5);
	g.addEdge(3,4);
	g.addEdge(5,4);
	g.addEdge(6,7);
	g.addEdge(6,9);
	g.addEdge(7,8);
	g.addEdge(8,4);
	
	

	bfsTraversal(g, 0);
}


