// file book.h
// Header file for class Book.

#ifndef BOOK_H
#define BOOK_H

#include "nodedata.h"

//---------------------------------------------------------------------------
// Book class: defined as a book equipped to:
//   - Initialize an empty book.
//   - Copy another book.
//   - Sets media to 'Book'.
//   - Hold genre information.
//   - Hold the number of this type of book in stock in the library.
//   - Read and set book information.
//   - Manipulate the number of a certain book available in the library.
//   - Display book information.
//
// Implementation and assumptions:
//   -- Book is the child class of NodeData and the parent class of
//      the genres Fiction, Children, and Periodical.
//   -- All of the functions excluding the constructor methods are pure virtual
//      functions that are to be implemented by the child classes.
//   -- We are assuming that every book read in has an initial 5 copies in the
//      libraries.
//---------------------------------------------------------------------------

class Book: public NodeData {
public:
    // Constructors
    Book(); // Constructor
    Book(const Book&); // Copy constructor
    virtual ~Book() = 0; // Pure virtual destructor


    // Functions
    // Sets book data as entered in from the book list.
    virtual void setData(istream&) = 0;
    // Sets book data as entered in from the command list.
    virtual void setComData(istream&) = 0;
    // Displays book information as requested by the display command.
    virtual void display() const = 0;
    // Displays book information as requested when iterating through patron
    // history.
    virtual void historyDisplay() const = 0;
    virtual NodeData* create() = 0; // Creates book object for factory.
    virtual void returnCopy() = 0; // Increments books available.
    virtual void checkoutCopy() = 0; // Decrements NodeData available.
    // Returns number of books available
    virtual int getNumAvailable() const = 0;
    virtual string getTitle() const = 0; // Return title of book.
    virtual int getMax() const = 0; // Get max books allowed.

    // Operator Overloads
    virtual bool operator<(const NodeData&) const = 0; // Overloads < operator.
    virtual bool operator>(const NodeData&) const = 0; // Overloads > operator.
    // Overloads == operator.
    virtual bool operator==(const NodeData&) const = 0;

protected:
    string genre; // Genre of book.
    int numAvail; // Number of this book available.
    int maxAvail;
};

//#include "book.cpp"

#endif //BOOK_H
