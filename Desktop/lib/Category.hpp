#pragma once

#include <string>

class Category{
	int id;
	std::string name;
	std::string description;

public:
	Category();
	Category(int id, std::string name, std::string description);

	std::string getName();
	std::string getDescription();
};

