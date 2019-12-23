//
// Created by Anthony Joo on 2019-02-26.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

template<class ItemType>
class LinkedList
{
public:
    // Output operator which allows the printing of information in the linked list.
    template<class friendItemType>
    friend ostream& operator <<(ostream &outStream, const LinkedList<friendItemType> &list);

    // Constructor, copy constructor, and destructor.
    LinkedList();
    LinkedList(LinkedList<ItemType>& l);
    ~LinkedList();

    // Class functions
    // Takes in a file to read in from and then build a linked list out of.
    bool BuildList(string fileName);
    // Inserts a given object into the linked list in sorted order.
    bool Insert(ItemType *obj);
    // Removes a given target object from the linked list and then passes this object into the reference, result.
    bool Remove(ItemType target, ItemType &result);
    // Finds a given target object in the linked list and then passes this object into the reference, result.
    bool Peek(ItemType target, ItemType &result) const;
    // isEmpty checks whether the linked list is empty.
    bool isEmpty() const;
    // DeleteList deletes a given list.
    void DeleteList();
    // Merge takes a given linked list and merges it with list1 in order.
    bool Merge(LinkedList &list1);

    // Operator Overloads
    // Overloads the + operator and returns a new linked list made of the two lists added together.
    LinkedList operator+(LinkedList &list);
    // Overloads the += operator and modifies the current list to also include the values passed in through list.
    LinkedList& operator+=(LinkedList &list);
    // Overloads the == operator so that one can check for equality between two linked lists.
    bool operator==(const LinkedList &list) const;
    // Overloads the != operator so that one can check for inequality between two linked lists.
    bool operator!=(const LinkedList &list) const;
    // Overloads the = operator so that one can assign a passed in list to the current list.
    LinkedList &operator=(const LinkedList &list);

private:
    // Node class which are the individual units which make a linked list.
    struct Node
    {
        ItemType *data;
        Node *next;
    };
    // Private "head" node that each linked list object is equipped with.
    Node* head;
};

#include "LinkedList.cpp"

#endif //CSS342LAB4_LINKEDLIST_H