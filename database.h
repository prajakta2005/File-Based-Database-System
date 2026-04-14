#ifndef DATABASE_H
#define DATABASE_H

#include "filehandler.h"
#include "indexmanager.h"
#include <vector>

class Database {
private:
    FileHandler    fileHandler;
    IndexManager   indexManager;
    std::vector<Record> records;  // in-memory cache

    void syncIndex();

public:
    Database(const std::string& filename);

    void insert(const Record& r);
    void deleteRecord(int id);
    void update(int id, const std::string& newName, const std::string& newData);
    void search(int id);
    void searchByName(const std::string& name);

    void displayAll();
};

#endif