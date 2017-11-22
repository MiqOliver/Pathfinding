#include "Algorithm.h"

#pragma region Algorithms

Path Algorithm::BFS(Node* target, Node* origin) {
	Path path;
	queue<Node*> frontier;
	unordered_map<Node*, Node*> came_from;
	
	frontier.push(origin);
	came_from[origin] = origin;

	while (!frontier.empty()) {
		Node* current = frontier.front();
		
		if (current == target) {
			while (current != origin) {
				path.points.push_back(current->position);
				current = came_from[current];
			}
			path.points.push_back(current->position);
			std::reverse(path.points.begin(), path.points.end());
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


Path Algorithm::Dijkstra(Node* target, Node* origin) {
	Path path;
	priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, CompareNodesByTerrain> frontier;
	unordered_map<Node*, Node*> came_from;
	unordered_map<Node*, int> cost_so_far;

	visited.clear();

	frontier.emplace(std::make_pair(0, origin));
	came_from[origin] = nullptr;
	cost_so_far[origin] = 0;

	while (frontier.size()) {
		Node* current = frontier.top().second;

		if (current == target) {
			while (current != origin) {
				path.points.push_back(current->position);
				current = came_from[current];
			}
			path.points.push_back(current->position);
			std::reverse(path.points.begin(), path.points.end());
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
		visited.push_back(*current);
		frontier.pop();
	}

	return path;
}


Path Algorithm::Greedy(Node* target, Node* origin) {
	Path path;
	priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, CompareNodesByTerrain> frontier;
	unordered_map<Node*, Node*> came_from;

	frontier.emplace(0, origin);
	came_from[origin] = nullptr;

	while (!frontier.empty()) {
		Node* current = frontier.top().second;

		if (current == target) {
			while (current != origin) {
				path.points.push_back(current->position);
				current = came_from[current];
			}
			path.points.push_back(current->position);
			std::reverse(path.points.begin(), path.points.end());
			while (frontier.size()) {
				frontier.pop();
			}
			return path;
		}

		for each(Node* n in current->adyacents) {
			if (!came_from[n]) {
				came_from[n] = current;
				float priority = Heuristic(target, n);
				frontier.emplace(priority, n);
			}
		}
		frontier.pop();
	}
	
	return path;
}

#pragma endregion


inline float Algorithm::Heuristic(Node* target, Node* actual) {
	return abs(target->position.x - actual->position.x) + abs(target->position.y - actual->position.y);
}

inline Algorithm &Algorithm::Instance() {
	static Algorithm a;
	return a;
}

//inline vector<Node> Algorithm::GetVisited() {
//	return visited;
//}