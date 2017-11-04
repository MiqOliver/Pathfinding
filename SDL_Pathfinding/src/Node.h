#pragma once
#include "Vector2D.h"
#include <vector>

template<class T1, class T2>
struct duo {
	T1 x;
	T2 y;
	duo(T1 _x, T2 _y) : x{ _x }, y{ _y } {}
};

struct Node
{
	Vector2D position;
	std::vector<duo<Node*, float>> adyacents;
};
