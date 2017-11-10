#pragma once
#include <vector>
#include <queue>
#include "Agent.h"
#include "Node.h"
#include "Vector2D.h"

using namespace std;

class Agent;

class Algorithm {
	public:
		Algorithm();
		~Algorithm();

		vector<Node*> path; 
		queue<Node*> frontier; //Empty
		vector<Node*> visited; //Empty

		vector<Node*> BFS(Node target);


};