#include "Item.hpp"

Item::Item(int id, std::string name, std::string description, int placement, int category){
	this->id = id;
	this->name = name;
	this->description = description;
	this->placementId = placement;
	this->categoryId = category;
}

int Item::getId() {
	return id;
}

void Item::setName(std::string name) {
	if(name.length() > 0 && name.length() <= 30)
		this->name = name;
}
std::string Item::getName() {
	return name;
}

void Item::setDescription(std::string description) {
	this->description = description;
}
std::string Item::getDescription() {
	return description;
}

void Item::setPlacementId(int placement) {
	this->placementId = placement;
}
int Item::getPlacementId() {
	return placementId;
}

void Item::setCategoryId(int category) {
	this->categoryId = category;
}
int Item::getCategoryId() {
	return categoryId;
}