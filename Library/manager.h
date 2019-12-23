// file manager.h
// header file for class Manager

#ifndef MANAGER_H
#define MANAGER_H

#include "bintree.h"
#include "bookfactory.h"
#include "commandfactory.h"
#include "patron.h"
#include <fstream>
#include <vector>

using namespace std;

//---------------------------------------------------------------------------
// Manager: defined as a manager equipped with many features:
//   - Holds book database, patron database as well as factories to create
//     commands or books.
//   - Executes the different commands in this class.
//   - Creates the books here.
//
// Implementation and assumptions:
//   -- This class "manages" the entire operations of the library as it has
//      access the the book database, patron database, as well as different
//      factories. This class will be responsible for actually running the many
//      different parts of the library.
//   -- We are assuming well-formed inputs however are still error-checking the
//      actual values that come through the input.
//---------------------------------------------------------------------------

class Manager {
public:
    // Constructor
    Manager();
    ~Manager();
    Manager(const Manager&);

    // Functions
    void execute(); // Execute the load patrons, books, and commands functions.
    void loadBooks(); // Loads books into the books database from input file.
    // Loads patrons into the books database from input file.
    void loadPatrons();
    // Loads commands into the books database from input file.
    void loadCommands();
    void displayBooks(); // Displays books in order decided by their genre.

private:
    BinTree db[26]; // Book database.
    BookFactory bookFactory; // factory to create books.
    CommandFactory commandFactory; // factory to create commands.
    Patron patrons[10000]; // patron database.
};

//#include "manager.cpp"

#endif //MANAGER_H
