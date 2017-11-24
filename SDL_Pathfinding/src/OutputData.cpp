#include "OutputData.h"

using namespace std;

inline OutputData &OutputData::Instance() {
	static OutputData o;
	return o;
}

void OutputData::WriteData(algorithms algorithm, float time, int pathLength, int counter) {
	ofstream data("../Algorhtms_Data.txt", ios_base::app);

	data << "\n\n";

	switch (algorithm) {
	case BFS:
		data << "[BFS]\n";
		break;
	case DIJKSTRA:
		data << "[DIJKSTRA]\n";
		break;
	case GBFS:
		data << "[GBFS]\n";
		break;
	case A:
		data << "[A*]\n";
		break;
	default:
		break;
	}

	data << "Time: ";
	data << time;
	data << "\nExplored Nodes: ";
	data << counter;
	data << "\nPath Length: ";
	data << pathLength;
	data.close();	
}
