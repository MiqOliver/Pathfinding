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

	//reset
	//while (!frontier.empty()) 
	//	frontier.pop();
	//if (!came_from.empty())
	//	came_from.clear();


	frontier.push(origin);
	came_from[origin] = origin;

	while (!frontier.empty()) {
		current = frontier.front();
		
		if (current == target) break; //Early exit

		for each(duo<Node*,int> n in current->adyacents) {
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
	
	came_from.clear();

	return path;
}


Path Algorithm::Dijkstra(Node* target, Node* origin) {
	Path path;
	priority_queue<Node*, vector<Node*>, CompareNodesByTerrain> frontier;
	//priority_queue<Node> frontier;
	map<Node*, Node*> came_from;
	map<Node*, int> cost_so_far;
	Node* current;

	frontier.push(origin);
	came_from[origin] = origin;
	cost_so_far[origin] = 0;

	while (!frontier.empty()) {
		current = frontier.top();

		//if (current == target) 
		//	break; //Early exit

		for each(duo<Node*, int> n in current->adyacents) {
			int new_cost = cost_so_far[current] + n.y;
			if (!cost_so_far[n.x] || new_cost < cost_so_far[n.x]) {
				frontier.push(n.x);
				came_from[n.x] = current;
				cost_so_far[n.x] = new_cost;
			}
		}
		frontier.pop();
	}

	current = target;
	path.points.push_back(current->position);
	while (current != origin) {
		current = came_from[current];
		if (current == nullptr) //AQUI ESTA L'ERROR
			break;
		path.points.push_back(current->position);
	}
	reverse(path.points.begin(), path.points.end());

	came_from.clear();
	cost_so_far.clear();

	return path;
}

/*

Path Algorithm::Dijkstra(Node* target, Node* origin) {
Path path;
priority_queue<Node, vector<Node>, CompareNodesByTerrain> frontier;
//priority_queue<Node> frontier;
map<Node*, Node*> came_from;
map<Node*, int> cost_so_far;
Node* current;
Node aux;

frontier.push(*origin);
came_from[origin] = origin;
cost_so_far[origin] = 0;

aux = frontier.top();

while (!frontier.empty()) {
current = &aux;
if (current == target)
break; //Early exit

for each(duo<Node*, int> n in current->adyacents) {
int new_cost = cost_so_far[current] + n.y;
if (!cost_so_far[n.x] || cost_so_far[n.x] > new_cost) {
frontier.push(*n.x);
came_from[n.x] = current;
cost_so_far[n.x] = new_cost;
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
reverse(path.points.begin(), path.points.end());

came_from.clear();
cost_so_far.clear();

return path;
}


*/

