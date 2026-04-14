// indexmanager.h
#ifndef INDEXMANAGER_H
#define INDEXMANAGER_H

#include <unordered_map>
#include <vector>
#include "record.h"

class IndexManager {
private:
    std::unordered_map<int, int> index; // id → position in vector

public:
    void buildIndex(const std::vector<Record>& records);
    void addToIndex(int id, int position);
    void removeFromIndex(int id);
    int  getPosition(int id);   // returns -1 if not found
    bool exists(int id);
};

#endif