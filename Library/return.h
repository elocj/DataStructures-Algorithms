//
// Created by Anthony Joo on 2019-11-29.
//

#ifndef RETURN_H
#define RETURN_H

#include "command.h"

class Return: public Command {
public:
    // Constructors
    Return(); // Constuctor
    virtual ~Return(); // Destructor
    Return(const Return&); // Copy constructor

    // Functions
    // Sets the data of Return such as its NodeData item as well as its
    // command type.
    virtual void setData(int id, istream&, BinTree db[], Patron patrons[]);
    // Creates and returns Return command for the factory to use.
    virtual Command* create();
    // Display Return command information as requested by the patron history
    virtual void display() const;
    // Returns 'valid' which is false in all cases where an error is detected
    // while inputting data into the Return command.
    virtual bool getBool() const;
    // Performs the primary function of the Return command at hand.
    virtual void run(int id, Patron patrons[]);
};

//#include "return.cpp"

#endif //ASSIGNMENT4_RETURN_H
