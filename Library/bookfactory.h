// file bookfactory.h
// header file for class BookFactory

#ifndef BOOKFACTORY_H
#define BOOKFACTORY_H

#include "fiction.h"
#include "children.h"
#include "periodical.h"

//---------------------------------------------------------------------------
// CommandFactory class: defined as a CommandFactory equipped to:
//   - Hash passed in values to get unique outcomes.
//   - Create a hash table to allow access to different books in O(1),
//     constant time.
//   - Also has a hash table for the type of media to be returned.
//
// Implementation and assumptions:
//   -- Factory helps obey open-close principle because if we wanted to add a
//      command we can just add it to the factory instead of having to go
//      into the primary code and change something.
//   -- Media will always be 'Hardcover' for this assignment.
//   -- We will use getMedia to check if the passed in media is in our media
//      list.
//   -- Value passed into hash must be a unique, capital letter, char.
//---------------------------------------------------------------------------

const int FICTION = 5;
const int PERIODICAL = 15;
const int CHILDREN = 24;
const int MEDIA = 7;
const int BOOKTABLESIZE = 52; // Twice the expected amount of 26.

class BookFactory {
public:
    // Constructor
    BookFactory(); // Constructor
    ~BookFactory(); // Destructor
    BookFactory(const BookFactory&); // Copy constructor

    // Functions
    int getIndex(char); // Returns the hashed value that is passed in.
    // Returns a specified book depending on the 'ch' passed in.
    NodeData* createBook(char ch, istream& infile);
    string getMedia(char val); // Returns the type of media we want.

private:
    int hash(char); // hashing function
    NodeData* genres[BOOKTABLESIZE]; // Hash table for book genres.
    string media[BOOKTABLESIZE]; // Hash table for media types.
};

//#include "bookfactory.cpp"

#endif //BOOKFACTORY_H
