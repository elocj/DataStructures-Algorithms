//
// Created by Anthony Joo on 2019-02-26.
//

#include <iostream>
#include <fstream>
#include "Child.h"
#include "LinkedList.h"
#include <sstream>

// Constructs a LinkedList object.
template<class ItemType>
LinkedList<ItemType>::LinkedList()
{
    head = NULL;
}

// Constructs a LinkedList object that is a copy of another.
template<class ItemType>
LinkedList<ItemType>::LinkedList(LinkedList<ItemType>& l)
{
    this->head = new Node();
    *this = l;
}

// Destroys a given LinkedList object.
template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    DeleteList();
}

// Inserts a given object into the LinkedList according to order. Returns true if the operation is complete, false
// otherwise.
template<class ItemType>
bool LinkedList<ItemType>::Insert(ItemType *obj)
{
    Node* current = head;
    Node* temp = new Node();
    temp->data = obj;
    if(this->isEmpty() || *head->data > *obj)
    {
        temp->next = head;
        head = temp;
        return true;
    }
    if(*head->data == *obj)
    {
        return false;
    }
    while(current->next != NULL && *current->next->data < *obj)
    {
        current = current->next;
        if(*current->data == *obj)
        {
            return false;
        }
    }
    if(current->next != NULL)
    {
        if(*current->next->data == *obj)
        {
            return false;
        }
    }
    temp->next = current->next;
    current->next = temp;
    return true;
}

// Removes a given object value from the LinkedList and assigns this value to the reference, result. Returns true
// if the operation is complete, false if otherwise.
template<class ItemType>
bool LinkedList<ItemType>::Remove(ItemType target, ItemType &result)
{
    Node* current = head;
    if(this->isEmpty())
    {
        return false;
    }
    if(*head->data == target)
    {
        ItemType* answer = &result;
        *answer = target;
        Node* temp = current;
        current = current->next;
        head = head->next;
        delete(temp);
        return true;
    }
    if(current->next == NULL)
    {
        return false;
    }
    while(*current->next->data != target)
    {
        current = current->next;
        if(current->next == NULL)
        {
            return false;
        }
    }
    ItemType* answer = &result;
    *answer = target;
    Node* temp = current->next;
    current->next = current->next->next;
    delete(temp);
    return true;
}

// Searches for a given object value in the LinkedList and assigns this value to the reference, result. Returns true
// if the operation is complete, false if otherwise.
template<class ItemType>
bool LinkedList<ItemType>::Peek(ItemType target, ItemType &result) const
{
    Node* current = head;
    if(this->isEmpty())
    {
        return false;
    }
    if(*head->data == target)
    {
        ItemType* answer = &result;
        *answer = target;
        return true;
    }
    if(current->next == NULL)
    {
        return false;
    }
    while(*current->next->data != target)
    {
        current = current->next;
        if(current->next == NULL)
        {
            return false;
        }
    }
    ItemType* answer = &result;
    *answer = target;
    return true;
}

// Returns true if the LinkedList is empty and false if LinkedList is not empty.
template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
    if(head == NULL)
    {
        return true;
    }
    return false;
}

// Deletes a given linked list.
template<class ItemType>
void LinkedList<ItemType>::DeleteList()
{
    Node* current = head;
    while(!this->isEmpty())
    {
        head = current->next;
        delete(current);
        current = head;
    }
}

// Builds a linked list out of a given input file. Return true if the operation is completed, false if otherwise.
template<class ItemType>
bool LinkedList<ItemType>::BuildList(string fileName)
{
    ifstream file;
    file.open(fileName);
    if(file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            stringstream iss(line);
            ItemType *temp = new ItemType();
            iss >> *temp;
            Insert(temp);
        }
        file.close();
        return true;
    }
    return false;
}

