#pragma once
#include "pch.h"

#include "Graph.h"
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <queue>
class Problem2 {
private:
	void printList(queue<int> l);
	bool isNodeInQueue(queue<int> &q, int v);
	//bool isNodeInStack(stack <int> s, int v);
	queue<int> bfsTraversal(Graph g, int startVertex);
	bool visitedNode(unordered_set<int> &nodeSet, int node);

};