// file periodical.cpp
// Member function definitions for class Periodical.

#include "periodical.h"

// ---------------------------------------------------------------------------
// Constructor
// Constructs an empty Periodical class where genre is set to 'periodical',
// numAvail is set to 1, and media is set to 'book'.

Periodical::Periodical() {
    title = "";
    year = 0;
    month = 0;
    genre = "periodical";
    numAvail = 1;
    media = "book";
    maxAvail = 1;
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for this Periodical object

Periodical::~Periodical() {

}

// ---------------------------------------------------------------------------
// Copy constructor
// Pre: Takes in a Periodical object.
// Post: Copies over this Fiction object with the object passed in by copying
//       title, year, month, media, and genre.

Periodical::Periodical(const Periodical& temp) {
    title = temp.title;
    year = temp.year;
    month = temp.month;
    genre = temp.genre;
    media = temp.media;
}

// ---------------------------------------------------------------------------
// setData
// Pre: Takes in a istream object reading in from a book input file.
// Post: Iterates through the istream object and sets the data of this
//       Periodical object. This sets the data of Periodical when istream is
//       passed in from the book list.

void Periodical::setData(istream& infile) {
    string monthTemp;
    infile.get();                     // get (and ignore) blank before author
    getline(infile, title, ',');     // input author, looks for comma terminator

    infile.get();                     // get (and ignore) blank before title
    getline(infile, monthTemp, ' ');      // input title
    month = stoi(monthTemp);

    infile >> year;                   // input year
}

// ---------------------------------------------------------------------------
// setComData
// Pre: Takes in a istream object reading in from a command input file.
// Post: Iterates through the istream object and sets the data of this
// Periodical object. This sets the data of Periodical when istream is
// passed in from the command list.

void Periodical::setComData(istream& infile) {
    string yearTemp;
    string monthTemp;
    getline(infile, yearTemp, ' '); // input author, looks for comma terminator
    year = stoi(yearTemp);
    getline(infile, monthTemp, ' '); // input author, looks for comma terminator
    month = stoi(monthTemp); // get (and ignore) blank before title
    getline(infile, title, ','); // input title
}

// ---------------------------------------------------------------------------
// display
// Displays the information of this Periodical object when it is requested by
// the command Display.

void Periodical::display() const {
    cout << left << setw(6) << numAvail << left << setw(38) <<
    title.substr(0, 36) << left << setw(6) << month << year << endl;
}

// ---------------------------------------------------------------------------
// historyDisplay
// Displays the information of this Periodical object when it is requested by
// patron history.

void Periodical::historyDisplay() const {
    cout << left << setw(29) << title.substr(0, 27) << month << "  " <<
    year << endl;
}

// ---------------------------------------------------------------------------
// Create
// Creates and returns a new Periodical object for the book factory to use.

NodeData* Periodical::create() {
    return new Periodical();
}

// ---------------------------------------------------------------------------
// operator<
// Pre: Takes in NodeData object
// Post: Returns a boolean that is true if the value of this Periodical object
//       is less than the passed in NodeData object according to a predefined
//       sorting rule where Periodical objects are sorted by date and then
//       title.

bool Periodical::operator<(const NodeData& item) const {
    const Periodical & temp = dynamic_cast<const Periodical&>(item);
    if(year < temp.year) {
        return true;
    } else if(year != temp.year) {
        return false;
    } else {
        if(month < temp.month) {
            return true;
        } else if(month != temp.month) {
            return false;
        } else {
            return title < temp.title;
        }
    }
}

// ---------------------------------------------------------------------------
// operator==
// Pre: Takes in NodeData object
// Post: Returns a boolean that is true if the value of this Periodical object
//       is equal to the passed in NodeData object according to a predefined
//       sorting rule where Periodical objects are sorted by date and then
//       title.

bool Periodical::operator==(const NodeData& item) const {
    const Periodical & temp = dynamic_cast<const Periodical&>(item);
    return (year == temp.year && month == temp.month && title == temp.title);
}

// ---------------------------------------------------------------------------
// operator>
// Pre: Takes in NodeData object
// Post: Returns a boolean that is true if the value of this Periodical object
//       is larger than the passed in NodeData object according to a predefined
//       sorting rule where Periodical objects are sorted by date and then
//       title.

bool Periodical::operator>(const NodeData& item) const {
    const Periodical & temp = dynamic_cast<const Periodical&>(item);
    if(year > temp.year) {
        return true;
    } else if(year != temp.year) {
        return false;
    } else {
        if(month > temp.month) {
            return true;
        } else if(month != temp.month) {
            return false;
        } else {
            return title > temp.title;
        }
    }
}

// ---------------------------------------------------------------------------
// returnCopy
// Increments the number of this Periodical book available as a copy of it is
// returned.

void Periodical::returnCopy() {
    numAvail++;
}

// ---------------------------------------------------------------------------
// checkoutCopy
// Decrements the number of this Periodical book available as a copy of it is
// checked-out.

void Periodical::checkoutCopy() {
    numAvail--;
}

// ---------------------------------------------------------------------------
// getNumAvailable
// Returns the number of this Periodical book available.

int Periodical::getNumAvailable() const {
    return numAvail;
}

// ---------------------------------------------------------------------------
// getTitle
// Returns the title of this Periodical book.

string Periodical::getTitle() const {
    return title;
}

// ---------------------------------------------------------------------------
// getMax
// Returns the max number of this book allowed

int Periodical::getMax() const {
    return maxAvail;
}