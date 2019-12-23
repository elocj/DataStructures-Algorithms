// file intset.cpp
// Member function definitions for class IntSet

#include "intset.h"

// ---------------------------------------------------------------------------
// Constructor
// Pre: Takes in no initial values
// Post: Constructs an empty IntSet object
IntSet::IntSet() {
    ptr = new bool[1];
    ptr[0] = false;
    size = 0;
}

// ---------------------------------------------------------------------------
// Constructor
// Pre: Takes in one initial value
// Post: Constructs an IntSet object with one value
IntSet::IntSet(int num1) {
    ptr = new bool[num1 + 1];
    size = num1 + 1;
    for(int i = 0; i < size; i++) {
        ptr[i] = false;
    }
    ptr[num1] = true;
}

// ---------------------------------------------------------------------------
// Constructor
// Pre: Takes in two initial values
// Post: Constructs an IntSet object with two values
IntSet::IntSet(int num1, int num2) {
    int arr[] = {num1, num2};
    int* max = std::max_element(arr, arr + 2);
    ptr = new bool[*max + 1];
    size = *max + 1;
    for(int i = 0; i < size; i++) {
        ptr[i] = false;
    }
    for(const int &val : arr) {
        if(val >= 0) {
            ptr[val] = true;
        }
    }
}

// ---------------------------------------------------------------------------
// Constructor
// Pre: Takes in three initial values
// Post: Constructs an IntSet object with three values
IntSet::IntSet(int num1, int num2, int num3) {
    int arr[] = {num1, num2, num3};
    int* max = std::max_element(arr, arr + 3);
    ptr = new bool[*max + 1];
    size = *max + 1;
    for(int i = 0; i < size; i++) {
        ptr[i] = false;
    }
    for(const int &val : arr) {
        if(val >= 0) {
            ptr[val] = true;
        }
    }
}

// ---------------------------------------------------------------------------
// Constructor
// Pre: Takes in four initial values
// Post: Constructs an IntSet object with four values
IntSet::IntSet(int num1, int num2, int num3, int num4) {
    int arr[] = {num1, num2, num3, num4};
    int* max = std::max_element(arr, arr + 4);
    ptr = new bool[*max + 1];
    size = *max + 1;
    for(int i = 0; i < size; i++) {
        ptr[i] = false;
    }
    for(const int &val : arr) {
        if(val >= 0) {
            ptr[val] = true;
        }
    }
}

// ---------------------------------------------------------------------------
// Constructor
// Pre: Takes in five initial values
// Post: Constructs an IntSet object with five values
IntSet::IntSet(int num1, int num2, int num3, int num4, int num5) {
    int arr[] = {num1, num2, num3, num4, num5};
    int* max = std::max_element(arr, arr + 5);
    ptr = new bool[*max + 1];
    size = *max + 1;
    for(int i = 0; i < size; i++) {
        ptr[i] = false;
    }
    for(const int &val : arr) {
        if(val >= 0) {
            ptr[val] = true;
        }
    }
}

