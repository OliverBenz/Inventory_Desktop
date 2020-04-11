#pragma once

#include <string>

class Placement{
	int id;
	std::string location;
	std::string name;
	std::string description;

public:
	Placement(int id, std::string location, std::string name, std::string description);
};

