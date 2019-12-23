// file manager.cpp
// Member function definitions for class Manager

#include "manager.h"

// ---------------------------------------------------------------------------
// Constructor
// Constructs a Manager object.

Manager::Manager() {

}

// ---------------------------------------------------------------------------
// Destructor
// Destructs manager class.

Manager::~Manager() {

}

// ---------------------------------------------------------------------------
// Copy constructor
// Copies one manager (that) to another (this).

Manager::Manager(const Manager&) {

}

// ---------------------------------------------------------------------------
// Execute
// Place in class where loadBooks, loadPatrons, and loadCommands is executed
// and overall code is run.

void Manager::execute() {
    loadBooks();
    loadPatrons();
    loadCommands();
}

// ---------------------------------------------------------------------------
// loadBooks
// Reads in the book txt file to read and create the different books that make
// up the library.

void Manager::loadBooks() {
    ifstream infile("data4books.txt");
    for(;;) {
        char gen = ' ';
        infile >> gen;
        if(infile.eof()) break;
        NodeData* book = bookFactory.createBook(gen, infile);
        if(book != nullptr) {
            book->setData(infile);
            if(!db[bookFactory.getIndex(gen)].insert(book)) {
                delete book;
                book = nullptr;
                cout << "-------------------------------------------------"
                        "------------------------------" << endl;
                cout << "ERROR: Book already inserted" << endl;
            } else {
                book = nullptr;
                delete book;
            }
        } else {
            cout << "----------------------------------------------------"
                    "---------------------------" << endl;
            cout << "ERROR: Invalid Code '" << gen << "'" << endl;
        }
    }
}

// ---------------------------------------------------------------------------
// loadPatrons
// Reads in the patrons txt file to create patrons and add them to the patrons
// database.

void Manager::loadPatrons() {
    ifstream infile("data4patrons.txt");
    for(;;) {
        Patron* add = new Patron();
        add->setData(infile);
        if (infile.eof()){
            delete add;
            add = nullptr;
            break;
        }
        patrons[add->getId()] = *add;
        delete add;
        add = nullptr;
    }
}

// ---------------------------------------------------------------------------
// loadCommands
// Reads in the commands txt file and creates/runs the commands that are called.

void Manager::loadCommands() {
    ifstream infile("data4commands.txt");
    for(;;) {
        char command;
        infile >> command;
        if (infile.eof()) break;
        if(command == 'D') {
            displayBooks();
        } else {
            Command* com = commandFactory.createCommand(command, infile);
            if(com != nullptr) {
                infile.get();
                int id;
                infile >> id;
                if (infile.eof()) break;
                if(patrons[id].getId() == -1) {
                    cout << "------------------------------------------------"
                            "-------------------------------" << endl;
                    cout << "ERROR: There is no patron with ID " << id <<
                    "." << endl;
                    string garbage;
                    getline(infile, garbage, '\n');
                    delete com;
                    com = nullptr;
                    continue;
                }
                com->setData(id, infile, db, patrons);
                com->run(id, patrons);
                if(!com->getBool()) {
                    delete com;
                    com = nullptr;
                }
            } else {
                cout << "-----------------------------------------------"
                        "--------------------------------" << endl;
                cout << "ERROR: '" << command <<
                "' is not a valid LibItem type." << endl;
                delete com;
                com = nullptr;
            }
        }
    }
}

// ---------------------------------------------------------------------------
// displayBooks
// Whenever the command 'D' is called it is supposed to display the books by
// genre which this function does.

void Manager::displayBooks() {
    cout << "----------------------------------------------------------------"
            "---------------" << endl;
    cout << "FICTION BOOKS" << endl;
    cout << left << setw(6) << "AVAIL" << left << setw(24) << "AUTHOR" <<
    left << setw(38) << "TITLE" << "YEAR" << endl;
    cout << db[5];
    cout << "CHILDREN BOOKS" << endl;
    cout << left << setw(6) << "AVAIL" << left << setw(24) << "AUTHOR" <<
    left << setw(38) << "TITLE" << "YEAR" << endl;
    cout << db[24];
    cout << "PERIODICAL BOOKS" << endl;
    cout << left << setw(6) << "AVAIL" << left << setw(38) << "TITLE" <<
    left << setw(6) << "MONTH" << "YEAR" << endl;
    cout << db[15];
}