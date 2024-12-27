// storage.cpp
#include "storage.h"

Storage::Storage(const std::string& filename) : filename(filename) {
    std::ofstream file(filename, std::ios::binary | std::ios::app);
    file.close();
}

void Storage::writePage(int pageNumber, const std::vector<char>& data) {
    std::fstream file(filename, std::ios::binary | std::ios::in | std::ios::out);
    file.seekp(pageNumber * PAGE_SIZE);
    std::vector<char> page(data);
    page.resize(PAGE_SIZE, 0); // Fill to 4KB
    file.write(page.data(), PAGE_SIZE);
    file.close();
}

std::vector<char> Storage::readPage(int pageNumber) {
    std::ifstream file(filename, std::ios::binary);
    file.seekg(pageNumber * PAGE_SIZE);
    std::vector<char> page(PAGE_SIZE, 0);
    file.read(page.data(), PAGE_SIZE);
    file.close();
    return page;
}
