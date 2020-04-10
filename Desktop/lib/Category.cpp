#include "Category.hpp"

Category::Category() {
	this->id = -1;
	this->name = "";
	this->description = "";
}
Category::Category(int id, std::string name, std::string description) {
	this->id = id;
	this->name = name;
	this->description = description;
}

std::string Category::getName() {
	return name;
}
std::string Category::getDescription() {
	return description;
}