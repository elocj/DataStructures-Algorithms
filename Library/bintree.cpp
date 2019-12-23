// file bintree.cpp
// Member function definitions for class BinSet

#include "bintree.h"

// ---------------------------------------------------------------------------
// Constructor
// Constructs an empty BinTree object and assign nullptr to root

BinTree::BinTree() {
    root = nullptr;
}

// ---------------------------------------------------------------------------
// Copy constructor
// Pre: Takes in a BinTree object
// Post: Copies over this BinTree object with the object passed in

BinTree::BinTree(const BinTree &tree) {
    root = nullptr;
    *this = tree;
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for this IntSet object

BinTree::~BinTree() {
    makeEmpty();
}

// ---------------------------------------------------------------------------
// makeEmpty
// Post: Deletes a BinTree object

void BinTree::makeEmpty() {
    makeEmptyUtil(root);
}

void BinTree::makeEmptyUtil(Node *&current) const {
    if (current == nullptr) {
        return;
    }
    makeEmptyUtil(current->left);
    makeEmptyUtil(current->right);
    delete(current->data);
    current->data = nullptr;
    delete(current);
    current = nullptr;
};

// ---------------------------------------------------------------------------
// insert
// Pre: Takes in a NodeData object to insert into the BinTree
// Post: Traverses the BinTree and inserts the NodeData object and returns
//       true if inserted successfully and false otherwise (object already
//       exists)

bool BinTree::insert(NodeData* currData) {
    return insertUtil(root, currData);
}

bool BinTree::insertUtil(Node*& current, NodeData* currData) const {
    if(current == nullptr) {
        current = new Node();
        current->data = currData;
    } else if(*currData > *current->data) {
        return insertUtil(current->right, currData);
    } else if(*currData < *current->data) {
        return insertUtil(current->left, currData);
    } else {
        return false;
    }
    return true;
}

// ---------------------------------------------------------------------------
// isEmpty
// Returns whether the BinTree is empty or not

bool BinTree::isEmpty() const {
    return root == nullptr;
}

// ---------------------------------------------------------------------------
// getHeight
// Pre: Takes in a NodeData object
// Post: Traverses through this tree for the passed in value. Once found it
//       returns the longest path from this value to a null value.

int BinTree::getHeight(const NodeData &temp) const {
    return heightUtil(root, temp, false);
}

int BinTree::heightUtil(const Node* current, const NodeData &temp, bool found)
const {
    if(current == nullptr) {
        return 0;
    } else if(*current->data == temp) {
        return 1 + std::max(heightUtil(current->left, temp, true),
                heightUtil(current->right, temp, true));
    } else if(found) {
        return 1 + std::max(heightUtil(current->left, temp, true),
                heightUtil(current->right, temp, true));
    } else {
        return std::max(heightUtil(current->left, temp, false),
                heightUtil(current->right, temp, false));
    }
}

// ---------------------------------------------------------------------------
// retrieve
// Pre: Takes in a NodeData value and passes in by reference a NodeData object
// Post: Traverses through this BinTree searching for the given value and
//       copies this value to the temp NodeData by reference. Returns true if
//       given value is found and otherwise false.

bool BinTree::retrieve(const NodeData& value, NodeData*& temp) const {
    return retrieveUtil(root, value, temp);
}

bool BinTree::retrieveUtil(Node* current, const NodeData& value,
        NodeData*& temp) const {
    if(current == nullptr) {
        return false;
    } else if(*current->data == value) {
        temp = current->data;
        return true;
    } else {
        return retrieveUtil(current->left, value, temp) ||
        retrieveUtil(current->right, value, temp);
    }
}

// ---------------------------------------------------------------------------
// operator<<
// Overloaded <<: outputs the values in this BinTree object through In
//                Order Traversal

ostream& operator<<(ostream& output, const BinTree& tree)
{
    tree.inOrderHelper(tree.root); //call inOrderDisplay
    output << endl;
    return output;
}

void BinTree::inOrderHelper(Node *current) const {
    if(current != nullptr) {
        inOrderHelper(current->left);
//        cout << *current->data << " ";
        current->data->display();
        inOrderHelper(current->right);
    }
}

// ---------------------------------------------------------------------------
// operator==
// Pre: Takes in BinTree object
// Post: Returns a boolean that is true if this BinTree object is equal to the
//       BinTree object passed in

bool BinTree::operator==(const BinTree &tree) const {
    Node* temp = tree.root;
    return isEqualUtil(root, temp);
}

bool BinTree::isEqualUtil(const Node* current, const Node* temp) const {
    if(current == nullptr && temp == nullptr) {
        return true;
    } else if(current == nullptr || temp == nullptr) {
        return false;
    } else if(*current->data == *temp->data) {
        return isEqualUtil(current->left, temp->left) &&
        isEqualUtil(current->right, temp->right);
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------------
// operator!=
// Pre: Takes in BinTree object
// Post: Returns a boolean that is true if this IntSet object is not equal
//       to the BinTree object passed in

bool BinTree::operator!=(const BinTree &tree) const {
    return !(*this == tree);
}