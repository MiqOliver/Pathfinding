#pragma once
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <concurrent_priority_queue.h>
#include "Agent.h"
#include "Node.h"
#include "Path.h"

using namespace std;

#define ALGORITHM Algorithm::Instance()

class Algorithm {
private:
	Algorithm() = default;
	Algorithm(const Algorithm &rhs) = delete;
	Algorithm &operator=(const Algorithm &rhs) = delete;

	static inline float Heuristic(Node* target, Node* actual);

public:
	inline static Algorithm &Instance(void);

	static Path BFS(Node* target, Node* origin);
	static Path Dijkstra(Node* target, Node* origin);
	static Path Greedy(Node* target, Node* origin);
	static Path AStar(Node* target, Node* origin);
};