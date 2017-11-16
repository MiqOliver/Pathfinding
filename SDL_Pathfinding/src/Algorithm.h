#pragma once
#include <vector>
#include <queue>
#include "Agent.h"
#include "Node.h"
#include "Vector2D.h"
#include "Path.h"

using namespace std;

class Agent;

class Algorithm {
	public:
		Algorithm();
		~Algorithm();

		Path* path; 

		void BFS(Node*, Node*, Algorithm);


};