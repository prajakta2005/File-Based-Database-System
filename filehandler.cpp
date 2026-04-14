// filehandler.cpp
#include "filehandler.h"
#include <sstream>

FileHandler::FileHandler(const std::string& fname) : filename(fname) {}

bool FileHandler::fileExists() {
    std::ifstream f(filename);
    return f.good();
}

void FileHandler::writeRecord(const Record& r) {
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        std::cerr << "Error opening file for write.\n";
        return;
    }
    file << r.id << "|" << r.name << "|" << r.data << "\n";
}

std::vector<Record> FileHandler::readAll() {
    std::vector<Record> records;
    std::ifstream file(filename);
    if (!file) return records;

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string idStr, name, data;
        std::getline(ss, idStr, '|');
        std::getline(ss, name,  '|');
        std::getline(ss, data,  '|');
        records.push_back({ std::stoi(idStr), name, data });
    }
    return records;
}

void FileHandler::rewriteFile(const std::vector<Record>& records) {
    std::ofstream file(filename, std::ios::trunc);
    if (!file) {
        std::cerr << "Error opening file for rewrite.\n";
        return;
    }
    for (const auto& r : records) {
        file << r.id << "|" << r.name << "|" << r.data << "\n";
    }
}