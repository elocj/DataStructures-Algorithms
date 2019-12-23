// file commandfactory.cpp
// Member function definitions for class CommandFactory

#include "commandfactory.h"

// ---------------------------------------------------------------------------
// Constructor
// Constructs a CommandFactory and sets the different commands in their
// respective hashed location in the command hash table.

CommandFactory::CommandFactory() {
    for(int i = 0; i < COMTABLESIZE; i++) {
        call[i] = nullptr;
    }
    call[CHECKOUT] = new Checkout();
    call[RETURN] = new Return();
    call[HISTORY] = new History();
//    media[MEDIA] = "Hardcover";
}

// ---------------------------------------------------------------------------
// Destructor
// Destructs a CommandFactory by making sure to delete every command and media
// object in their respective hash tables.

CommandFactory::~CommandFactory() {
    for(int i = 0; i < COMTABLESIZE; i++) {
        if (call[i] != nullptr) {
            delete call[i];
            call[i] = nullptr;
        }
    }
}

// ---------------------------------------------------------------------------
// Copy constructor.
// Copies one factory to another.

CommandFactory::CommandFactory(const CommandFactory&) {

}

// ---------------------------------------------------------------------------
// hash
// Pre: Takes in a 'ch' variable that holds the code for the type of command.
// Post: This hashing function takes the passed in char and subtracts
// by 'A' to create the hashing effect.

int CommandFactory::hash(char ch) {
    return ch - 'A';
}

// ---------------------------------------------------------------------------
// getIndex
// Pre: Takes in a 'ch' variable that holds the code for the type of command.
// Post: Returns the hashed value that is the result of hashing the passed in
//       character.

int CommandFactory::getIndex(char ch) {
    return hash(ch);
}

// ---------------------------------------------------------------------------
// getIndex
// Pre: Takes in a 'ch' variable that holds the code for the type of command.
//      Also takes an input stream to skip the line if the char code is
//      invalid.
// Post: Returns the desired command object if it exists in the hash table.

Command* CommandFactory::createCommand(char ch, istream& infile) {
    int index = getIndex(ch);
    string garbage;
    if(call[index] != nullptr) {
        return call[index]->create();
    } else {
        getline(infile, garbage, '\n');
        return nullptr;
    }
}