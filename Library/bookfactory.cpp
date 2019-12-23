// file bookfactory.cpp
// Member function definitions for class BookFactory

#include "bookfactory.h"

// ---------------------------------------------------------------------------
// Constructor
// Constructs a bookFactory and sets the different genre books in their
// respective hashed location in the book hash table. The media is also set
// in the media hash table.

BookFactory::BookFactory() {
    for(int i = 0; i < BOOKTABLESIZE; i++) {
        genres[i] = nullptr;
        media[i] = "nullString";
    }
    genres[FICTION] = new Fiction();
    genres[CHILDREN] = new Children();
    genres[PERIODICAL] = new Periodical();
    media[MEDIA] = "Hardcover";
}

// ---------------------------------------------------------------------------
// Destructor
// Destructs a bookFactory by making sure to delete every book
// object in their respective hash tables.

BookFactory::~BookFactory() {
    for(int i = 0; i < BOOKTABLESIZE; i++) {
        if(genres[i] != nullptr) {
            delete genres[i];
            genres[i] = nullptr;
        }
    }

}

// ---------------------------------------------------------------------------
// Copy constructor.
// Copies one factory to another.

BookFactory::BookFactory(const BookFactory&) {

}

// ---------------------------------------------------------------------------
// hash
// Pre: Takes in a 'ch' variable that holds the code for the type of book.
// Post: This hashing function takes the passed in char and subtracts
// by 'A' to create the hashing effect.

int BookFactory::hash(char ch) {
    return ch - 'A';
}

// ---------------------------------------------------------------------------
// getIndex
// Pre: Takes in a 'ch' variable that holds the code for the type of book.
// Post: Returns the hashed value that is the result of hashing the passed in
//       character.

int BookFactory::getIndex(char ch) {
    return hash(ch);
}

// ---------------------------------------------------------------------------
// getIndex
// Pre: Takes in a 'ch' variable that holds the code for the type of book.
//      Also takes an input stream to skip the line if the char code is
//      invalid.
// Post: Returns the desired book object if it exists in the hash table.

NodeData* BookFactory::createBook(char ch, istream& infile) {
    int index = getIndex(ch);
    string garbage;
    if(genres[index] != nullptr) {
        return genres[index]->create();
    } else {
        getline(infile, garbage, '\n');
        return nullptr;
    }
}

// ---------------------------------------------------------------------------
// getMedia
// Pre: Takes in a 'ch' variable that holds the code for the type of media.
// Post: Returns the media if it exists in the hash table.

string BookFactory::getMedia(char val) {
    return media[getIndex(val)];
}