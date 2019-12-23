// file book.cpp
// Member function definitions for class Book.

#include "book.h"

// ---------------------------------------------------------------------------
// Constructor
// Constructs an empty Book class.

Book::Book() {

}

// ---------------------------------------------------------------------------
// Copy constructor
// Pre: Takes in a Book object.
// Post: Copies over this Book object with the object passed in.

Book::Book(const Book& temp) {
    genre = temp.genre;
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for this Book object

Book::~Book() {

}