#include "database.h"
#include <iostream>
#include <limits>

int main() {
    Database db("database.txt");
    int choice;

    while (true) {
        std::cout << "\n===== File-Based Database =====\n";
        std::cout << "1. Insert Record\n";
        std::cout << "2. Delete Record\n";
        std::cout << "3. Update Record\n";
        std::cout << "4. Search by ID\n";
        std::cout << "5. Display All Records\n";
        std::cout << "6. Search by Name\n"; // 🔥 NEW
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input.\n";
            continue;
        }

        if (choice == 0) break;

        if (choice == 1) {
            Record r;
            std::cout << "Enter ID: ";    std::cin >> r.id;
            std::cin.ignore();
            std::cout << "Enter Name: ";  std::getline(std::cin, r.name);
            std::cout << "Enter Data: ";  std::getline(std::cin, r.data);
            db.insert(r);
        }
        else if (choice == 2) {
            int id;
            std::cout << "Enter ID to delete: "; std::cin >> id;
            db.deleteRecord(id);
        }
        else if (choice == 3) {
            int id; std::string name, data;
            std::cout << "Enter ID to update: "; std::cin >> id;
            std::cin.ignore();
            std::cout << "New Name: "; std::getline(std::cin, name);
            std::cout << "New Data: "; std::getline(std::cin, data);
            db.update(id, name, data);
        }
        else if (choice == 4) {
            int id;
            std::cout << "Enter ID to search: "; std::cin >> id;
            db.search(id);
        }
        else if (choice == 5) {
            db.displayAll();
        }
        else if (choice == 6) {  // 🔥 NEW FEATURE
            std::string name;
            std::cin.ignore();
            std::cout << "Enter name to search: ";
            std::getline(std::cin, name);
            db.searchByName(name);
        }
        else {
            std::cout << "Invalid choice.\n";
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}