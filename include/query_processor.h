// query_processor.h
#ifndef QUERY_PROCESSOR_H
#define QUERY_PROCESSOR_H

#include "schema_manager.h"
#include <string>

class QueryProcessor {
public:
    explicit QueryProcessor(SchemaManager& schemaManager);
    void executeQuery(const std::string& query);
private:
    SchemaManager& schemaManager;
};

#endif
