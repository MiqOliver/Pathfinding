#pragma once
#include <vector>
#include <map>
#include <queue>
#include <concurrent_priority_queue.h>
#include "Agent.h"
#include "Node.h"
#include "Path.h"

using namespace std;

class Agent;

class Algorithm {
	public:
		Algorithm();
		~Algorithm();

		static Path BFS(Node* target, Node* origin);
		static Path Dijkstra(Node* target, Node* origin);
		static Path Greedy(Node* target, Node* origin);

		static int Heuristic(Node* target, Node* actual);
};