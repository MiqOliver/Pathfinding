#pragma once
#include <iostream>
#include <fstream>
#include "Agent.h"
#include "Node.h"
#include "Path.h"

#define Output OutputData::Instance()

class OutputData
{
private:
	OutputData() = default;
	OutputData(const OutputData &rhs) = delete;
	OutputData &operator=(const OutputData &rhs) = delete;

public:
	static inline OutputData &Instance(void);

	static void WriteData(algorithms algorithm, float time, int pathLength, int counter);
};

