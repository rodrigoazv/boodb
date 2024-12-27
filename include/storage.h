// storage.h
#ifndef STORAGE_H
#define STORAGE_H

#include <fstream>
#include <string>
#include <vector>

class Storage {
public:
    explicit Storage(const std::string& filename);
    void writePage(int pageNumber, const std::vector<char>& data);
    std::vector<char> readPage(int pageNumber);
private:
    std::string filename;
    static const int PAGE_SIZE = 4096; // 4KB
};

#endif
