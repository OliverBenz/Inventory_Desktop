#include "Item.hpp"

Item::Item(int id, std::string name, std::string description, int placementId, int categoryId){
	this->id = id;
	this->name = name;
	this->description = description;
	this->placementId = placementId;
	this->categoryId = categoryId;
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

void Item::setPlacementId(int id) {
	if (id > 0) this->placementId = id;
}
int Item::getPlacementId() {
	return placementId;
}

void Item::setCategoryId(int id) {
	if (id > 0) this->categoryId = id;
}
int Item::getCategoryId() {
	return categoryId;
}