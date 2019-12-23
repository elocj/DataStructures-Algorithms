// file commandfactory.h
// header file for class CommandFactoryZ

#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "checkout.h"
#include "return.h"
#include "history.h"

//---------------------------------------------------------------------------
// CommandFactory class: defined as a CommandFactory equipped to:
//   - Hash passed in values to get unique outcomes.
//   - Create a hash table to allow access to different commands in O(1),
//     constant time.
//
// Implementation and assumptions:
//   -- Factory helps obey open-close principle because if we wanted to add a
//      command we can just add it to the factory instead of having to go
//      into the primary code and change something.
//   -- Value passed into hash must be a unique, capital letter, char.
//---------------------------------------------------------------------------

const int CHECKOUT = 2;
const int RETURN = 17;
const int HISTORY = 7;
//const int MEDIA = 7;
const int COMTABLESIZE = 52; // Twice expected value of 26.

class CommandFactory {
public:
    // Constructors
    CommandFactory(); // Constructor
    ~CommandFactory(); // Destructor
    CommandFactory(const CommandFactory&); // Copy constructor

    // Functions
    int getIndex(char); // Returns the hashed value that is passed in.
    // Returns a specified command depending on the 'ch' passed in.
    Command* createCommand(char ch, istream& infile);

private:
    int hash(char); // Hashing function.
    Command* call[COMTABLESIZE]; // Hash table for command types.
};

//#include "commandfactory.cpp"

#endif //COMMANDFACTORY_H
