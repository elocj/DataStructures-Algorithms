// file fiction.h
// Header file for class Fiction.

#ifndef FICTION_H
#define FICTION_H

#include "book.h"

//---------------------------------------------------------------------------
// Fiction class: defined as a Fiction object equipped to:
//   - Initialize an empty Fiction.
//   - Holds the author, title, and year of release of this Fiction book.
//   - Sets the genre to 'Fiction'.
//   - Copy another Fiction.
//   - Read and set Fiction information.
//   - Manipulate the number of a certain Fiction book available in the library.
//   - Display Fiction book information.
//
// Implementation and assumptions:
//   -- Child class of Book which is a child class of NodeData.
//   -- Holds the implementation of most of the functions declared in its
//      parent classes.
//   -- Sorted by author and then title.
//---------------------------------------------------------------------------

class Fiction: public Book {
public:
    // Constructors
    Fiction(); // Constructor
    Fiction(const Fiction&); // Copy constructor
    virtual ~Fiction(); // Destructor

    // Functions
    // Displays Fiction information as requested by the display command.
    virtual void display() const;
    // Displays Fiction information as requested when iterating through patron
    // history.
    virtual void historyDisplay() const;
    // Sets Fiction data as entered in from the book list.
    virtual void setData(istream&);
    // Sets Fiction data as entered in from the command list.
    virtual void setComData(istream&);
    virtual NodeData* create(); // Creates Fiction object for factory.
    virtual void returnCopy(); // Increments Fiction available.
    virtual void checkoutCopy(); // Decrements Fiction available.
    // Returns number of Fiction books available.
    virtual int getNumAvailable() const;
    virtual string getTitle() const; // Return title of Fiction book.
    virtual int getMax() const; // Get max books allowed.

    // Operator Overloads
    virtual bool operator<(const NodeData&) const; // Overloads < operator.
    virtual bool operator==(const NodeData&) const; // Overloads == operator.
    virtual bool operator>(const NodeData&) const; // Overloads > operator.

private:
    string author; // Fiction author.
    string title; // Fiction title.
    int year; // Year of Fiction release.
};

//#include "fiction.cpp"

#endif //FICTION_H
