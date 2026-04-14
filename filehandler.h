// filehandler.h
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "record.h"
#include <fstream>
#include <vector>
#include <string>

class FileHandler {
private:
    std::string filename;

public:
    FileHandler(const std::string& fname);

    void writeRecord(const Record& r);
    std::vector<Record> readAll();
    void rewriteFile(const std::vector<Record>& records);
    bool fileExists();
};

#endif