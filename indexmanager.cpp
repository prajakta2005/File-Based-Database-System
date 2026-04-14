// indexmanager.cpp
#include "indexmanager.h"

void IndexManager::buildIndex(const std::vector<Record>& records) {
    index.clear();
    for (int i = 0; i < (int)records.size(); i++) {
        index[records[i].id] = i;
    }
}

void IndexManager::addToIndex(int id, int position) {
    index[id] = position;
}

void IndexManager::removeFromIndex(int id) {
    index.erase(id);
}

int IndexManager::getPosition(int id) {
    if (index.find(id) != index.end())
        return index[id];
    return -1;
}

bool IndexManager::exists(int id) {
    return index.find(id) != index.end();
}