// ---------------------------------------------------------------------------
// Copy constructor
// Pre: Takes in a IntSet object
// Post: Copies over this IntSet object with the passed in object
IntSet::IntSet(IntSet& set) {
    ptr = new bool[set.size];
    for(int i = 0; i < set.size; i++) {
        ptr[i] = set.ptr[i];
    }
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for this IntSet object
IntSet::~IntSet() {
    delete [] ptr;
    ptr = nullptr;
}

// ---------------------------------------------------------------------------
// operator>>
// Overloaded >>: takes in and adds values to this IntSet continuously until
//                -1 is passed in
istream& operator>>(istream &input, IntSet &set) {
    int num = 0;
    while(num != -1) {
        input >> num;
        set.insert(num);
    }
    return input;
}

// ---------------------------------------------------------------------------
// operator<<
// Overloaded <<: outputs the values in this IntSet object in the format
//                '{ values}'
ostream& operator<<(ostream &output, const IntSet &set) {
    output << '{';
    for(int i = 0; i < set.size; i++) {
        const bool &val = set.ptr[i];
        if(val) {
            output << ' ' << i;
        }
    }
    output << '}' << endl;
    return output;
}

// ---------------------------------------------------------------------------
// operator+
// Pre: Takes in IntSet object
// Post: Returns the union of the values between this IntSet object and the
//       passed in IntSet object
IntSet IntSet::operator+(IntSet &set) {
    IntSet result;
    for(int i = 0; i < set.size; i++) {
        const bool &val = set.ptr[i];
        if(val) {
            result.insert(i);
        }
    }
    for(int i = 0; i < size; i++) {
        const bool &val = ptr[i];
        if(val) {
            result.insert(i);
        }
    }
    return result;
}

// ---------------------------------------------------------------------------
// operator*
// Pre: Takes in IntSet object
// Post: Return the intersection of the values between this IntSet object and
//       the IntSet object passed in
IntSet IntSet::operator*(IntSet &set) {
    IntSet result;
    for(int i = 0; i < set.size; i++) {
        const bool &val = set.ptr[i];
        if(val && size >= i + 1 && ptr[i]) {
            result.insert(i);
        }
    }
    return result;
}

// ---------------------------------------------------------------------------
// operator-
// Pre: Takes in IntSet object
// Post: Returns the set of values in this IntSet object that is not in the
//       passed in IntSet object
IntSet IntSet::operator-(IntSet &set) {
    IntSet result;
    for(int i = 0; i < size; i++) {
        const bool &val = ptr[i];
        if(val) {
            result.insert(i);
        }
    }
    for(int i = 0; i < set.size; i++) {
        const bool &val = set.ptr[i];
        if(val) {
            result.remove(i);
        }
    }
    return result;
}

// ---------------------------------------------------------------------------
// operator=
// Pre: Takes in IntSet object
// Post: Copies the values in the passed in IntSet object into this IntSet
IntSet &IntSet::operator=(const IntSet &set) {
    if(&set != this) {
        delete [] ptr;
        size = set.size;
        ptr = new bool[size];
        for(int i = 0; i < size; i++) {
            ptr[i] = false;
        }
        for(int i = 0; i < set.size; i++) {
            const bool &val = set.ptr[i];
            if(val) {
                ptr[i] = true;
            }
        }
    }
    return *this;
}

// ---------------------------------------------------------------------------
// operator+=
// Pre: Takes in IntSet object
// Post: Assigns to this IntSet its union with the passed in IntSet
IntSet& IntSet::operator+=(IntSet &set) {
    *this = *this + set;
    return *this;
}

// ---------------------------------------------------------------------------
// operator*=
// Pre: Takes in IntSet object
// Post: Assigns to this IntSet its intersection with another IntSet
IntSet& IntSet::operator*=(IntSet &set) {
    *this = *this * set;
    return *this;
}

// ---------------------------------------------------------------------------
// operator-=
// Pre: Takes in IntSet object
// Post: Assigns to this IntSet its difference from the passed in IntSet
IntSet& IntSet::operator-=(IntSet &set) {
    *this = *this - set;
    return *this;
}

// ---------------------------------------------------------------------------
// operator==
// Pre: Takes in IntSet object
// Post: Returns a boolean that is true if this IntSet object is equal to the
//       IntSet object passed in
bool IntSet::operator==(const IntSet &set) const {
    for(int i = 0; i < set.size; i++) {
        const bool &val = set.ptr[i];
        if(val) {
            if(size < i + 1 || !this->isInSet(i)) {
                return false;
            }
        }
    }
    for(int i = 0; i < size; i++) {
        const bool &val = ptr[i];
        if(val) {
            if(set.size < i + 1 || !set.isInSet(i)) {
                return false;
            }
        }
    }
    return true;
}

// ---------------------------------------------------------------------------
// operator!=
// Pre: Takes in IntSet object
// Post: Returns a boolean that is true if this IntSet object is equal to the
//       IntSet object passed in
bool IntSet::operator!=(const IntSet &set) const {
    return !(*this == set);
}

// ---------------------------------------------------------------------------
// insert
// Pre: Takes in a value to add into this IntSet object
// Post: Adds this value into this IntSet object and returns a boolean that is
//       true if the insert is successful
bool IntSet::insert(int value) {
    if(value >= 0) {
        if(size < value + 1) {
            bool *temp = new bool[value + 1];
            int tempSize = size;
            size = value + 1;
            for(int i = 0; i < size; i++) {
                temp[i] = false;
            }
            for(int i = 0; i < tempSize; i++) {
                temp[i] = ptr[i];
            }
            delete [] ptr;
            ptr = temp;
            temp = nullptr;
        }
        if(!ptr[value]) {
            ptr[value] = true;
        }
        return true;
    }
    return false;
}

// ---------------------------------------------------------------------------
// remove
// Pre: Takes in a value to remove from this IntSet object
// Post: Removes this value from this IntSet object and returns a boolean that
//       is true if the remove is successful
bool IntSet::remove(int value) {
    if(value >= 0 && size >= value + 1) {
        if(ptr[value]) {
            ptr[value] = false;
        }
        return true;
    }
    return false;
}

// ---------------------------------------------------------------------------
// isInSet
// Pre: Takes in a value to check if is in this IntSet object
// Post: Returns a boolean that is true if this value in in this IntSet object
bool IntSet::isInSet(int value) const {
    if(value >= 0 && size >= value + 1 && ptr[value]) {
        return true;
    }
    return false;
}

// ---------------------------------------------------------------------------
// isEmpty
// Returns a boolean that is true if this IntSet object is empty
bool IntSet::isEmpty() const {
    for(int i = 0; i < size; i++) {
        if(ptr[i]) {
            return false;
        }
    }
    return true;
}