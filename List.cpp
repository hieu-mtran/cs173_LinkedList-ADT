//==============================================================
// Hieu Tran
// December 2023
// List.cpp
// This file contains the class methods for the templated List class.
//==============================================================

#include <iostream>
#include <string>
#include "List.h"
using namespace std;

//==============================================================
// Default constructor
// Creates a new List object with:
// - capacity: default list size
// - size: 0 (empty List)
// Parameters: none
// Return value: none
//==============================================================
template <typename T>
            List<T>::List       (void)
{
    head = NULL;
}

//==============================================================
// Copy constructor
// Creates a new List object that is a copy of the parameter.
// Return value: none
//==============================================================
template <typename T>
            List<T>::List	    (const List<T> &mylist)
{
    if (mylist.head == NULL)
        head = NULL;
    else
    {
        Node *fromPtr = mylist.head;
        Node *toPtr;

        head = new Node;
        head->item = fromPtr->item;
        toPtr = head;
        fromPtr = fromPtr->next;

        while (fromPtr != NULL)
        {
            toPtr->next = new Node;
            toPtr = toPtr->next;
            toPtr->item = fromPtr->item;
            fromPtr = fromPtr->next;
        }
        
        toPtr->next = NULL;
    }
}

//==============================================================
// Destructor
// Deallocates the dynamically allocated memory used by a List.
//==============================================================
template <typename T>
            List<T>::~List      (void)
{
    Node *ptr = head;
    while (head != NULL)
    {
        ptr = head->next;
        delete head;
        head = ptr;
    }
}

//==============================================================
// Assignment operator
// Performs a deep copy operation, replacing the content of a List
// with a copy of the elements from another List.
// Parameters: address of the List to be copied from
// Return value: the modified List
//==============================================================
template <typename T>
List<T>     List<T>::operator=  (const List<T> &mylist)
{
    if (this != &mylist)
    {
        clear();
        if (mylist.head == NULL)
            head = NULL;
        else
        {
            Node *fromPtr = mylist.head;
            Node *toPtr;

            head = new Node;
            head->item = fromPtr->item;
            toPtr = head;
            fromPtr = fromPtr->next;

            while (fromPtr != NULL)
            {
                toPtr->next = new Node;
                toPtr = toPtr->next;
                toPtr->item = fromPtr->item;
                fromPtr = fromPtr->next;
            }

            toPtr->next = NULL;
        }
    }
    return *this;
}

//==============================================================
// append
// Appends a given item onto the back of a List.
// Parameters: item of type T
// Return value: none
//==============================================================
template <typename T>
void        List<T>::append     (const T &item)
{
    Node *qtr = new Node;
    qtr->item = item;
	qtr->next = NULL;
	
	if (head == NULL)
	{
		head = qtr;
	}
	else
	{
		Node *ptr = head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = qtr;
	}
}

//==============================================================
// operator[]
// Returns the item at a given index in a List.
// Parameters: index as int
// Return value:
// - none given an invalid index;
// - the item of type T if otherwise
//==============================================================
template <typename T>
T &         List<T>::operator[] (int index)
{
    if (index < 0 || index >= length())
        throw invalid_argument("Invalid index");

    Node *ptr = head;
    int ptr_pos = 0;

    while (ptr_pos != index)
    {
        ptr = ptr->next;
        ptr_pos++;
    }
    return ptr->item;
}

//==============================================================
// insert
// Inserts a given item into a given position of a List.
// Parameters:
// - item of type T - to be inserted
// - int position
// Return value: none (item inserted given a valid index)
//==============================================================
template <typename T>
void        List<T>::insert     (const T &item, int index)
{
    if (index < 0 || index > length())
        throw invalid_argument("Invalid index");
    else if (index == length())
        append(item);
    else if (index == 0)
    {
        Node *qtr = new Node;
        qtr->item = item;
        qtr->next = head;
        head = qtr;
    }
    else 
    {
        Node *ptr = head;
        int ptr_pos = 0;

        while (ptr_pos != index - 1)
        {
            ptr = ptr->next;
            ptr_pos++;
        }

        Node *qtr = new Node;
        qtr->item = item;
        qtr->next = ptr->next;
        ptr->next = qtr;
    }
}

//==============================================================
// remove
// Removes the item at a given index in a List.
// Parameters: index as int
// Return value: none (item removed given a valid index)
//==============================================================
template <typename T>
void        List<T>::remove     (int index)
{
    if (index < 0 || index >= length())
        throw std::invalid_argument("Invalid index");
        
    if (index == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        Node *ptr = head;
        int ptr_pos = 0;

        while (ptr_pos != index - 1)
        {
            ptr = ptr->next;
            ptr_pos++;
        }

        Node *qtr = ptr->next;
        ptr->next = qtr->next;
        delete qtr;
    }
}

//==============================================================
// operator+
// Concatenates two lists into a new list, existing lists remain unchanged.
// Parameters: List reference to l
// Returns: a new List object
//==============================================================
template <typename T>
List<T>     List<T>::operator+  (const List<T> &l) const
{
    List<T> concat;

    if (head == NULL && l.head == NULL)
    {
        return concat;
    }

    Node *leftPtr = head;
    while (leftPtr != NULL)
    {
        concat.append(leftPtr->item);
        leftPtr = leftPtr->next;
    }

    Node *rightPtr = l.head;
    while (rightPtr != NULL)
    {
        concat.append(rightPtr->item);
        rightPtr = rightPtr->next;
    }

    return concat;
}

//==============================================================
// length
// Returns the number of items in the List.
// Parameters: none
// Return value: size as int
//==============================================================
template <typename T>
int         List<T>::length     (void) const
{
    Node *ptr = head;
	int count = 0;
	
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}

	return count;
}

//==============================================================
// isEmpty
// Checks if the List in question is empty.
// Parameters: none
// Return value:
// - true if the list is empty;
// - false otherwise
//==============================================================
template <typename T>
bool         List<T>::isEmpty   (void) const
{
    return (head == NULL);
}

//==============================================================
// clear
// Removes all items from the List.
// Parameters: none
// Return values: none (all elements in List removed)
//==============================================================
template <typename T>
void        List<T>::clear      (void)
{
    this->~List();
    head = NULL;
}