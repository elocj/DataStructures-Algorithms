//
// Created by Anthony Joo on 2019-11-29.
//

#include "return.h"
#include "patron.h"

// ---------------------------------------------------------------------------
// Constructor
// Constructs an empty Return class.

Return::Return() {
    command = "Return";
    temp = nullptr;
    valid = true;
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for this Return object.

Return::~Return() {

}

// ---------------------------------------------------------------------------
// Copy constructor
// Pre: Takes in a Return object.
// Post: Copies over this Return object with the object passed in.

Return::Return(const Return& com) {
//    media = com.media;
    command = com.command;
    temp = com.temp;
}

// ---------------------------------------------------------------------------
// setData
// Pre: Takes in a istream object, and BinTree database saturated with all of
//      the books the library holds.
// Post: Reads through the passed in istream object to create a book, search
//       for the book in the database, and then assign it to the NodeData
//       object data member of Return. During this whole process error
//       is also happening for erroneous information.

void Return::setData(int id, istream& infile, BinTree db[], Patron patrons[]) {
    char genre;
    infile.get();
    infile >> genre;
    infile.get();
    char med;
    infile >> med;
    infile.get();
    NodeData* book = bookFactory.createBook(genre, infile);
    if(book != nullptr) {
        string medi = bookFactory.getMedia(med);
        if(medi != "nullString") {
            book->setComData(infile);
            if(!db[bookFactory.getIndex(genre)].retrieve(*book, temp)) {
                cout << "--------------------------------------------------"
                        "-----------------------------" << endl;
                cout << "ERROR: " << patrons[id].getFirst() << " " <<
                patrons[id].getLast() << " tried to return '" <<
                book->getTitle() << "' - not found in catalog." << endl;
                valid = false;
            }
        } else {
            string garbage;
            getline(infile, garbage, '\n');
            valid = false;
            cout << "---------------------------------------------------"
                    "----------------------------" << endl;
            cout << "ERROR: '" << med << "' is not a good book format." << endl;
        }
    } else {
        valid = false;
        cout << "---------------------------------------------------------"
                "----------------------" << endl;
        cout << "ERROR: No such genre '" << genre << "'" << endl;
    }
    delete book;
    book = nullptr;
}

// ---------------------------------------------------------------------------
// create
// Returns a copy of Return for the command factory to use.

Command* Return::create() {
    return new Return();
}

// ---------------------------------------------------------------------------
// display
// Displays the command information.

void Return::display() const {
    cout << "  " << left << setw(10) << command;
    temp->historyDisplay();
}

// ---------------------------------------------------------------------------
// getBool
// This boolean keeps track of if an error was detected so that proper memory
// deletion can occur.

bool Return::getBool() const {
    return valid;
}

// ---------------------------------------------------------------------------
// run
// Pre: Takes in a patron id as well as patron list.
// Post: Run performs the primary function of Return which is to Return
//       a book from the library so it will increment the amount of this book
//       left in the library by 1. Error checks occur here as well.

void Return::run(int id, Patron patrons[]) {
    if(temp != nullptr) {
        if(temp->getNumAvailable() < temp->getMax()) {
            temp->returnCopy();
            patrons[id].addCommand(this);
        } else {
            cout << "--------------------------------------------------"
                    "-----------------------------" << endl;
            cout << "ERROR: Returning book that has not been checked out." <<
            endl;
            valid = false;
        }
    }
}