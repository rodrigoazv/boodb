// schema_manager.h
#ifndef SCHEMA_MANAGER_H
#define SCHEMA_MANAGER_H

#include <string>
#include <vector>
#include <unordered_map>

struct TableSchema {
    std::string tableName;
    std::vector<std::string> columns;
};

class SchemaManager {
public:
    void createTable(const std::string& name, const std::vector<std::string>& columns);
    const TableSchema& getTable(const std::string& name) const;
private:
    std::unordered_map<std::string, TableSchema> tables;
};

#endif
