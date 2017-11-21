#include "Algorithm.h"

Algorithm::Algorithm(){

}

Algorithm::~Algorithm(){

}

Path Algorithm::BFS(Node* target, Node* origin) {
	Path path;
	queue<Node*> frontier;
	map<Node*, Node*> came_from;
	Node* current;

	frontier.push(origin);
	came_from[origin] = origin;

	while (!frontier.empty()) {
		current = frontier.front();
		
		if (current == target) break; //Early exit

		for each(duo<Node*,float> n in current->adyacents) {
			if (!came_from[n.x]) {
				frontier.push(n.x);
				came_from[n.x] = current;
			}
		}
		frontier.pop();
	}

	current = target;
	path.points.push_back(current->position);
	while (current != origin) {
		current = came_from[current];
		path.points.push_back(current->position);
	}
	//path->points.push_back(current->position);
	reverse(path.points.begin(), path.points.end());
	
	return path;
}

Path Algorithm::Dijkstra(Node* target, Node* origin) {
	Path path;
	priority_queue<Node*> frontier;
	map<Node*, Node*> came_from;
	map<Node*, float> cost_so_far;
	Node* current;

	frontier.push(origin);
	came_from[origin] = origin;
	cost_so_far[origin] = 0.f;

	while (!frontier.empty()) {
		current = frontier.top();

		if (current == target) break; //Early exit

		for each(duo<Node*, float> n in current->adyacents) {
			int new_cost = cost_so_far[current] + n.y;
			if (!cost_so_far[n.x] || cost_so_far[n.x] > new_cost) {
				cost_so_far[n.x] = new_cost;
				frontier.emplace(n.x, cost_so_far[n.x]);
				came_from[n.x] = current;
			}
		}
		frontier.pop();
	}

	current = target;
	path.points.push_back(current->position);
	while (current != origin) {
		current = came_from[current];
		path.points.push_back(current->position);
	}
	//path->points.push_back(current->position);
	reverse(path.points.begin(), path.points.end());

	return path;
}