// file children.cpp
// Member function definitions for class Children.

#include "children.h"

// ---------------------------------------------------------------------------
// Constructor
// Constructs an empty Children class where genre is set to 'Children',
// numAvail is set to 1, and media is set to 'book'.

Children::Children() {
    author = "";
    title = "";
    year = 0;
    genre = "children";
    numAvail = 5;
    media = "book";
    maxAvail = 5;
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for this Children object

Children::~Children() {

}

// ---------------------------------------------------------------------------
// Copy constructor
// Pre: Takes in a Children object.
// Post: Copies over this Fiction object with the object passed in by copying
//       title, year, author, media, and genre.

Children::Children(const Children& temp) {
    author = temp.author;
    title = temp.title;
    year = temp.year;
    genre = temp.genre;
    media = temp.media;
}

// ---------------------------------------------------------------------------
// setData
// Pre: Takes in a istream object reading in from a book input file.
// Post: Iterates through the istream object and sets the data of this
//       Children object. This sets the data of Children when istream is
//       passed in from the book list.

void Children::setData(istream& infile) {
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
// Post: Iterates through the istream object and sets the data of this
// Children object. This sets the data of Children when istream is
// passed in from the command list.

void Children::setComData(istream& infile) {
    getline(infile, title, ',');     // input author, looks for comma terminator

    infile.get();                     // get (and ignore) blank before title
    getline(infile, author, ',');      // input title
}

// ---------------------------------------------------------------------------
// display
// Displays the information of this Children object when it is requested by
// the command Display.

void Children::display() const {
    cout << left << setw(6) << numAvail << left << setw(24) <<
    author.substr(0, 22) << left << setw(38) << title.substr(0, 36) <<
    year << endl;
}

// ---------------------------------------------------------------------------
// historyDisplay
// Displays the information of this Children object when it is requested by
// patron history.

void Children::historyDisplay() const {
    cout << left << setw(29) << title.substr(0, 27) << left << setw(19) <<
    author.substr(0, 17) << year << endl;
}

// ---------------------------------------------------------------------------
// Create
// Creates and returns a new Children object for the book factory to use.

NodeData* Children::create() {
    return new Children();
}

// ---------------------------------------------------------------------------
// operator<
// Pre: Takes in NodeData object
// Post: Returns a boolean that is true if the value of this Children object
//       is less than the passed in NodeData object according to a predefined
//       sorting rule where Children objects are sorted by title and then
//       author.

bool Children::operator<(const NodeData& item) const {
    const Children & temp = dynamic_cast<const Children&>(item);
    if(title < temp.title) {
        return true;
    } else if(title != temp.title) {
        return false;
    } else {
        return author < temp.author;
    }
}

// ---------------------------------------------------------------------------
// operator==
// Pre: Takes in NodeData object
// Post: Returns a boolean that is true if the value of this Children object
//       is equal to the passed in NodeData object according to a predefined
//       sorting rule where Children objects are sorted by title and then
//       author.

bool Children::operator==(const NodeData& item) const {
    const Children & temp = dynamic_cast<const Children&>(item);
    return (author == temp.author && title == temp.title);
}

// ---------------------------------------------------------------------------
// operator>
// Pre: Takes in NodeData object
// Post: Returns a boolean that is true if the value of this Children object
//       is larger than the passed in NodeData object according to a predefined
//       sorting rule where Children objects are sorted by title and then
//       author.

bool Children::operator>(const NodeData& item) const {
    const Children & temp = dynamic_cast<const Children&>(item);
    if(title > temp.title) {
        return true;
    } else if(title != temp.title) {
        return false;
    } else {
        return author > temp.author;
    }
}

// ---------------------------------------------------------------------------
// returnCopy
// Increments the number of this Children book available as a copy of it is
// returned.

void Children::returnCopy() {
    numAvail++;
}

// ---------------------------------------------------------------------------
// checkoutCopy
// Decrements the number of this Children book available as a copy of it is
// checked-out.

void Children::checkoutCopy() {
    numAvail--;
}

// ---------------------------------------------------------------------------
// getNumAvailable
// Returns the number of this Children book available.

int Children::getNumAvailable() const {
    return numAvail;
}

// ---------------------------------------------------------------------------
// getTitle
// Returns the title of this Children book.

string Children::getTitle() const {
    return title;
}

// ---------------------------------------------------------------------------
// getMax
// Returns the max number of this book allowed

int Children::getMax() const {
    return maxAvail;
}