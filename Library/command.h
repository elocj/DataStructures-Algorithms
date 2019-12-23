// file command.h
// header file for class Command

#ifndef COMMAND_H
#define COMMAND_H
#include "nodedata.h"

#include "bintree.h"
#include "bookfactory.h"

//---------------------------------------------------------------------------
// Command class: defined as a Command equipped to:
//   - Initialize an empty Command.
//   - Holds a NodeData object, command name, media type, as well as Book
//     factory.
//   - Copy another command.
//   - Read and set Command data.
//   - Display command information.
//   - Performs actions to either checkout or return a book and/or display
//     history of patrons.
//
// Implementation and assumptions:
//   -- Command is the parent class of return, checkout, and history.
//   -- Forward referencing Patron to use its functions.
//   -- All of the functions excluding the constructor methods are pure virtual
//      functions that are to be implemented by the child classes.
//---------------------------------------------------------------------------

class Patron; // Forward reference Patron

class Command {
public:
    // Constructor
    Command();
    virtual ~Command();
    Command(const Command&);

    // Functions
    // Sets the data of Command such as its NodeData item as well as its command
    // type.
    virtual void setData(int id, istream&, BinTree db[], Patron patrons[]) = 0;
    // Creates and returns command for the factory to use.
    virtual Command* create() = 0;
    // Display command information as requested by the patron history
    virtual void display() const = 0;
    // Returns 'valid' which is false in all cases where an error is detected
    // while inputting data into the command.
    virtual bool getBool() const = 0;
    // Performs the primary function of the command at hand.
    virtual void run(int id, Patron patrons[]) = 0;

protected:
    NodeData* temp; // The book object this command holds.
    bool valid; // Bool to test if an error is identified while reading input.
    string command; // Command name.
//    string media; // Media type.
    BookFactory bookFactory; // Book factory.
};

//#include "command.cpp"

#endif //COMMAND_H
