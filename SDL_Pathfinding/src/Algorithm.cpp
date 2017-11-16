#include "Algorithm.h"

Algorithm::Algorithm(){

}

Algorithm::~Algorithm(){

}

Path* Algorithm::BFS(Node* target, Node* origin) {
	Path* path = new Path();
	queue<Node> frontier;
	map<Node*, Node*> came_from;
	Node* current = &NullNode;

	frontier.push(*origin);
	came_from[origin] = &NullNode;

	while (!frontier.empty()) {
		current = &frontier.front();
		frontier.pop();
		
		if (current == target) break;

		for each(duo<Node*,float> n in current->adyacents) {
			if (!came_from[n.x]) {
				frontier.push(*n.x);
				came_from[n.x] = current;

				
				draw_circle(TheApp::Instance()->getRenderer(), n.x->position.x, n.x->position.y, CELL_SIZE / 2, 255, 50, 50, 255);
			}
		}
	}

	current = target;
	path->points.push_back(current->position);
	while (current != origin) {
		current = came_from[current];
		path->points.push_back(current->position);
	}
	//path->points.push_back(current->position);
	reverse(path->points.begin(), path->points.end());
	
	return path;
}