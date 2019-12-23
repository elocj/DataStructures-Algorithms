//
// Created by Anthony Joo on 2019-02-26.
//

#ifndef CHILD_H
#define CHILD_H

#include <iostream>
#include <string>

class Child
{
public:
    // Output and input stream overloads.
    // Output operator allows the information in the Child class to be printed.
    friend ostream& operator <<(ostream &outStream, const Child &kid);
    // Input operator overload allows information to be passed into the Child object.
    friend istream &operator >>(istream &inStream, Child &kid);

    // Constructor, copy constructor, and constructor with parameters.
    Child();
    Child(Child& k);
    Child(string firstName, string lastName, int id);

    // Operator Overloads
    // Overloads = allowing one to assign the value of one Child to another.
    Child& operator=(const Child &kid);
    // Overloads != operator allowing one to test the inequality of one Child to another.
    bool operator!=(const Child &kid) const;
    // Overloads the == operator allowing one to test the equality of one Child to another.
    bool operator==(const Child &kid) const;
    // Overloads the < operator allowing one to test whether the current Child is "less" than another.
    bool operator<(const Child &kid) const;
    // Overloads the < operator allowing one to test whether the current Child is "more" than another.
    bool operator>(const Child &kid) const;

private:
    // firstName is a value of a Child object.
    string firstName;
    // lastName is a value of a Child object.
    string lastName;
    // id is a value of a Child object.
    int id;
};

#include "Child.cpp"

#endif //CSS342LAB4_CHILD_H