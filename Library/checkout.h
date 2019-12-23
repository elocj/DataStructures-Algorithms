// file checkout.h
// header file for class Checkout

#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "command.h"

using namespace std;

//---------------------------------------------------------------------------
// Checkout class: defined as a Checkout command equipped to:
//   - Initialize an empty Checkout.
//   - Holds a NodeData object, command name, media type, as well as Book
//     factory.
//   - Copy another command.
//   - Read and set Checkout data.
//   - Display checkout information.
//   - Performs actions to either checkout or return a book and/or display
//     history of patrons.
//
// Implementation and assumptions:
//   -- Checkout is the child class of Command.
//   -- Implements all of the pure virtual functions declared in Command.
//---------------------------------------------------------------------------

class Checkout: public Command {
public:
    // Constructors
    Checkout(); // Constructor
    virtual ~Checkout(); // Destructor
    Checkout(const Checkout&); // Copy constructor

    // Functions
    // Sets the data of Checkout such as its NodeData item as well as its
    // command type.
    virtual void setData(int id, istream&, BinTree db[], Patron patrons[]);
    // Creates and returns checkout command for the factory to use.
    virtual Command* create();
    // Display checkout command information as requested by the patron history
    virtual void display() const;
    // Returns 'valid' which is false in all cases where an error is detected
    // while inputting data into the checkout command.
    virtual bool getBool() const;
    // Performs the primary function of the checkout command at hand.
    virtual void run(int id, Patron patrons[]);
};

//#include "checkout.cpp"

#endif //CHECKOUT_H
