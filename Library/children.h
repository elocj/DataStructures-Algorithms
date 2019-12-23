// file children.h
// Header file for class Children.

#ifndef CHILDREN_H
#define CHILDREN_H

#include "book.h"

//---------------------------------------------------------------------------
// Children class: defined as a Fiction object equipped to:
//   - Initialize an empty Children book.
//   - Holds the author, title, and year of release of this Children book.
//   - Sets the genre to  'Children'.
//   - Copy another Children.
//   - Read and set Children information.
//   - Manipulate the number of a certain Children book available in
//     the library.
//   - Display Children book information.
//
// Implementation and assumptions:
//   -- Child class of Book which is a child class of NodeData.
//   -- Holds the implementation of most of the functions declared in its
//      parent classes.
//   -- Sorted by title and then author
//---------------------------------------------------------------------------

class Children: public Book {
public:
    // Constructors
    Children();
    Children(const Children&); //copy constructor
    virtual ~Children();

    // Functions
    // Displays Children information as requested by the display command.
    virtual void display() const;
    // Displays Children information as requested when iterating through patron
    // history.
    virtual void historyDisplay() const;
    // Sets Children data as entered in from the book list.
    virtual void setData(istream&);
    // Sets Children data as entered in from the command list.
    virtual void setComData(istream&);
    virtual NodeData* create(); // Creates Children object for factory.
    virtual void returnCopy(); // Increments Children available.
    virtual void checkoutCopy(); // Decrements Children available.
    // Returns number of Children books available.
    virtual int getNumAvailable() const;
    virtual string getTitle() const; // Return title of Children book.
    virtual int getMax() const; // Get max books allowed.

    // Operator Overloads
    virtual bool operator<(const NodeData&) const; // Overloads < operator.
    virtual bool operator==(const NodeData&) const; // Overloads == operator.
    virtual bool operator>(const NodeData&) const; // Overloads > operator.

private:
    string author; // Author of Children book
    string title; // Title of Children book
    int year; // Year of release
};

//#include "children.cpp"

#endif //CHILDREN_H
