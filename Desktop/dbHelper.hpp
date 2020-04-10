#pragma once
#include <string>
#include <vector>

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "lib/Category.hpp"
#include "lib/Item.hpp"

class dbHelper{
	sql::Driver* driver = nullptr;
	sql::Connection* connection = nullptr;
	sql::Statement* statement = nullptr;

public:
	dbHelper();
	~dbHelper();

	std::vector<std::string> getLocations();
	std::vector<Category> getCategories();
};

