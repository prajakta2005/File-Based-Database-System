#include "database.h"
#include <iostream>

Database::Database(const std::string& filename) : fileHandler(filename) {
    records = fileHandler.readAll();
    indexManager.buildIndex(records);
}

void Database::syncIndex() {
    indexManager.buildIndex(records);
}

void Database::insert(const Record& r) {
    if (indexManager.exists(r.id)) {
        std::cout << "Error: Record with ID " << r.id << " already exists.\n";
        return;
    }
    records.push_back(r);
    fileHandler.writeRecord(r);
    indexManager.addToIndex(r.id, records.size() - 1);
    std::cout << "Record inserted successfully.\n";
}

void Database::deleteRecord(int id) {
    int pos = indexManager.getPosition(id);
    if (pos == -1) {
        std::cout << "Error: Record with ID " << id << " not found.\n";
        return;
    }
    records.erase(records.begin() + pos);
    fileHandler.rewriteFile(records);
    syncIndex();
    std::cout << "Record deleted successfully.\n";
}

void Database::update(int id, const std::string& newName, const std::string& newData) {
    int pos = indexManager.getPosition(id);
    if (pos == -1) {
        std::cout << "Error: Record with ID " << id << " not found.\n";
        return;
    }
    records[pos].name = newName;
    records[pos].data = newData;
    fileHandler.rewriteFile(records);
    syncIndex(); // 🔥 safer
    std::cout << "Record updated successfully.\n";
}

void Database::search(int id) {
    int pos = indexManager.getPosition(id);
    if (pos == -1) {
        std::cout << "Record with ID " << id << " not found.\n";
        return;
    }
    records[pos].display();
}

// 🔥 NEW FEATURE: Search by Name (Partial Match)
void Database::searchByName(const std::string& name) {
    bool found = false;

    for (const auto& r : records) {
        if (r.name.find(name) != std::string::npos) {
            r.display();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No records found with name containing \"" << name << "\"\n";
    }
}

void Database::displayAll() {
    if (records.empty()) {
        std::cout << "Database is empty.\n";
        return;
    }
    std::cout << "\n--- All Records ---\n";
    for (const auto& r : records) r.display();
    std::cout << "-------------------\n";
}