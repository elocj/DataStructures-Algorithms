//
// Created by Anthony Joo on 2019-02-26.
//

#include <iostream>
#include "Child.h"
#include <sstream>

// Constructs a child object.
Child::Child()
{
    this->firstName = "";
    this->lastName = "";
    this->id = NULL;
}

// Constructs a copy constructor.
Child::Child(Child& k)
{
    *this = k;
}

// Constructor for a child with parameters.
Child::Child(string firstName, string lastName, int id)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = id;
}

// Overloads assignment operator to allow the copying of one child to another.
Child& Child::operator=(const Child &kid)
{
    this->firstName = kid.firstName;
    this->lastName = kid.lastName;
    this->id = kid.id;
    return *this;
}

// Overloads the inequality operator to test whether one child is not equal to another.
bool Child::operator!=(const Child &kid) const
{
    if(this->firstName == kid.firstName && this->lastName == kid.lastName && this->id == kid.id)
    {
        return false;
    }
    return true;
}

// Overloads the equality operator to test whether one child is equal to another.
bool Child::operator==(const Child &kid) const
{
    if(this->firstName == kid.firstName && this->lastName == kid.lastName && this->id == kid.id)
    {
        return true;
    }
    return false;
}

// Overloads the < operator to test whether one child is less in value than another.
bool Child::operator<(const Child &kid) const
{
    if(this->lastName < kid.lastName)
    {
        return true;
    } else if (this->lastName > kid.lastName)
    {
        return false;
    }
    else
    {
        if(this->firstName < kid.firstName)
        {
            return true;
        } else if (this->firstName > kid.firstName)
        {
            return false;
        }
        else
        {
            if(this->id < kid.id)
            {
                return true;
            } else if (this->id > id)
            {
                return false;
            }
            else
            {
                return false;
            }
        }
    }
}

// Overloads the > operator to test whether one child is greater in value than another.
bool Child::operator>(const Child &kid) const
{
    if(this->lastName > kid.lastName)
    {
        return true;
    } else if (this->lastName < kid.lastName)
    {
        return false;
    } else
    {
        if(this->firstName > kid.firstName)
        {
            return true;
        } else if(this->firstName < kid.firstName)
        {
            return false;
        }
        else
        {
            if(this->id > kid.id)
            {
                return true;
            } else if(this->id < kid.id)
            {
                return false;
            }
            else
            {
                return false;
            }
        }
    }
}

// Output operator overload allows the printing of child object information.
ostream& operator<<(ostream &outStream, const Child &kid)
{
    outStream << kid.firstName << kid.lastName << kid.id << flush;
    return outStream;
}

// Input operator overload allows the passing in of information to Child.
istream &operator >>(istream &inStream, Child &kid)
{
    inStream >> kid.firstName >> kid.lastName >> kid.id;
    return inStream;
}