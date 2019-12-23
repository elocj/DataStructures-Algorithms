//
// Created by Anthony Joo on 2019-11-26.
//

#include "patron.h"

Patron::Patron() {
    id = -1;
    first = "";
    last = "";
}

Patron::Patron(const Patron& temp) {
    id = temp.id;
    first = temp.first;
    last = temp.last;
    history = temp.history;
}

Patron::~Patron() {
    for(Command* com : history) {
        delete com;
        com = nullptr;
    }
}

void Patron::addCommand(Command* comm) {
    history.push_back(comm);
}

int Patron::getId() {
    return id;
}

void Patron::setData(istream& infile) {
    infile >> id;
    if (infile.eof()) return;

    infile.get();
    infile >> last;

    infile.get();
    infile >> first;
}

void Patron::printHistory() {
    cout << "----------------------------------------------------------------"
            "---------------" << endl;
    cout << id << "  " << last << ", " << first << ":" << endl;
    for(int i =  0; i < history.size(); i++) {
        history[i]->display();
    }
    cout << endl;
}

string Patron::getFirst() const {
    return first;
}

string Patron::getLast() const {
    return last;
}