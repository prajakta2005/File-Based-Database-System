# Smart File-Based Database System (C++)

## Overview
This project is a lightweight file-based database system implemented in C++ to simulate core database functionalities without relying on external DBMS software. It demonstrates how structured data can be stored, indexed, and retrieved efficiently using low-level file handling and in-memory data structures.

The system supports essential CRUD operations along with optimized search capabilities using hashing and flexible query-like features.

---

## Objectives
- To understand internal working principles of database systems
- To implement efficient data storage using file handling
- To design fast lookup mechanisms using indexing
- To apply object-oriented design for modular architecture

---

## Features

### Core Functionality
- **Insert** new records  
- **Delete** existing records  
- **Update** record details  
- **Display** all records  

### Search Capabilities
- **Fast ID-based search** using hashing (O(1) average complexity)  
- **Partial name-based search** using substring matching  

### System Design
- Modular architecture using OOP principles  
- Separation of concerns:
  - File handling layer  
  - Indexing layer  
  - Database logic layer  

### Data Persistence
- Records stored in a text file using structured formatting  
- Automatic synchronization between in-memory data and file storage  

---

## Technical Implementation

### Data Structures Used
- `std::vector` for in-memory record storage  
- `std::unordered_map` for indexing (ID → position mapping)  

### File Handling
- `std::fstream` for persistent storage  
- Append mode for insertion  
- Full rewrite strategy for update/delete operations  

### Indexing Strategy
- Hash-based indexing for constant-time lookup  
- Rebuilt after structural modifications  

---

## Time Complexity Analysis

| Operation            | Complexity |
|---------------------|-----------|
| Insert              | O(1)      |
| Search (by ID)      | O(1) avg  |
| Search (by Name)    | O(n)      |
| Delete              | O(n)      |
| Update              | O(n)      |

---

## Project Structure

├── main.cpp
├── database.h / database.cpp
├── filehandler.h / filehandler.cpp
├── indexmanager.h / indexmanager.cpp
├── record.h
└── database.txt

---

## How to Run
Compile
g++ main.cpp database.cpp filehandler.cpp indexmanager.cpp -o app
Execute
./app


