
#include <iostream>
#include "storage.h"
#include "schema_manager.h"
#include "query_processor.h"

int main() {
    SchemaManager schemaManager;
    QueryProcessor queryProcessor(schemaManager);

    // Exemplo: Criando uma tabela
    queryProcessor.executeQuery("CREATE users id name age");

    // Exemplo: Manipulando páginas
    Storage storage("database.data");
    storage.writePage(0, {'H', 'e', 'l', 'l', 'o'});
    auto data = storage.readPage(0);

    std::cout << "Read from storage: " << std::string(data.begin(), data.end()) << "\n";

    return 0;
}
