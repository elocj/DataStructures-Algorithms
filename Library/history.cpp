// file history.cpp
// Member function definitions for class History

#include "history.h"
#include "patron.h"

// ---------------------------------------------------------------------------
// Constructor
// Constructs an empty History class.

History::History() {
    command = "History";
    valid = true;
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for this History object.

History::~History() {

}

// ---------------------------------------------------------------------------
// Copy constructor
// Pre: Takes in a History object.
// Post: Copies over this History object with the object passed in.

History::History(const History& hist) {

}

// ---------------------------------------------------------------------------
// setData
// Pre: Takes in a istream object, and BinTree database saturated with all of
//      the books the library holds.
// Post: Reads through the passed in istream object to create a book, search
//       for the book in the database, and then assign it to the NodeData
//       object data member of History. During this whole process error
//       is also happening for erroneous information.

void History::setData(int id, istream& infile, BinTree db[], Patron patrons[]) {
//    valid = false;
}

// ---------------------------------------------------------------------------
// create
// Returns a copy of History for the command factory to use.

Command* History::create() {
    return new History();
}

// ---------------------------------------------------------------------------
// display
// Displays the command information.

void History::display() const {

}

// ---------------------------------------------------------------------------
// getBool
// This boolean keeps track of if an error was detected so that proper memory
// deletion can occur.

bool History::getBool() const {
    return valid;
}

// ---------------------------------------------------------------------------
// run
// Pre: Takes in a patron id as well as patron list.
// Post: Run performs the primary function of History which is display the
//       history of the patron passed in.

void History::run(int id, Patron patrons[]) {
    patrons[id].printHistory();
    valid = false;
}