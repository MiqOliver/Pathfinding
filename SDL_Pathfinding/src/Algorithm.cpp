#include "Algorithm.h"

#pragma region Algorithms

Path Algorithm::BFS(Node* target, Node* origin, int* count) {
	Path path;
	queue<Node*> frontier;
	unordered_map<Node*, Node*> came_from;
	
	frontier.push(origin);
	came_from[origin] = origin;

	while (!frontier.empty()) {
		Node* current = frontier.front();
		*count += 1;
		
		if (current == target) {
			while (current != origin) {
				path.points.push_back(current->position);
				current = came_from[current];
			}
			path.points.push_back(current->position);
			reverse(path.points.begin(), path.points.end());
			while (frontier.size()) {
				frontier.pop();
			}
			return path;
		}

		for each(Node* n in current->adyacents) {
			if (!came_from[n]) {
				frontier.push(n);
				came_from[n] = current;
			}
		}
		frontier.pop();
	}
		
	came_from.clear();

	return path;
}


Path Algorithm::Dijkstra(Node* target, Node* origin, int* count) {
	Path path;
	priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, CompareNodesByTerrain> frontier;
	unordered_map<Node*, Node*> came_from;
	unordered_map<Node*, int> cost_so_far;

	frontier.emplace(make_pair(0, origin));
	came_from[origin] = nullptr;
	cost_so_far[origin] = 0;

	while (frontier.size()) {
		Node* current = frontier.top().second;
		*count += 1;

		if (current == target) {
			while (current != origin) {
				path.points.push_back(current->position);
				current = came_from[current];
			}
			path.points.push_back(current->position);
			reverse(path.points.begin(), path.points.end());
			while (frontier.size()) {
				frontier.pop();
			}
			return path;
		}

		for each(Node* n in current->adyacents) {
			int new_cost = cost_so_far[current] + n->terrain;
			if (!cost_so_far[n] || new_cost < cost_so_far[n]) {
				came_from[n] = current;
				cost_so_far[n] = new_cost;
				frontier.emplace(new_cost, n);
			}
		}
		frontier.pop();
	}

	return path;
}


Path Algorithm::Greedy(Node* target, Node* origin, int* count) {
	Path path;
	priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, CompareNodesByTerrain> frontier;
	unordered_map<Node*, Node*> came_from;

	frontier.emplace(make_pair(0, origin));
	came_from[origin] = nullptr;

	while (!frontier.empty()) {
		Node* current = frontier.top().second;
		*count += 1;

		if (current == target) {
			while (current != origin) {
				path.points.push_back(current->position);
				current = came_from[current];
			}
			path.points.push_back(current->position);
			reverse(path.points.begin(), path.points.end());
			while (frontier.size()) {
				frontier.pop();
			}
			return path;
		}

		frontier.pop();

		for each(Node* n in current->adyacents) {

			if (!came_from[n]) {
				int priority = Heuristic(target, n);
				frontier.emplace(make_pair(priority, n));
				came_from[n] = current;
			}
		}
	}

	return path;
}


Path Algorithm::AStar(Node* target, Node* origin, int* count) {
	Path path;
	priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, CompareNodesByTerrain> frontier;
	unordered_map<Node*, Node*> came_from;
	unordered_map<Node*, int> cost_so_far;

	frontier.emplace(make_pair(0, origin));
	came_from[origin] = nullptr;
	cost_so_far[origin] = 0;

	while (frontier.size()) {
		Node* current = frontier.top().second;
		*count += 1;

		if (current == target) {
			while (current != origin) {
				path.points.push_back(current->position);
				current = came_from[current];
			}
			path.points.push_back(current->position);
			reverse(path.points.begin(), path.points.end());
			while (frontier.size()) {
				frontier.pop();
			}
			return path;
		}

		for each(Node* n in current->adyacents) {
			int new_cost = cost_so_far[current] + n->terrain;
			if (!cost_so_far[n] || new_cost < cost_so_far[n]) {
				cost_so_far[n] = new_cost;
				int priority = new_cost + Heuristic(target, n);
				frontier.emplace(priority, n);
				came_from[n] = current;
			}
		}
		frontier.pop();
	}

	return path;
}


Path Algorithm::MultipleTargets(vector<Node*> targets, Node* origin, int* count) {
	Path path;
	vector<Node*> targetsLeft = targets;
	Node* start = origin;
	

	for (int i = 0; i < targets.size(); i++) {
		Node* bestTarget = targetsLeft[0];
		float bestCost = Heuristic(targetsLeft[0], start);
		int index = 0;

		for (int j = 0; j < targetsLeft.size(); j++) {
			float cost = Heuristic(targetsLeft[j], start);
			if (cost < bestCost) {
				bestCost = cost;
				bestTarget = targetsLeft[j];
				index = j;
			}
		}

		Path newPath = AStar(start, bestTarget, count);
		path.points.insert(path.points.end(), newPath.points.begin(), newPath.points.end());
		start = bestTarget;
		targetsLeft.erase(targetsLeft.begin() + index);
	}

	return path;
}

#pragma endregion


inline int Algorithm::Heuristic(Node* target, Node* actual) {
	int x = (abs(target->position.x - SRC_WIDTH/2) - abs(target->position.x - SRC_WIDTH/2))/CELL_SIZE;
	int y = abs(target->position.y - actual->position.y)/CELL_SIZE;
	return x+y;
}

inline Algorithm &Algorithm::Instance() {
	static Algorithm a;
	return a;
}
