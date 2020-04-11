#pragma once

#include <string>
#include "Category.hpp"
#include "Placement.hpp"

class Item{
	int id;
	std::string name; // Char limit of 30!!
	std::string description;
	int placementId;
	int categoryId;

public:
	Item(int id, std::string name, std::string description, int placement, int category);

	int getId();

	void setName(std::string name);
	std::string getName();

	void setDescription(std::string description);
	std::string getDescription();

	void setPlacementId(int placementId);
	int getPlacementId();

	void setCategoryId(int categoryId);
	int getCategoryId();
};