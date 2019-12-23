// file binset.h
// header file for class BinSet

#ifndef BINTREE_H
#define BINTREE_H

#include "nodedata.h"
#include <algorithm>

//---------------------------------------------------------------------------
// BinTree class: defined as a binary tree equipped with many features:
//   - orders the elements so that the elements smaller in value are placed
//     on the left while elements larger in value are placed on the right
//   - insert an element into the tree
//   - initialize an empty tree
//   - check if tree is empty
//   - returning the height of a given element in the tree
//   - delete an element in the tree
//   - check if the tree contains a certain element
//   - print the binary tree
//
// Implementation and assumptions:
//   -- BinTree defaults to a nullptr root value when the constructor is called
//      without any parameters
//   -- in retrieve(), pass by reference the found value into a NodeData
//      variable
//   -- in arrayToBSTree(), recursively build the tree by taking the middle
//      element of the passed in array ((low + high) / 2))
//   -- the binary tree is made up of NodeData ADTs which hold string values
//   -- comparison of NodeData values is handled by the given NodeData class
//   -- on insert, false is returned if the value already exists in the tree
//   -- for bstreeToArray(), we are assuming an empty NodeData array of 100
//      elements
//---------------------------------------------------------------------------

class BinTree {
public:
    // constructors
    BinTree(); // constructor
    BinTree(const BinTree &); // copy constructor
    ~BinTree(); // destructor

    // functions
    bool isEmpty() const; // returns whether tree is empty
    int getHeight(const NodeData &) const; // returns the height of a given
                                           // NodeData in the tree
    void makeEmpty(); // deletes a BinTre object
    bool insert(NodeData*); // inserts a given NodeData into the BinTree
    bool retrieve(const NodeData&, NodeData*&) const; // retrieves a passed
                                                      // in NodeData and
                                                      // returns by reference.
                                                      // Also returns whether
                                                      // the retrieve was
                                                      // successful
//    void displaySideways() const; // displays BinTree sideways
//    void bstreeToArray(NodeData* []); // read values of BinTree into array
//    void arrayToBSTree(NodeData* []); // builds BinTree from array

    // operator overloading
    friend ostream& operator<<(ostream &, const BinTree &); // overloads <<
                                                            // operator
    bool operator==(const BinTree &) const; // overloads == operator
    bool operator!=(const BinTree &) const; // overloads != operator

private:
    struct Node {
        NodeData* data; // data associated with Node
        Node* left; // left pointer of given node
        Node* right; // right pointer of given node
    };
    Node* root; // root of given node

    // helper methods
    void inOrderHelper(Node*) const; // helper method for << operator
//    void sideways(Node*, int) const; // helper method for displaySideways()
    void makeEmptyUtil(Node *&) const; // helper method for makeEmpty()
//    void equalUtil(Node*&, const Node*) const; // helper method for = operator
    bool insertUtil(Node*&, NodeData*) const; // helper method for insert()
    int heightUtil(const Node*, const NodeData &, bool) const;
    // helper method of getHeight()
    bool retrieveUtil(Node*, const NodeData&, NodeData*&) const;
    // helper method for retrieve()
    bool isEqualUtil(const Node*, const Node*) const;
};

//#include "bintree.cpp"

#endif //BINTREE_H
