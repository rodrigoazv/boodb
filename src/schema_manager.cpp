// schema_manager.cpp
#include "schema_manager.h"
#include <stdexcept>

void SchemaManager::createTable(const std::string& name, const std::vector<std::string>& columns) {
    if (tables.find(name) != tables.end()) {
        throw std::runtime_error("Table already exists!");
    }
    tables[name] = {name, columns};
}

const TableSchema& SchemaManager::getTable(const std::string& name) const {
    auto it = tables.find(name);
    if (it == tables.end()) {
        throw std::runtime_error("Table not found!");
    }
    return it->second;
}
