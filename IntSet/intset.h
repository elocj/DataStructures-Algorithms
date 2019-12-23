// file intset.h
// header file for class IntSet

#ifndef ASSIGNMENT1_INTSET_H
#define ASSIGNMENT1_INTSET_H

#include <iostream>
#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------
// IntSet class: abstract data type that uses a boolean array to keep track of a
//               non-negative set of integers with additional features:
//   -- allows the initialization of an IntSet object of up to 5 values
//   -- allows input and output of the whole set
//   -- allows for comparison of two IntSets
//   -- allows for assignment of two IntSets
//   -- allows the union, intersection, and difference of two IntSets
//   -- size is part of the class
//
// Implementation and assumptions:
//   -- IntSet defaults to a size of 0 and one element with a value of false if
//      elements of IntSet not specified
//   -- Any negative integers inputted either through a constructor, insert
//      function, or >> input operator is ignored
//   -- >> IntSet input operator breaks on value of "-1"
//---------------------------------------------------------------------------

class IntSet {
public:
    IntSet(); // constructor, takes no values
    IntSet(int num1); // constructor, takes one value
    IntSet(int num1, int num2); // constructor, takes two values
    IntSet(int num1, int num2, int num3); // constructor, takes three values
    IntSet(int num1, int num2, int num3, int num4); // constructor, takes four
                                                    // values
    IntSet(int num1, int num2, int num3, int num4, int num5); // constructor,
                                                              // takes five
                                                              // values
    IntSet(IntSet& set); // copy constructor
    ~IntSet(); // destructor

    // overloaded <<: prints IntSet in form of "[ values]".
    friend ostream& operator <<(ostream &outStream, const IntSet &set);

    // overloaded >>: takes in valid, non-negative values to add to given IntSet
    //                continuously until -1 is passed in.
    friend istream &operator >>(istream &inStream, IntSet &set);

    IntSet operator+(IntSet &set); // union of two IntSets
    IntSet operator-(IntSet &set); // difference of two IntSets
    IntSet operator*(IntSet &set); // intersection of two IntSets
    IntSet &operator=(const IntSet &set); // Assigns one IntSet to another

    IntSet& operator+=(IntSet &set); // assigns the union of two IntSets to the
                                     // IntSet that calls the function
    IntSet& operator*=(IntSet &set); // assigns the intersection of two IntSets
                                     // to the IntSet that calls the function
    IntSet& operator-=(IntSet &set); // assigns the difference of two IntSets to
                                     // the IntSet that calls the function

    bool operator==(const IntSet &set) const; // equality, two IntSets are equal
    bool operator!=(const IntSet &set) const; // not equal, two IntSets differ

    bool insert(int value); // returns whether given value is valid and inserts
                            // into IntSet
    bool remove(int value); // returns whether given value is valid and removes
                            // from IntSet
    bool isInSet(int value) const; // returns whether given value is in IntSet
    bool isEmpty() const; // returns whether IntSet is empty

private:
    bool* ptr; // boolean array to track set of numbers
    int size; // size of array
};

#endif //ASSIGNMENT1_INTSET_H