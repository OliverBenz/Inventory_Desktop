#pragma once
#include <string>
#include <vector>

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "Category.hpp"
#include "Item.hpp"

class dbHelper{
	sql::Driver* driver = nullptr;
	sql::Connection* connection = nullptr;
	sql::Statement* statement = nullptr;

public:
	dbHelper();
	~dbHelper();

	std::vector<std::string> getLocations();
	std::vector<Category> getCategories();
	std::vector<Item> getItems();

	void pushItem(Item item);
};

