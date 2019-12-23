// file nodedata.h
// Header file for class NodeData.

#ifndef NODEDATA_H
#define NODEDATA_H

#include <iostream>
#include <string>
#include <iomanip>

//---------------------------------------------------------------------------
// NodeData class: defined as a NodeData equipped to:
//   - Initialize an empty NodeData.
//   - Holds the type of media this particular NodeData is.
//   - Copy another NodeData.
//   - Read and set NodeData information.
//   - Manipulate the number of a certain book available in the library.
//   - Display book information.
//
// Implementation and assumptions:
//   -- NodeData is the unit that the Library is made up of.
//   -- Book is the child class of NodeData
//   -- BinTree uses NodeData to sort books in order.
//   -- All of the functions excluding the constructor methods are pure virtual
//      functions that are to be implemented by the child classes.
//   -- We are only considering the Book media as of now.
//---------------------------------------------------------------------------

using namespace std;

class NodeData {
public:
    // Constructors
    NodeData(); // Constructor
    NodeData(const NodeData&); // Copy constructor
    virtual ~NodeData() = 0; // Destructor

    // Functions
    // Sets NodeData data as entered in from the book list.
    virtual void setData(istream&) = 0;
    // Sets NodeData data as entered in from the command list.
    virtual void setComData(istream&) = 0;
    // Displays NodeData information as requested by the display command.
    virtual void display() const = 0;
    // Displays NodeData information as requested when iterating through patron
    // history.
    virtual void historyDisplay() const = 0;
    virtual NodeData* create() = 0; // Creates NodeData object for factory.
    virtual void returnCopy() = 0; // Increments NodeData available.
    virtual void checkoutCopy() = 0; // Decrements NodeData available.
    // Returns number of NodeData available.
    virtual int getNumAvailable() const = 0;
    virtual string getTitle() const = 0; // Return title of NodeData.
    virtual int getMax() const = 0; // Get max books allowed.

    // Operator Overloads
    virtual bool operator<(const NodeData&) const = 0; // Overloads < operator.
    virtual bool operator>(const NodeData&) const = 0; // Overloads > operator.
    // Overloads == operator.
    virtual bool operator==(const NodeData& ) const = 0;

protected:
    string media; // Media type of NodeData.
};

//#include "nodedata.cpp"

#endif //NODEDATA_H
