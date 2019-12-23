// file periodical.h
// Header file for class Periodical.

#ifndef PERIODICAL_H
#define PERIODICAL_H

#include "book.h"

//---------------------------------------------------------------------------
// Periodical class: defined as a Fiction object equipped to:
//   - Initialize an empty Periodical book.
//   - Holds the title and month/year of release of this Periodical book.
//   - Sets the genre to 'Periodical'.
//   - Copy another Periodical.
//   - Read and set Periodical information.
//   - Manipulate the number of a certain Periodical book available in
//     the library.
//   - Display Periodical book information.
//
// Implementation and assumptions:
//   -- Child class of Book which is a child class of NodeData.
//   -- Holds the implementation of most of the functions declared in its
//      parent classes.
//   -- Sorted by date and then title.
//---------------------------------------------------------------------------

class Periodical: public Book {
public:
    // Constructors
    Periodical(); // Constructor
    Periodical(const Periodical&); // Copy constructor
    virtual ~Periodical(); // Destructor

    // Functions
    // Displays Periodical information as requested by the display command.
    virtual void display() const;
    // Displays Periodical information as requested when iterating through patron
    // history.
    virtual void historyDisplay() const;
    // Sets Periodical data as entered in from the book list.
    virtual void setData(istream&);
    // Sets Periodical data as entered in from the command list.
    virtual void setComData(istream&);
    virtual NodeData* create(); // Creates Periodical object for factory.
    virtual void returnCopy(); // Increments Periodical available.
    virtual void checkoutCopy(); // Decrements Periodical available.
    // Returns number of Periodical books available.
    virtual int getNumAvailable() const;
    virtual string getTitle() const; // Return title of Periodical book.
    virtual int getMax() const; // Get max books allowed.

    // Operator Overloads
    virtual bool operator<(const NodeData&) const; // Overloads < operator.
    virtual bool operator==(const NodeData&) const; // Overloads == operator.
    virtual bool operator>(const NodeData&) const; // Overloads > operator.

private:
    string title; // Title of Periodical book
    int year; // year of release
    int month; // month of release
};

//#include "periodical.cpp"

#endif //PERIODICAL_H
