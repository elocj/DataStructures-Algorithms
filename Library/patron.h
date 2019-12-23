//
// Created by Anthony Joo on 2019-11-26.
//

#ifndef PATRON_H
#define PATRON_H

#include "book.h"
#include "command.h"
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;

class Patron {
public:
    Patron();
    Patron(const Patron&);
    ~Patron();
    void setData(istream&);
    int getId();
    void addCommand(Command*);
    void printHistory();
    string getFirst() const;
    string getLast() const;

private:
    int id;
    string first;
    string last;
    vector<Command*> history;
};

//#include "patron.cpp"

#endif //PATRON_H
