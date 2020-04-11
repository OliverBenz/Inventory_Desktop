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
        // TODO: Check if statement nullptr
    }
}

dbHelper::~dbHelper() {
    delete connection;
    delete statement;
}

// TODO: Dynamic array 
std::vector<std::string> dbHelper::getLocations() {
    if (statement != nullptr) {
        sql::ResultSet* res = statement->executeQuery("SELECT * FROM locations");

        std::vector<std::string> result;
        while (res->next())
            result.push_back(res->getString("name"));
        delete res;

        return result;
    }
    else {
        std::cout << "SQL error at getLocations:\t" << std::endl;
        return std::vector<std::string>();
    }
    
}

std::vector<Category> dbHelper::getCategories() {
    if(statement != nullptr){
        sql::ResultSet* res = statement->executeQuery("SELECT * FROM categories");

        std::vector<Category> cats;
        while (res->next())
            cats.push_back(Category(res->getInt("id"), res->getString("name"), res->getString("description")));
        delete res;

        return cats;
    }
    else{
        std::cout << "SQL error at getCategories:\t" << std::endl;
        return std::vector<Category>();
    }
    
}

std::vector<Item> dbHelper::getItems() {
    if (statement != nullptr) {
        sql::ResultSet* res = statement->executeQuery("SELECT * FROM items");

        std::vector<Item> items;
        while (res->next()) {
            items.push_back(Item(res->getInt("id"), res->getString("name"), res->getString("description"), res->getInt("placementId"), res->getInt("categoryId")));
        }
        delete res;

        return items;
    }
    else {
        std::cout << "SQL error at getCategories:\t" << std::endl;
        return std::vector<Item>();
    }
}

void dbHelper::pushItem(Item i) {
    if (statement != nullptr) {
        try {
            sql::ResultSet* res = statement->executeQuery("INSERT INTO items VALUES (0, \"" + i.getName() + "\", \"" + i.getDescription() + "\", " + std::to_string(i.getPlacementId()) + ", " + std::to_string(i.getCategoryId()) + ");");
        }
        catch (sql::SQLException & e) {
            std::cout << "SQL Error at pushItem:\t" << e.what() << std::endl;
        }
    }
    else {
        std::cout << "SQL error inserting Item" << std::endl;
    }
}