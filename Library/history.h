// file history.h
// header file for class History

#ifndef HISTORY_H
#define HISTORY_H

#include "command.h"

class History: public Command {
public:
    // Constructors
    History(); // Constructor
    virtual ~History(); // Destructor
    History(const History&); // Copy constructor

    // Functions
    // Sets the data of History such as its NodeData item as well as its
    // command type.
    virtual void setData(int id, istream&, BinTree db[], Patron patrons[]);
    // Creates and returns History command for the factory to use.
    virtual Command* create();
    // Display History command information as requested by the patron history
    virtual void display() const;
    // Returns 'valid' which is false in all cases where an error is detected
    // while inputting data into the History command.
    virtual bool getBool() const;
    // Performs the primary function of the History command at hand.
    virtual void run(int id, Patron patrons[]);
};

//#include "history.cpp"

#endif //HISTORY_H