// Merge, merges two different Linked Lists together. Return true if the operation is completed, false if otherwise.
// A situation in which false is returned is if the lists are the same or the passed in list is empty.
template<class ItemType>
bool LinkedList<ItemType>::Merge(LinkedList<ItemType> &list1)
{
    Node* current = this->head;
    Node* current2 = list1.head;
    LinkedList<ItemType> result;
    result.head = new Node();
    result.head->data = new ItemType();
    Node* final = result.head;
    if(list1.isEmpty() || *this == list1)
    {
        return false;
    } else if(this->isEmpty())
    {
        result = list1;
    } else{
        if(*current->data < *current2->data)
        {
            *final->data = *current->data;
            current = current->next;
        } else if(*current->data > *current2->data)
        {
            *final->data = *current2->data;
            current2 = current2->next;
        } else
        {
            *final->data = *current->data;
            current = current->next;
            current2 = current2->next;
        }
        while(current != NULL && current2 != NULL)
        {
            final->next = new Node();
            final->next->data = new ItemType();
            final = final->next;
            if(*current->data < *current2->data)
            {
                *final->data = *current->data;
                current = current->next;
            } else if(*current->data > *current2->data)
            {
                *final->data = *current2->data;
                current2 = current2->next;
            } else
            {
                *final->data = *current->data;
                current = current->next;
                current2 = current2->next;
            }
        }
        while(current != NULL)
        {
            final->next = new Node();
            final->next->data = new ItemType();
            final = final->next;
            *final->data = *current->data;
            current = current->next;
        }
        while(current2 != NULL)
        {
            final->next = new Node();
            final->next->data = new ItemType();
            final = final->next;
            *final->data = *current2->data;
            current2 = current2->next;
        }
    }
    list1.DeleteList();
    *this = result;
    return true;
}

// Overloads the + operator in order to add multiple Linked Lists.
template<class ItemType>
LinkedList<ItemType> LinkedList<ItemType>::operator+(LinkedList<ItemType> &list)
{
    LinkedList<ItemType> result;
    this->Merge(list);
    result = *this;
    return result;
}

// Overloads the += operator in order to add a passed in linked list to a preexisting one.
template<class ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::operator+=(LinkedList<ItemType> &list)
{
    this->Merge(list);
    return *this;
}

// Overloads output operator and allows the printing of linked list data.
template<class ItemType>
ostream& operator<<(ostream &outStream, const LinkedList<ItemType> &list)
{
    class LinkedList<ItemType>::Node* temp = list.head;
    while(temp != NULL)
    {
        outStream << *temp->data << flush;
        temp = temp->next;
    }
    return outStream;
}

// Overloads the equality operator to test whether two linked lists are equal.
template<class ItemType>
bool LinkedList<ItemType>::operator==(const LinkedList<ItemType> &list) const
{
    Node* current = head;
    Node* current2 = list.head;
    if(this->isEmpty() && list.isEmpty())
    {
        return true;
    }
    if(this->isEmpty() || list.isEmpty() || *current->data != *current2->data)
    {
        return false;
    }
    while(current->next != NULL && current2->next != NULL)
    {
        current = current->next;
        current2 = current2->next;
        if(*current->data != *current2->data)
        {
            return false;
        }
    }
    if(current->next != NULL || current2->next != NULL)
    {
        return false;
    }
    return true;
}

// Overloads the inequality operator to test whether two linked lists are not equal.
template<class ItemType>
bool LinkedList<ItemType>::operator!=(const LinkedList<ItemType> &list) const
{
    Node* current = head;
    Node* current2 = list.head;
    if(this->isEmpty() && list.isEmpty())
    {
        return false;
    }
    if(current == NULL || current2 == NULL || *current->data != *current2->data)
    {
        return true;
    }
    while(current->next != NULL && current2->next != NULL)
    {
        current = current->next;
        current2 = current2->next;
        if(*current->data != *current2->data)
        {
            return true;
        }
    }
    if(current->next != NULL || current2->next != NULL)
    {
        return true;
    }
    return false;
}

// Overloads the assignment operator to allow one linked list to equal another.
template<class ItemType>
LinkedList<ItemType> &LinkedList<ItemType>::operator=(const LinkedList<ItemType> &list)
{
    if(this == &list || list.isEmpty())
    {
        return *this;
    }
    this->DeleteList();
    Node* current = list.head;
    head = new Node();
    Node* currentNow = head;
    currentNow->data = new ItemType();
    *currentNow->data = *current->data;
    while(current->next != NULL)
    {
        current = current->next;
        currentNow->next = new Node();
        currentNow->next->data = new ItemType();
        currentNow = currentNow->next;
        *currentNow->data = *current->data;
    }
    return *this;
}