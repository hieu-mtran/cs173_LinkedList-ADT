//========================================================
// Hieu Tran
// November 2023
// List.h
// This file contains the List class declaration.  
//========================================================

#include <iostream>
#include <string>
using namespace std;

#ifndef LIST_H
#define LIST_H

template <class T> 
class List
{
private:
	// struct for Node for linked list
	struct Node
	{
		T		item;
		Node 	*next;
	};
	
	Node	*head;		// the pointer for the linked list
	
public:
		List		( void );					// done
		List		( const List<T> &mylist );			// done
		~List		( void );					// done
List<T>		operator=	( const List<T> &mylist );			// done
void		append		( const T &item	);				// done
T &		operator[]	( int index );					// done
void		insert		( const T &item, int index );			// done
void		remove		( int index );					// done
List<T>		operator+	( const List<T> &mylist ) const;		// done
int			length		( void ) const;				// done
bool		isEmpty		( void ) const;					// done
void		clear		( void );					// done

friend ostream & operator<< ( ostream &os, List<T> &mylist )
{
	Node *ptr = mylist.head;
	os << "[ ";
	while ( ptr != NULL )
	{
		if ( ptr->next != NULL )
			os << ptr->item << ", ";
		else
			os << ptr->item << " ";
		ptr = ptr->next;
	}
	os << "]";
	return os;	
}


};


#include "List.cpp"

#endif


