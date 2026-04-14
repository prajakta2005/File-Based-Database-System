// record.h
#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <iostream>

struct Record {
    int id;
    std::string name;
    std::string data;

    void display() const {
        std::cout << "ID: " << id 
                  << " | Name: " << name 
                  << " | Data: " << data << "\n";
    }
};

#endif