// file fiction.cpp
// Member function definitions for class Fiction.h

#include "fiction.h"

// ---------------------------------------------------------------------------
// Constructor
// Constructs an empty Fiction class where genre is set to 'fiction', numAvail
// is set to 5, and media is set to 'book'.

Fiction::Fiction() {
    author = "";
    title = "";
    year = 0;
    genre = "fiction";
    numAvail = 5;
    media = "book";
    maxAvail = 5;
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for this Fiction object

Fiction::~Fiction() {

}

// ---------------------------------------------------------------------------
// Copy constructor
// Pre: Takes in a Fiction object.
// Post: Copies over this Fiction object with the object passed in.

Fiction::Fiction(const Fiction& temp) {
    author = temp.author;
    title = temp.title;
    year = temp.year;
    genre = temp.genre;
    media = temp.media;
}

// ---------------------------------------------------------------------------
// setData
// Pre: Takes in a istream object reading in from a book input file.
// Post: Iterates through the istream object and sets the data of this Fiction
//       object. This sets the data of Fiction when istream is passed in from
//       the book list.

void Fiction::setData(istream& infile) {
    infile.get(); // get (and ignore) blank before author
    getline(infile, author, ','); // input author, looks for comma terminator

    infile.get(); // get (and ignore) blank before title
    getline(infile, title, ','); // input title

    infile.get();
    infile >> year; // input year
}

// ---------------------------------------------------------------------------
// setComData
// Pre: Takes in a istream object reading in from a command input file.
// Post: Iterates through the istream object and sets the data of this Fiction
//       object. This sets the data of Fiction when istream is passed in from
//       the command list.

void Fiction::setComData(istream& infile) {
    getline(infile, author, ','); // input author, looks for comma terminator

    infile.get(); // get (and ignore) blank before title
    getline(infile, title, ','); // input title
}

// ---------------------------------------------------------------------------
// display
// Displays the information of this Fiction object when it is requested by
// the command Display.

void Fiction::display() const {
    cout << left << setw(6) << numAvail << left << setw(24) <<
    author.substr(0, 22) << left << setw(38) << title.substr(0, 36) << year << endl;
}

// ---------------------------------------------------------------------------
// historyDisplay
// Displays the information of this Fiction object when it is requested by
// patron history.

void Fiction::historyDisplay() const {
    cout << left << setw(29) << title.substr(0, 27) << left << setw(19) <<
    author.substr(0, 17) << year << endl;
}

// ---------------------------------------------------------------------------
// Create
// Creates and returns a new Fiction object for the book factory to use.

NodeData* Fiction::create() {
    return new Fiction();
}

// ---------------------------------------------------------------------------
// operator<
// Pre: Takes in NodeData object
// Post: Returns a boolean that is true if the value of this Fiction object is
//       less than the passed in NodeData object according to a predefined
//       sorting rule where Fiction objects are sorted by author and then title.

bool Fiction::operator<(const NodeData& item) const {
    const Fiction & temp = dynamic_cast<const Fiction&>(item);
    if(author < temp.author) {
        return true;
    } else if(author != temp.author) {
        return false;
    } else {
        return title < temp.title;
    }
}

// ---------------------------------------------------------------------------
// operator==
// Pre: Takes in NodeData object
// Post: Returns a boolean that is true if the value of this Fiction object is
//       equal to the passed in NodeData object according to a predefined
//       sorting rule where Fiction objects are sorted by author and then title.

bool Fiction::operator==(const NodeData& item) const {
    const Fiction & temp = dynamic_cast<const Fiction&>(item);
    return (author == temp.author && title == temp.title);
}

// ---------------------------------------------------------------------------
// operator>
// Pre: Takes in NodeData object
// Post: Returns a boolean that is true if the value of this Fiction object is
//       larger than the passed in NodeData object according to a predefined
//       sorting rule where Fiction objects are sorted by author and then title.

bool Fiction::operator>(const NodeData& item) const {
    const Fiction & temp = dynamic_cast<const Fiction&>(item);
    if(author > temp.author) {
        return true;
    } else if(author != temp.author) {
        return false;
    } else {
        return title > temp.title;
    }
}

// ---------------------------------------------------------------------------
// returnCopy
// Increments the number of this Fiction book available as a copy of it is
// returned.

void Fiction::returnCopy() {
    numAvail++;
}

// ---------------------------------------------------------------------------
// checkoutCopy
// Decrements the number of this Fiction book available as a copy of it is
// checked-out.

void Fiction::checkoutCopy() {
    numAvail--;
}

// ---------------------------------------------------------------------------
// getNumAvailable
// Returns the number of this Fiction book available.

int Fiction::getNumAvailable() const {
    return numAvail;
}

// ---------------------------------------------------------------------------
// getTitle
// Returns the title of this Fiction book.

string Fiction::getTitle() const {
    return title;
}

// ---------------------------------------------------------------------------
// getMax
// Returns the max number of this book allowed

int Fiction::getMax() const {
    return maxAvail;
}