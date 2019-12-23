// file checkout.cpp
// Member function definitions for class Checkout

#include "checkout.h"
#include "patron.h"


// ---------------------------------------------------------------------------
// Constructor
// Constructs an empty Checkout class.

Checkout::Checkout() {
    command = "Checkout";
    valid = true;
    temp = nullptr;
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for this Checkout object.

Checkout::~Checkout() {

}

// ---------------------------------------------------------------------------
// Copy constructor
// Pre: Takes in a Checkout object.
// Post: Copies over this Checkout object with the object passed in.

Checkout::Checkout(const Checkout& com) {
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
//       object data member of Checkout. During this whole process error
//       is also happening for erroneous information.

void Checkout::setData(int id, istream& infile, BinTree db[],
        Patron patrons[]) {
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
                cout << "-------------------------------------------------"
                        "------------------------------" << endl;
                cout << "ERROR: " << patrons[id].getFirst() << " " <<
                     patrons[id].getLast() << " tried to check out '" <<
                     book->getTitle() << "' - not found in catalog." << endl;
                valid = false;
            }
        } else {
            string garbage;
            getline(infile, garbage, '\n');
            valid = false;
            cout << "------------------------------------------------------"
                    "-------------------------" << endl;
            cout << "ERROR: '" << med << "' is not a good book format." << endl;
        }
    } else {
        cout << "----------------------------------------------------------"
                "---------------------" << endl;
        cout << "ERROR: No such genre '" << genre << "'." << endl;
        valid = false;
    }
    delete book;
    book = nullptr;
}

// ---------------------------------------------------------------------------
// create
// Returns a copy of Checkout for the command factory to use.

Command* Checkout::create() {
    return new Checkout();
}

// ---------------------------------------------------------------------------
// display
// Displays the command information.

void Checkout::display() const {
    cout << "  " << left << setw(10) << command;
    temp->historyDisplay();
}

// ---------------------------------------------------------------------------
// getBool
// This boolean keeps track of if an error was detected so that proper memory
// deletion can occur.

bool Checkout::getBool() const {
    return valid;
}

// ---------------------------------------------------------------------------
// run
// Pre: Takes in a patron id as well as patron list.
// Post: Run performs the primary function of Checkout which is to checkout
//       a book from the library so it will decrement the amount of this book
//       left in the library by 1. Error checks occur here as well.

void Checkout::run(int id, Patron patrons[]) {
    if(temp != nullptr) {
        if(temp->getNumAvailable() > 0) {
            temp->checkoutCopy();
            patrons[id].addCommand(this);
        } else {
            cout << "----------------------------------------------------"
                    "---------------------------" << endl;
            cout << "ERROR: All copies of '" <<
            temp->getTitle().substr(0, 29) << "' are checked out." << endl;
            valid = false;
        }
    }
}