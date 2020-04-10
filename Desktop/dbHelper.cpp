#include "dbHelper.hpp"

dbHelper::dbHelper() {
    try {
        // Create a connection
        driver = get_driver_instance();
        connection = driver->connect("tcp://127.0.0.1:3306", "root", "");

        // Connect to the MySQL test database
        connection->setSchema("inventory");

        statement = connection->createStatement();
    }
    catch (sql::SQLException & e) {
        // Throw error
    }
}

dbHelper::~dbHelper() {
    delete connection;
    delete statement;
}

// TODO: Dynamic array 
std::vector<std::string> dbHelper::getLocations() {
    sql::ResultSet* res = statement->executeQuery("SELECT * FROM locations");
    
    std::vector<std::string> result;
    while (res->next()) 
        result.push_back(res->getString("name"));
    delete res;
    
    return result;
}

std::vector<Category> dbHelper::getCategories() {
    sql::ResultSet* res = statement->executeQuery("SELECT * FROM categories");

    std::vector<Category> cats;
    while (res->next())
        cats.push_back(Category(res->getInt("id"), res->getString("name"), res->getString("description")));
    delete res;

    return cats;
}