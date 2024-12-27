// query_processor.cpp
#include "query_processor.h"
#include <iostream>
#include <sstream>

QueryProcessor::QueryProcessor(SchemaManager& schemaManager) : schemaManager(schemaManager) {}

void QueryProcessor::executeQuery(const std::string& query) {
    std::istringstream iss(query);
    std::string command;
    iss >> command;

    if (command == "CREATE") {
        std::string tableName;
        iss >> tableName;

        std::vector<std::string> columns;
        std::string column;
        while (iss >> column) {
            columns.push_back(column);
        }

        schemaManager.createTable(tableName, columns);
        std::cout << "Table " << tableName << " created.\n";
    } else {
        std::cout << "Unknown command.\n";
    }
}
